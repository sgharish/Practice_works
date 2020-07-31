#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int scoreboard();
int in_over();
int score_sheet(int run,char wick);
int match_details();
int toss_stat(int opt,int won);
int wickets();
int match_format();
int target();
int rotation();
int bowling();

int formate,max_over,max_wicket,max_inning;
int overs = 0;
char team_1[10],team_2[10],bat_1[10],bat_2[10],bowl[10],wick;
int option,toss;
int t_run=0,b1_run=0,b2_run=0,balls=0,wicket=0,innings=0,tar_run=0,striker =1;

int main(){
        match_format();
        match_details();
        printf("who is batting and who won the toss? \n 1.%s\n 2.%s \n 3. TBA\n",team_1,team_2);
        scanf("%d %d",&option,&toss);
        if(toss_stat(option,toss)==0){
                return 0;
        }

        scoreboard();
        while(overs<max_over){
                in_over();
                bowling();
        }
        overs=0;
        b1_run=0;
        b2_run=0;
        tar_run = t_run+1;
        t_run=0;
        wicket=0;
        innings++;
        if(innings == 1){
                scoreboard();
        while(overs<2){
                in_over();
                bowling();
        }
        target();
        }
}

int match_format(){
        int op;
        printf("Format of the match\n 1. ODI \n 2.T20\n 3.MANUAL ENTRY");
        scanf("%d",&op);
        switch(op){
                case 1: max_inning = 2;
                       max_over= 50;
                        max_wicket = 10;
                        break;
                         case 2:max_inning = 2;
                        max_over= 20;
                        max_wicket = 10;
                        break;
                default:printf("ENTER THE No. Of INNING:\n");
                        scanf("%d",&max_inning);
                        printf("ENTER THE no of overs:\n");
                        scanf("%d",&max_over);
                        printf("MAX wickets\n");
                        scanf("%d",&max_wicket);
                        break;
        }
}

int match_details(){
        printf("enter the team names:\n");
        scanf("%s %s",team_1,team_2);
        printf("-----TODAYS MATCH------\n%s \t %s\n",team_1,team_2);
}

int toss_stat(int opt,int won){
        switch(won){
                case 1: printf("Toss won by %s\n",team_1);
                        break;
                case 2: printf("Toss won by %s\n",team_2);
                        break;
                default: printf(" yet to happen\n");
                         return(0);
                         break;
        }
        if(opt ==1){
                printf("%s is batting\n",team_1);
        }
        else if(opt==2){
                 printf("%s is batting\n",team_2);
        }
}


int scoreboard(){
        printf("Enter the batmans second name:\n");
        scanf("%s %s",bat_1,bat_2);
        printf("%s* %s\n",bat_1,bat_2);
        bowling();
}

int in_over(){
        int run,op,extras =0;
        char extra;
        for(balls = 0;balls<(6+extras);balls++){
                printf("Enter run scored in this ball and 'w' if wicket fall or an extra 'e'or 'b' for both:\n ");
                scanf("%d %c",&run,&wick);
                score_sheet(run,wick);
                switch(wick){
                        case 'w':wickets();
                                break;

                        case 'e': extras++;
                                 break;

                        case 'b':wickets();
                                extras++;
                                break;
                }
                if(innings!=0 && wicket<max_wicket){
                        target();
        }
        }
        overs++;
        rotation();
        return(overs);
}

int score_sheet(int run,char wick){
        int oore;
        if(run%2!=0&&striker==1&&wick !='e'){
                b1_run+=run;
                striker=2;
                printf("%s:%d \n %s:%d*\n",bat_1,b1_run,bat_2,b2_run);
        }
        else if(run%2==0&&striker==1&&wick !='e') {
                b1_run+=run;
                striker=1;
                printf("%s:%d*\n%s:%d\n",bat_1,b1_run,bat_2,b2_run);
        }
        else if(run%2!=0&&striker!=1&&wick !='e') {
                b2_run+=run;
                striker=1;
                printf("%s:%d\n%s:%d*\n",bat_1,b1_run,bat_2,b2_run);
        }
        else if(wick!='e'){
                b2_run+=run;
                striker=2;
                printf("%s:%d  \n%s:%d*\n",bat_1,b1_run,bat_2,b2_run);
        }
        t_run +=run;
        printf("total:%d/%d in overs:%d.%d\n",t_run,wicket,overs,balls);
        return(t_run);
}

int bowling(){
        printf("Enter the bowlers detail");
        scanf("%s",bowl);
        printf("%s\n is bowling the %d over",bowl,overs);
}

int wickets(){
        int num;
        char bat[10];
        wicket++;
        printf("who's wicket: 1 or 2");
        scanf("%d",&num);
        if(wicket<max_wicket){
                printf("Enter the new batsman name\n");
        if(num==1){
                scanf("%s",bat_1);
                printf("%sis the new batsmen\n",bat_1);
                striker =1;
                b1_run=0;
        }
        else{
                scanf("%s",bat_2);
 printf("%sis the new batsmen\n",bat_2);
                b2_run=0;
                striker = 2;
        }
        }
        else{
                overs = max_over;
                balls = 6;
                printf("End of the innings\n total = %d",t_run);
                return(0);
        }
}

int rotation(){
        if(striker!=1){
                striker =1;
        }
        else{
                striker = 2;
        }
}

int target(){
        int targetr=tar_run - t_run;
        printf("%d is the target\n",targetr);
        if(targetr<=0){
                printf("batting team won the match\n");
                overs = 2;
                balls =6;
        }
        else if (overs>=max_over&&targetr>0){
                printf("bowling team won the match\n");
                return 0;
        }
}


