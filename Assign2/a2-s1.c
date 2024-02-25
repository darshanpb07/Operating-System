Q1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int start[10],length[10],num=0,i=0,bit[30],j,flag=0;
    char name[20][10],del[10],delete_status[30];
    int ch=0;
    while(1)
    {
        printf("\n Which Operation You Want To Perform ");
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
                     scanf("%s",&name[i][0]);
                     printf("\n Enter the start block of the file : ");
                     scanf("%d",&start[i]);
                     printf("\n Enter the length of the file : ");
                     scanf("%d",&length[i]);
                     
                
                for (j=start[i];j<start[i]+length[i];j++)
                { 
                    if(bit[j]==0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                    {
                        printf("\n %s File can not be stored on disk..",name[i]);
                    }
                    else
                    {
                        delete_status[i]=1;
                        for (j=start[i];j<start[i]+length[i];j++)
                         bit[j]=0;
                         printf("\n %s File be stored on disk..",name[i]);
                       /* printf("\n Bit Vector : ");
                        for (j=0;j<30;j++)
                            printf("%d ",bit[j]);*/
                        num++;
                        i++;
                    }
                flag=0;
                printf("\n # File Name  |  Strat  |  Length  ");
                for (j=0;j<30;j++)
                    if (delete_status[j]==1)
                       printf("\n %d %10s |  %5d  | %5d",j,name[j],start[j],length[j]);
                break;
            case 2:
                printf("\n Enter the name of the file :");
                scanf("%s",&del[0]);
                int found = -1;
                for (j = 0; j < num; j++)
                    if (strcmp(del,name[j]) == 0) 
                    {
                       found = j;
                       break;
                    }
                if (found==-1)
                   printf("\n File Not Found..!!");
                else
                {
                    for (j=start[found];j<start[found]+length[found];j++)
                         bit[j]=1;
                    delete_status[found]=-1;
                    printf("\n %s file deleted..",&del[0]);
                    printf("\n # File Name  |  Strat  |  Length  ");
                for (j=0;j<30;j++)
                    if (delete_status[j]==1)
                       printf("\n %d %10s |  %5d  | %5d",j,name[j],start[j],length[j]);    
                }
                break;
          case 3:
                printf("\n # File Name  |  Strat  |  Length  ");
                for (j=0;j<30;j++)
                    if (delete_status[j]==1)
                    printf("\n %d %10s |  %5d  | %5d",j,name[j],start[j],length[j]);
                break;
          case 4:
                printf("\n Bit Vector : ");
                        for (j=0;j<30;j++)
                            printf("%d ",bit[j]);
                break;
         case 5:exit(0);
         break;
         default:
                printf("\nPlz..Enter Valid Option..!!");
        }
    }
    return 0;
}
