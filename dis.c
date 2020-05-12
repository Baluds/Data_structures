#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Student
{
    char stdName[50];
    char USN[50];
    int semNo;
    int scoredCredits;
    int pendingCredits;
}v;
struct studentBST
{
    struct Student student;
    struct studentBST *right;
    struct studentBST *left;
};
struct studentBST * createNode(struct Student s);        
void insertStudentBST(struct studentBST *h,struct Student s);
void displayStudent(struct Student std);
struct Student* searchStudent(struct studentBST * sl, char *usn);
void requiredCredits(struct Student s);
void inorderBST(struct studentBST *s);
int main()
{
    struct studentBST *head=NULL;
    struct Student *a;
   // h=NULL;
    int flag1;
    char choice[20],roll[50],ch[50];
    flag1=0;
    do
    {
      printf("Enter the details of Students\n");
     printf("Student Name,USN,Semester\n");
     scanf("%s %s %d",v.stdName,v.USN,&v.semNo);
                 do{
       if(flag1==1)
       {
           scanf("%d",&v.semNo);
         
       }
       if(v.semNo <=8 && v.semNo >1)
    {
    printf("Enter the scored and pending credits");
    scanf("%d %d",&v.scoredCredits,&v.pendingCredits);
    printf("\n");
    flag1=0;
    }
    else if(v.semNo==1)
    {
         v.scoredCredits=0;
        v.pendingCredits=0;
        flag1=0;
    }
    else if(v.semNo>8 || v.semNo <=0 || isalpha(v.semNo))
    {
        flag1=1;
        printf("Please Enter Sem NO b/w 1-8\n");
        
    }
    }while(v.semNo>8 || v.semNo<=0 || isalpha(v.semNo));
     insertStudentBST(head,v);           
printf("Do you want to insert one more student data?(y/n)");
scanf("%s",choice);
 }while(strcmp(choice,"y")==0);  
 printf("\nInserted Student Details!!");
 inorderBST(head);
 do
 {
 printf("\nEnter the Student USN to search");
 scanf("%s",roll);
 a=searchStudent(head,roll);
 if(a==NULL)
 printf("\nStudent Data Doesn't Exist!!");
// else
 //searchStudent(h,roll);
// requiredCredits(v);
 printf("\nDo you want to search one more student data?(y/n");
 scanf("%s",ch);
}while(strcmp(ch,"y")==0);
   return 0;
}




struct studentBST *createNode(struct Student s)
{
struct studentBST *newnode=(struct studentBST*)malloc(sizeof(struct studentBST));
newnode->right=NULL;
newnode->left=NULL;
newnode->student=s;

return newnode;
}
void insertStudentBST(struct studentBST *h,struct Student s)
{
    struct studentBST *newnode=(struct studentBST*)malloc(sizeof(struct studentBST));
   // newnode=createNode(s);
    if(h==NULL)
    {
        newnode=createNode(s);
        h=newnode;
    }
    else if(strcmp(h->student.USN,s.USN)==1)
    {
        insertStudentBST(h->right,s);
    }
    else
    {
     insertStudentBST(h->left,s);  
    }

}
void displayStudent(struct Student std)
{
    printf("%-10s %-10s %-10d %-10d %-d\n",std.stdName, std.USN,std.semNo,std.scoredCredits,std.pendingCredits);
}

struct Student* searchStudent(struct studentBST *sl, char *usn)
{
    if(sl==NULL)
    {
       return NULL;   
       }
    if(strcmp(sl->student.USN,usn)==0)
    {
        displayStudent(sl->student);
        requiredCredits(sl->student);
    }
  else if(strcmp(sl->student.USN,usn)==1)
    {
        sl->student=searchStudent(sl->right,usn);
    }
    else
    {
     sl->student=searchStudent(sl->left,usn);  
    }
   return &(sl->student);
}
void requiredCredits(struct Student s)
{
   int max=180,x;
   x=max-s.scoredCredits;
  printf("\n%s scored credits till sem %d is %d",s.stdName,s.semNo,s.scoredCredits);
   printf("\nRequired to complete the graduation %d",x);
}
void inorderBST(struct studentBST *s)
{
if(s==NULL)
{
    return;
    
}
  else
  {
      inorderBST(s->left);
      printf("%s %s %d %d",s->student.stdName,s->student.USN,s->student.scoredCredits,s->student.pendingCredits);
      inorderBST(s->right);
  }
   
}