#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>

#include <windows.h>
#include "MMSystem.h"


//#include<SDL.h>



using namespace std;

#define ESC    	27

int pg = 1;
char tecla = 0;



void AlteraCorImg(unsigned char *P, int Tam, int Cor) {
  int i;
  for(i=0; i < Tam; i++)
    if (i > 23 and i % 4 < 3)
      P[i] = Cor;
}

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





int main(){     
  initwindow(700, 600, "Imagens", 200, 20);
  setbkcolor(RGB(100,150,100));
  int pg;
  char tecla = 0;
  unsigned char *P, *M;
  int TamP, i, x, y, passo = 2;
  bool song = false;

  TamP = imagesize(0, 0, 31, 31);
  P = (unsigned char *)malloc(TamP);
  M = (unsigned char *)malloc(TamP);


  cleardevice();
  readimagefile("Sans.bmp", 0, 0, 31, 31); // carrega a imagem
  getimage(0, 0, 31, 31, P); // captura para o ponteiro P
  getimage(0, 0, 31, 31, M); // captura para a mascara M (a mesma imagem de P, que depois sera manipulada na rotina PreparaImg)

  PreparaImg(TamP, P, M); // configura as cores branca e preta em cada pixel para formar o recorte

  x = 70;
  y = 30;
  PlaySound(NULL, 0,0);
  while(tecla != ESC) {
   

    if(GetKeyState(VK_LEFT)&0x80) x-=passo;
    if(GetKeyState(VK_RIGHT)&0x80) x+=passo;
    if(GetKeyState(VK_UP)&0x80) y-=passo;
    if(GetKeyState(VK_DOWN)&0x80) y+=passo;
    if(GetKeyState(VK_END)&0x80){
    	PlaySound(("tada1.wav"), NULL, SND_MEMORY);
    	printf("end\n");
    	song = false;
    	
    	
    }	
    
    
    if(GetKeyState(VK_SPACE)&0x80){
    	if(song == false){
		
    	PlaySound(TEXT("tada.wav"), NULL, SND_ASYNC);
    	PlaySound(TEXT("tada1.wav"), NULL, SND_FILENAME); 
    	song = true;
    	printf("a\n");
    	delay(100);
    	}
    	else{
		
    	PlaySound(NULL,0,0);
    	song = false;
    	printf("b\n");
    	delay(100);
    	}
    	
    	
	} 
    putimage(x, y, M, AND_PUT);
    putimage(x, y, P, OR_PUT);
    telaUp();



  }
  
  closegraph();	
  free(P);
  free(M);
  return 0; 
}


