#include <iostream>
#include <conio.h>
#include <graphics.h>

using namespace std;

int x_radius = 50;
int y_radius = 50;

int st_angle = 0;
int en_angle = 0;

int position_x = 55;
int position_y = 55;

int visual_page = 1;

void draw(){
            setactivepage(visual_page);
            cleardevice();
            sector(position_x, position_y, st_angle, en_angle, x_radius, y_radius);
            setvisualpage(visual_page);
            position_x++;
            position_y++;
            en_angle++;
            x_radius++;
            cout << "\n"<< en_angle;
}

int main(){
    initwindow(800,600, "BGI Explorer");
    setcolor(2);
    for(int i = 0; i <= 360; i++){
            draw();
    }
    getch();
}
