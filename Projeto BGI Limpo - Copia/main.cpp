#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include <time.h>
using namespace std;

#define ESC    	27

int pg = 1;
char tecla = 0;

void PreparaImg(int Tam, unsigned char *Img, unsigned char *Msk) {
// Tam � o tamanho dos ponteiros da imagem e da m�scara
// Img � o ponteiro que aponta para o vetor que cont�m a imagem capturada com getimage(..)
// Msk � o ponteiro que ser� transformado em m�scara
  int i;
  unsigned char B, G, R;
  B = Img[24];
  G = Img[25];
  R = Img[26];
  for(i=24; i < Tam; i+=4) {
    if (Img[i]==B and Img[i+1]==G and Img[i+2]==R) {
      Img[i] = 0;
      Img[i+1] = 0;
      Img[i+2] = 0;
      Msk[i] = 255;
      Msk[i+1] = 255;
      Msk[i+2] = 255;
    }
    else {
      Msk[i] = 0;
      Msk[i+1] = 0;
      Msk[i+2] = 0;
    }
  }
}

void telaUp(){
    setvisualpage(pg);
    fflush(stdin);
    if (kbhit()){
        tecla = getch();
    }
    delay(000);
    if (pg == 1) pg = 2; else pg=1;{
        setactivepage(pg);
    }
    cleardevice();  
    //Frames Per Second
    delay(8);     
}


int main()  { 
initwindow(700, 600, "Imagens", 200, 20);
setbkcolor(RGB(100,150,100));
int pg;
char tecla = 0;
unsigned char *T1, *T1M,*T1A,*T1AM,*T2, *T2M,*T2A,*T2AM,*T3, *T3M,*T4, *T4M,*T5, *T5M,*T6, *T6M;
int Tam,x,y;
  
  Tam = imagesize(0, 0, 234, 224);
  T1 = (unsigned char *)malloc(Tam);
  T1M = (unsigned char *)malloc(Tam);
  T1A = (unsigned char *)malloc(Tam);
  T1AM = (unsigned char *)malloc(Tam);
  T2A = (unsigned char *)malloc(Tam);
  T2AM = (unsigned char *)malloc(Tam);
  T2 = (unsigned char *)malloc(Tam);
  T2M = (unsigned char *)malloc(Tam);
  T3 = (unsigned char *)malloc(Tam);
  T3M = (unsigned char *)malloc(Tam);
  T4 = (unsigned char *)malloc(Tam);
  T4M = (unsigned char *)malloc(Tam);
  T5 = (unsigned char *)malloc(Tam);
  T5M = (unsigned char *)malloc(Tam);
  T6 = (unsigned char *)malloc(Tam);
  T6M = (unsigned char *)malloc(Tam);
  

  
  cleardevice();
  
  readimagefile("t1.bmp", 0, 0, 234, 224);
	readimagefile("t2.bmp", 235, 0, 469, 224);
	readimagefile("t3.bmp", 470, 0, 704, 224);
	readimagefile("t4.bmp", 705, 0, 903, 224);
	readimagefile("t5.bmp", 940, 0, 1174, 224);
	readimagefile("t6.bmp", 1175, 0, 1409, 224);
	readimagefile("t1A.bmp",1410,0,1644,224);
	readimagefile("t2A.bmp",1645,0,1879,224); 
    
    getimage(0, 0, 234, 224, T1); // captura para o ponteiro P
    getimage(0, 0, 234, 224, T1M);
    
    getimage(1410,0,1644,224, T1A); // captura para o ponteiro P
    getimage(1410,0,1644,224, T1AM);
    
	getimage(235, 0, 469, 224,T2);
	getimage(235, 0, 469, 224,T2M); 
	
	getimage(1645,0,1879,224, T2A); // captura para o ponteiro P
    getimage(1645,0,1879,224, T2AM);
	
	getimage(470, 0, 704, 224, T3);
	getimage(470, 0, 704, 224, T3M); 
	
	getimage(705, 0, 903, 224, T4);
	getimage(705, 0, 903, 224, T4M); 
	
	getimage(940, 0, 1174, 224, T5);
	getimage(940, 0, 1174, 224, T5M); 
	
	getimage(1175, 0, 1409, 224, T6);
	getimage(1175, 0, 1409, 224, T6M);  
    
    PreparaImg(Tam, T1, T1M);
    PreparaImg(Tam, T2, T2M);
    PreparaImg(Tam, T3, T3M);
    PreparaImg(Tam, T4, T4M);
    PreparaImg(Tam, T5, T5M);
    PreparaImg(Tam, T6, T6M);
    
    PreparaImg(Tam, T1A, T1AM);
    PreparaImg(Tam, T2A, T2AM);
	x = y = 300;
while(tecla != ESC) {
	
	putimage(x, y, T1M, AND_PUT);
    putimage(x, y, T1, OR_PUT);
    delay(100);
	cleardevice();
	putimage(x, y, T2M, AND_PUT);
    putimage(x, y, T2, OR_PUT);
    delay(100);
    //cleardevice();
    putimage(x, y, T3M, AND_PUT);
    putimage(x, y, T3, OR_PUT);
    delay(100);
    //cleardevice();
    putimage(x, y, T4M, AND_PUT);
    putimage(x, y, T4, OR_PUT);
    delay(100);
    //cleardevice();
    putimage(x, y, T5M, AND_PUT);
    putimage(x, y, T5, OR_PUT);
    delay(100);
    //cleardevice();
    
    putimage(x, y, T6M, AND_PUT);
    putimage(x, y, T6, OR_PUT);
    delay(100);
    //cleardevice();
	telaUp();
    
}
  closegraph();	
  free(T1);
  free(T2);
  free(T3);
  free(T4);
  free(T5);
  free(T6);
  free(T1M);
  free(T2M);
  free(T3M);
  free(T4M);
  free(T5M);
  free(T6M);
  return 0; 
}	
