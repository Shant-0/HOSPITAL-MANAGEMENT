#include <stdio.h>
#include <string.h>
#include<stdlib.h>
typedef struct
{
    char name[50];
    int age;
    char ailment[50];
    char doctor[50];
    int patient_count;
    int bed;
    int ward;
} Patient;
typedef struct
{
    char docname[50];
    int fees_per_day;
    char tratment[20];
    int patientcount;
} doctor;
doctor doc [100];
Patient patients[1000];
int patient_count = 0;
int bed_price = 1200;
int ward_price = 800;
int maxbedcount = 750;
int maxwardcount =250;
int bedcount = 0;
int wardcount = 0;
int patientcount=0;
void admit(int n,int maxb,int maxw)
{
    int idx;
    char dok[50];
    if (patient_count >= n)
    {
        printf("Patient limit reached!\n");
        return;
    }
    printf("Enter Patient Name : ");
    scanf(" %[^\n]", patients[patient_count].name); 
    printf("Enter Age : ");
    scanf("%d", &patients[patient_count].age);
    printf("Enter Patient ailment : ");
    scanf(" %[^\n]", patients[patient_count].ailment);
    printf("Enter doctor name : ");
    scanf(" %[^\n]", dok);
    int doc_found=0;
    for (int i = 0; i < 5; i++)
    {
    if (strcmp(dok,doc[i].docname)==0)
    {
       strcpy(patients[patient_count].doctor,dok);
       doc_found=1;
       idx=i;
    }
    }
    if (doc_found==0)
    {
        printf("doctor not found.");
        return;
    }
    if (strcmp(doc[idx].tratment,patients[patient_count].ailment)!=0)
    {
        printf("this doctor dosen't treat for this rog.");
        return;
    }
    printf("enter where the patient wanted to be admited\n1. ward(800 taka per day)\n2. cabin(1200 taka per day)\nenter :");
    int choice;
    scanf("%d",&choice);
    switch (choice)
    {
    case 1 :
       {
        wardcount++;
        if (wardcount>maxw)
        {
            printf("ward is full!!");
        }
        else
        {
             patients[patient_count].ward=wardcount;
             doc[idx].patientcount++;
             patient_count++;
             printf("Patient admitted successfully!\n");
        }
       }
        break;
    case 2 :
    {
        bedcount++;
        if (maxb<bedcount)
        {
            printf("bed is full!!");
        }
        else{
          patients[patient_count].bed=bedcount;
          doc[idx].patientcount++;
          patient_count++;
          printf("Patient admitted successfully!\n");
          }
    }
    break;
    default:
    printf("invalid input.");
        break;
    }   
}
void doct(int n)
{
     for (int i = 0; i < n; i++)
    {
       printf("Enter doctor name :");
       scanf(" %[^\n]", doc[i].docname);
       printf("Enter the doctors fees per day :");
       scanf(" %d",& doc[i].fees_per_day);
       printf("Enter the doc treatment :");
       scanf(" %[^\n]", doc[i].tratment);
    }
}
void update_doc(int n)
{
        int index;       
    for (int i = 0; i < n; i++)
    {
        printf("\n%d. doctor : %s",i+1,doc[i].docname);
    }
    printf("\nEnter the index of the doctor to update (1 to %d): ", n);
    scanf("%d", &index);
    index--;            
    int change;
    if (index >= 0 && index < n)
    {
        printf("What do you want to update : \n1. doctor name.\n2. doctor fee.\n3. doctor treatment. \nEnter :");
        scanf("%d",&change);
        switch (change)
        {
        case 1:
        {
            printf("Enter new doctor name: ");
            scanf(" %[^\n]", doc[index].docname);
        }
            break;
         case 2:
         {
            printf("Enter new doctor fee: ");
            scanf(" %d",& doc[index].fees_per_day);
         }
            break;
         case 3:
         {
            printf("Enter new doctors treatment: ");
            scanf(" %[^\n]", doc[index].tratment);
         }
            break;
        default:
        {
         printf("enter a valid input");
          return;
        }
        break;
        }
        printf("update successfull");

    }
    else
    printf("Invalid doctor index!\n\n");
}
void genreport(int n,int mb , int mw)
{
    printf("Hospital report.");
    for (int i = 0; i < n; i++)
     {   
        printf("\ndoctor: %s\nfees per day :%d\npatients under him :%d\n\n", doc[i].docname,doc[i].fees_per_day,doc[i].patientcount);
     }
     printf("total patient :%d empty bed :%d empty ward :%d",patient_count,mb-bedcount,mw-wardcount);
}
void searchpatient()
{
    char name[50];
   printf("\nEnter patient name :");
   scanf(" %[^\n]", name);
   int found = 0;
   for (int i = 0; i < patient_count; i++)
   {
    if (strcmp(patients[i].name,name)==0)
    {
        found=1;
        if (patients[i].bed==0)
            printf("\npatient :%s\ndoctor :%s\nward number :%d\n",patients[i].name,patients[i].doctor,patients[i].ward);
        else
        printf("\npatient :%s\ndoctor :%s\nbed number :%d\n",patients[i].name,patients[i].doctor,patients[i].bed);
    }
   }
    if(found == 0)
    {
    printf("patient not found!!\n\n");
   }
}
void discharge(int n)
{
    int idx;
    char name[50];
   printf("\nEnter patient name :");
   scanf(" %[^\n]", name);
   int found=0;
   for (int i = 0; i < patient_count; i++)
   {   
      if (strcmp(patients[i].name,name)==0)
       {
         idx=i;  
         found=1;
       }
   }
   if(found!=0)
   {
    if (patients[idx].bed==0)
         {
           wardcount--;
         }
         if (patients[idx].ward==0)
         {
           bedcount--;
         }
   for (int i = idx; i < patient_count; i++)
   {
      patients[i]=patients[i+1];
   }
   for (int i = 0; i < n; i++)
   {
    if(strcmp(patients[idx].doctor,doc[i].docname)==0)
    doc[i].patientcount--;
   }
   printf("\npatient discharged\n");
    patient_count--;
   }
   else
   printf("enter a valid patient name");
}
void billing(int n)
{
    int idx1,idx2,day;
    char name[50];
     printf("\nEnter your patient name :");
     scanf(" %[^\n]", name);
     for (int i = 0; i < patient_count; i++)
     {
        if (strcmp(patients[i].name,name)==0)
        {
           idx1=i; 
        }
     }
     for (int i = 0; i < n; i++)
   {
     if(strcmp(patients[idx1].doctor,doc[i].docname)==0)
     idx2=i;
   }
     int bed , ward;
     printf("\nhow many days the patient was admited in bed :");
     scanf("%d",& bed);
     printf("\nhow many days the patient was admited in ward :");
     scanf("%d",& ward);
     day=bed+ward;
     int doc_bill;
     doc_bill=day*doc[idx2].fees_per_day;
     int bill;
     bill=(bed*1200)+(ward*800);
    printf("\ndoctors bill :%d\nhospital bill :%d\ntotal bill :%d",doc_bill,bill,doc_bill+bill);
}
void showpatient()
{
    for (int i = 0; i < patient_count; i++)
   {
      printf("patient name :%s\tpatient age :%d\npatients doctor :%s\tpatient has :%s\n\n",patients[i].name,patients[i].age,patients[i].doctor,patients[i].ailment);
   }
}
int main()
{
   int n,pat,maxb,maxw;
   printf("enter how many doctors your hospital have :");
   scanf("%d",&n);
   printf("enter how many patients can your hospital have :");
   scanf("%d",&pat);
   printf("enter how many beds your hospital have :");
   scanf("%d",&maxb);
   printf("enter how many wards your hospital have :");
   scanf("%d",&maxw);
   doct(n);
    int choice;
  do
    {
        printf("\nHospital  Management System\n\n");
        printf("1. Add Patient\n");
        printf("2. Display Patient Details\n");
        printf("3. Update doctor Status\n");
        printf("4. doctor Report\n");
        printf("5. discharge patient\n");
        printf("6. Billing System\n");
        printf("7. showpatient\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            admit(pat,maxb,maxw);
            break;
            case 2:
            searchpatient();
            break;
            case 3:
             update_doc(n);
            break;
            case 4:
            genreport(n,maxb,maxw);
            break;
            case 5:
            discharge(n);
            break;
            case 6:
            billing(n);
            break;
            case 7:
            showpatient(); 
            break;
            case 8:
            printf("tada");
            break;
            default:
            printf("invalid input");
            break;
        }
    }
    while(choice!=8);
    
}