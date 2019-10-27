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

int i = 0, nx_1 = 150, ny_1 = 395, size, passo = 10;
char t = 0;
int pg = 0;

float velx = 0,vely = 0, grav = 0.5;
bool onGround = true;

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
	int size = imagesize(0, 0, 234,204);
    setvisualpage(15);
    setactivepage(16);
    //t1
    
    readimagefile("t1.bmp", 0, 0, 234,204);
    bmp[0] = (unsigned char *)malloc(size);
    mask[0] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,204, bmp[0]);
    getimage(0, 0, 234,204, mask[0]);
    PreparaImg(size, bmp[0], mask[0]);
    cleardevice();
    
    
    //t2
    readimagefile("t2.bmp", 0, 0, 234,204);
    bmp[1] = (unsigned char *)malloc(size);
    mask[1] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,204, bmp[1]);
    getimage(0, 0, 234,204, mask[1]);
    PreparaImg(size, bmp[1], mask[1]);
    cleardevice();
    
    
    //t3
    readimagefile("t3.bmp", 0, 0, 234,204);
    bmp[2] = (unsigned char *)malloc(size);
    mask[2] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,204, bmp[2]);
    getimage(0, 0, 234,204, mask[2]);
    PreparaImg(size, bmp[2], mask[2]);
    cleardevice();
	
    //t4
    readimagefile("t4.bmp", 0, 0, 234,204);
    bmp[3] = (unsigned char *)malloc(size);
    mask[3] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,204, bmp[3]);
    getimage(0, 0, 234,204, mask[3]);
    PreparaImg(size, bmp[3], mask[3]);
    cleardevice();
    
    //t5
    readimagefile("t5.bmp", 0, 0, 234,204);
    bmp[4] = (unsigned char *)malloc(size);
    mask[4] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,204, bmp[4]);
    getimage(0, 0, 234,204, mask[4]);
    PreparaImg(size, bmp[4], mask[4]);
    cleardevice();
    
    //t6
    readimagefile("t6.bmp", 0, 0, 234,204);
    bmp[5] = (unsigned char *)malloc(size);
    mask[5] = (unsigned char *)malloc(size);
    getimage(0, 0, 234,204, bmp[5]);
    getimage(0, 0, 234,204, mask[5]);
    PreparaImg(size, bmp[5], mask[5]);
    cleardevice();
    
}
void startJump(){
	
	if(onGround){
		vely = -20.0;
		onGround = false;
	}
}

void endJump(){
	
	if (vely < -10){
		vely = -10;
	}
}

void update(){
	
	vely += grav;
	ny_1 += vely;
	
	if(ny_1 > 395.0)
    {
        ny_1 = 395.0;
        vely = 0.0;
        onGround = true;
    }

}

int main(){
	
    initwindow(700, 700);
    setbkcolor(RGB(100,150,100));
    img();
    
    while(true){
      setactivepage(0);
      cleardevice();
      setfillstyle(1,1);
      bar(0,600,700,700);
      putimage(nx_1, ny_1, mask[i], AND_PUT);
      putimage(nx_1, ny_1, bmp[i], OR_PUT);
      if (i <= 4){
      	i++;
	  }
	  else
	  i = 0;
	  
	  delay(100);
	  
      if(GetKeyState(VK_LEFT)&0x80)  nx_1 -= passo;
      if(GetKeyState(VK_RIGHT)&0x80) nx_1 += passo;
      if(GetKeyState(VK_UP)&0x80)  ny_1 -= passo;
      if(GetKeyState(VK_DOWN)&0x80) ny_1 += passo;
      if(GetKeyState(VK_SPACE)&0x80){
      	startJump();
      	update();
      	endJump();
      	
	  } 
      
    }   
}
