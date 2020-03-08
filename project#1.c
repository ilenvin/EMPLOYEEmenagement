#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
enum Status{working=1, resigned, stopped, retired};
struct StartDate{
    int day;
    int mon;
    int year;
};
struct Employee{
    int id;
    char firstname[20];
    char lastname[20];
    char sex[8];
    int yob;
    char tel[20];
    char email[20];
    struct StartDate date;
    char position[20];
    enum Status stat;
    char status[10];
};
typedef struct Employee Employee;

Employee emp[1000];
int latestEmployeeIndex=0;
int n=0; //n as latest employee index

/*bool checkExist(int id){
    for(int i=0; i<1000; i++){
        if(employees[i].id == id){
            return true;
        }
    }
    return false;
*/
void displayMenu(){

    printf("\n1. Add a new employee\t\t\t\t5. Search an employee\n");
    printf("2. Display info of all working employee\t\t6. Sorted by started working date\n");
    printf("3. Update info\t\t\t\t\t7. Sorted by position\n");
    printf("4. Delete an employee\t\t\t\t8. Display all retired employee\n");
    printf("\t\t\t\t\t\t9.Exit the program\n");
}

void addNewEmployee(){

    printf("Enter ID: "); scanf("%d", &emp[n].id);
    printf("Enter first name: "); scanf("%s", &emp[n].firstname);
    printf("Enter last name: "); scanf("%s", &emp[n].lastname);
    printf("Enter sex: "); scanf("%s", &emp[n].sex);
    printf("Enter year of birth: "); scanf("%d", &emp[n].yob);
    printf("Enter phone number: "); scanf("%s", &emp[n].tel);
    printf("Enter email: "); scanf("%s", &emp[n].email);
    printf("Enter started working date (dd-mm-yyyy): ");
    scanf("%d %d %d",&emp[n].date.day,&emp[n].date.mon,&emp[n].date.year);
    printf("Enter position: "); scanf("%s", &emp[n].position);
    printf("Choose working status:\n\t1. Working\t2. Resigned\t3. Stopped\t4. Retired\n");
    printf(">> "); scanf("%d", &emp[n].stat);
    n++;
}
void copyStatus(){ //copying from enum to variable status
    for(int i=0;i<n;i++){
        if(emp[i].stat==working){
            strcpy(emp[i].status,"working");
        }
        else if(emp[i].stat==resigned){
            strcpy(emp[i].status,"resigned");
        }
        else if(emp[i].stat==stopped){
            strcpy(emp[i].status,"stopped");
        }
        else if(emp[i].stat==retired){
            strcpy(emp[i].status,"retired");
        }
    }
}

void displayWorking(){
    printf("No.\tID\tFirstname\tLastname\tSex\tBirth's year\tPhone number\tEmail\tStatus\tStated working date\tPosition\n");
    copyStatus();
    for(int i=0;i<n;i++){
        //if(emp[i].stat==working){
            printf("%d\t%d\t%s\t%s\t%s\t%d\t%s\t%s\t%s\t%2d-%2d-%d\t%s\n",i+1,emp[i].id,emp[i].firstname,emp[i].lastname,emp[i].sex,emp[i].yob,emp[i].tel,emp[i].email,emp[i].status,emp[i].date.day,emp[i].date.mon,emp[i].date.year,emp[i].position);
        //}
    }
}
void Search(int id){
    int flag=0;

    copyStatus();
    for(int i=0;i<n;i++){
        if(emp[i].id==id){
            printf("\nFirst name: %s\n",emp[i].firstname);
            printf("Last name: %s\n",emp[i].lastname);
            printf("Sex: %s\n",emp[i].sex);
            printf("Birth's year: %d\n",emp[i].yob);
            printf("Phone number: %s\n",emp[i].tel);
            printf("Email: %s\n",emp[i].email);
            printf("Working status: %s\n",emp[i].status);
            printf("Started date: %2d-%2d-%d\n",emp[i].date.day,emp[i].date.mon,emp[i].date.year);
            printf("Position: %s\n",emp[i].position);
            flag=1;
        }
        if(flag==0){
            printf("is not found.\n");
        }
    }
}

void displayRetired(){
    copyStatus();
    for(int i=0;i<n;i++){
        if(emp[i].stat==retired){
            printf("%d\t%s\t%s\n",emp[i].id,emp[i].firstname,emp[i].lastname);
        }
    }
}

int main(){

    int opt, id;

    printf("\t\t\t********************************\n");
    printf("\t\t\t~WELCOME TO EMPLOYEE MANAGEMENT~\n");
    printf("\t\t\t********************************\n");

    //addNewEmployee();
    //scanf("%s ",&employees[0].stat);

    while(opt!=9){
        displayMenu();
        printf("\n>>Enter your option: "); scanf("%d", &opt);

        switch(opt){
            case 1:{
                addNewEmployee();
                break;
            }
            case 2:{
                //display all
                displayWorking();
                break;
            }
            case 3:{
                //update
                break;
            }
            case 4:{
                //delete
                break;
            }
            case 5:{
                //search

                printf(">>Enter id: "); scanf("%d",&id);

                printf("The employee with ID %d ",id);
                Search(id);

                break;
            }
            case 6:{
                //sorted by working date
                break;
            }
            case 7:{
                //sorted by position
                break;
            }
            case 8:{
                //display retired
                displayRetired();
                break;
            }
            case 9:{
                printf("Exiting the program.....\n");
                break;
            }
            default:{
                printf("INVALID!!\n");
            }
        }

    }




}
