#include<stdio.h>
#include<string.h>

struct project {
    int id;
    char name[50];
    char technology[50];
    char status[20];
};
struct project projects[100];
int count = 0;

// CREATE 
void add_project(){
    printf("No. of details of projects u what to add?");
       int choice;
       scanf("%d",&choice);
       for(int i=0;i<choice;i++){
    printf("\nEnter Project ID:");
    scanf("%d",&projects[count].id);

    printf("Enter Project Name:");
    scanf("%s",projects[count].name);

    printf("Enter Project Technology Use:");
    scanf("%s",projects[count].technology);

    printf("Enter Project Status(Complete/In Progress):");
    scanf("%s",projects[count].status);
    count++;

    printf("✅PROJECT %d IS ADDED SUCCESSFULLY !");
    
}
}

//VIEW
void view_projects(){
    if(count == 0){
        printf("\n❌Project Not Found !\n");
        return;
    }
    printf("\n ----- PROJECTS LIST -----");
    for(int i=0;i<count;i++){
        printf("\nPROJECT ID:%d",projects[i].id);
        printf("\nPROJECT Name:%s",projects[i].name);
        printf("\nPROJECT Technology:%s",projects[i].technology);
        printf("\nPROJECT Status:%s",projects[i].status);
    }
}
 
//SEARCH
void search_project(){
    int id, found= 0;
    printf("\n ----- SEARCH PROJECT -----");
    printf("ENTER PROJECT ID TO SEARCH:");
    scanf("%d",&id);

    for(int i=0;i<count;i++){
        if(projects[i].id==id){
            printf("Project Found !");
            printf("\nPROJECT Name:%s",projects[i].name);
            printf("\nPROJECT Technology:%s",projects[i].technology);
            printf("\nPROJECT Status:%s",projects[i].status);
            found=1;
            break;
        }
    }
        if(!found)
            printf("\n❌Project Not Found !\n");
}

//Update
void update_project(){
    int id,found=0;
    printf("\n ----- UPDATE PROJECT-----");
    printf("\n Enter Project ID to Update:");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(projects[i].id==id){
            printf("\nEnter New PROJECT Name:");
            scanf("%s",projects[i].name);

            printf("\n Enter New PROJECT Technology:");
            scanf("%s",projects[i].technology);

            printf("\nEnter New PROJECT Status:");
            scanf("%s",projects[i].status);

            printf("\n ✅Project Updated Successfully !");
            found=1;
            break;
        }
    }
        if(!found)
           printf("❌Project Not Found !"); 
}

//DELETE
void delete_project(){
    int id,found=0;
    printf("\n ----- DELETE PROJECT-----");
    printf("\n Enter Project ID to Delete:");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(projects[i].id==id){
            for(int j=i; j<count-1;j++){
                projects[j]=projects[j+1];
            }
            count--;
            found =1;
            printf("\n✅Project is Deleted Successfully !");
            break;
        }
    }
        if(!found)
        printf("\n ❌Project Not Found !");
}
// DASHBOARD
void dashboard() {

    int completed = 0;
    int inprogress = 0;

    for(int i = 0; i < count; i++) {

        if(strcmp(projects[i].status, "Completed") == 0)
            completed++;
        else
            inprogress++;
    }

    printf("\n================================");
    printf("\n          DASHBOARD");
    printf("\n================================");

    printf("\nTotal Projects      : %d", count);
    printf("\nCompleted Projects  : %d", completed);
    printf("\nIn Progress         : %d", inprogress);

    if(count > 0) {
        printf("\nCompletion Rate     : %.2f%%",
               (completed * 100.0) / count);
    }

    printf("\n================================\n");
}

int main(){
    int choice;
    do {
        printf("\n* * * * * * PORTFOLIO PROJECT MANAGER * * * * * *\n");
        
        printf("\n1.ADD PROJECTS");
        printf("\n2.VIEW PROJECTS");
        printf("\n3.SEARCH PROJECT");
        printf("\n4.UPDATE PROJECT");
        printf("\n5.DELETE PROJECT");
        printf("\n6.DASHBOARD");
        printf("\n7.EXIT");

        printf("\nEnter Your Choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1: 
                add_project();
                break;
            case 2:
                view_projects();
                break;
            case 3:
                search_project();
                break;
            case 4:
                update_project();
                break;
            case 5:
                delete_project();
                break;
            case 6:
                dashboard();
            
            case 7:
                 printf("\n == T H A N K  Y O U ! ==");
                 printf("\n == FOR USING PORTFOLIO PROJECT MANAGER==");
                 break;
            default:
                 printf("\n == INVAILD CHOICE ! ==");
                 printf("\n === PLZ TRY AGAIN ===");                       
        }
    }
    while(choice !=6);
    return 0;
}