#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct Subject
{
    char stdId[50];
    char stdName[50];
    int stdcredits;
}p[8][8],g;

struct Student
{
    char stName[50];
    char USN[50];
    int semNo;
    int scoredCredits;
    int scoredPending;
   
}v;

struct subQ
{
    struct Subject sub[10];
    int front;
    int rear;
}chota;
struct subStatusQ
{
    char status[40];
    int front;
    int rear;
}bada;
struct studentList
{
    struct Student student;
    struct studentList* next;
};
struct studentList * createNode(struct Student s);
void insertStudentList(struct studentList ** h, struct Student s);
void displaySubjectDetails(struct Subject []);
void displayAttemptedSub(struct subQ *ss,struct subStatusQ *sq);
void displayStudent(struct studentList *sl);
void init_Q(struct subQ *s,struct subStatusQ *sq);
void insertSubjectQ(struct subQ *s,struct Subject sb);
void insertStatusQ(struct subStatusQ *s,char c);
struct Subject deleteSubjectQ(struct subQ *s);
char deleteStatusQ(struct subStatusQ *s);
void creditCalculation(struct subQ *s,struct subStatusQ *sq,struct Student *std);

int main()
{
   char choice[50],ch[50];
   char li;
   int zebra;
 struct studentList *h=NULL;
    int flag1,flag;
    init_Q(&chota,&bada);
    flag1=0;
    flag=0;
    
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
    init_Q(&chota,&bada);
    printf("Enter the details of Students\n");
    printf("Student Name,USN,Semester\n");
    scanf("%s %s %d",v.stName,v.USN,&v.semNo);
  do{
       if(flag1==1)
       {
           scanf("%d",&v.semNo);
         
       }
       if(v.semNo <=8 && v.semNo >1)
    {
    printf("Enter the scored and pending credits");
    scanf("%d %d",&v.scoredCredits,&v.scoredPending);
    printf("\n");
    flag1=0;
    }
    else if(v.semNo==1)
    {
         v.scoredCredits=0;
        v.scoredPending=0;
        flag1=0;
    }
    else if(v.semNo>8 || v.semNo <=0 || isalpha(v.semNo))
    {
        flag1=1;
        printf("Please Enter Sem NO b/w 1-8\n");
        
    }
    }while(v.semNo>8 || v.semNo<=0 || isalpha(v.semNo));
    printf("Select the attempted subjects of Semester %d from the below list\n",v.semNo);
    displaySubjectDetails(p1[v.semNo]);
    do
    {
   printf("Enter the SNo");
    scanf("%d",&zebra);
    do
    {      if(flag==1)
           {
           scanf("%d",&zebra);
           }
        if((zebra<9) && (zebra>0))
        {
        getchar();
        printf("\nEnter the Subject Status(P/F)");
        scanf("%c",&li);
        printf("\n");
        g=p1[v.semNo][zebra-1];
      // printf("%s hiiii",g.stdName);
        insertSubjectQ(&chota,g);
        insertStatusQ(&bada,li);
        displayAttemptedSub(&chota,&bada);
        flag=0;
        }
        else
        {
            flag=1;
            printf("Enter the valid choice");
        }
        
        }while(zebra>=9 || zebra<=0);
        creditCalculation(&chota,&bada,&v);
        printf("Do you want to stop the insertion of subject?(y/n)");
        scanf("%s",ch);
        printf("\n");
}while(strcmp(ch,"n")==0);
insertStudentList(&h,v);
printf("Do you want to one more Calculation?(y/n)");

scanf("%s",choice);
    }while(strcmp(choice,"y")==0);
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

void displaySubjectDetails(struct Subject s5[])
{
    int i;
   printf("%-10s %-10s %-10s %-s\n","SNo","Sub Id","Sub Name","Sub Credits");
   for(i=0;i<8;i++)
   {
   printf("%-10d %-10s %-10s %-d\n",i+1,s5[i].stdId,s5[i].stdName,s5[i].stdcredits);
   }
}

