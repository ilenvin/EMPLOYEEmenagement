#include<stdio.h>
/*Structure*/
struct date{
    int d,m,y;
}date;
struct employee{
    char firstname[100],lastname[100],email[100],status[50],position[50];
    int id,year,tel;
    struct date Sdate;
};
typedef struct employee employee;
//Function
employee info[1000];
void AddEmployee(int x);
void DisplayInfo();
void DisplayViaID();
//Main Program
int main(){
    int select,n,i=1;
    while(i>0){
        printf("--------------------------\n");
        printf("---------(Menu)-----------\n");
        printf("  1. Add employee\n");
        printf("  2. Display employee information\n");
        printf("  3. Display employee info via ID\n");
        printf("  4. Update employee info via ID\n");
        printf("  5. Delete employee info via ID\n");
        printf("  6. Display retire employee\n");
        printf("  7. Exit\n");
        printf(">>>>>> Select (1-7): "); scanf("%d",&select);
        if(select==1){
            printf(">>>Input among of employee: "); scanf("%d",&n);
            AddEmployee(n);
        }else if(select==2){
            DisplayInfo();
        }else if(select==3){
            //
        }else if(select==4){
            //
        }else if(select==5){
            //
        }else if(select==6){
            //
        }else if(select==7){
            break;
        }
        i++;
    }
}
//Block Code of Function
void AddEmployee(int x){
    FILE *file;
    file=fopen("Employee.txt","a");
    for(int i=0;i<x;i++){
        printf(">>>>Employee %d<<<<\n",i+1);
        printf("\tFirst name: "); scanf("%s",&info[i].firstname);
        printf("\tLast name: "); scanf("%s",&info[i].lastname);
        printf("\tID: "); scanf("%d",&info[i].id);
        printf("\tBirth's year: "); scanf("%d",&info[i].year);
        printf("\tPhone number: "); scanf("%d",&info[i].tel);
        printf("\tStart working date: \n");
        printf("\t\t_Day: "); scanf("%d",&info[i].Sdate.d);
        printf("\t\t_Month: "); scanf("%d",&info[i].Sdate.m);
        printf("\t\t_Year: "); scanf("%d",&info[i].Sdate.y);
        printf("\tPosition: "); scanf("%s",&info[i].position);
        printf("\tStatus: "); scanf("%s",&info[i].status);
        printf("\tEmail: "); scanf("%s",info[i].email);
        fprintf(file,"%s %s %d %d %d %d %d %d %s %s %s\n",info[i].firstname,info[i].lastname,info[i].id,info[i].year,info[i].tel,info[i].Sdate.d,info[i].Sdate.m,info[i].Sdate.y,info[i].position,info[i].status,info[i].email);
    }
    fclose(file);
}
void DisplayInfo(){
    FILE *file;
    char str[11][100];
    printf("------------------------------------------------------------------------------------------------------------\n");
    printf("Name\t\tID\tBirth's year\tTelephone\tStart Date\tPosition\tStatus\tEmail\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
    file=fopen("Employee.txt","r");
        while(fscanf(file,"%s %s %s %s %s %s %s %s %s %s %s",str[0],str[1],str[2],str[3],str[4],str[5],str[6],str[7],str[8],str[9],str[10])!=EOF){
            printf("%s\t%s\t%s\t%s\t\t%s\t%s/%s/%s\t%s\t\t%s\t%s\n",str[0],str[1],str[2],str[3],str[4],str[5],str[6],str[7],str[8],str[9],str[10]);
        }
    printf("------------------------------------------------------------------------------------------------------------\n");
    fclose(file);
}

