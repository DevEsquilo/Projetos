//Programa realizado por Andre Duarte Mergulhao Filho, Gabriel Obmerga
//Joao Victor Cabocolino Alves, Jonas Goncalves Portes e Thatyanne Correa Gomes
//Grupo 3
#include<graphics.h>
#include<stdio.h>
#include<conio.h>

#define ESC    	27

int visual(int corn){
	setcolor(RGB(255,0,0));
	setlinestyle(1,0,25);
	moveto(50,50);lineto(650,50);
	
	moveto(145,150);lineto(565,150);
	
	moveto(245,250);lineto(465,250);
	
	moveto(50,350);lineto(240,350);
	
	moveto(470,350);lineto(650,350);
	
	moveto(245,450);lineto(465,450);
	
	moveto(145,550);lineto(565,550);
	
	moveto(50,650);lineto(650,650);
	
//Barras_Externas_Verticais

	moveto(50,50);lineto(50,650);
	
	moveto(145,150);lineto(145,550);
	
	moveto(245,250);lineto(245,450);
	
	moveto(350,50);lineto(350,250);
	
	moveto(350,450);lineto(350,650);
	
	moveto(465,250);lineto(465,450);
	
	moveto(565,150);lineto(565,550);
	
	moveto(650,50);lineto(650,650);
	
//Circulos_Externos

    setfillstyle(1, RGB(255,0,0));
    setcolor(RGB(255,0,0));
    setlinestyle(1, 0, 6);
	    
	fillellipse(50, 50, 33, 33);
    fillellipse(350, 50, 33, 33);
	fillellipse(650, 50, 33, 33);
	
	fillellipse(145, 150, 33, 33);
	fillellipse(350, 150, 33, 33);
	fillellipse(565, 150, 33, 33);
    
    fillellipse(245, 250, 33, 33);
	fillellipse(350, 250, 33, 33);
	fillellipse(465, 250, 33, 33);
    
    fillellipse(50, 350, 33, 33);
    fillellipse(145, 350, 33, 33);
    fillellipse(245, 350, 33, 33);
	fillellipse(465, 350, 33, 33);
    fillellipse(565, 350, 33, 33);
    fillellipse(650, 350, 33, 33);

	fillellipse(245, 450, 33, 33);
	fillellipse(350, 450, 33, 33);
	fillellipse(465, 450, 33, 33);
    
	fillellipse(145, 550, 33, 33);
	fillellipse(350, 550, 33, 33);
	fillellipse(565, 550, 33, 33);

	fillellipse(50, 650, 33, 33);
    fillellipse(350, 650, 33, 33);
    fillellipse(650, 650, 33, 33);
    
//Barras_Internas_Horizontais

	setcolor(RGB(153,1,153));
	setlinestyle(1,0,12);
	moveto(80,50);lineto(320,50);
	moveto(380,50);lineto(620,50);
	
	moveto(175,150);lineto(320,150);
	moveto(380,150);lineto(535,150);
	
	moveto(275,250);lineto(320,250);
	moveto(380,250);lineto(435,250);
	
	moveto(80,350);lineto(120,350);
	moveto(175,350);lineto(215,350);
	moveto(497,350);lineto(535,350);
	moveto(595,350);lineto(620,350);
	
	moveto(275,450);lineto(320,450);
	moveto(380,450);lineto(435,450);
	
	moveto(175,550);lineto(320,550);
	moveto(380,550);lineto(535,550);
	
	moveto(80,650);lineto(320,650);
	moveto(380,650);lineto(620,650);
	
//Barras_Internas_Verticais

	moveto(50,80);lineto(50,320);
	moveto(50,380);lineto(50,620);
	
	moveto(145,180);lineto(145,325);
	moveto(145,377);lineto(145,520);
	
	moveto(245,280);lineto(245,320);
	moveto(245,380);lineto(245,420);
	
	moveto(350,80);lineto(350,120);
	moveto(350,180);lineto(350,220);
	moveto(350,480);lineto(350,520);
	moveto(350,580);lineto(350,620);
	
	moveto(465,280);lineto(465,320);
	moveto(465,380);lineto(465,420);
	
	moveto(565,180);lineto(565,325);
	moveto(565,380);lineto(565,525);
	
	moveto(650,80);lineto(650,320);
	moveto(650,380);lineto(650,620);
	
///Circulos_Internos

    setcolor(RGB(153,1,153));
    setlinestyle(1, 0, 6);
	
	circle(50, 50, 25);
	circle(350, 50, 25);
	circle(650, 50, 25);
	
	circle(145, 150, 25);
	circle(350, 150, 25);
	circle(565, 150, 25);
	
	circle(245, 250, 25);
	circle(350, 250, 25);
	circle(465, 250, 25);
	
	circle(50, 350, 25);
	circle(145, 350, 25);
	circle(245, 350, 25);    
	circle(465, 350, 25);
	circle(565, 350, 25);
	circle(650, 350, 25);
	
	circle(245, 450, 25);
	circle(350, 450, 25);
	circle(465, 450, 25);
	
	circle(145, 550, 25);
	circle(350, 550, 25);
	circle(565, 550, 25);
	
	circle(50, 650, 25);
	circle(350, 650, 25);
	circle(650, 650, 25);
	
	if (corn == 1){
		setfillstyle(1, RGB(255,255,255));
		setcolor(RGB(255,255,255));
		setlinestyle(1, 0, 6);
	
		fillellipse(50, 50, 20, 20);
    	fillellipse(350, 50, 20, 20);
    	fillellipse(350, 250, 20, 20);
		fillellipse(465, 350, 20, 20);
		fillellipse(565, 550, 20, 20);
	}
	if (corn == 2){
		setfillstyle(1, RGB(0,0,0));
		setcolor(RGB(0,0,0));
		setlinestyle(1, 0, 6);
		
		fillellipse(50, 350, 20, 20);
		fillellipse(145, 350, 20, 20);
		fillellipse(50, 650, 20, 20);
		fillellipse(650, 650, 20, 20);
		fillellipse(350, 150, 20, 20);
		fillellipse(465, 450, 20, 20);
		fillellipse(145, 550, 20, 20);
		
	}
	if (corn == 3){
		setfillstyle(1, RGB(255,255,255));
		setcolor(RGB(255,255,255));
		setlinestyle(1, 0, 6);
	
		fillellipse(50, 50, 20, 20);
    	fillellipse(350, 50, 20, 20);
    	fillellipse(350, 250, 20, 20);
		fillellipse(465, 350, 20, 20);
		fillellipse(565, 550, 20, 20);
		
		setfillstyle(1, RGB(0,0,0));
		setcolor(RGB(0,0,0));
		setlinestyle(1, 0, 6);
		
		fillellipse(50, 350, 20, 20);
		fillellipse(145, 350, 20, 20);
		fillellipse(50, 650, 20, 20);
		fillellipse(650, 650, 20, 20);
		fillellipse(350, 150, 20, 20);
		fillellipse(465, 450, 20, 20);
		fillellipse(145, 550, 20, 20);
	}
	if (corn == 4 || corn == 0) {
		setfillstyle(1, RGB(255,0,0));
    	setcolor(RGB(255,0,0));
    	setlinestyle(1, 0, 6);
    	
    	fillellipse(50, 350, 20, 20);
		fillellipse(145, 350, 20, 20);
		fillellipse(50, 650, 20, 20);
		fillellipse(650, 650, 20, 20);
		fillellipse(350, 150, 20, 20);
		fillellipse(465, 450, 20, 20);
		fillellipse(145, 550, 20, 20);
		
		fillellipse(50, 50, 20, 20);
    	fillellipse(350, 50, 20, 20);
    	fillellipse(350, 250, 20, 20);
		fillellipse(465, 350, 20, 20);
		fillellipse(565, 550, 20, 20);
	}
}


