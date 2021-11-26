#include "iGraphics.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

int opn=0,cover=0; //'cover' covers 'v' from increment .... 'v' is the vanished cards counter

int vanish_ara[2][25]= {0};

int window=0, contin=0, vanish=0, window2check=0, opn2check=0;

int temp,t,i,j,k=0,v=0;

int easy[4][4][2], hard[5][5][2];

int flip[3];

int hold_x,hold_y;

int used[4][4]= {0};

int hard_used[5][5]= {0};


char chicken[2][40]={{"music_off.bmp"},{"music_on.bmp"}};

char e_button[2][40]={{"easy.bmp"},{"on_easy.bmp"}}; //dif-4

char h_button[2][40]={{"hard.bmp"},{"on_hard.bmp"}}; //5-dif


char hrd[25][40]= {{"h1.bmp"},{"h2.bmp"},{"h3.bmp"},{"h4.bmp"},{"h5.bmp"},{"h6.bmp"},{"h7.bmp"},{"h8.bmp"},{"h9.bmp"},{"2.bmp"},{"4.bmp"},{"3.bmp"},{"h1.bmp"},{"h2.bmp"},{"h3.bmp"},{"h4.bmp"},{"h5.bmp"},{"h6.bmp"},{"h7.bmp"},{"h8.bmp"},{"h9.bmp"},{"2.bmp"},{"4.bmp"},{"3.bmp"},{"h10.bmp"}};

char es[16][40]= {{"1.bmp"},{"2.bmp"},{"3.bmp"},{"4.bmp"},{"5.bmp"},{"6.bmp"},{"8.bmp"},{"9.bmp"},{"1.bmp"},{"2.bmp"},{"3.bmp"},{"4.bmp"},{"5.bmp"},{"6.bmp"},{"8.bmp"},{"9.bmp"}};


char poof[6][30]= {{"poof1.bmp"},{"poof2.bmp"},{"poof3.bmp"},{"poof4.bmp"},{"poof5.bmp"},{"poof6.bmp"}};

char bonus_animate[20][30]= {{"h10.bmp"},{"h10.bmp"},{"h10.1.bmp"},{"h10.2.bmp"},{"h10.3.bmp"},{"h10.4.bmp"},{"Cover5.bmp"},{"clockeye4.bmp"},{"clockeye3.bmp"},{"clockeye2.bmp"},{"clockeye1.bmp"},{"clockeye.bmp"},{"clockeye.bmp"},{"clockeye.bmp"},{"poof1.bmp"},{"poof2.bmp"},{"poof3.bmp"},{"poof4.bmp"},{"poof5.bmp"},{"poof6.bmp"}};


char animated_cards[16][12][40]=
{
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"1.4.bmp"},{"1.3.bmp"},{"1.2.bmp"},{"1.1.bmp"},{"1.bmp"},{"1.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"2.4.bmp"},{"2.3.bmp"},{"2.2.bmp"},{"2.1.bmp"},{"2.bmp"},{"2.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"3.4.bmp"},{"3.3.bmp"},{"3.2.bmp"},{"3.1.bmp"},{"3.bmp"},{"3.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"4.4.bmp"},{"4.3.bmp"},{"4.2.bmp"},{"4.1.bmp"},{"4.bmp"},{"4.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"5.4.bmp"},{"5.3.bmp"},{"5.2.bmp"},{"5.1.bmp"},{"5.bmp"},{"5.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"6.4.bmp"},{"6.3.bmp"},{"6.2.bmp"},{"6.1.bmp"},{"6.bmp"},{"6.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"8.4.bmp"},{"8.3.bmp"},{"8.2.bmp"},{"8.1.bmp"},{"8.bmp"},{"8.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"9.4.bmp"},{"9.3.bmp"},{"9.2.bmp"},{"9.1.bmp"},{"9.bmp"},{"9.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"1.4.bmp"},{"1.3.bmp"},{"1.2.bmp"},{"1.1.bmp"},{"1.bmp"},{"1.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"2.4.bmp"},{"2.3.bmp"},{"2.2.bmp"},{"2.1.bmp"},{"2.bmp"},{"2.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"3.4.bmp"},{"3.3.bmp"},{"3.2.bmp"},{"3.1.bmp"},{"3.bmp"},{"3.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"4.4.bmp"},{"4.3.bmp"},{"4.2.bmp"},{"4.1.bmp"},{"4.bmp"},{"4.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"5.4.bmp"},{"5.3.bmp"},{"5.2.bmp"},{"5.1.bmp"},{"5.bmp"},{"5.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"6.4.bmp"},{"6.3.bmp"},{"6.2.bmp"},{"6.1.bmp"},{"6.bmp"},{"6.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"8.4.bmp"},{"8.3.bmp"},{"8.2.bmp"},{"8.1.bmp"},{"8.bmp"},{"8.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"9.4.bmp"},{"9.3.bmp"},{"9.2.bmp"},{"9.1.bmp"},{"9.bmp"},{"9.bmp"}}
};

