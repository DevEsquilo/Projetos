#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include <windows.h>
#include "MMSystem.h"

using namespace std;

#define ESC    	27
#define ENTER   13
int i = 0, size, Qpiso = 1, Cpiso;
char t = 0;
int pg = 0;
//int telaX = 1280, telaY = 700;
bool pulo = true;
bool pause = true;
int Tam = 11;
int ALE = 0;
int altura = 224;
int largura = 234;
int largurachao = 400;
int tela = (1366, 768);

char tecla;

void *background;

unsigned char *bmp[6];
unsigned char *mask[6];
unsigned char *chon[2];

void *bk;
void *menu;


struct player{
  int X;
  int Y;
};
struct piso{
  int X;
  int Y;
  int passoX;
  int size;;
};

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

void img(piso Piso)
{
    Piso.size = imagesize(0 ,0 ,399, 99);
	  int size = imagesize(0, 0, 234,224);

    int sizebk = imagesize(0,0,1366, 768);
    
    setvisualpage(15);
    setactivepage(16);

    //t1
    readimagefile(".\\assets\\t1.bmp", 0, 0, 234,224);
    bmp[0] = (unsigned char *)malloc(size);
    mask[0] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[0]);
    getimage(0, 0, 234,224, mask[0]);
    PreparaImg(size, bmp[0], mask[0]);
    
    //t2
    readimagefile(".\\assets\\t2.bmp", 0, 0, 234,224);
    bmp[1] = (unsigned char *)malloc(size);
    mask[1] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[1]);
    getimage(0, 0, 234,224, mask[1]);
    PreparaImg(size, bmp[1], mask[1]);
    
    //t3
    readimagefile(".\\assets\\t3.bmp", 0, 0, 234,224);
    bmp[2] = (unsigned char *)malloc(size);
    mask[2] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[2]);
    getimage(0, 0, 234,224, mask[2]);
    PreparaImg(size, bmp[2], mask[2]);
	  
    //t4
    readimagefile(".\\assets\\t4.bmp", 0, 0, 234,224);
    bmp[3] = (unsigned char *)malloc(size);
    mask[3] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[3]);
    getimage(0, 0, 234,224, mask[3]);
    PreparaImg(size, bmp[3], mask[3]);
    
    cleardevice();

    //t5
    readimagefile(".\\assets\\t5.bmp", 0, 0, 234,224);
    bmp[4] = (unsigned char *)malloc(size);
    mask[4] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[4]);
    getimage(0, 0, 234,224, mask[4]);
    PreparaImg(size, bmp[4], mask[4]);
    
    //t6
    readimagefile(".\\assets\\t6.bmp", 0, 0, 234,224);
    bmp[5] = (unsigned char *)malloc(size);
    mask[5] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[5]);
    getimage(0, 0, 234,224, mask[5]);
    PreparaImg(size, bmp[5], mask[5]);

    //pisos
    readimagefile(".\\assets\\chon.bmp", 0, 0, 399, 99);
    chon[0] = (unsigned char *)malloc(Piso.size);
    chon[1] = (unsigned char *)malloc(Piso.size);
    getimage(0, 0, 399, 30, chon[0]);
    getimage(0, 0, 399, 30, chon[1]);
    PreparaImg(Piso.size, chon[0], chon[1]);

    cleardevice();

    readimagefile(".\\assets\\fundo.bmp", 0, 0, 1366, 768);
    bk = (void *)malloc(sizebk);
    getimage(0, 0, 1366, 768, bk);

    readimagefile(".\\assets\\menu.bmp", 0, 0, 1366, 768);
    menu = (void*)malloc(sizebk);
    getimage(0, 0, 1366, 768, menu);

    cleardevice();
}


void teclado()
{
  fflush(stdin);
  if(kbhit()){
    int key = getch();
    if(key == VK_ESCAPE) pause = !pause;
  }
}

