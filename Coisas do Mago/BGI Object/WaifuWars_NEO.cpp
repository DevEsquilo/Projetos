#include <iostream>
#include <conio.h>
#include <graphics.h>

#define LEFT   	75
#define RIGHT  	77
#define UP     	72
#define DOWN   	80
#define ESC    	27
#define ENTER   13

using namespace std;

int tamanho;
int i = 0;

char input = 0;

bool game_on = true;

void *nave, *nave_mask;

void load_image();

class Player{
public:
    int x;
    int y;
    int speed;

    Player();
    ~Player();
};

class Item{
public:
    int x;
    int y;
    int points;

    Item();
    ~Item();
};

Player::Player(){
    x = 200;
    y = 200;
    speed = 10;
}

Player::~Player(){
    cout << "Destroyed !";
}

Item::Item(){
    x = 0;
    y = 0;
    points = 1;
}

int main(){
    initwindow(800,600,"The new Waifu Wars !");
    load_image();

    Player Rei;

    while(game_on){
        if(i == 2) i = 1; else i = 2;
        
        setactivepage(i);
        cleardevice();
        putimage(Rei.x, Rei.y, nave_mask, 3);
        putimage(Rei.x, Rei.y, nave, 2);
        setvisualpage(i);

        if(GetKeyState(VK_LEFT)&0x80) Rei.x -= Rei.speed;
        if(GetKeyState(VK_RIGHT)&0x80) Rei.x += Rei.speed;
        if(GetKeyState(VK_UP)&0x80) Rei.y -= Rei.speed;
        if(GetKeyState(VK_DOWN)&0x80) Rei.y += Rei.speed;

        if(Rei.x > 800) Rei.x = -170;
        if(Rei.x < -170) Rei.x = 800;
        if(Rei.y > 600) Rei.y = -230;
        if(Rei.y < -230) Rei.y = 600;

        cout << "POS X: " << Rei.x << " - POS Y: " << Rei.y << "\n";
        //getch();
    }
}

void load_image(){
    setvisualpage(1);
    setactivepage(15);

    readimagefile("Naves/Nave_Rei.bmp", 0, 0, 199, 249);
    tamanho = imagesize(0, 0, 199, 249);
    nave = malloc(tamanho);
    getimage(0, 0, 199, 249, nave);
    cleardevice();

    readimagefile("Naves/Nave_Mask.bmp", 0, 0, 199, 249);
    tamanho = imagesize(0, 0, 199, 249);
    nave_mask = malloc(tamanho);
    getimage(0, 0, 199, 249, nave_mask);
    cleardevice();
}
