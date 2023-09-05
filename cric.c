#include <stdio.h>
#include <stdlib.h>
char t1[10],t2[10];
int i,j;
int sc1,sc2;
struct player 
{
    char name1[20];
    char name2[20];
    
} s[11];

void details()
{

    printf(" Enter Team 1 :\n");
    gets(t1);
    printf(" Enter Team 2 :\n");
    gets(t2);
    printf(" Enter team1 players:\n");
    for (i = 0; i < 3; ++i)
    {
        printf("%d",i+1);
        scanf("%s",s[i].name1);
    }
    printf(" Enter team2 names:\n");
    for (i = 0; i < 3; ++i)
    {
        printf("%d",i+1);
        scanf("%s",s[i].name2);
    }
    
}
void toss()
{
    int toss,ts,d,i=1;
    printf("\nToss Time!!");
    printf("\n%s Call \n1. For HEADS or 2.For Tails\n",t1);
    scanf("%d",&toss);
     ts=1 + (rand() % 2);
     printf("\nResult of toss:");
     if(ts==0)
     {
         printf("\nHeads");
     }
     else
     {
         printf("\nTails");
     }
     
     if(ts==toss)
     {
         printf("\n%s won the toss",t1);
         while(i=1)
         {     
             printf("\nEnter 1.Batting\t2.Bowling\n");
             scanf("%d",&d);
             if(d==1)
             {
                 printf("\n%s chose to Bat\n",t1);
                 break;
             }
             else if(d==2)
             {
                 printf("\n%s chose to Bowl\n",t1);
                 break;
             }
             else
             {
                 printf("\nEnter a vaild input\n");
             }
         }     
     }
     else 
     {
         printf("\n%s won the toss",t2);
             
            while(i=1)
            {
                printf("\nEnter 1.Batting\t2.Bowling");
                scanf("%d",&d);
               if(d==1)
               {
                   printf("\n%s chose to Bat \n",t2);
                   break;
               }
                 else if(d==2)
                {
                   printf("\n%s chose to Bowl\n",t2);
                   break;
                }
                 else
                {
                  printf("\ninvalid input");
                  
                }
            }
     }
}
void display()
{
    printf("\t\t\tCricket tournament\n");
    printf("\t\t\t   %s    VS    %s \n",t1,t2);
    printf("\t__________________________________________________________________\n");
    printf("  \t   slno\t\t      Team1 \t\t\t Team2\n");
    for (i = 0; i < 3; ++i)
    {
       printf("\n  \t   %d  ", i + 1);
       printf("    \t\t%s \t\t\t %s \n",s[i].name1,s[i].name2);
    }
    
    
    
    
   
}


struct sll
{
    int runs;
    struct sll *next;
};
typedef struct sll node;
node *start=NULL;
node* create()
{
    int i;
    node *new1;
    new1=(node*)malloc(sizeof(node));
    new1->next=NULL;
    return(new1);
}
void insert_r()
{
    node *new1;
    int sum=0,w=0;
    int count=0;
    float rr;
    for(j=0;j<2;j++)
    {
      printf("   OVER %d\n",j+1);
       for(i=0;i<6;i++)
       {
          new1=create();
          printf("\nEnter:\n>runs scored\n>7 for wide\n>8 for out\n");
          scanf("%d",&new1->runs);
          start=new1;
          if(new1->runs==7)
          {
             printf("   wide");
             i--;
             count++;
             new1->runs=0;
          }
          else if(new1->runs==8)
          {
            printf("   batsman out");
            w++;
            new1->runs=0;
          }
          else if(new1->runs<=6)
          {
            sum=sum+(new1->runs);
          }
          else
          {
           printf("enter valid input\n");
           i--;
          }
        }
         rr=(sum+count)/j;
        printf("  CURRENT SCORE: %d-%d\t\t run_rate=%.2f\n ",sum+count,w,rr);
    }
      sc1=sum+count;
    printf("_______________________________________________________________");
    printf(" Score : %d-%d ",sc1,w);
}

void main()
{
   
     details();
     display();
     toss();
     printf("\t\t\tINNING 1 BEGINS\n");
     printf("\t\t\t 2 over match\n");
     insert_r();
}
     