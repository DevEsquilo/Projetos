#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
using namespace std;

#define ESC    	27

//tela
int pg = 1, telaX, telaY;
//teclas
char tecla = 0;
//bolinhas
int xB = 0, yB = 200;
//Vetores
int *starX, *starY, *starC,*star1X, *star1Y, *star1C, *poly = NULL;
int sta, i =0;
int s;




//poly = (int*)malloc(sizeof(int)*7);


poly[0] = 12;
poly[1] =12 ;
poly[2] =12 ;
poly[3] = 12;
poly[4] = 12;
poly[5] =12 ;
poly[6] = 12;





// Teste pra ver lag com a bolinha
void bolinha(){
    xB+=1;
    setfillstyle(1,(RGB(255,255,0)));
    setcolor(RGB(255,255,0));
    fillellipse(xB, yB, telaX*0.8/(100),telaX*0.8/(100)); 
    if(xB==telaX+200){
        xB=-200;
    }
}
// Alterna a pagina de desenho.
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
}
// Faz estrelas
void star(){
    int i=0;
    srand(time(NULL));
    while (i!=sta){
        putpixel(starX[i],starY[i],starC[i]);
        i+=1;
        if(i==sta){
            break;
        }
    }
}

// Faz estrelas grandes
void stars(){
    int i=0;
    while (i!=sta){
        // starX[i] = rand()% telaX;
        // starY[i] = rand()% telaY+rand()%telaY-10;
        // starC[i] = rand()%16;
        putpixel(star1X[i]+1,star1Y[i],star1C[i]);
        putpixel(star1X[i]-1,star1Y[i],star1C[i]);
        putpixel(star1X[i],star1Y[i]+1,star1C[i]);
        putpixel(star1X[i],star1Y[i]-1,star1C[i]);
        putpixel(star1X[i],star1Y[i],star1C[i]);
        i+=1;
        if(i==sta){
            break;
        }
    }
}


int main(){
	
    printf("Digite o tamanho X da tela: ");
    scanf("%d", &telaX);

    telaY = (telaX/3)*2;
    sta = (telaY*telaX)*(0.8)/(100);
    starX = (int*)malloc(sizeof(int)*sta);
    starY = (int*)malloc(sizeof(int)*sta);
    starC = (int*)malloc(sizeof(int)*sta);

    star1X = (int*)malloc(sizeof(int)*sta);
    star1Y = (int*)malloc(sizeof(int)*sta);
    star1C = (int*)malloc(sizeof(int)*sta);

    
    initwindow(telaX, telaY);
    setbkcolor(RGB(0,0,0));
    while(i<sta){
        starX[i] = rand()% telaX;
        starY[i] = rand()% telaY;
        starC[i] = rand()%16;
        star1X[i] = rand()% telaX;
        star1Y[i] = rand()% telaY;
        star1C[i] = rand()%16;
        i+=1;

    }

    while(tecla != ESC) {
        
        bolinha();
        star();
        stars();
        telaUp();
        fillpoly(3,poledance);

        
        

        
        
    }	
	
closegraph();	
free(starX);
free(starY);
free(starC);
return 0;
	
}



