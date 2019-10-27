#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include <time.h>
using namespace std;

#define ESC    	27

int pg = 1;
char tecla = 0;

struct circ{
	int passox;
	int passoy;
	int Cor;
	int raio;
	int X;
	int Y;
};

int main()  { 
	circ *A;
	A = NULL;
	srand(time(NULL));
	int cont = 0;
	int px = 1, py = 1;
	
	initwindow(700, 700);
	A = (circ *)realloc(A, sizeof(circ) * 8);
	for (int i=0;i<=7;i++){
		A[i].X = 350;
		A[i].Y = 350;
		A[i].Cor = RGB(rand()%256, rand()%256, rand()%256);
		A[i].raio = 20;
		
	}
	A[0].passox = 0;A[0].passoy = -1;
	A[1].passox = 0;A[1].passoy = 1;
	A[2].passox = 1;A[2].passoy = 0;
	A[3].passox = -1;A[3].passoy = 0;
	A[4].passox = 1;A[4].passoy = -1;
	A[5].passox = -1;A[5].passoy = 1;
	A[6].passox = 1;A[6].passoy = 1;
	A[7].passox = -1;A[7].passoy = -1;
  
  while(tecla != ESC) {
  	if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    cleardevice();
    
    
if (cont == 200){
	
	for (int i=0;i<=7;i++){
    	setfillstyle(1, A[i].Cor);
    	fillellipse(A[i].X, A[i].Y, A[i].raio, A[i].raio);
    	A[i].X += A[i].passox;
    	A[i].Y += A[i].passoy;
    	
    	
//    	A[i].X -= A[i].passox; A[i].Y -= A[i].passoy;
	if (A[i].X <= 350 && A[i].Y <= 350){
		A[i].passox = -px;A[i].passoy = py;
	}
	else if (A[i].X <= 350 && A[i].Y >= 350){
		A[i].passox = px;A[i].passoy = py;
	
	}
	else if (A[i].X >= 350 && A[i].Y >= 350){
		A[i].passox = px;A[i].passoy = -py;
		
	}
	else if (A[i].X >= 350 && A[i].Y <= 350){
		A[i].passox = -px;A[i].passoy = -py;
		
	}
    	
	}
	
	
}
else{
	for (int i=0;i<=7;i++){
    	setfillstyle(1, A[i].Cor);
    	fillellipse(A[i].X, A[i].Y, A[i].raio, A[i].raio);
    	A[i].X += A[i].passox; A[i].Y += A[i].passoy;
    	
	}
	cont++;
}

//
//for (int i=0;i<=7;i++){
//
//	
//}


	setvisualpage(pg);
	if(GetKeyState(0x53)&0x80) {
		px = -px; py = -py;
	}
	fflush(stdin);    
    if (kbhit()){
      tecla = getch();
    }
    
}
  closegraph();	
  return 0; 
  free(A);
}
