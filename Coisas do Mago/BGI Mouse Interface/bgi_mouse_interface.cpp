#include <iostream>
#include <graphics.h>
#include <conio.h>

using namespace std;

void draw();

int main(){
    initwindow(800,600,"BGI Mouse Interface");
    draw();
    setvisualpage(1);

    getch();
}

void draw(){

    //Main Menu;

    setactivepage(1);

    /*
    // Referencial Lines;

    line(0, 150, 800, 150);
    line(0, 300, 800, 300);  //Horizontal-Line;
    line(0, 450, 800, 450);

    line(200, 0, 200, 600);
    line(400, 0, 400, 600);  //Vertical-Line;
    line(600, 0, 600, 600);

    */

    setfillstyle(1, BLUE);
    bar(20, 20, 380, 130);

    setfillstyle(1, GREEN);
    bar(20, 170, 380, 280);

    setfillstyle(1, RED);
    bar(20, 320, 380, 430);

    setfillstyle(1, CYAN);
    bar(420, 20, 780, 430);
    bar(20, 470, 780, 580);

    //First Screen;

    setactivepage(2);
    setfillstyle(1, BLUE);
    bar(20, 20, 780, 430);
    bar(20, 470, 780, 580);

    //Second Screen;

    setactivepage(3);
    setfillstyle(1, GREEN);
    bar(20, 20, 780, 430);
    bar(20, 470, 780, 580);

    //Third Screen;

    setactivepage(5);
    setfillstyle(1, GREEN);
    bar(20, 20, 780, 430);
    bar(20, 470, 780, 580);

}
/*

BLACK 0
BLUE 1
GREEN 2
CYAN 3
RED 4
MAGENTA 5
BROWN 6
LIGHTGRAY 7
DARKGRAY 8
LIGHTBLUE 9
LIGHTGREEN 10
LIGHTCYAN 11
LIGHTRED 12
LIGHTMAGENTA 13
YELLOW 14
WHITE 15

*/
