#include<iostream>
#include<graphics.h>
#include <time.h>
using namespace std;

int main()  { 
  srand(time(NULL)); 
  initwindow(600, 700);
  setbkcolor(RGB(0,191,255));
  cleardevice();
  setfillstyle(1, RGB(255,165,0));
  fillellipse(50, 250, 200,200);
  
  setfillstyle(1, RGB(255,255,255));
  for(int i=0;i<10;i++){
  	int j = rand()%599;
  	int h = rand()%249;
  	fillellipse(j, h, 15,10);
  	fillellipse(j, h+5, 20,10);
  }
  setfillstyle(1, RGB(65,105,225));
  bar(0, 250, 600, 450);
  setfillstyle(1, RGB(245, 204, 77));
  bar(0, 450, 600, 700);
  
  setcolor(RGB(192,192,192));
  setlinestyle(0,1,14);
  line(50,550,125,350);
  

  while(!kbhit());	

  closegraph();	
  return 0; 
}
