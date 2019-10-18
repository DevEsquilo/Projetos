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

int i, nx_1 = 150, ny_1 = 400, size, fx = 0, fy = -1320;
char t = 0;

void *background;
unsigned char *p0;
unsigned char *p1;
unsigned char *p2;
unsigned char *p3;
unsigned char *p4;
unsigned char *p5;
unsigned char *p6;
unsigned char *p7;
unsigned char *p8;
unsigned char *p9;
unsigned char *p10;

bool jogando = true;
bool on = false, on1 = false;
void PreparaImg(int Tam, unsigned char *Img, unsigned char *Msk) {
// Tam é o tamanho dos ponteiros da imagem e da máscara
// Img é o ponteiro que aponta para o vetor que contém a imagem capturada com getimage(..)
// Msk é o ponteiro que será transformado em máscara
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
    setvisualpage(15);
    setactivepage(16);

    //Mascara t1
    readimagefile("t1M.bmp", 0, 0, 235,225);
    size = imagesize(0, 0, 235,225);
    p1 = (unsigned char *)malloc(size);
    getimage(0, 0, 235,225, p1);
    cleardevice();

    //t1
    readimagefile("t1.bmp", 0, 0, 235,225);
    size = imagesize(0, 0, 235,225);
    p2 = (unsigned char *)malloc(size);
    getimage(0, 0, 235,225, p2);
    cleardevice();
    
    //Mascara t2
    readimagefile("t2M.bmp", 0, 0, 234,224);
    size = imagesize(0, 0, 234,224);
    p3 = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, p2);
    cleardevice();
    
    //t2
    readimagefile("t2.bmp", 0, 0, 234,224);
    size = imagesize(0, 0, 234,224);
    p4 = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, p3);
    cleardevice();
    
    //Mascara t3
    readimagefile("t3M.bmp", 0, 0, 234,224);
    size = imagesize(0, 0, 234,224);
    p5 = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, p2);
    cleardevice();
    
    //t3
    readimagefile("t3.bmp", 0, 0, 234,224);
    size = imagesize(0, 0, 234,224);
    p6 = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, p3);
    cleardevice();
    
    //Mascara t4
    readimagefile("t4M.bmp", 0, 0, 234,224);
    size = imagesize(0, 0, 234,224);
    p7 = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, p2);
    cleardevice();
    
    //t4
    readimagefile("t4.bmp", 0, 0, 234,224);
    size = imagesize(0, 0, 234,224);
    p8 = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, p3);
    cleardevice();
    
    //Mascara t5
    readimagefile("t5M.bmp", 0, 0, 234,224);
    size = imagesize(0, 0, 234,224);
    p9 = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, p2);
    cleardevice();
    
    //t5
    readimagefile("t5.bmp", 0, 0, 234,224);
    size = imagesize(0, 0, 234,224);
    p8 = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, p3);
    cleardevice();
    
    //Mascara t6
    readimagefile("t6M.bmp", 0, 0, 234,224);
    size = imagesize(0, 0, 234,224);
    p9 = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, p2);
    cleardevice();
    
    //t6
    readimagefile("t6.bmp", 0, 0, 234,224);
    size = imagesize(0, 0, 234,224);
    p10 = (unsigned char *)malloc(size);
    getimage(0, 0, 234,224, p3);
    cleardevice();
    
}

void first_background()
{
    setvisualpage(15);
    setactivepage(16);
    readimagefile("p.bmp", 0, 0, 1079, 1919);
    size = imagesize(0, 0, 1079, 1919);
    background = malloc(size);
    getimage(0, 0, 1079, 1919, background);
}

void game()
{
    //putimage(fx, fy, background, 0);           //Exibe a imagem de fundo.
    putimage(nx_1, ny_1, p1, 3);               //Exibe a m�scara da primeira nave.
    putimage(nx_1, ny_1, p2, 2);               //Exibe a imagem da primeira nave.

    putimage(nx_1, ny_1, p4, 3);
    putimage(nx_1, ny_1, p3, 2);

    putimage(nx_1, ny_1, p6, 3);
    putimage(nx_1, ny_1, p5, 2);

    putimage(nx_1, ny_1, p8, 3);
    putimage(nx_1, ny_1, p7, 2);

    putimage(nx_1, ny_1, p10, 2); 
    putimage(nx_1, ny_1, p9, 3);

}
int main(){
    //
    initwindow(1080, 1920);
    setbkcolor(RGB(100,150,100));
    //first_background();
    closegraph();
    delay(100);
    initwindow(800, 600, "Waifu Wars !");
    
    img();  
    
    setactivepage(15);
    
    first_background();
    closegraph();
    initwindow(800, 600, "Waifu Wars !");
    img();
    setactivepage(15);


    //putimage(fx, fy, background, 0);           //Exibe a imagem de fundo.
    
    putimage(0,0, p1, 3);               //Exibe a m�scara da primeira nave.
    putimage(0,0, p2, 2);
/*
    putimage(0,0, p3, 3);               //Exibe a m�scara da primeira nave.
    putimage(0,0, p4, 2);

    putimage(0,0, p6, 3);               //Exibe a m�scara da primeira nave.
    putimage(0,0, p5, 2);
    */
    

    setvisualpage(15);
    getch();
    if(GetKeyState(ENTER)&0x80)
    {
          on = true;
          on1 = true;
          //cliente = true;
    }
    while(on)
    {
        if(i ==2 ) i = 1; else i = 2;
        setactivepage(i);
        game();
        setvisualpage(i);
        if(GetKeyState(VK_LEFT)&0x80)  nx_1 -= 1;
        if(GetKeyState(VK_RIGHT)&0x80) nx_1 += 1;
        if(GetKeyState(VK_UP)&0x80)  ny_1 -= 1;
        if(GetKeyState(VK_DOWN)&0x80) ny_1 += 1;
    }
}
