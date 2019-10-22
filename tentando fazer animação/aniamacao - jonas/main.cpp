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

int i = 0, size;
char t = 0;
int pg = 0;
int telaX = 1280, telaY = 700;
bool pulo = true;

void *background;


unsigned char *bmp[6];
unsigned char *mask[6];
unsigned char *chon[2];


struct piso{
  double X;
  double Y;
  double passoX;
  int size;
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

void img(piso piso)
{

    piso.size = imagesize(0 ,0 ,399, 99);
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
    chon[0] = (unsigned char *)malloc(piso.size);
    chon[1] = (unsigned char *)malloc(piso.size);
    getimage(0, 0, 399, 99, chon[0]);
    getimage(0, 0, 399, 99, chon[1]);
    PreparaImg(piso.size, chon[0], chon[1]);




    cleardevice();
    
}


int main(){
  piso Piso;
  player Player;
  srand(time(NULL));
  Piso.X = telaX + 420;
  Piso.Y = rand() %telaY, 100;
  Player.X = 150, Player.Y = 400;
  
  initwindow(telaX,telaY);
  setbkcolor(RGB(100,100,100));
  img(Piso);
  
  while(true){
    if(pg == 2)pg = 1;else pg = 2;
    setactivepage(pg);
    cleardevice();
    putimage(Player.X, Player.Y, mask[i], AND_PUT);
    putimage(Player.X, Player.Y, bmp[i], OR_PUT);

    putimage(Piso.X, Piso.Y, chon[1], AND_PUT);
    putimage(Piso.X, Piso.Y, chon[0], OR_PUT);    
    i++;
    lineto(0,400);
    if(i == 5)i = 0;
    
    setvisualpage(pg);

    if(GetKeyState(VK_UP)&0x80&&(pulo))Player.Y -=120;

    if(Player.Y <=216) pulo = false;
    if(Player.Y>=496)pulo = true;//else pulo = false; // 496

    if(Player.Y>=Piso.Y-100 && Player.Y<=Piso.Y+100) Player.Y +=10; //cabeçada no piso

    delay(80);

    Player.Y+=40;

    if(Player.Y>=telaY-203) Player.Y = telaY-204; //pra n cair do chao
  
    
    if(Player.Y+224<=Piso.Y+224 && Player.X+234>=Piso.X ){
      Player.Y = Piso.Y-200; // segura o player no piso

    } 

    if(GetKeyState(VK_LEFT)&0x80)  Player.X -= 20;
    if(GetKeyState(VK_RIGHT)&0x80) Player.X += 20;
    if(GetKeyState(VK_DOWN)&0x80) printf("%d-",Player.Y);
    Piso.X-=20;
    if(Piso.X<-320) {
      Piso.X = telaX + 420;
      Piso.Y = rand() %telaY, 100;



      
    }
    if(GetKeyState(VK_SPACE)&0x80)  delay(500);
	}	
}