char animated_hard_cards[25][12][40]=
{
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h1.4.bmp"},{"h1.3.bmp"},{"h1.2.bmp"},{"h1.1.bmp"},{"h1.bmp"},{"h1.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h2.4.bmp"},{"h2.3.bmp"},{"h2.2.bmp"},{"h2.1.bmp"},{"h2.bmp"},{"h2.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h3.4.bmp"},{"h3.3.bmp"},{"h3.2.bmp"},{"h3.1.bmp"},{"h3.bmp"},{"h3.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h4.4.bmp"},{"h4.3.bmp"},{"h4.2.bmp"},{"h4.1.bmp"},{"h4.bmp"},{"h4.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h5.4.bmp"},{"h5.3.bmp"},{"h5.2.bmp"},{"h5.1.bmp"},{"h5.bmp"},{"h5.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h6.4.bmp"},{"h6.3.bmp"},{"h6.2.bmp"},{"h6.1.bmp"},{"h6.bmp"},{"h6.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h7.4.bmp"},{"h7.3.bmp"},{"h7.2.bmp"},{"h7.1.bmp"},{"h7.bmp"},{"h7.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h8.4.bmp"},{"h8.3.bmp"},{"h8.2.bmp"},{"h8.1.bmp"},{"h8.bmp"},{"h8.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h9.4.bmp"},{"h9.3.bmp"},{"h9.2.bmp"},{"h9.1.bmp"},{"h9.bmp"},{"h9.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"2.4.bmp"},{"2.3.bmp"},{"2.2.bmp"},{"2.1.bmp"},{"2.bmp"},{"2.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"4.4.bmp"},{"4.3.bmp"},{"4.2.bmp"},{"4.1.bmp"},{"4.bmp"},{"4.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"3.4.bmp"},{"3.3.bmp"},{"3.2.bmp"},{"3.1.bmp"},{"3.bmp"},{"3.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h1.4.bmp"},{"h1.3.bmp"},{"h1.2.bmp"},{"h1.1.bmp"},{"h1.bmp"},{"h1.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h2.4.bmp"},{"h2.3.bmp"},{"h2.2.bmp"},{"h2.1.bmp"},{"h2.bmp"},{"h2.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h3.4.bmp"},{"h3.3.bmp"},{"h3.2.bmp"},{"h3.1.bmp"},{"h3.bmp"},{"h3.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h4.4.bmp"},{"h4.3.bmp"},{"h4.2.bmp"},{"h4.1.bmp"},{"h4.bmp"},{"h4.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h5.4.bmp"},{"h5.3.bmp"},{"h5.2.bmp"},{"h5.1.bmp"},{"h5.bmp"},{"h5.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h6.4.bmp"},{"h6.3.bmp"},{"h6.2.bmp"},{"h6.1.bmp"},{"h6.bmp"},{"h6.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h7.4.bmp"},{"h7.3.bmp"},{"h7.2.bmp"},{"h7.1.bmp"},{"h7.bmp"},{"h7.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h8.4.bmp"},{"h8.3.bmp"},{"h8.2.bmp"},{"h8.1.bmp"},{"h8.bmp"},{"h8.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h9.4.bmp"},{"h9.3.bmp"},{"h9.2.bmp"},{"h9.1.bmp"},{"h9.bmp"},{"h9.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"2.4.bmp"},{"2.3.bmp"},{"2.2.bmp"},{"2.1.bmp"},{"2.bmp"},{"2.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"4.4.bmp"},{"4.3.bmp"},{"4.2.bmp"},{"4.1.bmp"},{"4.bmp"},{"4.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"3.4.bmp"},{"3.3.bmp"},{"3.2.bmp"},{"3.1.bmp"},{"3.bmp"},{"3.bmp"}},
    {{"Cover.bmp"},{"Cover1.bmp"},{"Cover2.bmp"},{"Cover3.bmp"},{"Cover4.bmp"},{"Cover5.bmp"},{"h10.4.bmp"},{"h10.3.bmp"},{"h10.2.bmp"},{"h10.1.bmp"},{"h10.bmp"},{"h10.bmp"}}
};


