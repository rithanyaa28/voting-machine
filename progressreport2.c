#include<stdio.h>
#include<string.h>
int main()
{   FILE*p;
    p=fopen("voterid1.txt","w");
    fprintf(p,"abc123\n");
    fclose(p);
    FILE*p1;
    p1=fopen("voterid2.txt","w");
    fprintf(p1,"abc456\n");
    fclose(p1);
    FILE*a;
    a=fopen("abc123.txt","w");
    fprintf(a,"name:karthika  age:18  gender:female \n");
    fclose(a);
    FILE*b;
    b=fopen("abc456.txt","w");
    fprintf(b,"name:siva  age:19  gender:male \n");
    fclose(b);
    struct vote
    {
        FILE*fpointer;
        char line[100];
        int exist;

    };
    struct vote v[2];
    char voterid[100];
    printf("ENTER YOUR VOTER ID\n");
    scanf("%s",voterid);
    v[0].exist=0;
    v[1].exist=0;
    int found[2]={0,0};
    int x=0;
    for(int i=0;i<2;i++)
    {
         char filename[100];
         sprintf(filename,"voterid%d.txt",i+1);
         v[i].fpointer=fopen(filename,"r+");
    while(fgets(v[i].line,100,v[i].fpointer))
    {
        char *ptr=strstr(v[i].line,voterid);
        if(ptr!=NULL)
        {
            v[i].exist=1;
            break;
        }
    }

    if(v[i].exist==1)
    {   char ch;
        strcat(voterid,".txt");
        FILE*f1;
        f1=fopen(voterid,"r");
        do
        {
            ch=fgetc(f1);
            printf("%c",ch);

        }
        while(ch!=EOF);
        fclose(f1);
        int n;
        printf("CAST YOUR VOTE BY ENTERING NUMBERS FROM 1 TO 4 BY SEEING THE SYMBOLIC NAMES OF THE PARTIES.ANY OTHER NUMBER WILL CAST VOTE FOR NOTA\n\n");
        printf(" 1.LOTUS\n 2.HAND\n 3.SUN\n 4.TORCHLIGHT\n");
        scanf(" %d",&n);
        switch(n)
        {
        case 1:
              {
                FILE*f11;
                char lotus[100];
                sprintf(lotus,"lotus%d.txt",i+1);
                f11=fopen(lotus,"a");
                fprintf(f11,"1\n");
                fputc('0',v[i].fpointer);
                printf("YOU HAVE VOTED FOR LOTUS\n\n");
                printf("THANKS FOR VOTING\n");
                fclose(f11);
                break;
              }
        case 2:
              {
                FILE*f12;
                char hand[100];
                sprintf(hand,"hand%d.txt",i+1);
                f12=fopen(hand,"a");
                fprintf(f12,"1\n");
                fputc('0',v[i].fpointer);
                printf("YOU HAVE VOTED FOR HAND\n\n");
                printf("THANKS FOR VOTING\n");
                fclose(f12);
                break;
               }
        case 3:
               {
                FILE*f13;
                char sun[100];
                sprintf(sun,"sun%d.txt",i+1);
                f13=fopen(sun,"a");
                fprintf(f13,"1\n");
                fputc('0',v[i].fpointer);
                printf("YOU HAVE VOTED FOR SUN\n\n");
                printf("THANKS FOR VOTING\n");
                fclose(f13);
                break;
               }
        case 4:
               {
                FILE*f14;
                char torch[100];
                sprintf(torch,"torch%d.txt",i+1);
                f14=fopen(torch,"a");
                fprintf(f14,"1\n");
                fputc('0',v[i].fpointer);
                printf("YOU HAVE VOTED FOR TORCHLIGHT\n\n");
                printf("THANKS FOR VOTING\n");
                fclose(f14);
                break;
               }
            default:
               {
                FILE*f15;
                char nota[100];
                sprintf(nota,"nota%d.txt",i+1);
                f15=fopen(nota,"a");
                fprintf(f15,"1\n");
                fputc('0',v[i].fpointer);
                printf("YOU HAVE VOTED FOR NOTA\n\n");
                printf("THANKS FOR VOTING\n");
                fclose(f15);
                break;
               }
        }
        found[i]=1;
        x=i+1;
    }
    }
    int zero=0;
    for(int j=0;j<2;j++)
    {
        if(found[j]!=0)
        {
            zero=1;
            break;
        }
    }
    if(zero==0)
        printf("YOUR VOTER ID NOT FOUND\n OR YOU HAVE ALREADY VOTED\n");




    return 0;
}