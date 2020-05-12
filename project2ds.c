#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Subject
{
    char stdId[50];
    char stdName[50];
    int stdcredits;
}p[8][8];
struct subStack
{
    struct Subject sub[500];
    int totalCredits;
    int top;
}k;
struct Student
{
    char stName[50];
    char USN[50];
    int semNo;
    int scoredCredits;
    int pendingCredits;
    struct subStack substack;
}s;
struct studentList
{
    struct Student student;
    struct studentList* next;
};
struct studentList * createNode(struct Student s);
void insertStudentList(struct studentList ** h, struct Student s);
void displaySubjectDetails(struct Subject []);
int findSubject(struct Subject s[],char * sid);
void displaySubject(struct subStack *ss);
void displayStudent(struct studentList *sl);
void int_Stack(struct subStack *s,int pending_credits);
void pushSubject(struct subStack *s,struct Subject sb);
void popSubject(struct subStack *s);
int main()
{
   char id[50],ans[20]  ,bigch[20],biggestch[20];
   int a;
 struct studentList *h=NULL;
    int flag1;
    
    flag1=0;
    
  struct Subject p1[9][8]={
{{" "," ",4},          {" "," ",4},             {" "," ",4},              {" "," ",4},               {" "," ",4},              {" "," ",4},           {" "," ",4},             {" "," ",4}},
{{"MA1C01","MATHS1",5},{"PH1C01","PHYSICS",5},  {"CV1C01","MECHANICS",5}, {"ME1C01","MECHANICAL",5}, {"EE1C01","ELECTRICAL",5},{"PH1L01","EPL",4},    {"CM1L01","CHEMISTRY",4},{"ME1L01","GEP",4}},
{{"MAC101","MATHS2",5},{"CH1C01","CHEMISTRY",5},{"CS","C-PROGRAMMING",5}, {"EC1C01","ELECTRONICS",5},{"ME1C02","CAD",5},       {"CH1L01","ECL",4},    {"CS1L01","CCP",4},      {"CV101","Digital Programming",5}},
{{"MA3C01","MATHS3",5},{"CS3C03","DS",5},       {"CS3C02","DE",5},        {"CS3C03","CO",5},         {"CS3C04","DMS",5},       {"CS3C05","USP",5},    {"CS3L01","DSL",4},      {"CS3L02","DEL",4}},
{{"MA4C03","MATHS4",5},{"CS4C01","ADA",5},      {"CS02","SE",5},          {"CS403","OOPS",5},        {"CS4C04","FAFL",5},      {"CS4C05","DCN",5},    {"CS4L01","ADAL",4},     {"CS4L02","OOPL",4}},
{{"CS0407","SA",5},    {"CS0413","OS",5},       {"CS0414","DBMS",5},      {"CS0512","SS",5},         {"CS0424","ME",5},        {"CS0425","MP",5},     {"CS0106","MPL",4},      {"CS0107","DBMS",4}},
{{"CS0418","CN",5},    {"CS0523","OOMD",5},     {"CS0425","CD",5},        {"CS0450","WTA",5},        {"CS0426","DA",5},        {"CS0427","ANDROID",5},{"CS0112","WTAL",4},     {"CS0109","CNL",4}},
{{"CS0445","DOS",5},   {"CS0521","CNS",5},      {"CS0422","PPAA",5},      {"CS0522","E1",5},         {"CS0523","E2",5},        {"CS0524","E3",5},     {"CS0524","E4",4},       {"CS0524","E5",4}},
{{"CS0501","CC",5},    {"CS0502","E6",5},       {"CS0503","E7",5},        {"CS0110","SEMINAR",5},    {"CS0602","PROJECT",5},   {"CS0504","E8",4},     {"CS0505","E9",4},       {"CS0506","E10",4}}
        };
    do
    {
    printf("Enter the details to register for the Semester\n");
    printf("Student Name,USN,Semester\n");
    scanf("%s %s %d",s.stName,s.USN,&s.semNo);
  do{
       if(flag1==1)
       {
           scanf("%d",&s.semNo);
         
       }
       if(s.semNo <=8 && s.semNo >1)
    {
    printf("Enter the scored and pending credits");
    scanf("%d %d",&s.scoredCredits,&s.pendingCredits);
    flag1=0;
    }
    else if(s.semNo==1)
    {
         s.scoredCredits=0;
        s.pendingCredits=0;
        flag1=0;
    }
    else if(s.semNo>8 || s.semNo <=0 || isalpha(s.semNo))
    {
        flag1=1;
        printf("Please Enter Sem NO b/w 1-8\n");
        
    }
    }while(s.semNo>8 || s.semNo<=0 || isalpha(s.semNo));
    printf("Select the required subjects for Semester %d from the below list\n",s.semNo);
    displaySubjectDetails(p1[s.semNo]);
    int_Stack(&k,s.pendingCredits);
  do
  {
do
  {
      printf("Enter the Subject Id\n");
    scanf("%s",id);
   a=findSubject(p1[s.semNo],id);
  
   if(a!=-1)
   {
   pushSubject(&k,p1[s.semNo][a-1]);
   printf("\nCurrent total credits %d\n",k.totalCredits);
   }
   else
   printf("Subject Not found,Plz Enter correct Sub Id!!\n");
  }while(a==-1);
  printf("Confirm your selection!!(y/n)\n");
  scanf("%s",ans);
  if(strcmp(ans,"n")==0)
  {
    popSubject(&k);
    k.totalCredits=k.totalCredits-p1[s.semNo][a].stdcredits;
    printf("Total credits after Confirmation %d\n",k.totalCredits);
  }
  else
  {
  printf("Total credits after Confirmation %d\n",k.totalCredits);
  }
   if(k.totalCredits<=30)
   {
 printf("Do you want stop the selection of subjects?(y/n)\n");
  scanf("%s",bigch);
   }
   if(strcmp(bigch,"y")==0 && k.totalCredits<20 )
  {
  printf("You didn't reach the credits target!!\nPlease continue..\n");
  }
  if(k.totalCredits>30)
  {
  printf("Crossed credits limits!!\n");
  popSubject(&k);
    k.totalCredits=k.totalCredits-p1[s.semNo][a].stdcredits;
    printf(" Removed the recently added subject!!\n");
    printf("Total credits after removing %d\n",k.totalCredits);
    printf("Do you want stop the selection of subjects?(y/n)\n");
  scanf("%s",bigch);
 
  }
  }while(strcmp(bigch,"n")==0 || k.totalCredits<20);

    displaySubject(&k);
    s.substack=k;
    insertStudentList(&h,s);
   printf("Do you want to one more registration?(y/n)\n");
   scanf("%s",biggestch);
    }while(strcmp(biggestch,"y")==0);
    displayStudent(h);
    return 0;
}