int dif=4; //4 means easy difficulty and 5 means hard

int win=0, lose=0, bonus=0;

int indx=0, inc=0;

int indx2=11, dec=0;

int indx3=0, inc2=0;

int indx4=0, inc3=0;

int music=1;


int back_x = 630, back_y = 5, back_len = 66, back_wid = 66;

int n_gm_x = 155, n_gm_y = 270, n_gm_len = 410, n_gm_wid = 120;

int optn_x = 26, optn_y = 17, optn_len = 81, optn_wid = 81;

int ext_x = 602, ext_y =15, ext_len= 80, ext_wid = 80;

int score=0, score_helper=500, hard_score_helper=1000, score_holder;


char scored[33];

int time_x=145, hard_time_x=120, hard_time_len=500, time_y=600, time_len=420, time_wid=30, hard_len=500, len=420, dl=0, cover2=0; //'cover2' covers 'score_holder' from decrement

char player_name[11], player_named[11];

int name_indx=0, player_num=0;

int txt_x=272, txt_y= 125, txt_len=150, txt_wid=35;

int highscores=0, highscore_x=200, highscore_y;

int credit=0, how=0;


FILE *fp;



typedef struct
{
    char name[20];
    int ix;
    int iy;
} image;

image cards[16];

image hard_cards[25];


typedef struct
{
    char name[20];
    int score;
} scores;

scores players[5];



void animate()
{
    indx=indx+inc; //to animate after click .... inc=1 is set in mouse-click

    //if(indx==10) Sleep(50);

    if(indx==11) inc=0;
}

void animate2()
{
    indx2=indx2-dec;

    if(indx2==10)
    {
        Sleep(100);
    }

    if(indx2==0) dec=0;
}

void poofing()
{
    indx3=indx3+inc2;

    if(indx3==5) inc2=0;
}

void clockeye()
{
    indx4=indx4+inc3;

    //if(indx4==12) Sleep(300);

    if(indx4==19) inc3=0;
}

void timedown()
{
    if(dif==4) len=len-dl;
    else hard_len=hard_len-dl;

    if(len==0 || hard_len==0) lose=1;
}



void backbutton()
{
    iShowBMP(back_x, back_y, "home.bmp");
}

void textbox()
{
    iSetColor(255,255,255);
    iRectangle(txt_x, txt_y, txt_len, txt_wid);
}



