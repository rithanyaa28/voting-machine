#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
  int i,a,lotus,hand,sun,torchlight,nota;
  float p,t,plotus,phand,psun,ptorchlight,pnota;
  lotus=5;
  hand=4;
  sun=1;
  torchlight=1;
  nota=3;





    t=lotus+hand+sun+torchlight+nota;
    printf("Total vote polled is :%f\n",t);
    p=(t/15)*100;
    printf("percentage of vote polled is: %f\n",p);

    SYSTEMTIME stime;
    GetSystemTime(&stime);
    printf("today date is:%d/%d/%d\n",stime.wDay,stime.wMonth,stime.wYear);
    if (stime.wDay>=4&&stime.wMonth>=06&&stime.wYear>=2021)

   {

    plotus=(lotus/t)*100;
    phand=(hand/t)*100;
    psun=(sun/t)*100;
    ptorchlight=(torchlight/t)*100;
    pnota=(nota/t)*100;

  struct can
    {
        int vote;
        char name[30];
        char party[20];
        float per;
    };
    struct can cans[5];
    strcpy(cans[0].name,"Reka Thakure");
    strcpy(cans[0].party,"BJP");
    cans[0].vote=lotus;
    cans[0].per=plotus;


    strcpy(cans[1].name,"Anooj Dejah");
    strcpy(cans[1].party,"INC");
    cans[1].vote=hand;
    cans[1].per=phand;


    strcpy(cans[2].name,"Sorojini Supramanium");
    strcpy(cans[2].party,"DMK");
    cans[2].vote=sun;
    cans[2].per=psun;


    strcpy(cans[3].name,"Suhana Bose");
    strcpy(cans[3].party,"AAP");
    cans[3].vote=torchlight;
    cans[3].per=ptorchlight;


    strcpy(cans[4].name,"NOTA");
    strcpy(cans[4].party,"X");
    cans[4].vote=nota;
    cans[4].per=pnota;


    int k;
    float  j ;
    char candi[20];
    char candy[20];
    for(int b=0;b<5;b++)
    {

        for(int c=b+1;c<5;c++)
        {
            if (cans[c].vote >cans[b].vote)

              {

                k=cans[b].vote;
                cans[b].vote=cans[c].vote;
                cans[c].vote=k;
                j=cans[b].per;
                cans[b].per=cans[c].per;
                cans[c].per=j;
                strcpy(candi,cans[b].name);
                strcpy(cans[b].name,cans[c].name);
                strcpy(cans[c].name,candi);
                strcpy(candy,cans[b].party);
                strcpy(cans[b].party,cans[c].party);
                strcpy(cans[c].party,candy);

            }
        }
    }
        for(int q=0;q<5;q++)
        {
            printf("%s " ,cans[q].name);
            printf("%s\n",cans[q].party);
            printf("vote gained:");
            printf("%d\n",cans[q].vote);
            printf("percentage of vote:");
            printf("%f\n",cans[q].per);

        }
    if(cans[0].vote>cans[1].vote)
    {
        if(strcmp(cans[0].name,"NOTA")==0)
        {
            if(cans[1].vote>cans[2].vote)
            {
                printf("winner is %s %s\n",cans[1].name, cans[1].party);
            }
            else
            {
                printf("relection with fresh candidates will be conducted");
            }
        }
        else
        {
            printf("winner is %s %s\n",cans[0].name,cans[0].party);
        }

    }
    else if((cans[0].vote==cans[1].vote)&&(cans[1].vote>cans[2].vote))
    {
        if((strcmp(cans[0].name,"NOTA")==0))
        {
            printf("winner is %s %s\n",cans[1].name,cans[1].party);
        }
        if ((strcmp(cans[1].name,"NOTA"))==0)
        {
            printf("winner is %s %s\n",cans[0].name,cans[0].party);
        }
        else
        {
            printf("Relection will be conducted");
        }
    }
    else
    {
        printf("Relection will be conducted");
    }

   }
   else
   {
       printf("Result will be announced on 08/06/2021");
   }




 return 0;


 }
