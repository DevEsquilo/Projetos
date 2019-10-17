#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include <time.h>
using namespace std;

#define ESC    	27

int pg = 1;
int i;
char tecla = 0;
unsigned char *T1, *T1M,*T2, *T2M,*T3, *T3M,*T4, *T4M,*T5, *T5M,*T6, *T6M;
int Tam,x,y;

void PreparaImg(int Tam, unsigned char *Img, unsigned char *Msk) {
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
    fflush(stdin);
    if(pg == 2) pg = 1; else pg = 2;
        setactivepage(pg);
        cleardevice();
     	
     	setvisualpage(pg);
}

void Desenha_Img(){
	
setvisualpage(1);
setactivepage(15);
  
cleardevice();

readimagefile("t1.bmp", 0, 0, 234, 224);
Tam = imagesize(0, 0, 234, 224);
T1 = (unsigned char *)malloc(Tam);
getimage(0, 0, 234, 224, T1);
cleardevice();

readimagefile("t2.bmp", 235, 0, 469, 224);
Tam = imagesize(235, 0, 469, 224);
T2 = (unsigned char *)malloc(Tam);
getimage(235, 0, 469, 224,T2);
cleardevice();

readimagefile("t3.bmp", 470, 0, 704, 224);
Tam = imagesize(470, 0, 704, 224);
T3 = (unsigned char *)malloc(Tam);
getimage(470, 0, 704, 224, T3);
cleardevice();

//aaaaa
readimagefile("t4.bmp", 705, 0, 903, 224);
Tam = imagesize(705, 0, 903, 224);
T4 = (unsigned char *)malloc(Tam);
getimage(705, 0, 903, 224, T4);
cleardevice();

readimagefile("t5.bmp", 940, 0, 1174, 224);
Tam = imagesize(940, 0, 1174, 224);
T5 = (unsigned char *)malloc(Tam);
getimage(940, 0, 1174, 224, T5);
cleardevice();

readimagefile("t6.bmp", 1175, 0, 1409, 224);
Tam = imagesize(1175, 0, 1409, 224);
T6 = (unsigned char *)malloc(Tam);
getimage(1175, 0, 1409, 224, T6);
cleardevice();

readimagefile("t1A.bmp",1410,0,1644,224);
readimagefile("t2A.bmp",1645,0,1879,224); 
    
 // captura para o ponteiro P
T1M = (unsigned char *)malloc(Tam);
getimage(0, 0, 234, 224, T1M);  
cleardevice();


T2M = (unsigned char *)malloc(Tam);
getimage(235, 0, 469, 224,T2M); 
cleardevice();


T3M = (unsigned char *)malloc(Tam);
getimage(470, 0, 704, 224, T3M); 
cleardevice();


T4M = (unsigned char *)malloc(Tam);
getimage(705, 0, 903, 224, T4M);
cleardevice();


T5M = (unsigned char *)malloc(Tam);
getimage(940, 0, 1174, 224, T5M); 
cleardevice();


T6M = (unsigned char *)malloc(Tam);
getimage(1175, 0, 1409, 224, T6M); 
cleardevice();
    

PreparaImg(Tam, T1, T1M);
PreparaImg(Tam, T2, T2M);
PreparaImg(Tam, T3, T3M);
PreparaImg(Tam, T4, T4M);
PreparaImg(Tam, T5, T5M);
PreparaImg(Tam, T6, T6M);
cleardevice();
    
x = y = 300;
}

void Desenha_Img();





void sans()
{
  //putimage(x,y,bmp,layer);
  putimage(100,100,T1,2);
  putimage(100,100,T1M,3);
  putimage(100,100,T2,2);
  putimage(100,100,T2M,3);
  putimage(100,100,T3,2);
  putimage(100,100,T3M,3);
  putimage(100,100,T4,2);
  putimage(100,100,T4M,3);
  putimage(100,100,T5,2);
  putimage(100,100,T5M,3);
  putimage(100,100,T6,2);
  putimage(100,100,T6M,3);
  
}





int main()  { 
initwindow(700, 600, "Imagens", 200, 20);
setbkcolor(RGB(100,150,100));
int pg;
char tecla = 0;


while(tecla != ESC) 
{
	if(pg == 2) pg = 1; else pg = 2;


  setactivepage(pg);   
	sans();
	//telaUp();
    
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



