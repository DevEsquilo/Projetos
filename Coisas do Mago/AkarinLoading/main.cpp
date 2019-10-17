#include <iostream>
#include <graphics.h>

int page = 0;
int i = 0;
int x = 62;

void loadImage();
void reference();
void loadingBar();

void *image[8];
void *mask[8];

int main(){

	initwindow(800, 600, "Akarin Loading");
	loadImage();
	reference();

	while(true){

		if(page == 2)page = 1;else page = 2;

		setactivepage(page);
		cleardevice();

		putimage(250,0,mask[i], 3);
		putimage(250,0,image[i], 2);
		loadingBar();
		//reference();
		i++;

		setvisualpage(page);
		delay(80);

		if(i == 8)i = 0;
	}

}

void loadImage(){

	setvisualpage(1);
	setactivepage(15);

	readimagefile("frame1.bmp", 0, 0, 279, 497);
	int size = imagesize(0,0,279,497);
	image[0] = malloc(size);
	getimage(0,0,279,497, image[0]);
	cleardevice();

	readimagefile("frame2.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	image[1] = malloc(size);
	getimage(0,0,279,497,image[1]);
	cleardevice();

	readimagefile("frame3.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	image[2] = malloc(size);
	getimage(0,0,279,497,image[2]);
	cleardevice();

	readimagefile("frame4.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	image[3] = malloc(size);
	getimage(0,0,279,497,image[3]);
	cleardevice();

	readimagefile("frame5.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	image[4] = malloc(size);
	getimage(0,0,279,497,image[4]);
	cleardevice();

	readimagefile("frame6.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	image[5] = malloc(size);
	getimage(0,0,279,497,image[5]);
	cleardevice();

	readimagefile("frame7.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	image[6] = malloc(size);
	getimage(0,0,279,497,image[6]);
	cleardevice();

	readimagefile("frame8.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	image[7] = malloc(size);
	getimage(0,0,279,497,image[7]);
	cleardevice();

	readimagefile("frame1mask.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	mask[0] = malloc(size);
	getimage(0,0,279,497,mask[0]);
	cleardevice();

	readimagefile("frame2mask.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	mask[1] = malloc(size);
	getimage(0,0,279,497,mask[1]);
	cleardevice();

	readimagefile("frame3mask.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	mask[2] = malloc(size);
	getimage(0,0,279,497,mask[2]);
	cleardevice();

	readimagefile("frame4mask.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	mask[3] = malloc(size);
	getimage(0,0,279,497,mask[3]);
	cleardevice();

	readimagefile("frame5mask.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	mask[4] = malloc(size);
	getimage(0,0,279,497,mask[4]);
	cleardevice();

	readimagefile("frame6mask.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	mask[5] = malloc(size);
	getimage(0,0,279,497,mask[5]);
	cleardevice();

	readimagefile("frame7mask.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	mask[6] = malloc(size);
	getimage(0,0,279,497,mask[6]);
	cleardevice();

	readimagefile("frame8mask.bmp", 0, 0, 279, 497);
	size = imagesize(0,0,279,497);
	mask[7] = malloc(size);
	getimage(0,0,279,497,mask[7]);
	cleardevice();

}

void reference(){

	line(0, 150, 800, 150);
    line(0, 300, 800, 300);  //Horizontal-Line;
    line(0, 450, 800, 450);

    line(200, 0, 200, 600);
    line(400, 0, 400, 600);  //Vertical-Line;
    line(600, 0, 600, 600);

}

void loadingBar(){

	settextstyle(3,0,6);
	outtextxy(300,480,"Loading");
	bar(50,530,750,570);
	setfillstyle(SOLID_FILL, RED);
	setcolor(RED);
	bar(60,540,x,560);
	setfillstyle(SOLID_FILL, WHITE);
	setcolor(WHITE);

	if(x <= 740)x++;
}
