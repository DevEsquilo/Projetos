#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

using namespace std;

#define ESC    	27
#define ENTER   13


int pg = 0;


struct Bola{
	
};
int main(){
	
  initwindow(700,500);
  setbkcolor(RGB(100,150,100));
  
    while(true){
      if(pg == 2)pg = 1;else pg = 2;
      setactivepage(pg);
	}
}
