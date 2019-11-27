#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include <time.h>
using namespace std;

#define ESC    	27


unsigned char *T1, *T1M,*T2, *T2M, *T3, *T4;
char tecla;
int pg = 1;

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

struct fisica{
	float x;
	float y;
};

struct coords{
	int x,y;
};

bool onGround(int fy){
	if (fy + 100 <= 480){
		return false;
	}
	else 
	return true;
		
}

void desenho(){
	int Tam = imagesize(0, 0, 49, 49);
	int Tam2 = imagesize(0, 0, 199, 112);
	int Tam3 = imagesize(0,0,1279,133);
	int Tam4 = imagesize(0,0,1999,799);
  	T1 = (unsigned char *)malloc(Tam);
  	T1M = (unsigned char *)malloc(Tam);
  	T2 = (unsigned char *)malloc(Tam2);
  	T2M = (unsigned char *)malloc(Tam2);
  	T3 = (unsigned char *)malloc(Tam3);
  	T4 = (unsigned char *)malloc(Tam4);

  	
  	
  	cleardevice();
  	setactivepage(10);
  	
  	readimagefile("teste.bmp", 0, 0, 49, 49);
  	getimage(0, 0, 49, 49, T1); // captura para o ponteiro P
    getimage(0, 0, 49, 49, T1M);
  	PreparaImg(Tam, T1, T1M);
  	cleardevice();
  	
  	readimagefile("plataforma.bmp", 0, 0, 199, 112);
  	getimage(0, 0, 199, 112, T2); // captura para o ponteiro P
    getimage(0, 0, 199, 112, T2M);
  	PreparaImg(Tam2, T2, T2M);
  	cleardevice();
  	
  	readimagefile("chao.bmp", 0,0,1279,133);
  	getimage(0,0,1279,133, T3); // captura para o ponteiro P
  	cleardevice();
  	
  	readimagefile("background.bmp", 0,0,1999,799);
  	getimage(0,0,1999,799, T4); // captura para o ponteiro P
  	cleardevice();
}

int main()  { 
	initwindow(1920, 800);
	srand(time(0));
	coords plat[20], F, centro[20], B1, B2;
	
	bool onAir = true;
	bool onCollision = false;
	F.x = 10;
	F.y = 10;
	
	B1.x = 0;
//	B2.x = 2000;
	
	//Define localiza��o das plataformas e do centro de cada uma
	for (int i=0;i<10;i++)
      {
       plat[i].x=rand()%1920;
       plat[i].y=rand()%600;
       centro[i].x = plat[i].x + 100;
       centro[i].y = plat[i].y + 55;
      }
	
	int h=300;
    float dx=3,dy=0;
	
	desenho();

  	
  	
 	 while(tecla != ESC) {
    	// Alterna a p�gina de desenho. Explicarei isso na pr�xima aula. 
    	cleardevice();
    	if (pg == 1) pg = 2; else pg=1;
    	setactivepage(pg);
		cleardevice();
		
		setbkcolor(WHITE);
		//Background e sua movimenta��o
//		putimage(B1.x,0,T4, AND_PUT);
//		putimage(B1.x,0,T4, OR_PUT);
//		putimage(B2.x,0,T4, AND_PUT);
//		putimage(B2.x,0,T4, OR_PUT);
//		B1.x += -10;
//		B2.x += -10;
//		
//		if (B1.x == -2000)
//		B1.x = 2001;
//		
//		if (B2.x == -2000)
//		B2.x = 2001;
//		
		
		
		
		
		//Gravidade do personagem
		dx = 3;
		if (onAir){
			dy+=0.5;
    		F.y+=dy;
    }
    	
    	//Movimenta��o do personagem
    	if(GetKeyState(VK_RIGHT)&0x80) F.x += dx;
    	if(GetKeyState(VK_LEFT)&0x80) F.x -= dx;
    	if (F.y>667 || (GetKeyState(VK_SPACE)&0x80))  dy=-10;

		//Cria novas plataformas		
		for (int i=0;i<10;i++){
			if (centro[i].x + 73 < 0){
				plat[i].x= 1920;
				plat[i].y=rand()%600;
				centro[i].x = plat[i].x + 100;
       			centro[i].y = plat[i].y + 55;
			}
		}
		
		//Colis�o com o topo das plataformas
    	for (int i=0;i<10;i++){
     		if ((F.x+50>centro[i].x-73) && (F.x+25<centro[i].x+73) && (F.y+50>centro[i].y-28 ) && (F.y+25<plat[i].y+28) && (dy>0)){
      			dy = 0;
			  }
					
      }
      	
      	//Colis�o com a base das plataformas
      	for (int i=0;i<10;i++){
      		if ((F.y <= centro[i].y+28 && (F.x+50>centro[i].x-73) && (F.x<centro[i].x+73)) && (dy<0) ){
      			dy=1;
			  }
      		
		  }
		
		//Colis�o com a borda da plataforma
		for (int i=0;i<10;i++){
			if ((F.x + 50 > centro[i].x-73) && (F.x < centro[i].x+73) && (F.y > centro[i].y - 28) && (F.y < centro[i].y+28)){
				dx = -3;
				printf("A");
//				printf("X do Cubo: %d\n", F.x);
//				printf("Y do Cubo: %d\n", F.y);
//				printf("X da Plataforma: %d\n", plat[i].x);
//				printf("Y da Plataforma: %d\n", plat[i].y);
			}
			else 
			dx = 3;
		}
		
		
    	//Desenho das plataformas
    	for (int i=0;i<10;i++)
    	{
    		putimage(plat[i].x,plat[i].y,T2M, AND_PUT);
    		putimage(plat[i].x,plat[i].y,T2, OR_PUT);
    	
	    }
	    //Movimenta��o das plataformas para a direita
	    for (int i=0;i<10;i++)
    	{
    		plat[i].x -= 5;
    		centro[i].x -=5;

	    }
	    
		//Desenho do ch�o
		putimage(0,700,T3, AND_PUT);
		putimage(0,700,T3, OR_PUT);		
		putimage(1280,700,T3, AND_PUT);
		putimage(1280,700,T3, OR_PUT);	
		
		//Desenho do personagem
		putimage(F.x, F.y, T1M, AND_PUT);
    	putimage(F.x, F.y, T1, OR_PUT);
    	
    	
  		setvisualpage(pg);
  		delay(50);
  		fflush(stdin);
    	if (kbhit())
    		tecla = getch();
    	
}
		closegraph();	
		free(T1);
		free(T1M);
		free(T2);
		free(T2M);
		return 0; 
}