void iDraw()
{
    if(lose==1) //time up
    {
        iClear();

        window=100;

        iShowBMP(0,0, "LOSE.bmp");

		if(cover2==0)
        {
			if(music==1) PlaySound("lose.wav", NULL, SND_ASYNC);

            cover2=1; //so that this block can't be accessed again		
        }
    }

	else if(credit==1)
	{
		iClear();

		iShowBMP(0,0, "credit.bmp");
	}

	else if(how==1)
	{
		iClear();

		iShowBMP(0,0, "how.bmp");
	}

    else if(highscores==1)
    {
        iClear();

        window=100;

        win=0;

        iShowBMP(0,0, "highscores.bmp");

        iSetColor(255,255,255);

        for(i=0,highscore_x=250,highscore_y=300; i<player_num; i++,highscore_y-=30)
        {
            iText(highscore_x, highscore_y, players[i].name, GLUT_BITMAP_TIMES_ROMAN_24);
        }

        for(i=0,highscore_x=400,highscore_y=300; i<player_num; i++,highscore_y-=30)
        {
            itoa(players[i].score, scored, 10);
            iText(highscore_x, highscore_y, scored, GLUT_BITMAP_TIMES_ROMAN_24);
        }

        //backbutton();
    }

    else if(win==1)  //game over
    {
        iClear();

        window=100;    //to restrict from entering the blocks below

        iShowBMP(0,0, "WON.bmp");

        dl=0;

        if(cover2==0)
        {
            if(dif==4) score_holder=score_helper-(score*5)+len;
            else score_holder=hard_score_helper-(score*5)+hard_len;

			if(music==1) PlaySound("win.wav", NULL, SND_LOOP | SND_ASYNC);

            cover2=1; //so that this block can't be accessed again		
        }

        itoa(score_holder, scored, 10);

        iText(257, 260, "Your score is : ", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(402, 260, scored, GLUT_BITMAP_TIMES_ROMAN_24);

        //printf("%s\n",player_name);

        textbox();
        iText(txt_x+5, txt_y+10, player_name, GLUT_BITMAP_TIMES_ROMAN_24);

        //backbutton();
    }

    else if(window==0)  //Menu
    {
        iShowBMP(0,0, "main_menu.bmp");
    }

    else if(window==1) //Game window
    {
        iClear();

        if(dif==4)
        {
            iShowBMP(0,0, "easy_back.bmp");

            iSetColor(47,51,225);
            iFilledRectangle(time_x, time_y, len, time_wid);   //time bar
            iSetColor(0,0,0);
            iRectangle(time_x, time_y, time_len, time_wid);

            iShowBMP(70, 585, "clock.bmp");
        }
        else
        {
            iShowBMP(0,0, "hard_back.bmp");

            iSetColor(47,51,225);
            iFilledRectangle(hard_time_x, time_y, hard_len, time_wid);   //time bar
            iSetColor(0,0,0);
            iRectangle(hard_time_x, time_y, hard_time_len, time_wid);

            iShowBMP(45, 580, "clock.bmp");
        }

        for(i=0; i<dif; i++)
        {
            for(j=0; j<dif; j++)
            {
                if(vanish==1)
                {
                    for(t=0; t<v; t++)
                    {
                        if(dif==4 && easy[i][j][0]==vanish_ara[0][t] && easy[i][j][1]==vanish_ara[1][t])
                        {
                            contin=1;
                            break;
                        }
                        else if(dif==5 && hard[i][j][0]==vanish_ara[0][t] && hard[i][j][1]==vanish_ara[1][t])
                        {
                            contin=1;
                            break;
                        }
                    }
                }

                if(contin==1)
                {
                    contin=0;
                    continue;
                }

                if(dif==4) iShowBMP(easy[i][j][0], easy[i][j][1], "Cover.bmp");
                else iShowBMP(hard[i][j][0], hard[i][j][1], "Cover.bmp");
            }
        }


        if(opn==1)
        {
            if(dif==4)  iShowBMP(cards[flip[0]].ix, cards[flip[0]].iy, animated_cards[flip[0]][indx] );
            else
            {
                if(opn2check==1) //this came from opn2 bcz the bonus card vanished and this one remained for pair check
                {
                    iShowBMP(hard_cards[flip[0]].ix, hard_cards[flip[0]].iy, hard_cards[flip[0]].name );
                }
                else iShowBMP(hard_cards[flip[0]].ix, hard_cards[flip[0]].iy, animated_hard_cards[flip[0]][indx] );

                if(indx==11 && flip[0]==24)
                {
                    if(indx3!=5) inc2=1;

                    iShowBMP(hard_cards[flip[0]].ix, hard_cards[flip[0]].iy, poof[indx3] );

                    if(v!=25 && cover==0)
                    {
                        vanish=1;
                        vanish_ara[0][v]= hard_cards[flip[0]].ix;
                        vanish_ara[1][v]= hard_cards[flip[0]].iy;
                        v++;

                        if((hard_len+100)<=hard_time_len) hard_len=hard_len+100;
                        else hard_len=hard_time_len;
                    }

                    cover=1;

                    bonus=1;

                    if(indx3==5 && v==25) win=1; //if the last card is the bonus card

                    if(indx3==5) opn=0;
                }
            }
        }

        else if(opn==2)
        {
            if(dif==4)
            {
                iShowBMP(cards[flip[0]].ix, cards[flip[0]].iy, cards[flip[0]].name );
                iShowBMP(cards[flip[1]].ix, cards[flip[1]].iy, animated_cards[flip[1]][indx] );
            }
            else if(dif==5)
            {
                iShowBMP(hard_cards[flip[0]].ix, hard_cards[flip[0]].iy, hard_cards[flip[0]].name );
                iShowBMP(hard_cards[flip[1]].ix, hard_cards[flip[1]].iy, animated_hard_cards[flip[1]][indx] );

                if(indx==11 && flip[0]==24) //if opn=2 happens before poofing the bonus card
                {
                    if(indx3!=5) inc2=1;

                    iShowBMP(hard_cards[flip[0]].ix, hard_cards[flip[0]].iy, poof[indx3] );

                    if(v!=25 && cover==0)
                    {
                        vanish=1;
                        vanish_ara[0][v]= hard_cards[flip[0]].ix;
                        vanish_ara[1][v]= hard_cards[flip[0]].iy;
                        v++;

                        if((hard_len+100)<=hard_time_len) hard_len=hard_len+100;
                        else hard_len=hard_time_len;
                    }

                    cover=1;

                    bonus=1;

                    //if(indx3==5 && v==25) win=1; //if the last card is the bonus card

                    if(indx3==5)
                    {
                        opn=1;
                        opn2check=1;

                        flip[0]=flip[1];
                        flip[1]=-1;
                        k--;
                    }
                }

                if(indx==11 && flip[1]==24)
                {
                    //if(indx4!=19) inc3=1;

                    //iShowBMP(hard_cards[flip[1]].ix, hard_cards[flip[1]].iy, bonus_animate[indx4] );

                    if(indx3!=5) inc2=1;

                    iShowBMP(hard_cards[flip[1]].ix, hard_cards[flip[1]].iy, poof[indx3] );

                    if(v!=25 && cover==0)
                    {
                        vanish=1;
                        vanish_ara[0][v]= hard_cards[flip[1]].ix;
                        vanish_ara[1][v]= hard_cards[flip[1]].iy;
                        v++;
                        k--;

                        if((hard_len+100)<=hard_time_len) hard_len=hard_len+100;
                        else hard_len=hard_time_len;
                    }

                    cover=1;

                    bonus=1; //keeping out from entering the block below

                    if(indx3==5) opn=1;
                }
            }

            if(indx==11 && bonus==0) //indx=11 means the animation has completed
            {
                if(dif==4)
                {
                    if(strcmp(cards[flip[0]].name,cards[flip[1]].name)==0)
                    {
                        vanish=1;

                        if(v!=16 && cover==0)
                        {
                            vanish_ara[0][v]= cards[flip[0]].ix;
                            vanish_ara[1][v]= cards[flip[0]].iy;
                            v++;
                            vanish_ara[0][v]= cards[flip[1]].ix;
                            vanish_ara[1][v]= cards[flip[1]].iy;
                            v++;
                        }

                        cover=1;

                        if(indx3!=5) inc2=1;

                        iShowBMP(cards[flip[0]].ix, cards[flip[0]].iy, poof[indx3] );

                        iShowBMP(cards[flip[1]].ix, cards[flip[1]].iy, poof[indx3] );

                        if(indx3==5 && v==16) win=1;

                    }
                    else
                    {
                        if(indx2!=0) dec=1;

                        iShowBMP(cards[flip[1]].ix, cards[flip[1]].iy, animated_cards[flip[1]][indx2] );
                        iShowBMP(cards[flip[0]].ix, cards[flip[0]].iy, animated_cards[flip[0]][indx2] );
                    }
                }
                else
                {
                    if(strcmp(hard_cards[flip[0]].name,hard_cards[flip[1]].name)==0)
                    {
                        vanish=1;

                        if(v!=25 && cover==0)
                        {
                            vanish_ara[0][v]= hard_cards[flip[0]].ix;
                            vanish_ara[1][v]= hard_cards[flip[0]].iy;
                            v++;
                            vanish_ara[0][v]= hard_cards[flip[1]].ix;
                            vanish_ara[1][v]= hard_cards[flip[1]].iy;
                            v++;
                        }

                        cover=1;

                        if(indx3!=5) inc2=1;

                        iShowBMP(hard_cards[flip[0]].ix, hard_cards[flip[0]].iy, poof[indx3] );

                        iShowBMP(hard_cards[flip[1]].ix, hard_cards[flip[1]].iy, poof[indx3] );

                        if(indx3==5 && v==25) win=1;

                    }
                    else
                    {
                        if(indx2!=0) dec=1;

                        iShowBMP(hard_cards[flip[1]].ix, hard_cards[flip[1]].iy, animated_hard_cards[flip[1]][indx2] );
                        iShowBMP(hard_cards[flip[0]].ix, hard_cards[flip[0]].iy, animated_hard_cards[flip[0]][indx2] );
                    }
                }
            }
        }

        backbutton();
    }

    else if(window==2) //option window
    {
        iClear();

        iShowBMP(0,0, "options.bmp");

        iShowBMP(285,485, chicken[music]);

        iShowBMP(200,340, e_button[5-dif]);

        iShowBMP(350,340, h_button[dif-4]);

        backbutton();
    }
}

void iMouseMove(int mx, int my)
{
    //place your codes here
}

void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if(window==0)
        {
            if(mx >= n_gm_x && mx <= (n_gm_x+n_gm_len) && my >= n_gm_y && my <= (n_gm_y+n_gm_wid))
            {
                window = 1;
                dl=1;
				
				//PlaySound(0,0,0);
				if(music==1) PlaySound("start.wav", NULL, SND_LOOP | SND_ASYNC);

                if(dif==4) //these blocks are for randomly generating co-ords
                {
                    for(i=0; i<16; i++)
                    {
                        while(1)
                        {
                            hold_x=rand()%4;
                            hold_y=rand()%4;

                            if(used[hold_x][hold_y]==0) break;
                        }

                        cards[i].ix=easy[hold_x][hold_y][0];
                        cards[i].iy=easy[hold_x][hold_y][1];

                        used[hold_x][hold_y]=1;
                    }
                }
                else
                {
                    for(i=0; i<25; i++)
                    {
                        while(1)
                        {
                            hold_x=rand()%5;
                            hold_y=rand()%5;

                            if(hard_used[hold_x][hold_y]==0) break;
                        }

                        hard_cards[i].ix=hard[hold_x][hold_y][0];
                        hard_cards[i].iy=hard[hold_x][hold_y][1];

                        hard_used[hold_x][hold_y]=1;
                    }
                }
                //printf("bonus card %d %d\n",hard_cards[24].ix,hard_cards[24].iy);
				//printf("same card %d %d\n",hard_cards[0].ix,hard_cards[0].iy);
				//printf("same card %d %d\n",hard_cards[12].ix,hard_cards[12].iy);
			}

            if(mx >= optn_x && mx <= (optn_x+optn_len) && my >= optn_y && my <= (optn_y+optn_wid))
            {
                window = 2;
            }

            if(mx >= ext_x && mx <= (ext_x+ext_len) && my >= ext_y && my <= (ext_y+ext_wid))
            {
                exit(0);
            }

        }

        else if(mx >=back_x && mx <= (back_x+back_len) && my >= back_y && my <= (back_y+back_wid))
        {
            if(window==1 || lose==1 || (highscores==1 && window2check==0) || win==1)
            {
                lose=0;
                highscores=0;
                window = 0;
                dl=0;
                opn=0;                          //functional back button
                vanish=0;
                v=0;
                cover=0;
                cover2=0;
                k=0;
                win=0;
                bonus=0;
                score=0;
                len=time_len;
                hard_len=hard_time_len;
				if(music==1) PlaySound("daylight.wav", NULL, SND_LOOP | SND_ASYNC);
                //name_indx=0;
                //player_name[0]='\0';

                for(i=0; i<2; i++)
                {
                    for(j=0; j<25; j++)
                    {
                        vanish_ara[i][j] = 0;
                    }
                }

                for(i=0; i<4; i++)
                {
                    for(j=0; j<4; j++)
                    {
                        used[i][j]=0;
                    }
                }

                for(i=0; i<5; i++)
                {
                    for(j=0; j<5; j++)
                    {
                        hard_used[i][j]=0;
                    }
                }
            }

            else if(window==2) 
			{	
				window=0;
			}

            else if(highscores==1 && window2check==1)
            {
                highscores=0;
                window=2;
				window2check=0;
            }

			else if(credit==1)
			{
				credit=0;
				window=2;
			}

			else if(how==1)
			{
				how=0;
				window=2;
			}
        }

        else if(window==1)
        {
            score++;

            if(opn==2 || opn==0)
            {
                opn=0;
                k=0;
                cover=0;

                flip[0]=-1;
            }

            for(i=0; i<v; i++)
            {
                if(mx >= vanish_ara[0][i] && mx <= (vanish_ara[0][i]+92) && my >= vanish_ara[1][i] && my <= (vanish_ara[1][i]+92)) break;
            }

            if(i==v)
            {
                if(dif==4)
                {
                    for(i=0; i<16; i++)
                    {
                        if(mx >= cards[i].ix && mx <= (cards[i].ix+92) && my >= cards[i].iy && my <= (cards[i].iy+92) && i!=flip[0]) //The arrray flip will be searched to detect flipped cards
                        {
                            flip[k]=i;
                            opn++;
                            k++;

                            inc=1;
                            indx=0;
                            indx2=11;
                            indx3=0;
							//cover=0;
                        }
                    }
                }

                else
                {
                    for(i=0; i<25; i++)
                    {
                        if(mx >= hard_cards[i].ix && mx <= (hard_cards[i].ix+92) && my >= hard_cards[i].iy && my <= (hard_cards[i].iy+92) && i!=flip[0]) //The arrray flip will be searched to detect flipped cards
                        {
                            flip[k]=i;
                            opn++;
                            k++;

                            inc=1;
                            indx=0;
                            indx2=11;
                            indx3=0;
                            indx4=0;
                            bonus=0;
                            opn2check=0;
							cover=0;
                        }
                    }
                }
            }
        }

        else if(window==2)
        {
            if(mx >=305 && mx<=305+60 && my>=505 && my<=505+60)
			{
				music=(music==1)?0:1;

				if(music==1) PlaySound("daylight.wav", NULL, SND_LOOP | SND_ASYNC);
				else PlaySound(0,0,0);
			}

            else if(mx >=200 && mx<=200+130 && my>=340 && my<=340+40) dif=4;
		
            else if(mx >=350 && mx<=350+130 && my>=340 && my<=340+40) dif=5;

            else if(mx >=200 && mx<=200+300 && my>=125 && my<=125+55)
            {
                highscores=1;
                window2check=1; //means that you've entered high scores through window 2
				window=100;
			}

			else if(mx >=250 && mx<=250+180 && my>=15 && my<=15+55) 
			{
				credit=1;
				window=100;
			}

			else if(mx >=200 && mx<=200+300 && my>=230 && my<=230+55)
			{
				how=1;
				window=100;
			}
        }
    }


    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
    }
}

