#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int scoreboard();
int in_over();
int score_sheet();
int match_details();
int toss_stat(int opt,int won);
int wickets();

int overs = 0;
char team_1[10],team_2[10];
int option,toss;
int t_run=0,b1_run=0,b2_run=0,wicket=0,innings=0;
int main(){
        match_details();
        printf("who is batting and who won the toss? \n 1.%s\n 2.%s \n 3. TBA\n",team_1,team_2);
        scanf("%d %d",&option,&toss);
        if(toss_stat(option,toss)==0){
                return 0;
        }

        while(innings<2){
                scoreboard();
        while(overs<2){
                in_over();
        }
        overs=0;
        innings++;
        b1_run=0;
        b2_run=0;
        t_run=0;
        wicket=0;
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
                default: printf("\n yet to happen");
                         return(0);
                         break;
        }
        if(opt ==1){
                printf("\n%s is batting",team_1);
        }
        else if(opt==2){
                 printf("\n%s is batting",team_2);
        }
}
int scoreboard(){
        char bat_1[10],bat_2[10],bowl[10];
        printf("\nEnter the batmans bowler second name:\n");
        scanf("%s %s %s",bat_1,bat_2,bowl);
        printf("%s\n %s\t \t %s",bat_1,bat_2,bowl);
}

int in_over(){
        int balls = 0,run,op,extras=0;
        char wick;
        for(balls = 0;balls<(6+extras);balls++){
                printf("\nEnter run scored in this ball and y if wicket fall:\n ");
                scanf("%d %c",&run,&wick);
                printf("who scored 1 or 2 or 0(extra/wicket)");
                scanf("%d",&op);
                printf("over:%d.%d",overs,balls);
                if(wick == 'y'){
                        int w = wickets();
                if(w==0){
                        innings++;
                        break;
                }
                }
                score_sheet(run,op);
        }
        overs++;
        return(overs);
}

int score_sheet(int run,int b){
        switch(b){
                case 1: b1_run +=run;
                        break;
                case 2: b2_run +=run;
                        break;
                default: break;
        }
        t_run +=run;

        printf("total:%d/%d     batsman1:%d  batsman2:%d",t_run,wicket,b1_run,b2_run);
}

int wickets(){
        int num;
        char bat[10];
        printf("who's wicket: 1 or 2");
        scanf("%d",&num);
           printf("Enter the new batsman name");
                scanf("%s",bat);
                printf("%s\n is the new batsmen",bat);
        if(num==1){
                b1_run=0;
        }
        else{
                b2_run=0;
        }
        wicket++;
        if(wicket==2){
                return(0);
        }

     }
