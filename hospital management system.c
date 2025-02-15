#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

// Define a struct for a patient
struct patient {
    char fname[50];
    char lname[50];
    char patienttype[50];
    char sex[50];
    char bloodtype[50];
    char disease[50];
    int age;
    int address;
    int serialnumber;
};


struct patient allpatient[1000];


int countpatients = 0;

// Find the index of a patient given their serial number
int findpatient(int k)
{
    for(int i = 0; i < countpatients; i++) {
        if(allpatient[i].serialnumber == k) {
            return i;
        }
    }
    return -1;
}

// Add a patient to the allpatient array
void add_patient()
{
    if(countpatients == 1000) {
        return; // Full capacity
    }
    struct patient s;
    printf("Patient's Name\n");
    printf("First Name: ");
    scanf("%s", s.fname);
    printf("Last Name: ");
    scanf("%s", s.lname);
    printf("sex: ");
    scanf("%s", s.sex);
    printf("patienttype:");
    scanf("%s", s.patienttype);
    printf("bloodtype:");
    scanf("%s", s.bloodtype);
    printf("disease:");
    scanf("%s", s.disease);
    printf("age:");
    scanf("%d", &s.age);
    printf("address:");
    scanf("%d", &s.address);
    printf("serial number:");
    scanf("%d", &s.serialnumber);
    allpatient[countpatients] = s;
    countpatients++;
}
// Edit a patient's information
void edit_patient()
{
    int serial_num;
    printf("Please enter the serial number of the patient: ");
    scanf("%d", &serial_num);
    int index = findpatient(serial_num);
    if(index == -1) {
        printf("Patient not found.\n");
        return;
    }
    int option;
    printf("What do you want to edit?\n");
    printf("Enter your option:\n");
    printf("1. First name\n2. Last name\n3. Patient type\n4. Sex\n5. Blood type\n6. Disease\n7. Age\n8. Address\n");
    printf("Option: ");
    scanf("%d", &option);
    if(option >= 1 && option <= 8) {
        if(option == 1) {
            printf("Enter the new first name: ");
            scanf("%s", allpatient[index].fname);
        }
        else if(option == 2) {
            printf("Enter the new last name: ");
            scanf("%s", allpatient[index].lname);
        }
        else if(option == 3) {
            printf("Enter the new patient type: ");
            scanf("%s", allpatient[index].patienttype);
        }
        else if(option == 4) {
            printf("Enter the newsex: ");
            scanf("%s", allpatient[index].sex);
        }
        else if(option == 5) {
            printf("Enter the new blood type: ");
            scanf("%s", allpatient[index].bloodtype);
        }
        else if(option == 6) {
            printf("Enter the new disease: ");
            scanf("%s", allpatient[index].disease);
        }
        else if(option == 7) {
            printf("Enter the new age: ");
            scanf("%d", &allpatient[index].age);
        }
        else if(option == 8) {
            printf("Enter the new address: ");
            scanf("%s", allpatient[index].address);
        }
    }
    else {
        printf("Invalid option.\n");
        return;
    }
}
//List a patient's information given their serial number
void list_patient()
{
    int k;
    printf("Enter a serial number: ");
    scanf("%d", &k);
    int index = findpatient(k);
    if(index == -1) {
        printf("Patient not found\n");
    }
    else {
        printf("First name: %s\n", allpatient[index].fname);
        printf("Last name: %s\n", allpatient[index].lname);
        printf("Patient type: %s\n", allpatient[index].patienttype);
        printf("Sex: %s\n", allpatient[index].sex);
        printf("Blood type: %s\n", allpatient[index].bloodtype);
        printf("Disease: %s\n", allpatient[index].disease);
        printf("Age: %d\n", allpatient[index].age);
        printf("Address: %d\n", allpatient[index].address);
    }
}

// Delete a patient given their serial number
void patient_delete()
{
    int k;
    printf("Enter a serial number: ");
    scanf("%d", &k);
    int index = findpatient(k);
    if(index == -1) {
        printf("Patient not found\n");
    }
    else {
        printf("The deleted patient is %s %s\n", allpatient[index].fname, allpatient[index].lname);
        for(int i = index; i < countpatients - 1;i++) {
            allpatient[i] = allpatient[i+1];
        }
        countpatients--;
    }
}

// Calculate the hospital's remaining capacity
void hospital_capacity()
{
    int capacity = 1000 - countpatients;
    printf("The capacity of the hospital is %d\n", capacity);
}

// Track the number of emergency patients and available intensive care beds
void Track_intensive_care()
{
    int beds = 1000;
    int count = 0;
    for(int i = 0; i < countpatients; i++) {
        if(strcmp(allpatient[i].patienttype, "emergency") == 0) {
            count++;
        }
    }
    int capacity = beds - count;
    printf("The number of emergency patients is %d\n", count);
    printf("The number of available beds is %d\n", capacity);
}

// Track the number of newborn babies and available incubators
void Track_baby_incubators()
{
    int incubators = 1000;
    int incubatorscount = 0;
    for(int i = 0; i < countpatients; i++) {
        if(strcmp(allpatient[i].patienttype, "new born") == 0) {
            incubatorscount++;
        }
    }
    int babyincubators = incubators - incubatorscount;
    printf("The number of babies in incubators is %d\n",incubatorscount);
    printf("The number of available incubators is %d\n", babyincubators);
}
int main(){
    int input;
    while(1) {
        printf("\n");
        printf("1. Add patient\n");
        printf("2. Track intensive care\n");
        printf("3. Track baby incubators\n");
        printf("4. Hospital capacity\n");
        printf("5. Edit patient information\n");
        printf("6. List patient information\n");
        printf("7. Delete patient\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &input);
        switch(input) {
            case 1:
                add_patient();
                break;
            case 2:
                Track_intensive_care();
                break;
            case 3:
                Track_baby_incubators();
                break;
            case 4:
                hospital_capacity();
                break;
            case 5:
                edit_patient();
                break;
            case 6:
                list_patient();
                break;
            case 7:
                patient_delete();
                break;
            case 8:
                return 0;
            default:
                printf("Invalid option\n");
                break;
        }
    }

    return 0;
}