struct studentList * createNode(struct Student s)
{
struct studentList *newnode=(struct studentList*)malloc(sizeof(struct studentList));
newnode->next=NULL;
newnode->student=s;
return newnode;
}

void insertStudentList(struct studentList ** h, struct Student s)
{
struct studentList *newnode;
struct studentList *temp;
newnode=createNode(s);
temp=*h;
if(*h==NULL)
{
    *h=newnode;

}
else
{
while(temp->next!=NULL)
{
    temp=temp->next;
}
temp->next=newnode;
}
}

void displaySubjectDetails(struct Subject s5[8])
{
    int i;
   printf("%-10s %-10s %-s\n","Sub Id","Sub Name","Sub Credits");
   for(i=0;i<8;i++)
   {
   printf("%-10s %-10s %d\n",s5[i].stdId,s5[i].stdName,s5[i].stdcredits);
   }
}

int findSubject(struct Subject s6[],char *sid)
{
   int flag,j;
  flag=0;
  for(j=0;j<8;j++)
        {
            if(strcmp(s6[j].stdId,sid)==0)
            {
            flag=1;
            break;
            }
           }
     if(flag==0)
     {
         return -1;
     }
     else
     {
         return j+1;
         
     }
       }

void displaySubject(struct subStack *ss)
{
    int i;
    printf("\nSelected Subjects are");
    printf("%-10s %-10s %-s\n","Sub Id","Sub Name","Sub Credits");
    for(i=0;i<=ss->top;i++)
    {
printf("%-10s %-10s %-d\n",ss->sub[i].stdId,ss->sub[i].stdName,ss->sub[i].stdcredits);
}
printf("Total Credits after selection %d",k.totalCredits);
   }

void displayStudent(struct studentList *sl)
{
    int i;
    printf("Student registration details:\n");
    struct studentList *temp;
    temp=sl;
    while(temp!=NULL)
    {
     printf("%-10s %-10s %-10s %-10s %-s\n","Stud Name","Stud USN","Semester","Sc credits","Pe credits");
 printf("%-10s %-12s %-10d %-10d %-d\n",temp->student.stName,temp->student.USN,temp->student.semNo,temp->student.scoredCredits,temp->student.pendingCredits);  
 printf("\nSelected Subjects are");
    printf("%-10s %-10s %-s\n","Sub Id","Sub Name","Sub Credits");
    for(i=0;i<=temp->student.substack.top;i++)
    {
printf("%-10s %-10s %-d\n",temp->student.substack.sub[i].stdId,temp->student.substack.sub[i].stdName,temp->student.substack.sub[i].stdcredits);
}
printf("Total Credits after selection %d",temp->student.substack.totalCredits);
temp=temp->next;
}
}

void int_Stack(struct subStack *s2,int pending_credits)
{
    s2->totalCredits=pending_credits;
    s2->top=-1;
}

void pushSubject(struct subStack *s1,struct Subject sb)
{
    s1->top=s1->top+1;
   s1->sub[s1->top]=sb;
  s1->totalCredits=sb.stdcredits+s1->totalCredits;
}

void popSubject(struct subStack *s1)
{
    if(s1->top==-1)
    {
    printf("stack is empty");
    }
    else
    {
        s1->top=s1->top-1;
    }
}