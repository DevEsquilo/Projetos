#include <iostream>
#include <cmath>
#include <conio.h>
#include <graphics.h>

using namespace std;

int pitagoras[11];

int main(){

    initwindow(800, 600, "C++ Pitagoras");

    pitagoras[0] = 50;
    pitagoras[1] = 50;

    pitagoras[2] = 50;
    pitagoras[3] = 100;

    pitagoras[4] = 50;
    pitagoras[5] = 100;

    pitagoras[6] = 150;
    pitagoras[7] = 100;

    pitagoras[8] = 150;
    pitagoras[9] = 100;

    pitagoras[10] = 50;
    pitagoras[11] = 50;

    drawpoly(6, pitagoras);
    getch();

}