int main()  {     
  int pg;
  char tecla = 0;
  int z, corn = 0;

  initwindow(700,700,"Trilha",100,0);	
  setbkcolor(RGB(153,1,153));

//Aperte a tecla "1" para mostrar as pecas brancas;
//Aperte a tecla "2" para mostrar as pecas pretas;
//Aperte a tecla "3" para mostrar ambas as pecas;
//Aperte a tecla "4" para apagar as pecas;

  outtextxy(200,200,"Aperte a tecla '1' para mostrar as pecas brancas.");
  outtextxy(200,250,"Aperte a tecla '2' para mostrar as pecas pretas.");
  outtextxy(200,300,"Aperte a tecla '3' para mostrar ambas as pecas.");
  outtextxy(200,350,"Aperte a tecla '4' para apagar as pecas.");
  outtextxy(200,400,"Para continuar, aperte qualquer botão...");
  getch();
  
  while(tecla != ESC) {
    if (pg == 1) pg = 2; else pg=1;
    setactivepage(pg);
    cleardevice();
	z = visual(corn);
	
	fflush(stdin);
    setvisualpage(pg);
    
    if (kbhit()){
      tecla = getch();
	  if (tecla == '1'){
	  	corn = 1;
	  }
	  if (tecla == '2'){
	  	corn = 2;
	  }
	  if (tecla == '3'){
	  	corn = 3;
	  }
	  if (tecla == '4'){
	  	corn = 4;
	  }	  	  	  	  
	}
	delay(50);	
	}
	closegraph();	
  	
 	return 0; 
}
