//includes{
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
//}

//ints{
  int i = 0, size, Qpiso = 1, Cpiso;
  int Tam = 6;
  int ALE = 0;
  int altura = 224;
  int largura = 234;
  int largurachao = 400;
  int tela = (1366, 768);
  int pg = 0;


//}

//Defines{
  #define ESC    	27
  #define ENTER   13
//}

//Bools{
  bool pulo = true;
  bool pause = true;
  bool passo1 = false, passo2 = false, passo3 = false, amiga = true;

//}

//Unsigned chars{
  unsigned char *correr[6];
  unsigned char *mask[6];
  unsigned char *pular[4];
  unsigned char *maskP[4];
  unsigned char *chon[1];
  unsigned char *chonP[1];
  unsigned char *anubis[1];
  unsigned char *anubisP[1];
//}

//voids{
  void *background;
  void *bk;
  void *menu;
  void *button[3];
//}

char t = 0;
char tecla;

DWORD telaX = GetSystemMetrics(SM_CXSCREEN);
DWORD telaY = GetSystemMetrics(SM_CYSCREEN);

POINT P;
HWND janela;

//Falas{
  char *falas[] = {
    (char*)"Jogar", 
    (char*)"Opcoes", 
    (char*)"Sair"
    };
  char *fintro[] = {
    (char*)"Akil foi um ladrao renomado em vida, mas depois de",
    (char*)"  'um acidente de trabalho' teve que despedir da vida",
    (char*)"     e entrar para o mundo dos mortos, mas para isso ",
    (char*)"     precisaria passar pelo teste de Anubis, onde seu",
    (char*)"      coracao teria que pesar menos que uma pena.",
    (char*)"   Sabendo que nao teria chance de passar pelo teste,",
    (char*)"  Akil arriscou a vida que ja nao tinha mais e arrancou",
    (char*)"  seu coracao das maos de Anubis e fugiu, tentando se",
    (char*)"                  salvar da condenacao eterna",
    };
//}

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
  Piso.size = imagesize(0 ,0 , 399,160);
  int size = imagesize(0, 0, 234,224);
  int sizebk = imagesize(0,0,1366, 768);
  int sizeA = imagesize(0,0,700,712);
  int sizebutton = imagesize(0,0,719, 294);

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
  readimagefile(".\\assets\\plataforma1.bmp", 0, 0, 399,160);
  chon[0] = (unsigned char *)malloc(Piso.size);
  chonP[0] = (unsigned char *)malloc(Piso.size);
  getimage(0, 0, 399,160, chon[0]);
  getimage(0, 0, 399,160, chonP[0]);
  PreparaImg(Piso.size, chon[0], chonP[0]);

  //anubis
  readimagefile(".\\assets\\anubis.bmp", 0, 0, 450, 468);
  anubis[0] = (unsigned char *)malloc(sizeA);
  anubisP[0] = (unsigned char *)malloc(sizeA);
  getimage(0, 0, 450, 468, anubis[0]);
  getimage(0, 0, 450, 468, anubisP[0]);
  PreparaImg(sizeA, anubis[0], anubisP[0]);
  

  readimagefile(".\\assets\\fundo.bmp", 0, 0, telaX, telaY);
  bk = (void *)malloc(sizebk);
  getimage(0, 0, telaX, telaY, bk);

  readimagefile(".\\assets\\menu.bmp", 0, 0, telaX, telaY);
  menu = (void*)malloc(sizebk);
  getimage(0, 0, telaX, telaY, menu);

  
  button[0] = (void *)malloc(sizebutton);
  button[1] = (void *)malloc(sizebutton);
  button[2] = (void *)malloc(sizebutton);
  readimagefile(".\\assets\\play.bmp", 0, 0, 350, 100);
  getimage(0, 0, 350, 100, button[0]);
  readimagefile(".\\assets\\opcoes.bmp", 0, 0, 350, 100);
  getimage(0, 0, 350, 100, button[1]);
  readimagefile(".\\assets\\sair.bmp", 0, 0, 350, 100);
  getimage(0, 0, 350, 100, button[2]);

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
  int buttonX = telaX/3+60;
  int buttonY = telaY/3;
  int buttonY1 = telaY/3 + telaY/12 + 50;
  int buttonY2 = telaY/3 + telaY/12*(2) + 100;
  setbkcolor(RGB(194,178,128));
  if(pause){
    putimage(0, 0, menu, 0);
    putimage(buttonX,buttonY, button[0], 0);
    putimage(buttonX,buttonY1, button[1], 0);
    putimage(buttonX,buttonY2, button[2], 0);
    while(pause){
      teclado();
    }
  }
}