void pausa()
{
  while(pause){
    putimage(0, 0, menu, 0);
    teclado();
  }
}



int main(){
  int Size;
  int x = 0;
  piso *Piso;
  Piso = NULL;
  player Player;


  srand(time(NULL));
  DWORD telaX = GetSystemMetrics(SM_CXSCREEN);
  DWORD telaY = GetSystemMetrics(SM_CYSCREEN);

  initwindow(telaX,telaY,"",-3,-3);
  
  
  setbkcolor(RGB(100,100,100));
  //putimage(0,0,bk,0);

  Player.X = 300, Player.Y = 400;

  Cpiso  = 9;
  Piso = (piso*)realloc(Piso, sizeof(piso)* 12);
  
  for(x = 0; x < Tam; x++){
  Piso[x].X = rand() %telaX+750, telaX;
  Piso[x].Y = rand() %telaY, 100;
  }

  img(Piso[0]);
  //char tecla;

  
  // abre o arquivo em mp3 e coloca um apelido nele "bk"  \"nome do aquivo.extensão"\ -> ** quantida de vezes q vai tocar  -> 
  mciSendString("open .\\sons\\bk.mp3 type mpegvideo alias bk", NULL, 10, NULL);

  PlaySound(NULL, 0,0);
  ALE = 900+ (rand()%101);
  
  while(1){
    teclado();
  	pausa();
    mciSendString("play bk notify repeat", NULL, 0 ,0);

    if(pg == 2)pg = 1;else pg = 2;
    setactivepage(pg);
    cleardevice();

    
    //Fundo da tela
    putimage(0, 0, bk, 0);

    //desenha os chaos
    for(Cpiso = 0; Cpiso < Tam; Cpiso++) { //Faz o desenhos dos pisos
          putimage(Piso[Cpiso].X, Piso[Cpiso].Y, chon[1], AND_PUT);
          putimage(Piso[Cpiso].X, Piso[Cpiso].Y, chon[0], OR_PUT);
    }
    //desenha o personagem
    putimage(Player.X, Player.Y, mask[i], AND_PUT);
    putimage(Player.X, Player.Y, bmp[i], OR_PUT);
    
    i++; //progride a animação do Player
    if(i == 5)i = 0; //reseta a animação do player
    
    setvisualpage(pg);

    if(GetKeyState(VK_UP)&0x80&&(pulo))Player.Y -=120;

    //faz verificação do player, se esta no chão ou não
    if(Player.Y>=496)pulo = true; // deixa pular
    delay(80); // FPS

    Player.Y+=50; // famosa gravidade

    if(Player.Y>=telaY-203) Player.Y = telaY-204; //pra n cair do chao
    
    //movimentação do personagem em cima do piso
    for(Cpiso = 0; Cpiso <= Tam; Cpiso++) {
      if(Player.Y+altura <= Piso[Cpiso].Y && Player.X+largura >= Piso[Cpiso].X){
        Player.Y = Piso[Cpiso].Y-altura;
        if(Player.X >= Piso[Cpiso].X+largura){
          //Player.Y-=10;
        }
      }
    }
    
    if(GetKeyState(VK_LEFT)&0x80)  Player.X -= 20;
    if(GetKeyState(VK_RIGHT)&0x80) Player.X += 20;
    
    for(Cpiso = 0; Cpiso < Tam; Cpiso++)Piso[Cpiso].X-=20;// movimentação linear do piso
    
    // magica do piso dar a volta
    for(Cpiso = 0; Cpiso < Tam; Cpiso++) {
      if(Piso[Cpiso].X<= -ALE) {
        srand(time(NULL));
        Piso[Cpiso].X = telaX + 500 + rand()%1000;
        Piso[Cpiso].Y = 250+rand() % 519;
      }
    }
    if(GetKeyState(VK_END)&0x80)break;
    
    //if(collisao) sndPlaySound(".\\sons\\morte.wav", SND_ASYNC);
    Tam = 11;
	}	
}
