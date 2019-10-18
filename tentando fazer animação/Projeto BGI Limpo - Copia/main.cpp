#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include <time.h>
using namespace std;

#define ESC    	27

char tecla = 0;
int pg = 0;

unsigned char *T1, *T1M,*T2,*T2M,*T3, *T3M,*T4, *T4M,*T5, *T5M,*T6, *T6M;

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

unsigned char* getImageByIndex(int index){
	switch(index){
		case 0:
			return T1;
			break;
		case 1:
			return T2;
			break;
		case 2:
			return T3;
			break;
		case 3:
			return T4;
			break;
		case 4:
			return T5;
			break;
		case 5:
			return T6;
			break;
	}
}

unsigned char* getMaskByIndex(int index){
	switch(index){
		case 0:
			return T1M;
			break;
		case 1:
			return T2M;
			break;
		case 2:
			return T3M;
			break;
		case 3:
			return T4M;
			break;
		case 4:
			return T5M;
			break;
		case 5:
			return T6M;
			break;
	}
}

int main()  { 
initwindow(700, 600, "Imagens", 200, 20);
setbkcolor(RGB(100,150,100));

char tecla = 0;

int Tam,x,y;

int width = 234;
int height = 224;
  
  Tam = imagesize(0, 0, width, height);
  T1 = (unsigned char *)malloc(Tam);
  T1M = (unsigned char *)malloc(Tam);
  T2 = (unsigned char *)malloc(Tam);
  T2M = (unsigned char *)malloc(Tam);
  T3 = (unsigned char *)malloc(Tam);
  T3M = (unsigned char *)malloc(Tam);
  T4 = (unsigned char *)malloc(Tam);
  T4M = (unsigned char *)malloc(Tam);
  T5 = (unsigned char *)malloc(Tam);
  T5M = (unsigned char *)malloc(Tam);
  T6 = (unsigned char *)malloc(Tam);
  T6M = (unsigned char *)malloc(Tam);

  
  cleardevice();
  
  	int xx = 0;
  	int yy = 0;
  	
  	int bpm = 1;
  	for(xx = 0; xx < 3; xx++){
  		for(yy = 0; yy < 2; yy++){
  			char num[((sizeof(bpm) * CHAR_BIT) + 2) /3 + 2];
  			sprintf(num, "%d", bpm);
  			
  			
  			char result[6];
  			strcpy(result, "t");
  			strcat(result, num);
  			strcat(result, ".bpm");
  			
  			printf(result);
  			
  			readimagefile(result, xx*width, yy*height, (xx+1)*width, (yy+1)*height);

  			bpm++;
		}
	}
	
	bpm = 1;
  	for(xx = 0; xx < 3; xx++){
  		for(yy = 0; yy < 2; yy++){
  			getimage(xx*width, yy*height, (xx+1)*width, (yy+1)*height, getImageByIndex(bpm-1));
    		getimage(xx*width, yy*height, (xx+1)*width, (yy+1)*height, getMaskByIndex(bpm-1));
  			
  			bpm++;
  		}
  	}
  
  /*
  	readimagefile("t1.bmp", 0, 0, 234, 224);
	readimagefile("t2.bmp", 235, 0, 470, 224);
	readimagefile("t3.bmp", 471, 0, 705, 224);
	
	readimagefile("t4.bmp", 0, 225, 234, 449);
	readimagefile("t5.bmp", 235, 225, 470, 449);
	readimagefile("t6.bmp", 471, 225, 705, 449);
    
    getimage(0, 0, 234, 224, T1); // captura para o ponteiro P
    getimage(0, 0, 234, 224, T1M);
    
	getimage(235, 0, 469, 224,T2);
	getimage(235, 0, 469, 224,T2M); 
	
	getimage(470, 0, 704, 224, T3);
	getimage(470, 0, 704, 224, T3M); 
	
	getimage(0, 225, 234, 449, T4);
	getimage(0, 225, 234, 449, T4M); 
	
	getimage(235, 225, 469, 449, T5);
	getimage(235, 225, 469, 449, T5M); 
	
	getimage(470, 225, 704, 449, T6);
	getimage(470, 225, 704, 449, T6M);  
	
	*/
    
    PreparaImg(Tam, T1, T1M);
    PreparaImg(Tam, T2, T2M);
    PreparaImg(Tam, T3, T3M);
    PreparaImg(Tam, T4, T4M);
    PreparaImg(Tam, T5, T5M);
    PreparaImg(Tam, T6, T6M);
    
	x = y = 300;
	
	/*
	setactivepage(1);
	putimage(x, y, T1M, AND_PUT);
    putimage(x, y, T1, OR_PUT);
    setactivepage(2);
    putimage(x, y, T2M, AND_PUT);
    putimage(x, y, T2, OR_PUT);
    setactivepage(3);
    putimage(x, y, T3M, AND_PUT);
    putimage(x, y, T3, OR_PUT);
    setactivepage(4);
    putimage(x, y, T4M, AND_PUT);
    putimage(x, y, T4, OR_PUT);
    setactivepage(5);
    putimage(x, y, T5M, AND_PUT);
    putimage(x, y, T5, OR_PUT);
    setactivepage(6);
    putimage(x, y, T6M, AND_PUT);
    putimage(x, y, T6, OR_PUT);
    
    */
    
    //delay(10000);   

int frame = 0;

while(tecla != ESC) {
	if(pg == 0) pg = 1;
	else pg = 0;
	cleardevice();
	setvisualpage(0);
	
	
    fflush(stdin);
    if (kbhit()){
        tecla = getch();
    }
    
    frame++;
    frame = frame%6;
    
    printf("%d", frame);
    
    putimage(x, y, getMaskByIndex(frame), AND_PUT);
    putimage(x, y, getImageByIndex(frame), OR_PUT);
    
    /*
    if(pg == 1){
    	pg = 2;
	}
	else if(pg == 2){
		pg = 3;
	}
	else if(pg == 3){
		pg = 4;
	}
	else if(pg == 4){
		pg = 5;
	}
	else if(pg == 5){
		pg = 6;
	}
	else{
		pg = 1;
	}
	printf("%d",pg);
	*/
	
	
	
    delay(1000);   
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