void iKeyboard(unsigned char key)
{
    if(key=='\r')
    {
        if(player_num<5) player_num++;

        strcpy(player_named,player_name);

        for(i=0; i<10; i++)
            player_name[i]='\0';

        name_indx=0;

        for(i=0; i<player_num; i++)
        {
            if(players[i].score < score_holder)
            {
                for(j=4; j>=i; j--)
                {
                    strcpy(players[j].name,players[j-1].name);
                    players[j].score=players[j-1].score;
                }

                players[i].score = score_holder;
                strcpy(players[i].name,player_named);

                fp=fopen("HighScores.txt","w");

                fprintf(fp,"%d\n", player_num);

                for(i=0; i<player_num; i++)
                {
                    fprintf(fp,"%s %d\n", players[i].name, players[i].score);
                }

                fclose(fp);

                break;
            }
        }

        highscores=1;
    }
    else if(key=='\b' && name_indx!=0)
    {
        name_indx--;
        player_name[name_indx] ='\0';
    }
    else if(name_indx<10)
    {
        player_name[name_indx] = key;
        name_indx++;
    }
}

void iSpecialKeyboard(unsigned char key)
{

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
}





int main()
{
    fp=fopen("HighScores.txt","r");

    fscanf(fp,"%d\n", &player_num);

    for(i=0; i<player_num; i++)
    {
        fscanf(fp,"%s %d\n", &players[i].name, &players[i].score);
    }

    fclose(fp);


    int x=135,y=80;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            easy[i][j][0]=x;
            easy[i][j][1]=y;

            y+=115;
        }

        y=80;
        x+=115;
    }

    x=90;
    y=40;

    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
        {
            hard[i][j][0]=x;
            hard[i][j][1]=y;

            y+=107;
        }

        y=40;
        x+=107;
    }


    for(i=0; i<16; i++)
    {
        strcpy(cards[i].name,es[i]);
    }

    for(i=0; i<25; i++)
    {
        strcpy(hard_cards[i].name,hrd[i]);
    }

    srand(time(NULL));


    iSetTimer(150, timedown);

    iSetTimer(20, animate);

    iSetTimer(20, animate2);

    iSetTimer(50, poofing);

    iSetTimer(30, clockeye);


    if(music==1) PlaySound("daylight.wav", NULL, SND_LOOP | SND_ASYNC);


    iInitialize(700, 650, "Card Matching");

    return 0;
}
