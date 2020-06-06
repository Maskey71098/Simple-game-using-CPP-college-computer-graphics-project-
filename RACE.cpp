
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

void enemycar(int x, int y)
 {
	setcolor(15);
	rectangle(x+1,y,x+49,y+100);//body
	rectangle(x+1,y+25,x+49,y+75);//stripes for body
	floodfill((x+x+50)/2,(y+y+140)/2,15);
  }

void mycar(int x, int y)
 {
	setcolor(15);
	rectangle(x+1,y,x+49,y+100);
	rectangle(x+1,y+25,x+49,y+75);
	setfillstyle(5,RED);
	floodfill((x+x+50)/2,(y+y+100)/2,15);
	setfillstyle(2,BLUE);
	floodfill((x+x+50)/2,(y+y+40)/2,15);
	floodfill((x+x+50)/2,(y+y+160)/2,15);
  }

void myclear(int x,int y)
 {
	setcolor(8);
	rectangle(x+1,y,x+49,y+100);
	rectangle(x+1,y+25,x+49,y+75);
	setfillstyle(SOLID_FILL,8);
	floodfill((x+x+50)/2,(y+y+100)/2,8);
	floodfill((x+x+50)/2,(y+y+40)/2,8);
	floodfill((x+x+50)/2,(y+y+160)/2,8);
 }


 void enemyclear(int x,int y)
 {
	setcolor(8);
	rectangle(x+1,y,x+49,y+100);
	rectangle(x+1,y+25,x+49,y+75);
 }

void main()
 {
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");

	int x=300,y=350,ch,life=3,score=0;
	char choice;

  //--------- BASIC INFO-------- //
  cout<<"\n\n\n\n\n\t\t\t ROAD RASH";
  cout<<"\n\t\t\t ---------------";
  cout<<"\n\t\t\t MOVE TO AVOID OBSTACLES";
  cout<<"\n\t\t\t ---------------";
  cout<<"\n\t\t\t GAME ON!!!!";
  delay(1500);

  //--------- CLEAR INFO---------//
  for(int m=1;m<15;m++)
    for(int n=1;n<40;n++)
    {
	gotoxy(n,m);
	cout<<" ";
    }

  //--------GAMING CONSOLE CONFIGURATION-------//

  setcolor(RED);

  rectangle(249,0,401,getmaxy()); //draw gaming console
  setfillstyle(SOLID_FILL,8); //fill pattern,fill color
  floodfill(325,getmaxy()/2,RED);//fill an enclosed area intx,inty,border color

  for(int level=1;(level<=5)&&(life>0);level++)
  {
	if(level==1)
	{
		gotoxy(5,5);
		cout<<"Your Game Starts In";
		gotoxy(5,7);
		cout<<"3";
		delay(1000);
		gotoxy(5,7);
		cout<<"2";
		delay(1000);
		gotoxy(5,7);
		cout<<"1";
		delay(1000);
		gotoxy(5,5);
		cout<<"                     ";
		gotoxy(5,7);
		cout<<" ";
	}
	else
	{
	 // comment for ingame level transition //
	 /*
	       gotoxy(5,5);
	       cout<<"Next Level Starts In";
	       gotoxy(5,7);
	       cout<<"3";
	       delay(1000);
	       gotoxy(5,7);
	       cout<<"2";
	       delay(1000);
	       gotoxy(5,7);
	       cout<<"1";
	       delay(1000);
	       gotoxy(5,5);
	       cout<<"                     ";
	       gotoxy(5,7);
	       cout<<" ";
	 */
	 }

	for(int i=0;(i<15)&&(life>0);i++)
	{
		if((level==5)&&(i==14))
		{
			gotoxy(5,5);
			cout<<"You have won";
			gotoxy(5,6);
			cout<<"Wanna continue <y/n>";
			choice = getch();
			if ((choice=='y')||(choice=='Y'))
				main();
			else
				exit(0);
		 }
    // GAME INFORMATION CONSOLES //
	  setcolor(RED);
	  rectangle(10,10,120,40);
	  gotoxy(4,2);
	  cout<<"Level "<<level;
	  rectangle(getmaxx()-120,10,getmaxx(),40);
	  gotoxy(68,2);
	  cout<<"Lives = "<<life;
	  rectangle(getmaxx()-120,55,getmaxx(),85);
	  gotoxy(68,5);
	  cout<<"Score = "<<score;

    // ---------------------------------------//
	  int accident=0;
	  //cstdlib for rand
	  int y1=1,x1=250+((rand()%3)*50);
	  int y2=1,x2=250+((rand()%3)*50);
	  score += 10;
	  while(y1<getmaxy()-1)
	  {
		enemyclear(x1,y1);
		enemyclear(x2,y2);
		y1++;
		y2++;
		if(accident == 1)
			break;
		enemycar(x1,y1);
		enemycar(x2,y2);
		mycar(x,y);
		delay(5-level);
		if(kbhit	()) //conio.h returns non zero if key is in buffer
		{
		     //	mycar(x,y);
			ch=getch();
			switch(ch)
			{
				//esc//
				case 27: exit(0);
					break;
																						//left button//
				case 75:myclear(x,y);
					if(x>250)
						x=x-50;
					if((x==x1)||(x==x2))
	  if( ( (abs(y-y1)<100) ) || ( (abs(y-y2)<100) ) )
	  {
		accident=1;
		x=x+50;
		mycar(x,y);
		goto Next1;
	  }
	  mycar(x,y);
		break;
	  //right button//
	  case 77:myclear(x,y);
		if(x<350)
			x=x+50;
		if((x==x1)||(x==x2))
	  if( ( (abs(y-y1)<100) ) || ( (abs(y-y2)<100) ) )
	  {
		accident=1;
		x=x-50;
		mycar(x,y);
		goto Next1;
	  }
	  mycar(x,y);
		break;
	  //down button//
	  case 72:myclear(x,y);
		  if(y>0)
			y=y-5;
		  mycar(x,y);
			break;
	  //up button//
	  case 80:myclear(x,y);
		  if(y<getmaxy()-105)
			y=y+5;
		  mycar(x,y);
			break;
	    }//switch end bracket
	}// kbhit end bracket

	// head on collision
	if((x==x1)||(x==x2))
	{
		if( ( (abs(y-y1)<100) ) || ( (abs(y-y2)<100) ) )
			accident=1;

	Next1:
		if(accident==1)
		{
			life =life-1;
			if(life==0)
			{
				gotoxy(5,5);
				cout<<"GAME OVER ";
				gotoxy(5,6);
				cout<<"You could not save";
				gotoxy(5,7);
				cout<<"your car";
				break;
			}
			gotoxy(5,5);
			cout<<"You have lost 1 life";
			delay(3000);
			gotoxy(5,5);
			cout<<"                    ";
		}//end if accident
	} //end if head on
  }// end for while
}// end for i
} //end for level

 getch();
 }