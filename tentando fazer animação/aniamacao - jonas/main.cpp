#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <locale.h>
#include <ctime>

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
int Tam = 6;
int ALE = 0;
int altura = 224;
int largura = 234;
int largurachao = 400;
int tela = (1366, 768);

char tecla;


unsigned char *correr[6];
unsigned char *mask[6];
unsigned char *pular[4];
unsigned char *maskP[4];

unsigned char *chon[2];

void *background;
void *bk;
void *menu;

bool passo1 = false, passo2 = false, passo3 = false, amiga = true;

DWORD telaX = GetSystemMetrics(SM_CXSCREEN);
DWORD telaY = GetSystemMetrics(SM_CYSCREEN);

POINT P;
HWND janela;

//Falas
  char *falas[] = {
    (char*)"Jogar", 
    (char*)"Opcoes", 
    (char*)"Sair"
    };
  char *fintro[] = {
    (char*)"Samuel cara de pastel pecou gravemente, e o grande",
    (char*)"uma pena... e seu coracao, era mais pesado",
    (char*)"Anubis veio lhe julgar, pesando o seu coracao com"
    };

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
struct bg{
  int X0;
  int X1;
  int largura;
};

void PreparaImg(int Tam, unsigned char *Img, unsigned char *Msk)
{
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
  Piso.size = imagesize(0 ,0 ,400, 151);
  int size = imagesize(0, 0, 234,224);
  int sizebk = imagesize(0,0,1366, 768);

  //correr1
  readimagefile(".\\assets\\correr1.bmp", 0, 0, 234,224);
  correr[0] = (unsigned char *)malloc(size);
  mask[0] = (unsigned char *)malloc(size);
  getimage(0, 0, 234,224, correr[0]);
  getimage(0, 0, 234,224, mask[0]);
  PreparaImg(size, correr[0], mask[0]);

  //correr2
  readimagefile(".\\assets\\correr2.bmp", 0, 0, 234,224);
  correr[1] = (unsigned char *)malloc(size);
  mask[1] = (unsigned char *)malloc(size);
  getimage(0, 0, 234,224, correr[1]);
  getimage(0, 0, 234,224, mask[1]);
  PreparaImg(size, correr[1], mask[1]);

  //correr3
  readimagefile(".\\assets\\correr3.bmp", 0, 0, 234,224);
  correr[2] = (unsigned char *)malloc(size);
  mask[2] = (unsigned char *)malloc(size);
  getimage(0, 0, 234,224, correr[2]);
  getimage(0, 0, 234,224, mask[2]);
  PreparaImg(size, correr[2], mask[2]);
  
  //correr4
  readimagefile(".\\assets\\correr4.bmp", 0, 0, 234,224);
  correr[3] = (unsigned char *)malloc(size);
  mask[3] = (unsigned char *)malloc(size);
  getimage(0, 0, 234,224, correr[3]);
  getimage(0, 0, 234,224, mask[3]);
  PreparaImg(size, correr[3], mask[3]);

  //correr5
  readimagefile(".\\assets\\correr5.bmp", 0, 0, 234,224);
  correr[4] = (unsigned char *)malloc(size);
  mask[4] = (unsigned char *)malloc(size);
  getimage(0, 0, 234,224, correr[4]);
  getimage(0, 0, 234,224, mask[4]);
  PreparaImg(size, correr[4], mask[4]);
  
  //correr6
  readimagefile(".\\assets\\correr6.bmp", 0, 0, 234,224);
  correr[5] = (unsigned char *)malloc(size);
  mask[5] = (unsigned char *)malloc(size);
  getimage(0, 0, 234,224, correr[5]);
  getimage(0, 0, 234,224, mask[5]);
  PreparaImg(size, correr[5], mask[5]);

  //pulo1
  readimagefile(".\\assets\\pulo1.bmp", 0, 0, 234,224);
  pular[4] = (unsigned char *)malloc(size);
  maskP[4] = (unsigned char *)malloc(size);
  getimage(0, 0, 234,224, pular[4]);
  getimage(0, 0, 234,224, maskP[4]);
  PreparaImg(size, pular[4], maskP[4]);

  //pulo2
  readimagefile(".\\assets\\pulo2.bmp", 0, 0, 234,224);
  pular[4] = (unsigned char *)malloc(size);
  maskP[4] = (unsigned char *)malloc(size);
  getimage(0, 0, 234,224, pular[4]);
  getimage(0, 0, 234,224, maskP[4]);
  PreparaImg(size, pular[4], maskP[4]);

  //pulo3
  readimagefile(".\\assets\\pulo3.bmp", 0, 0, 234,224);
  pular[4] = (unsigned char *)malloc(size);
  maskP[4] = (unsigned char *)malloc(size);
  getimage(0, 0, 234,224, pular[4]);
  getimage(0, 0, 234,224, maskP[4]);
  PreparaImg(size, pular[4], maskP[4]);

  //pisos
  readimagefile(".\\assets\\plataforma1.bmp", 0, 0, 400, 151);
  chon[0] = (unsigned char *)malloc(Piso.size);
  chon[1] = (unsigned char *)malloc(Piso.size);
  getimage(0, 0, 399, 150, chon[0]);
  getimage(0, 0, 399, 150, chon[1]);
  PreparaImg(Piso.size, chon[0], chon[1]);


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
  if(pause){
    int tamBar, Y1 = telaY/2 - telaY/10, Y2, Y3, XT = telaX/3, YT = telaX/3 + telaX/3,textoMeio = XT+20+(XT/3);
    tamBar = telaX/19;
    //printf("%d",tamBar);
    putimage(0, 0, menu, 0);
    //outtextxy(telaX/4,telaY/6,(char*)"TA NA TELA DE PAUSA POHAN");
    setcolor(0);
    
    setfillstyle(1, RGB(194,178,128));
    bar(XT, Y1 , YT, Y1 +tamBar);
    outtextxy(textoMeio+8, Y1 + (Y1 /11), falas[0]);
    setfillstyle(1, RGB(194,178,128));
    bar(XT, Y1 + tamBar+14, YT, Y1 + tamBar * 2 + 10);
    outtextxy(textoMeio-8, Y1+ tamBar+10 + (Y1 / 11) , falas[1]);
    setfillstyle(1, RGB(194,178,128));
    bar(XT, 20 + Y1 + tamBar*2, YT, Y1 +tamBar*3 + 10);
    outtextxy(textoMeio+19, Y1+ tamBar*2+10 + (Y1 / 11), falas[2]);

    while(pause){
      if(GetKeyState(VK_END)&0x80){pause = false; break;}
      teclado();
    }
  }
}

