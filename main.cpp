#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
# include <stdio.h>
#include<time.h>

using namespace std;

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}

void setTextColor(int textColor, int backColor=0)
{
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
int colorAttribute = backColor << 4 | textColor;
SetConsoleTextAttribute(consoleHandle, colorAttribute);
}

class mohit{
	public:
		mohit(int w,int h);
		void print();
		int showh(){ return height-1;}
		int showw(){ return weidth-1;}
	private:
		int weidth;
		int height;		
};

mohit::mohit(int w,int h){
	weidth=w;
	height=h;
}

void mohit::print(){
	for(int i=0;i<weidth;i++){
		gotoxy(i,0);
		cout<<"#";
	}
	for(int i=0;i<height;i++){
		gotoxy(0,i);
		cout<<"#";
	}
	for(int i=0;i<weidth;i++){
		gotoxy(i,height);
		cout<<"#";
	}
	for(int i=0;i<height;i++){
		gotoxy(weidth,i);
		cout<<"#";
	}
	   
}

class mane{
	public:
	   mane(int e1,int r1,int e2,int r2);
	   void printm();
	   int getx1(){return x1;}
	   int getx2(){return x1+1;}
	   int gety1(){return y1;}
	   int getx3(){return x2;}
	   int getx4(){return x2+1;}
	   int gety2(){return y2;}
	   char e='$';
	private:
	    int x1,x2;
		int y1,y2;
		char u[2];
		
			
};

mane::mane(int e1,int r1,int e2,int r2){
	x1=e1; x2=e2;
	y1=r1; y2=r2;
	for (int i=0;i<2;i++)
	     u[i]=e;
}

void mane::printm(){	
	setTextColor(3,0);
    	gotoxy(x1,y1); 
	for (int i=0;i<2;i++){
    
		cout<<u[i];}

    setTextColor(5,0);
    gotoxy(x2,y2);
    for (int i=0;i<2;i++){
       	
		cout<<u[i];}
	  
}


class takhte{
	public:
		takhte();
		takhte(int z,int k,mohit* s);
		void control();
		int getx(){return x;}
		int getx2(){return x+7;}
		int gety(){return y-1;}
			
	private:
		int x;
		int y;
		char o[7];
		mohit* v;	
};



takhte::takhte(int z,int k,mohit* s){
	v=s;
	if(z<0||z>v->showw())
	   abort();
	x=z;
	y=k;
	for(int i=0;i<=6;i++)
	    o[i]='_';
	gotoxy(x,y);
	for(int i=0;i<=6;i++)
	   cout<<o[i];
}

void takhte::control(){
	if(kbhit()){
	  switch(getch()){  
	  case 's':
	  	  gotoxy(1,y);
	  	  cout<<"                              ";
		  x++;
		  if(x+6>v->showw())
	  	  break;
		  for(int i=1;i<=7;i++){
		    	o[0]=' ';
            	o[i]='_';}
		    gotoxy(x,y);
	        for(int i=0;i<=7;i++)
		       cout<<o[i];	
		       break;
  	    case 'a':
  	    	gotoxy(1,y);
  	    	cout<<"                             ";
  	    	x--;	
			if(x<0)
  	    	break;
  	    	for(int i=0;i<=6;i++){
  	    		o[7]=' ';
  	    		o[i]='_';}
  	    	gotoxy(x,y);
			for(int i=0;i<=7;i++)
		       cout<<o[i];
		       break;}
	}
	
}
class ball{
	public:
		ball(int a,int b,mohit* m);
		void move(takhte z,mane a);	
    private:
		int x;
		int y;
		char c='@';
		char d=' ';
		mohit* n;	
};

ball::ball(int a,int b, mohit* m){
	n=m;	
	if(a<=1||a> n-> showw()||b<1||b>n->showh())
	   abort();
	x=a;
	y=b;
	gotoxy(x,y);
	cout<<c;
}

