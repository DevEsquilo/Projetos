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

struct coords{
	int x,y;
};
coords plat[20], F, B1, B2, espaco;

void desenho(){
	int Tam = imagesize(0, 0, 49, 49);
	int Tam2 = imagesize(0, 0, 229, 99);
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
  	
  	readimagefile("plataforma_rect.bmp", 0, 0, 229, 99);
  	getimage(0, 0, 229, 99, T2); // captura para o ponteiro P
  	cleardevice();
  	
  	readimagefile("chao.bmp", 0,0,1279,133);
  	getimage(0,0,1279,133, T3); // captura para o ponteiro P
  	cleardevice();
  	
  	readimagefile("background.bmp", 0,0,1999,799);
  	getimage(0,0,1999,799, T4); // captura para o ponteiro P
  	cleardevice();
}

void criaPlat() {
	
//	for (int i=0;i<10;i++){
//		plat[i].x= 200 + rand()%1920;
//    	plat[i].y=50 +rand()%600;
//      }
//    for (int i=0;i<10;i++){
//    	for (int j=0;j<10;j++){
//    		if (i==j) j++;
//			if (((plat[j].x <= plat[i].x <= plat[j].x + 230) && (plat[j].y <= plat[i].y <= plat[j].y +100)) || 
//			((plat[j].x <= plat[i].x+230 <= plat[j].x + 230) && (plat[j].y <= plat[i].y+100<= plat[j].y +100)) ||
//			((plat[j].x <= plat[i].x <= plat[j].x + 230) && (plat[j].y <= plat[i].y+100<= plat[j].y +100)) ||
//			((plat[j].x <= plat[i].x+230 <= plat[j].x + 230) && (plat[j].y <= plat[i].y <= plat[j].y +100))){
//				plat[i].x=200 + rand()%1920;
//    			plat[i].y=50 + rand()%600;
//			}
//		}
//		
//	}
	espaco.y = 75 ;
	for (int i=0;i<10;i++){
		plat[i].x = 200 + rand()%1700;;
		plat[i].y = espaco.y;
		espaco.y = espaco.y + 175;
		if (espaco.y >= 750) espaco.y = 75;
	}
}

int main()  { 
	initwindow(1920, 800);
	srand(time(0));
	bool onAir = false;
	bool onTop = false;
	
	
	F.x = 150;
	F.y = 660;
	
	B1.x = 0;
	B2.x = 1900;
	
	//Define localização das plataformas
	criaPlat();

	
	int h=300;
    float dx=5,dy=0;
	
	desenho();

  	
  	espaco.y = 75;
	espaco.x = 75;	
 	 while(tecla != ESC) {
    	
    	if (pg == 1) pg = 2; else pg=1;
    	setactivepage(pg);
		cleardevice();
		
		setbkcolor(WHITE);
		
		//Background e sua movimentação
		putimage(B1.x,0,T4, AND_PUT);
		putimage(B1.x,0,T4, OR_PUT);
//		putimage(B2.x,0,T4, AND_PUT);
//		putimage(B2.x,0,T4, OR_PUT);
//		B1.x += -10;
//		B2.x += -10;
//		printf("%d", B1.x);
//		if (B1.x <= -2000){
//			B1.x = 1900;
//		}
//
//		if (B2.x <= -2000){
//			B2.x = 1900;
//		}
		
		
		
		
		
		
		//Gravidade do personagem		
		dy+=1;
    	F.y+=dy;
    	
    	if (F.y >= 660){
    		F.y = 660;
    		onAir = false;
		}
    	
    	
    	if(F.y <= 470 && onTop == false)
    		onAir = true;
    		
    	//Movimentação do personagem
//    	if(GetKeyState(VK_RIGHT)&0x80 && F.x < 200) F.x += dx;
//    	if(GetKeyState(VK_LEFT)&0x80 && F.x > 100) F.x -= dx;
    	if (GetKeyState(VK_SPACE)&0x80 && onAir == false){
    		dy = -20;
    		onTop = false;
			onAir = true;
		} 
		
		
		//Cria novas plataformas
		for (int i=0;i<10;i++){
			if (plat[i].x + 230 <= 0){
					plat[i].x = 1920 + (rand()%500) ;
					plat[i].y = espaco.y;
					espaco.y = espaco.y + 175;
					if (espaco.y >= 750) espaco.y = 75;
			}
		}
		
		//Colisão com o topo das plataformas
    	for (int i=0;i<10;i++){
     		if ((F.x+45>plat[i].x) && (F.x+15<plat[i].x+230) && (F.y+50>plat[i].y ) && (F.y+25<plat[i].y+100) && (dy>0)){
      			F.y = plat[i].y -50;
      			dy = 0;
      			onAir = false;
      			onTop = true;
      			
			  }
					
      }
      	
      	//Colisão com a base das plataformas
      	for (int i=0;i<10;i++){
      		if ((F.y <= plat[i].y+100 && (F.x+50>=plat[i].x) && (F.x<=plat[i].x+230)) && (F.y+50>=plat[i].y) && (dy<0) ){
      			
			  }
      		
		  }
		
		//Colisão com a borda da plataforma
		for (int i=0;i<10;i++){
			if ((F.x + 50 > plat[i].x) && (F.x < plat[i].x+230) && (F.y > plat[i].y) && (F.y < plat[i].y+100)){
				F.x = plat[i].x - 50;
			}

		}
		
//		for (int i=0;i<10;i++){
//			if ((F.x + 50 > plat[i].x) && (F.x < plat[i].x+230) && (F.y > plat[i].y) && (F.y < plat[i].y+100) && (GetKeyState(VK_LEFT)&0x80)){
//				F.x = plat[i].x + 230;
//			}
//
//		}
		
		
		
    	//Desenho das plataformas
    	for (int i=0;i<10;i++)	
    	{
    		putimage(plat[i].x,plat[i].y,T2, AND_PUT);
    		putimage(plat[i].x,plat[i].y,T2, OR_PUT);
    	
	    }
	    //Movimentação das plataformas para a direita
	    for (int i=0;i<10;i++)
    	{
    		plat[i].x = plat[i].x - 5;

	    }
	    

		//Desenho do chão
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
		free(T3);
		free(T4);
		return 0; 
}