void intro()
{
  while(amiga){
    if(pg == 2)pg = 1;else pg = 2;
    setactivepage(pg);
    cleardevice();
    if(passo3 == true)amiga = false;

    outtextxy(telaX/6,telaY/6,fintro[0]);
    delay(800);
    
    if(passo2){
      outtextxy(telaX/6,telaY/6+140,fintro[1]);
      passo3 = true;
      delay(800);
    }
    
    if(passo1){
      outtextxy(telaX/6,telaY/6+70,fintro[2]);
      delay(800);
      passo2 = true;
    }
    passo1 = true;
    setvisualpage(pg);
  }
}

void tempoAtual(int Coord, char *Msg, int X, int Y);

int main(){
  setlocale(LC_ALL,"Portuguese");
  int Size;
  int x = 0;
  float xtempo, ytempo;
  clock_t time_req;
  piso *Piso;
  Piso = NULL;
  player Player;
  bg bkg;

  bkg.X0 = 0;
  bkg.X1 = 1366;
  bkg.largura = 1366;

  srand(time(NULL));

  initwindow(telaX,telaY,"",-3,-3);
  
  setbkcolor(RGB(195,195,195));
  
  Player.X = 300, Player.Y = 400;

  Cpiso  = 9;
  Piso = (piso*)realloc(Piso, sizeof(piso)* 12);
  
  for(x = 0; x < Tam; x++){
  Piso[x].X = rand() %telaX+750, telaX;
  Piso[x].Y = rand() %telaY, 100;
  }
  setactivepage(1);
  
  img(Piso[0]);
  
  setvisualpage(1);
  cleardevice();
  
  // abre o arquivo em mp3 e coloca um apelido nele "bk"  \"nome do aquivo.extensão"\ -> ** quantida de vezes q vai tocar  -> 
  mciSendString("open .\\sons\\bk.mp3 type mpegvideo alias bk", NULL, 0, NULL);
  

  PlaySound(NULL, 0,0);
  ALE = 900+ (rand()%101);
  settextstyle(TRIPLEX_FONT, HORIZ_DIR,20);
  intro();
  cleardevice();
  
  while(1){
    setbkcolor(RGB(194,178,128));
    teclado();
  	pausa();
    setbkcolor(RGB(195,195,195));
    mciSendString("play bk notify repeat", NULL, 0 ,0);
    if(GetKeyState(VK_SPACE)&0x80) {
      mciSendString("stop som", NULL, 0, 0);    // p�ra a reprodu��o do alias fundo
      mciSendString("open .\\sons\\sfx3.mp3 type MPEGVideo alias som", NULL, 0, 0); 
      mciSendString("play som", NULL, 0, 0);
    }

    if(pg == 2)pg = 1;else pg = 2;
    setactivepage(pg);
    cleardevice();
/*
    //Fundo da tela
    putimage(bkg.X0, 0, bk, 0);
    putimage(bkg.X1, 0, bk, 0);
    bkg.X0-=4;
    bkg.X1-=4;
    if(bkg.X0 + bkg.largura <= 5)bkg.X0 = bkg.largura;
    if(bkg.X1 + bkg.largura <= 5)bkg.X1 = bkg.largura;
*/
    //desenha os chaos
    for(Cpiso = 0; Cpiso < Tam; Cpiso++) { //Faz o desenhos dos pisos
      putimage(Piso[Cpiso].X, Piso[Cpiso].Y, chon[1], AND_PUT);
      putimage(Piso[Cpiso].X, Piso[Cpiso].Y, chon[0], OR_PUT);
    }

    //desenha o personagem
    putimage(Player.X, Player.Y, mask[i], AND_PUT);
    putimage(Player.X, Player.Y, correr[i], OR_PUT);

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
      if(Piso[Cpiso].X <= -ALE) {
        srand(time(NULL));
        Piso[Cpiso].X = telaX + 500 + rand()%1000;
        Piso[Cpiso].Y = 250+rand() % 519;
      }
    }
    if(GetKeyState(VK_END)&0x80)break;

	}	
  closegraph();
}