void displayAttemptedSub(struct subQ *ss,struct subStatusQ *sq)
{
     int i;
     //printf("%d is front\n",ss->front);
    //printf("%s is rear\n",ss->sub[ss->rear].stdName);

   printf("%-10s %-10s %-10s %-s\n","Sub Id","Sub Name","Sub Credits","Sub Status");
   for(i=ss->front+1;i<=ss->rear;i++)
   {
  printf("%-10s %-10s %-10d %c\n",ss->sub[i].stdId,ss->sub[i].stdName,ss->sub[i].stdcredits,sq->status[i]);
   }
}

void displayStudent(struct studentList *sl)
{
   // int i;
    printf("Student Updated details after Sem Exam:\n");
    struct studentList *temp;
    temp=sl;
    while(temp!=NULL)
    {
     printf("%-10s %-10s %-10s %-10s %-s\n","Stud Name","Stud USN","Semester","Sc credits","Pe credits");
 printf("%-10s %-10s %-10d %-10d %-d\n",temp->student.stName,temp->student.USN,temp->student.semNo,temp->student.scoredCredits,temp->student.scoredPending);  
/* printf("\nSelected Subjects are");
    printf("%-10s %-10s %-s\n","Sub Id","Sub Name","Sub Credits");
    for(i=0;i<=temp->student.substack.top;i++)
    {
printf("%-10s %-10s %-d\n",temp->student.substack.sub[i].stdId,temp->student.substack.sub[i].stdName,temp->student.substack.sub[i].stdcredits);
}
printf("Total Credits after selection %d",temp->student.substack.totalCredits);*/
temp=temp->next;
}
}

void init_Q(struct subQ *s,struct subStatusQ *sq)
{
 s->front=0;
 s->rear=0;
 sq->front=0;
 sq->rear=0;
    
}

void insertSubjectQ(struct subQ *s,struct Subject sb)
{
   // printf("insert alli");
  // printf("%d rear value is",s->rear);
   if(s->rear>=10)
   {
   printf("overflow");
   }
   else
   {
    //printf("%d rear value is",s->rear);
    s->rear=s->rear+1;
    // printf("%d rear value is",s->rear);
    s->sub[s->rear]=sb;
   // printf("%s is there",s->sub[s->rear].stdName);
   }
}

void insertStatusQ(struct subStatusQ *s,char c)
{
  if(s->rear>=10)
   {
   printf("overflow");
   }
   else
   {
    s->rear=s->rear+1;
    s->status[s->rear]=c;
  //  printf("%c is there",s->status[s->rear]);
   }
    
}

struct Subject deleteSubjectQ(struct subQ *s)
{
    
struct Subject x;
    /*if(s->rear<s->front)
   {
        printf("Queue is empty");
        
    }
    else
    {*/
        x=s->sub[s->front];
        s->front=s->front+1;
        return x;
        
   // }
    
}

char deleteStatusQ(struct subStatusQ *s)
{
    char re;
   /* if(s->rear<s->front)
    {
        printf("Queue is empty");
        ret
    }
    else
    {*/
        re=s->status[s->front];
        s->front=s->front+1;
        return re;
    //}
}

void creditCalculation(struct subQ *s,struct subStatusQ *sq,struct Student *std)
{
     //int i;
     char j;
     //printf("scored is %d,pending is %d",std->scoredCredits,std->scoredPending);
      //for(i=s->front+1;i<=s->rear;i++)
    //  {
        j=sq->status[s->rear];
        if(j=='P')
        {
          //  printf("SUB C %d",std->scoredCredits);
            std->scoredCredits=std->scoredCredits+s->sub[s->rear].stdcredits;
        }
        else
        {
            std->scoredPending=std->scoredPending+s->sub[s->rear].stdcredits;
        }
     // }
}