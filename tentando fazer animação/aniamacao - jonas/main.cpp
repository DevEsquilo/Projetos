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

int i = 0, nx_1 = 150, ny_1 = 400, size;
char t = 0;
int pg = 0;
int telaX = 1280, telaY = 700;
bool pulo = true;

void *background;


unsigned char *bmp[6];
unsigned char *mask[6];
 


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

void img()
{
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
    cleardevice();
    printf("t1 %d\n", getactivepage());
    
    //t2
    readimagefile("t2.bmp", 0, 0, 234,224);
    bmp[1] = (unsigned char *)malloc(size);
    mask[1] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[1]);
    getimage(0, 0, 234,224, mask[1]);
    PreparaImg(size, bmp[1], mask[1]);
    cleardevice();
    printf("t2 %d\n", getactivepage());
    
    //t3
    readimagefile("t3.bmp", 0, 0, 234,224);
    bmp[2] = (unsigned char *)malloc(size);
    mask[2] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[2]);
    getimage(0, 0, 234,224, mask[2]);
    PreparaImg(size, bmp[2], mask[2]);
    cleardevice();
	  printf("t3 %d\n", getactivepage());
    //t4
    readimagefile("t4.bmp", 0, 0, 234,224);
    bmp[3] = (unsigned char *)malloc(size);
    mask[3] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[3]);
    getimage(0, 0, 234,224, mask[3]);
    PreparaImg(size, bmp[3], mask[3]);
    cleardevice();
    printf("t4 %d\n", getactivepage());
    //t5
    readimagefile("t5.bmp", 0, 0, 234,224);
    bmp[4] = (unsigned char *)malloc(size);
    mask[4] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[4]);
    getimage(0, 0, 234,224, mask[4]);
    PreparaImg(size, bmp[4], mask[4]);
    cleardevice();
    printf("t5 %d\n", getactivepage());
    //t6
    readimagefile("t6.bmp", 0, 0, 234,224);
    bmp[5] = (unsigned char *)malloc(size);
    mask[5] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, bmp[5]);
    getimage(0, 0, 234,224, mask[5]);
    PreparaImg(size, bmp[5], mask[5]);
    cleardevice();
    printf("t6 %d\n", getactivepage());
}


int main(){
	
  initwindow(telaX,telaY);
  setbkcolor(RGB(100,150,100));
  img();
  
    while(true){
      if(pg == 2)pg = 1;else pg = 2;
      setactivepage(pg);
      cleardevice();
      putimage(nx_1, ny_1, mask[i], AND_PUT);
      putimage(nx_1, ny_1, bmp[i], OR_PUT);    
      i++;
      lineto(0,400);
      if(i == 5)i = 0;
      
      setvisualpage(pg);
      if(GetKeyState(VK_UP)&0x80&&(pulo))ny_1 -=120;
	  if(ny_1 <=216) pulo = false;
	  if(ny_1>=496)pulo = true;//else pulo = false; // 496
      delay(80);
      ny_1+=40;
      if(ny_1>=telaY-203) ny_1 = telaY-204; //pra n cair do chao
	  
      if(GetKeyState(VK_LEFT)&0x80)  nx_1 -= 20;
      if(GetKeyState(VK_RIGHT)&0x80) nx_1 += 20;
      if(GetKeyState(VK_DOWN)&0x80) printf("%d-",ny_1);
    
      
	  
      //chao 234-telaY;
	}	
}
