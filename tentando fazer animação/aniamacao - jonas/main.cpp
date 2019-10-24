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

int i = 0, size, Qpiso = 1, Cpiso;
char t = 0;
int pg = 0;
int telaX = 1280, telaY = 700;
bool pulo = true;
int Tam = 6;

void *background;

unsigned char *bmp[6];
unsigned char *mask[6];
unsigned char *chon[2];

struct piso{
  double X;
  double Y;
  double passoX;
  int size;;
};

struct posi{
  double mmmmmm;
};



struct player{
  double X;
  double Y;
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
    setvisualpage(15);
    setactivepage(16);

    //t1
    readimagefile("t1.bmp", 0, 0, 234,224);
    bmp[0] = (unsigned char *)malloc(size);
    mask[0] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[0]);
    getimage(0, 0, 234,224, mask[0]);
    PreparaImg(size, bmp[0], mask[0]);
    
    //t2
    readimagefile("t2.bmp", 0, 0, 234,224);
    bmp[1] = (unsigned char *)malloc(size);
    mask[1] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[1]);
    getimage(0, 0, 234,224, mask[1]);
    PreparaImg(size, bmp[1], mask[1]);
    
    //t3
    readimagefile("t3.bmp", 0, 0, 234,224);
    bmp[2] = (unsigned char *)malloc(size);
    mask[2] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[2]);
    getimage(0, 0, 234,224, mask[2]);
    PreparaImg(size, bmp[2], mask[2]);
	  
    //t4
    readimagefile("t4.bmp", 0, 0, 234,224);
    bmp[3] = (unsigned char *)malloc(size);
    mask[3] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[3]);
    getimage(0, 0, 234,224, mask[3]);
    PreparaImg(size, bmp[3], mask[3]);
    
    //t5
    readimagefile("t5.bmp", 0, 0, 234,224);
    bmp[4] = (unsigned char *)malloc(size);
    mask[4] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[4]);
    getimage(0, 0, 234,224, mask[4]);
    PreparaImg(size, bmp[4], mask[4]);
    
    //t6
    readimagefile("t6.bmp", 0, 0, 234,224);
    bmp[5] = (unsigned char *)malloc(size);
    mask[5] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[5]);
    getimage(0, 0, 234,224, mask[5]);
    PreparaImg(size, bmp[5], mask[5]);

    //pisos
    readimagefile("chon.bmp", 0, 0, 399, 99);
    chon[0] = (unsigned char *)malloc(Piso.size);
    chon[1] = (unsigned char *)malloc(Piso.size);
    getimage(0, 0, 399, 30, chon[0]);
    getimage(0, 0, 399, 30, chon[1]);
    PreparaImg(Piso.size, chon[0], chon[1]);

    cleardevice();
    
}

int main(){
  int x = 0;
  piso *Piso;
  Piso = NULL;
  player Player;
  srand(time(NULL));

  initwindow(telaX,telaY);
  setbkcolor(RGB(100,100,100));
  Player.X = 150, Player.Y = 400;

  Cpiso  =9;
  Piso = (piso*)realloc(Piso, sizeof(piso)* Cpiso);
  
  for(x = 0; x < Tam; x++){
  Piso[x].X = 10;
  Piso[x].Y = rand() %telaY, 100;
  }

  img(Piso[0]);
  char tecla;
  while(tecla != ESC){
    if(pg == 2)pg = 1;else pg = 2;
    setactivepage(pg);
    cleardevice();

    //sprite do player
    putimage(Player.X, Player.Y, mask[i], AND_PUT);
    putimage(Player.X, Player.Y, bmp[i], OR_PUT);

    //sprite do piso
    putimage(Piso[Cpiso].X, Piso[Cpiso].Y, chon[1], AND_PUT);
    putimage(Piso[Cpiso].X, Piso[Cpiso].Y, chon[0], OR_PUT);    

    i++; //progride a animação do Player
    if(i == 5)i = 0; //reseta a animação do player

    for(Cpiso = 0; Cpiso < Tam; Cpiso++) { //Faz o desenhos dos pisos
      putimage(Piso[Cpiso].X, Piso[Cpiso].Y, chon[1], AND_PUT);
      putimage(Piso[Cpiso].X, Piso[Cpiso].Y, chon[0], OR_PUT);
    }
    setvisualpage(pg);

    if(GetKeyState(VK_UP)&0x80&&(pulo))Player.Y -=120;

    //faz verificação do player, se esta no chão ou não
    if(Player.Y <=216)pulo = false; // para pulo
    if(Player.Y>=496)pulo = true; // deixa pular
    delay(80); // FPS

    Player.Y+=40; // famosa gravidade

    if(Player.Y>=telaY-203) Player.Y = telaY-204; //pra n cair do chao
  
    if(GetKeyState(VK_LEFT)&0x80)  Player.X -= 20;
    if(GetKeyState(VK_RIGHT)&0x80) Player.X += 20;
    if(GetKeyState(VK_DOWN)&0x80) printf("%d-",Player.Y);
    
    for(Cpiso = 0; Cpiso < Tam; Cpiso++) {
    Piso[Cpiso].X-=20;// movimentação linear do piso
    }

    // magica do piso dar a volta
      for(Cpiso = 0; Cpiso < Tam; Cpiso++) {
      if(Piso[Cpiso].X<-320) {
        Piso[Cpiso].X = telaX + 420;
        Piso[Cpiso].Y = rand() %telaY, 100;
      }
      }
    //delay para testes
    if(GetKeyState(VK_SPACE)&0x80)delay(900);
    Tam = 6;
	}	
}
