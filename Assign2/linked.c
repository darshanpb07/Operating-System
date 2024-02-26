#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int num=0,i=0,bit[30],j,flag=0,k;
    char del[10],delete_status[30];
    int ch=0,block[10];
    // he fkt check karnyaasathi print kel aahe
    for (j=0;j<30;j++)
    {
        bit[j]=1;
        delete_status[j]=-1;
        printf("%d ",bit[j]);
    }
    struct blck
    {
        int blockno;
        struct blck *next;
    };
    struct blockf
    {
        char name[10];
        int startblock;
        int nob;
        struct blck *next1;
    };
     
    struct blockf ary[10];
    struct blck *temp=NULL;
    while(1)
    {
        printf("\n *** Which Operation You Want To Perform ***");
        printf("\n 1. Create a File...");
        printf("\n 2. Delete a File...");
        printf("\n 3. Display Directory...");
        printf("\n 4. Display Bit Vector...");
        printf("\n 5. Exit...");
        printf("\n Enter Your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                     printf("\n Enter the name of the file : ");
                     scanf("%s",&ary[i].name);
                     printf("\n Enter the start block of the file : ");
                     scanf("%d",&ary[i].startblock);
                     printf("\n Enter the number of blocks needed for the file : ");
                     scanf("%d",&ary[i].nob);
                     printf("\n Enter the blocks : ");
                     block[0]=ary[i].startblock;
                     printf("\n 1 : block - %d\n",ary[i].startblock);
                     for (j=1;j<ary[i].nob;j++)
                     {
                         printf(" %d : block - ",j+1);
                         scanf("%d",&block[j]);
                         if (bit[block[j]]==0)
                         {
                            printf("\nThis Block already allocated..!!\n");
                            j--;
                            continue;
                         }
                     }
                     printf("%s %d %d ",ary[i].name,ary[i].startblock,ary[i].nob);
                     for (j=0;j<ary[i].nob;j++)
                         printf("\n block - %d",block[j]);
                         delete_status[i]=1;
                         for (j=0;j<ary[i].nob;j++)
                             bit[block[j]]=0;
                         printf("\n %s File be stored on disk..",ary[i].name);
                         printf("\n Bit Vector : ");
                         for (j=0;j<30;j++)
                             printf("%d ",bit[j]);
                         ary[i].next1=NULL;
                         if (ary[i].nob>1)
                         {
                     	 	 temp=malloc(sizeof(struct blck));
                                 temp->blockno=block[1];
                                 ary[i].next1=temp;
                                 temp->next=NULL;
                                 struct blck *t1=temp;
                                 for (j=2;j<=ary[i].nob;j++)
                       		 {
                        		 temp=malloc(sizeof(struct blck));
                            		 temp->blockno=block[j];
                                	 temp->next=NULL;
                                	 t1->next=temp;
                                	 t1=temp;
                       		 }
                                 
                                 num++;
                       		 i++;
                        } 
                        flag=0;
                        break;
         case 2 :
                   printf("\n Enter the name of the file :");
                   scanf("%s",&del[0]);
                   int found = -1;
                   for (j = 0; j < num; j++)
                       if (strcmp(del,ary[j].name) == 0) 
                       {
                          found = j;
                          break;
                        }
                   if (found==-1)
                       printf("\n File Not Found..!!"); 
                   else
                   {
                      delete_status[found]=-1;
                      //printf("\n File Found at %d..",found);
                      bit[ary[found].startblock]=1;
                      temp=ary[found].next1;
                      for (k=1;k<ary[found].nob;k++)
                      {
                            //printf("%d -->",temp->blockno);
                            bit[temp->blockno]=1;
                            temp=temp->next;
                      }
                      printf("\n %s file deleted..",&del[0]);
                   } 
                   break;
         case 3 : 
                   printf("\n File Name | Strat | NOBs | Blocks");
                   for (j=0;j<num;j++)
                   {
                       if (delete_status[j]==1)
                       {
                       printf("\n %6s    | %3d   | %3d  | ",ary[j].name,ary[j].startblock,ary[j].nob);
                       printf("%d -->",ary[j].startblock);
                       temp=ary[j].next1;
                       for (k=1;k<ary[j].nob;k++)
                       {
                            printf("%d -->",temp->blockno);
                            temp=temp->next;
                       }
                       printf("NULL"); 
                       }      
                   }
                   break;
         case 4:
                 printf("\n Bit Vector : ");
                        for (j=0;j<30;j++)
                            printf("%d ",bit[j]);
                 break;
         case 5: exit(0);
                 break;
         default:
                printf("\nPlz..Enter Valid Option..!!");
        }
    }
    return 0;
}