void ball::move(takhte z,mane a){		
   while(1){
   	int v=200;
	if(x>14&&y==1){
	   while (y>=1&&y<=n->showh()&&x>1&&x<n->showw()){
	        z.control();
			Sleep(v);
	        gotoxy(x,y);
	        cout<<d;
	        x++;
        	y++;
	        gotoxy(x,y);
	        cout<<c;
	        if(a.e=='$')
	        if((x==a.getx1()&&y==a.gety1())||(x==a.getx2()&&y==a.gety1())||(x==a.getx3()&&y==a.gety2())||(x==a.getx4()&&y==a.gety2()))
	        	break;
	        if(y==z.gety()&&x>=z.getx()&&x<=z.getx2())
	        break;
			}}
	if(x<=14&&y==1){
		while(y>=1&&y<=n->showh()&&x>1&&x<n->showw()){
			z.control();
	        Sleep(v);
	        gotoxy(x,y);
        	cout<<d;
        	x--;
        	y++;
        	gotoxy(x,y);
        	cout<<c;
        	if(a.e=='$')
        	if((x==a.getx1()&&y==a.gety1())||(x==a.getx2()&&y==a.gety1())||(x==a.getx3()&&y==a.gety2())||(x==a.getx4()&&y==a.gety2()))
	        break;
	        if(y==z.gety()&&x>=z.getx()&&x<=z.getx2())
	        break;
	}}
	if(x==y||x==n->showw()){
		while(y>1&&y<n->showh()&&x>1&&x<=n->showw()){
		z.control();
		Sleep(v);
		gotoxy(x,y);
		cout<<d;
		x--;
		y++;
		gotoxy(x,y);
		cout<<c;
		if(a.e=='$')
		if((x==a.getx1()&&y==a.gety1())||(x==a.getx2()&&y==a.gety1())||(x==a.getx3()&&y==a.gety2())||(x==a.getx4()&&y==a.gety2()))
	        break;
	    if(y==z.gety()&&x>=z.getx()&&x<=z.getx2())
	        break;
	}}
	if(y>x||x==1){
	 while(y>1&&y<n->showh()&&x>=1&&x<n->showw()){	
	 z.control();
	 Sleep(v);
	 gotoxy(x,y);
		cout<<d;
		x++;
		y++;
		gotoxy(x,y);
		cout<<c;
		if(a.e=='$')
		if((x==a.getx1()&&y==a.gety1())||(x==a.getx2()&&y==a.gety1())||(x==a.getx3()&&y==a.gety2())||(x==a.getx4()&&y==a.gety2()))
	        break;
		if(y==z.gety()&&x>=z.getx()&&x<=z.getx2())
	        break;
}
	}
   if(x<y&&y==z.gety()&&x>=z.getx()&&x<=z.getx2()){
   	 while(x>1&&x<n->showw()&&y>1&&y<n->showh()){	
   	 	z.control();
   	 	Sleep(v);
   	 	gotoxy(x,y);
   	 	cout<<d;
   	 	x++;
   	 	y--;
   	 	gotoxy(x,y);
   	 	cout<<c;
   	 	if(a.e=='$')
   	 	if((x==a.getx1()&&y==a.gety1())||(x==a.getx2()&&y==a.gety1())||(x==a.getx3()&&y==a.gety2())||(x==a.getx4()&&y==a.gety2()))
	        break;
		}
   }
   if(x>=y&&y==z.gety()&&x>=z.getx()&&x<=z.getx2()){
     while(x>1&&x<n->showw()&&y>1&&y<n->showh()) { 
   		z.control();
   		Sleep(v);
   	 	gotoxy(x,y);
   	 	cout<<d;
   	 	x--;
   	 	y--;
   	 	gotoxy(x,y);
   	 	cout<<c;
   	 	if(a.e=='$')
   	 	if((x==a.getx1()&&y==a.gety1())||(x==a.getx2()&&y==a.gety1())||(x==a.getx3()&&y==a.gety2())||(x==a.getx4()&&y==a.gety2()))
	        break;
	   }}
	if(y>=x&&x==1){
		while(x>=1&&x<n->showw()&&y>1&&y<n->showh()){
		z.control();
   		Sleep(v);
   	 	gotoxy(x,y);
   	 	cout<<d;
   	 	x++;
   	 	y--;
   	 	gotoxy(x,y);
   	 	cout<<c;
   	 	if(a.e=='$')
   	 	if((x==a.getx1()&&y==a.gety1())||(x==a.getx2()&&y==a.gety1())||(x==a.getx3()&&y==a.gety2())||(x==a.getx4()&&y==a.gety2()))
	        break;
	     if(y==z.gety()&&x>=z.getx()&&x<=z.getx2())
	        break;   
		}
	}
		if(y<x&&x==n->showw()){
		while(x>1&&x<=n->showw()&&y>1&&y<n->showh()){
		z.control();
   		Sleep(v);
   	 	gotoxy(x,y);
   	 	cout<<d;
   	 	x--;
   	 	y--;
   	 	gotoxy(x,y);
   	 	cout<<c;
   	 	if(a.e=='$')
   	 	if((x==a.getx1()&&y==a.gety1())||(x==a.getx2()&&y==a.gety1())||(x==a.getx3()&&y==a.gety2())||(x==a.getx4()&&y==a.gety2()))
	        break;
	    if(y==z.gety()&&x>=z.getx()&&x<=z.getx2())
	        break;
		}
	}
   if(a.e!=' '){
   if(x>=y&&(x==a.getx1()&&y==a.gety1())||(x==a.getx2()&&y==a.gety1())||(x==a.getx3()&&y==a.gety2())||(x==a.getx4()&&y==a.gety2())){
   	while(x>1&&x<n->showw()&&y>1&&y<n->showh()){
   		z.control();
   		Sleep(v);
   	 	gotoxy(x,y);
   	 	a.e=d;
		cout<<a.e;
   	 	x--;
   	 	y--;
   	 	gotoxy(x,y);
   	 	cout<<c;
   	 	if(y==z.gety()&&x>=z.getx()&&x<=z.getx2())
	    break;
	   }}
   }if(a.e!=' '){
    if(x<y&&(x==a.getx1()&&y==a.gety1())||(x==a.getx2()&&y==a.gety1())||(x==a.getx3()&&y==a.gety2())||(x==a.getx4()&&y==a.gety2())){
   	while(x>1&&x<n->showw()&&y>1&&y<n->showh()){ 
   		z.control();
   		Sleep(v);
   	 	gotoxy(x,y);
		a.e=d;
		cout<<a.e;
   	 	x++;
   	 	y--;
   	 	gotoxy(x,y);
   	 	cout<<c;  	 	
   	 	if(y==z.gety()&&x>=z.getx()&&x<=z.getx2())
        break;
	   }}
   }
   if(y==z.gety()&&x>=z.getx()&&x<=z.getx()+5)
     v-=50;
   if(y==n->showh()){
		gotoxy(12,7);
		setTextColor(4,0);
		cout<<"game over:(";
   }
   }}


void matn(){
	gotoxy(1,23);
	setTextColor(2,0);
	cout<<"Press s to go right and press a to go left";
	gotoxy(1,24);
	cout<<	"Be careful if your rocket touch wall you will fail";
}

int main() {
	mohit a(30,20);
	a.print();
    matn();
    srand(time(NULL));
    int x1=rand()%(25-5+1)+5;
    int x2=rand()%(25-5+1)+5;
    int y1=rand()%(7-3+1)+3;
    int y2=rand()%(7-3+1)+3;
    mane r(x1,y1,x2,y2);
    r.printm();
    Sleep(1000);
	takhte z(13,18,&a);
	setTextColor(6,0);
	srand(time(NULL));
	int x=rand()%28+1;	
	ball n(x,1,&a);
	n.move(z,r);					
	return 0;
}

