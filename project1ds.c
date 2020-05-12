#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Subject
{
    char subId[50];
    char subName[50];
    int subCredits;
}s;
struct subjectList
{
    struct Subject subjectSub;
    struct subjectList* subjectList;
};
void insert(struct subjectList **h,struct Subject s);
struct subjectList* createNode(struct Subject s);
void display(struct subjectList* s);
int main()
{
    int choice,x;
    char ch[10];
    struct subjectList *head1=NULL,*head2=NULL,*head3=NULL,*head4=NULL,*head5=NULL,*head6=NULL,*head7=NULL,*head8=NULL;
   do
   {
       do
    {
        printf("Enter the Semester for which you want to insert the subjects\n");
        scanf("%d",&choice);
       x=0;
        if(choice>8)
        {
             printf("Please Enter Sem No b/w 1 - 8\n");  
        }
    } while (choice>8);
    do
    {
       x++;
        printf("Enter the Subject %d Details\nEnter Subject Id,Name,Credits\n",x);
        if(choice==1)
        insert(&head1,s);
        if(choice==2)
        insert(&head2,s);
        if(choice==3)
        insert(&head3,s);
        if(choice==4)
        insert(&head4,s);
        if(choice==5)
        insert(&head5,s);
        if(choice==6)
        insert(&head6,s);
        if(choice==7)
        insert(&head7,s);
        if(choice==8)
        insert(&head8,s);
        
    }while(x<7);
    printf("Do you want to insert one more Sem subject details?(y/n)");
    scanf("%s",ch);
   }while(strcmp(ch,"y")==0);
   if(strcmp(ch,"n")==0)
   {
   printf("Display the Entered Sem Details\n");
   printf("Semester 1 Details\n");
   if(head1!=NULL)
   display(head1);
   else
   printf("----Not Entered Yet----\n");
   printf("Semester 2 Details\n");
   if(head2!=NULL)
   display(head2);
   else
   printf("----Not Entered Yet----\n");
   printf("Semester 3 Details\n");
   if(head3!=NULL)
   display(head3);
   else
   printf("----Not Entered Yet----\n");
   printf("Semester 4 Details\n");
   if(head4!=NULL)
   display(head4);
   else
   printf("----Not Entered Yet----\n");
   printf("Semester 5 Details\n");
   if(head5!=NULL)
   display(head5);
   else
   printf("----Not Entered Yet----\n");
   printf("Semester 6 Details\n");
   if(head6!=NULL)
   display(head6);
   else
   printf("----Not Entered Yet----\n");
   printf("Semester 7 Details\n");
   if(head7!=NULL)
   display(head7);
   else
   printf("----Not Entered Yet----\n");
   printf("Semester 8 Details\n");
   if(head8!=NULL)
   display(head8);
   else
   printf("----Not Entered Yet----\n");
   }
   return 0;
   
}

void insert(struct subjectList **h,struct Subject s)
{
    scanf("%s %s %d",s.subId,s.subName,&s.subCredits);

     struct subjectList *temp=(struct subjectList*)malloc(sizeof(struct subjectList));
     struct subjectList *temp1=(struct subjectList*)malloc(sizeof(struct subjectList));
    temp=createNode(s);
    temp1=*h;
    if(*h==NULL)
    {
        *h=temp;
    }
    else
    {
    while(temp1->subjectList!=NULL)
    {
        temp1=temp1->subjectList;
    }
    temp1->subjectList=temp;
    }
}
struct subjectList* createNode(struct Subject s)
 {
     struct subjectList *temp=(struct subjectList*)malloc(sizeof(struct subjectList));
     temp->subjectSub=s;
     temp->subjectList=NULL;
     return temp;
     
 }
 void display(struct subjectList* s)
 {
      struct subjectList *temp1=(struct subjectList*)malloc(sizeof(struct subjectList));
      temp1=s;
      printf("%-10s %-10s %-10s\n","Sub Id","Sub Name","Sub Credits");
      while(temp1!=NULL)
    {
        printf("%s      %s         %d         \n",temp1->subjectSub.subId,temp1->subjectSub.subName,temp1->subjectSub.subCredits);
        temp1=temp1->subjectList;
    } 
 }