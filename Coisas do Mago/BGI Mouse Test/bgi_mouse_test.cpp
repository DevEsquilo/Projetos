#include <iostream>
#include <graphics.h>

using namespace std;

int x, y;

int main(){
    initwindow(800, 600, "Mouse Test");
    while(true){
        getmouseclick(WM_LBUTTONDBLCLK, x, y);
        cout << "X : " << x << "\n";
        cout << "Y : " << y << "\n";
        delay(500);
    }

}
