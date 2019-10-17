#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

int tam, x, y, i = 1, color = 1;
int width = 118, height = 481;

void *loading, *loading_bar;

void load_assets();
//X: 113 Y: 476

int main(){
    initwindow(800, 600, "007 - The Loading is Not Enough");
    load_assets();

    while(true){
            if(i == 2) i = 1; else i = 2;
            setactivepage(i);
            putimage(0, 250, loading, 2);
            setfillstyle(1, color);
            bar(113, 476, width, height);
            setvisualpage(i);
            if(width < 685) width++;
            if(width == 684){
                    width = 118;
                    color++;
                    setactivepage(1);
                    cleardevice();
                    setactivepage(2);
                    cleardevice();
            }
            if(color == 16) color = 2;
            cout << color << "\n";
            //delay(50);
    }
}

void load_assets(){

    setvisualpage(1);
    setactivepage(15);

    readimagefile("bar.bmp", 0, 0, 799, 299);
    tam = imagesize(0, 0, 799, 299);
    loading = malloc(tam);
    getimage(0, 0, 799, 299, loading);
    cleardevice();
}