void intro()
{
  int y = telaY/10;
  setbkcolor(RGB(0,0,0));
  cleardevice();
  
  
  delay(800);
  
  setactivepage(1);
  outtextxy(telaX/8, y, fintro[0]);
  setvisualpage(1);
  delay(2000);
  setactivepage(1);
  outtextxy(telaX/8, y*2 , fintro[1]);
  setvisualpage(1);
  delay(2000);
  setactivepage(1);
  outtextxy(telaX/8 ,y*3 , fintro[2]);
  setvisualpage(1);
  delay(2000);
  setactivepage(1);
  outtextxy(telaX/8 ,y*4 , fintro[3]);
  setvisualpage(1);
  delay(2000);
  setactivepage(1);
  outtextxy(telaX/8 ,y*5 , fintro[4]);
  setvisualpage(1);
  delay(2000);
  setactivepage(1);
  outtextxy(telaX/8 ,y*6 , fintro[5]);
  setvisualpage(1);
  delay(2000);
  setactivepage(1);
  outtextxy(telaX/8 ,y*7 , fintro[6]);
  setvisualpage(1);
  delay(2000);
  setactivepage(1);
  outtextxy(telaX/8 ,y*8 , fintro[7]);
  setvisualpage(1);
  delay(2000);
  setactivepage(1);
  outtextxy(telaX/8 ,y*9 , fintro[8]);
  setvisualpage(1);
  delay(3000);
}

void tempoAtual(int Coord, char *Msg, int X, int Y);

int main(){
  setlocale(LC_ALL,"Portuguese");
  int Size;
  int x = 0;
  int YA = 20;
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
  
  setbkcolor(RGB(0,0,0));
  settextstyle(TRIPLEX_FONT, HORIZ_DIR,40);
  outtextxy(telaX/3,telaY/11, (char*)"carregando...");
  
  Player.X = 300, Player.Y = 400;

  Cpiso  = 9;
  Piso = (piso*)realloc(Piso, sizeof(piso)* 12);
  
  for(x = 0; x < Tam; x++){
    Piso[x].X = telaX+ (rand() % 100 * rand() % 100 + rand() % 4000);
    Piso[x].Y = rand() %telaY, 100;
    srand(time(NULL));
    delay(900);
  }
  setactivepage(1);
  
  img(Piso[0]);
  
  setvisualpage(1);
  cleardevice();
  
  // abre o arquivo em mp3 e coloca um apelido nele "bk"  \"nome do aquivo.extensão"\ -> ** quantida de vezes q vai tocar  -> 
  mciSendString("open .\\sons\\bk.mp3 type mpegvideo alias bk", NULL, 0, NULL);
  
  PlaySound(NULL, 0,0);
  ALE = 900+ (rand()%101);
  
  //intro();
  cleardevice();
  
  while(1){
    teclado();
  	pausa();
    setbkcolor(RGB(195,195,195));
    //mciSendString("play bk notify repeat", NULL, 0 ,0);
    /*
    if(GetKeyState(VK_SPACE)&0x80) {
      mciSendString("close som", NULL, 0, 0);    // para a reproducao do alias fundo
      mciSendString("open .\\sons\\sfx3.mp3 type MPEGVideo alias som", NULL, 0, 0); 
      mciSendString("play som", NULL, 0, 0);
    }
    */
    
    if(pg == 2)pg = 1;else pg = 2;
    setactivepage(pg);
    cleardevice();
    
//Fundo da tela{
    putimage(bkg.X1, 0, bk, 0);
    putimage(bkg.X0, 0, bk, 0);
    bkg.X0-=4;
    bkg.X1-=4;
    if(bkg.X0 + bkg.largura < 0)bkg.X0 = bkg.largura;
    if(bkg.X1 + bkg.largura < 0)bkg.X1 = bkg.largura;
//}

//desenha os chaos{
    for(Cpiso = 0; Cpiso < Tam; Cpiso++) { //Faz o desenhos dos pisos
      putimage(Piso[Cpiso].X, Piso[Cpiso].Y, chonP[0], AND_PUT);
      putimage(Piso[Cpiso].X, Piso[Cpiso].Y, chon[0], OR_PUT);
    }
//}    

    /*
    */

//desenha o personagem{
    putimage(Player.X, Player.Y, mask[i], AND_PUT);
    putimage(Player.X, Player.Y, correr[i], OR_PUT);
    putimage(0,YA,anubisP[0], AND_PUT);
    putimage(0,YA,anubis[0], OR_PUT);
    i++; //progride a animação do Player
    if(i == 5)i = 0; //reseta a animação do player
//}


    YA = 100+rand()% 100;    
    setvisualpage(pg);
    delay(80); // FPS

//TeclasGet{
    if(GetKeyState(VK_UP)&0x80&&(pulo))Player.Y -=120;
    if(GetKeyState(VK_LEFT)&0x80)  Player.X -= 20;
    if(GetKeyState(VK_RIGHT)&0x80) Player.X += 20;
    if(GetKeyState(VK_END)&0x80)break;
    if(GetKeyState(VK_SPACE)&0x80) delay(8000);
//}

    for(Cpiso = 0; Cpiso < Tam; Cpiso++)Piso[Cpiso].X-=20;// movimentação linear do piso
    // magica do piso dar a volta
    for(Cpiso = 0; Cpiso < Tam; Cpiso++) {
      if(Piso[Cpiso].X <= -ALE) {
        srand(time(NULL));
        Piso[Cpiso].X = telaX + 500 + rand()%1000;
        Piso[Cpiso].Y = 250+rand() % 519;
      }
    }
    
  }	
  closegraph();
}
