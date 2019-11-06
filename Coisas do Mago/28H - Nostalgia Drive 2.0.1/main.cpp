#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include<time.h>

using namespace std;

//Variaveis para carregar imagens:
void *button, *menuBG, *text, *mainMenu, *backButton, *creditos, *backGroundEx, *teste, *carro, *carroMask, *logo;

void *partida1, *partida2, *partida3, *partida4, *partida5, *partidaMask;
//_______\\
//SpriteArts dos Personagens:
void *alucard, *crono, *link, *pacman, *rin, *sonic;
void *cronoCard, *zoomCronoCard,*alucardCard,*zoomAlucardCard, *pacmanCard, *zoomPacmanCard,
*rinCard, *zoomRinCard, *sonicCard, *zoomSonicCard, *linkCard, *zoomLinkCard;
void *vitoria, *derrota;
//_______\\

//Seleção de pista:
void *deserto, *noite, *campo, *neve;

//Utilidade:
int imgSize,
screen = 2,
posX = 300,
posY = 455;
int coluna = 1;
int comando = 0;
bool apertou = false;
bool window;

//______\\

//Intro:
void *intro1, *intro2, *titulo;

//Sprites das pistas:
void *pistaRetaImg1,*pistaRetaImg2,*pistaRetaImg3,*pistaRetaImg4;
//_______\\

//Sprites para Obstaculos:
void *barril, *barril2, *barril3, *barril4, *barril4Mask, *barril3Mask, *barril2Mask, *barrilMask, *caixa1, *caixa1Mask, *caixa2, *caixa2Mask, *caixa3, *caixa3Mask, *caixa4, *caixa4Mask;
void *barrilBoom, *barrilBoomMask, *caixaSmash, *caixaSmashMask;
//_______\\

//Sprites HUD:
void *vidas3, *vidas2, *vidas1, *vidasMask, *voltaHud, *volta2Hud, *volta3Hud;

//Sprites das exibições dos carros:
void *ferrariEx, *lamborginiEx, *dodgeEx, *mcLarenEx, *eclipseEx, *mercedesEx;
void *ferrariMask, *lamborginiMask, *dodgeMask, *mcLarenMask, *eclipseMask, *mercedesMask;
//__________\\

bool portuguese; // Janela ativa //Precisa ser global
bool servidor; // Servidor T client F // Precisa ser global
bool player[6];// Bloqueia o personagem;
int playerServer;//Personagem do servidor:
int playerClient;// Personagem do cliente:

//Variaveis ingame:
int pistaReta = 1;
int position = 0;
int pista;
int barrilID0 = 0;
int barrilID1 = 0;
int barrilID2 = 0;
int CaixaID0 = 0;
int CaixaID1 = 0;
int CaixaID2 = 0;
int OB1, OB2, OB3, OBc1, OBc2, OBc3;
int l1, l2, l3;
bool Lane1 = false;
bool Lane2 = true;
bool Lane3 = false;
bool caixa;
int boxcontrol;
bool colidiu;
int vidas = 3;
int volta = 1;
int dif = 20;
//__________\\

//Funções do jogo:
void MenuPrincipal();
void SelecionaPlayer();
void GetImage();
void ClickDrainButton();
void Server();
void SelectLanguage();
void Creditos();
void SelecionaPlayer();
void MenuPrincipal();
void ConfirmarPersonagem();
void SelecionaPista();
void Intro();
void ChamaPerda();
void ChamaVitoria();
//________\\

//Funcoes inGame:

void Instrucoes(){

    settextstyle(3,HORIZ_DIR,15);
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    setcolor(WHITE);

    cleardevice();

    if(portuguese){

        outtextxy(400,100,"Use as setas para desviar dos obstaculos.");
        delay(500);
        outtextxy(400,250,"A cada volta você ganha uma vida extra.");
        delay(500);
        outtextxy(400,400,"O limite de vidas permitido é 3.");
        delay(500);
        outtextxy(400,550,"Lembre-se, as caixas podem ser traiçoeiras.");

    }else{

        outtextxy(400,100,"Use the arrow keys to dodge the obstacles.");
        delay(500);
        outtextxy(400,250,"At every turn you get an extra life.");
        delay(500);
        outtextxy(400,400,"The allowed limit is 3 lives.");
        delay(500);
        outtextxy(400,550,"Remember, the boxes can be treacherous.");

    }

    delay(4000);
    cleardevice();

}

void CarregaObstaculos(){

    setactivepage(16);
    setvisualpage(1);

    readimagefile("Bitmap/InGame/Obstaculos/Barril.bmp",0,0,29,39);
    imgSize = imagesize(0,0,29,39);
    barril = malloc(imgSize);
    getimage(0,0,29,39,barril);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/BarrilMask.bmp",0,0,29,39);
    imgSize = imagesize(0,0,29,39);
    barrilMask = malloc(imgSize);
    getimage(0,0,29,39,barrilMask);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/Barril.bmp",0,0,49,66);
    imgSize = imagesize(0,0,49,66);
    barril2 = malloc(imgSize);
    getimage(0,0,49,66,barril2);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/BarrilMask.bmp",0,0,49,66);
    imgSize = imagesize(0,0,49,66);
    barril2Mask = malloc(imgSize);
    getimage(0,0,49,66,barril2Mask);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/Barril.bmp",0,0,74,94);
    imgSize = imagesize(0,0,74,94);
    barril3 = malloc(imgSize);
    getimage(0,0,74,94,barril3);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/BarrilMask.bmp",0,0,74,94);
    imgSize = imagesize(0,0,74,94);
    barril3Mask = malloc(imgSize);
    getimage(0,0,74,94,barril3Mask);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/Barril.bmp",0,0,99,129);
    imgSize = imagesize(0,0,99,129);
    barril4 = malloc(imgSize);
    getimage(0,0,99,129,barril4);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/BarrilMask.bmp",0,0,99,129);
    imgSize = imagesize(0,0,99,129);
    barril4Mask = malloc(imgSize);
    getimage(0,0,99,129,barril4Mask);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/BarrilBoom.bmp",0,0,249,199);
    imgSize = imagesize(0,0,249,199);
    barrilBoom = malloc(imgSize);
    getimage(0,0,249,199,barrilBoom);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/BarrilBoomMask.bmp",0,0,249,199);
    imgSize = imagesize(0,0,249,199);
    barrilBoomMask = malloc(imgSize);
    getimage(0,0,249,199,barrilBoomMask);
    cleardevice();

    //____________________________________________________\\

    readimagefile("Bitmap/InGame/Obstaculos/Caixote.bmp",0,0,39,29);
    imgSize = imagesize(0,0,39,29);
    caixa1 = malloc(imgSize);
    getimage(0,0,39,29,caixa1);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/CaixoteMask.bmp",0,0,39,29);
    imgSize = imagesize(0,0,39,29);
    caixa1Mask = malloc(imgSize);
    getimage(0,0,39,29,caixa1Mask);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/Caixote.bmp",0,0,49,38);
    imgSize = imagesize(0,0,49,38);
    caixa2 = malloc(imgSize);
    getimage(0,0,49,38,caixa2);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/CaixoteMask.bmp",0,0,49,38);
    imgSize = imagesize(0,0,49,38);
    caixa2Mask= malloc(imgSize);
    getimage(0,0,49,38,caixa2Mask);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/Caixote.bmp",0,0,74,56);
    imgSize = imagesize(0,0,74,56);
    caixa3 = malloc(imgSize);
    getimage(0,0,74,56,caixa3);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/CaixoteMask.bmp",0,0,74,56);
    imgSize = imagesize(0,0,74,56);
    caixa3Mask = malloc(imgSize);
    getimage(0,0,74,56,caixa3Mask);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/Caixote.bmp",0,0,99,74);
    imgSize = imagesize(0,0,99,74);
    caixa4 = malloc(imgSize);
    getimage(0,0,99,74,caixa4);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/CaixoteMask.bmp",0,0,99,74);
    imgSize = imagesize(0,0,99,74);
    caixa4Mask = malloc(imgSize);
    getimage(0,0,99,74,caixa4Mask);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/CaixoteSmash.bmp",0,0,249,199);
    imgSize = imagesize(0,0,249,199);
    caixaSmash = malloc(imgSize);
    getimage(0,0,249,199,caixaSmash);
    cleardevice();

    readimagefile("Bitmap/InGame/Obstaculos/CaixoteSmashMask.bmp",0,0,249,199);
    imgSize = imagesize(0,0,249,199);
    caixaSmashMask = malloc(imgSize);
    getimage(0,0,249,199,caixaSmashMask);
    cleardevice();

    setactivepage(1);

}
//______________\\//

void PutObstaculos(){

    if(Lane1&&Lane2&&Lane3 && barrilID0 == 0 && barrilID1 == 0 && barrilID2 == 0){

        Lane2 = false;

    }

    if(!caixa){

        if(Lane1 ){

            if(barrilID0 <= 3){

                if(barrilID0 == 0){

                    putimage(355,386,barrilMask, AND_PUT);
                    putimage(355,386,barril,OR_PUT);
                    OB1 += 1;
                    if(OB1 >= 10){

                        OB1 = 0;
                        barrilID0 += 1;

                    }

                }else if(barrilID0 == 1){

                    putimage(330,384,barril2Mask, AND_PUT);
                    putimage(330,384,barril2,OR_PUT);
                    OB1 += 1;
                    if(OB1 >= 10){

                        OB1 = 0;
                        barrilID0 += 1;

                    }

                }else if(barrilID0 == 2){

                    putimage(285,415,barril3Mask,AND_PUT);
                    putimage(285,415,barril3,OR_PUT);
                    OB1 += 1;
                    if(OB1 >= 10){

                        OB1 = 0;
                        barrilID0 += 1;

                    }

                }else{

                    putimage(225,450,barril4Mask,AND_PUT);//275,525
                    putimage(225,450,barril4,OR_PUT);
                    OB1 += 1;
                    if(coluna == 0){

                        putimage(150,425,barrilBoomMask,AND_PUT);
                        putimage(150,425,barrilBoom,OR_PUT);
                        colidiu = true;

                    }
                    if(OB1 >= 10){

                        OB1 = 0;
                        barrilID0 += 1;
                        Lane1 = false;

                    }

                }

            }

            if(barrilID0 > 3)barrilID0 = 0;

        }
        if(Lane2 ){

             if(barrilID1 <= 3){

                if(barrilID1 == 0){

                    putimage(385,386,barrilMask, AND_PUT);
                    putimage(385,386,barril,OR_PUT);
                    OB2 += 1;
                    if(OB2 >= 10){

                        OB2 = 0;
                        barrilID1 += 1;

                    }

                }else if(barrilID1 == 1){

                    putimage(375,384,barril2Mask, AND_PUT);
                    putimage(375,384,barril2,OR_PUT);
                    OB2 += 1;
                    if(OB2 >= 10){

                        OB2 = 0;
                        barrilID1 += 1;

                    }

                }else if(barrilID1 == 2){

                    putimage(362,415,barril3Mask,AND_PUT);
                    putimage(362,415,barril3,OR_PUT);
                    OB2 += 1;
                    if(OB2 >= 10){

                        OB2 = 0;
                        barrilID1 += 1;

                    }

                }else{

                    putimage(350,450,barril4Mask,AND_PUT);
                    putimage(350,450,barril4,OR_PUT);
                    OB2 += 1;
                    if(coluna == 1){

                        putimage(275,425,barrilBoomMask,AND_PUT);
                        putimage(275,425,barrilBoom,OR_PUT);
                        colidiu = true;

                    }
                    if(OB2 >= 10){

                        OB2 = 0;
                        barrilID1 += 1;
                        Lane2 = false;

                    }

                }

            }

            if(barrilID1 > 3)barrilID1 = 0;

        }
        if(Lane3 ){

        if(barrilID2 <= 3){

            if(barrilID2 == 0){

                putimage(415,386,barrilMask, AND_PUT);
                putimage(415,386,barril,OR_PUT);
                OB3 += 1;
                if(OB3 >= 10){

                    OB3 = 0;
                    barrilID2 += 1;

                }

            }else if(barrilID2 == 1){

                putimage(430,384,barril2Mask, AND_PUT);
                putimage(430,384,barril2,OR_PUT);
                OB3 += 1;
                if(OB3 >= 10){

                    OB3 = 0;
                    barrilID2 += 1;

                }

            }else if(barrilID2 == 2){

                putimage(462,415,barril3Mask,AND_PUT);
                putimage(462,415,barril3,OR_PUT);
                OB3 += 1;
                if(OB3 >= 10){

                    OB3 = 0;
                    barrilID2 += 1;

                }

            }else{

                putimage(510,450,barril4Mask,AND_PUT);
                putimage(510,450,barril4,OR_PUT);
                OB3 += 1;
                if(coluna == 2){

                    putimage(435,425,barrilBoomMask,AND_PUT);
                    putimage(435,425, barrilBoom,OR_PUT);
                    colidiu = true;

                }
                if(OB3 >= 10){

                    OB3 = 0;
                    barrilID2 += 1;
                    Lane3 = false;

                }

            }

        }

        if(barrilID2 > 3)barrilID2 = 0;

        }

    }
    if(!Lane1 && !Lane2 && !Lane3){

        l1 = rand()%dif; //37
        l2 = rand()%dif; //37
        l3 = rand()%dif; //37

        if(l1 == 12 || l1 == 15)Lane1 = true;
        if(l2 == 12 || l2 == 15)Lane2 = true;
        if(l3 == 12 || l2 == 15)Lane3 = true;
        caixa = ! caixa;

    }

}
//_____________\\//

void PutObstaculos2(){

    if(Lane1&&Lane2&&Lane3 && CaixaID0 == 0 && CaixaID1 == 0 && CaixaID2 == 0){

        Lane2 = false;

    }

    if(caixa){

        if(Lane1){

            if(CaixaID0 <= 3){

                if(CaixaID0 == 0){

                    putimage(355,386,caixa1Mask, AND_PUT);
                    putimage(355,386,caixa1,OR_PUT);
                    OBc1 += 1;
                    if(OBc1 >= 10){

                        OBc1 = 0;
                        CaixaID0 += 1;

                    }

                }else if(CaixaID0 == 1){

                    putimage(330,384,caixa2Mask, AND_PUT);
                    putimage(330,384,caixa2,OR_PUT);
                    OBc1 += 1;
                    if(OBc1 >= 10){

                        OBc1 = 0;
                        CaixaID0 += 1;

                    }

                }else if(CaixaID0 == 2){

                    putimage(285,415,caixa3Mask,AND_PUT);
                    putimage(285,415,caixa3,OR_PUT);
                    OBc1 += 1;
                    if(OBc1 >= 10){

                        OBc1 = 0;
                        CaixaID0 += 1;

                    }

                }else{

                    putimage(225,500,caixa4Mask,AND_PUT);//275,525
                    putimage(225,500,caixa4,OR_PUT);
                    OBc1 += 1;
                    if(coluna == 0){

                        putimage(150,425,caixaSmashMask,AND_PUT);
                        putimage(150,425,caixaSmash,OR_PUT);
                        colidiu = true;

                    }
                    if(OBc1 >= 10){

                        OBc1 = 0;
                        CaixaID0 += 1;
                        Lane1 = false;
                        caixa = false;

                    }

                }

            }

            if(CaixaID0 > 3)CaixaID0 = 0;

        }
        if(Lane2){

             if(CaixaID1 <= 3){

                if(CaixaID1 == 0){

                    putimage(385,386,caixa1Mask, AND_PUT);
                    putimage(385,386,caixa1,OR_PUT);
                    OBc2 += 1;
                    if(OBc2 >= 10){

                        OBc2 = 0;
                        CaixaID1 += 1;

                    }

                }else if(CaixaID1 == 1){

                    putimage(375,384,caixa2Mask, AND_PUT);
                    putimage(375,384,caixa2,OR_PUT);
                    OBc2 += 1;
                    if(OBc2 >= 10){

                        OBc2 = 0;
                        CaixaID1 += 1;

                    }

                }else if(CaixaID1 == 2){

                    putimage(362,415,caixa3Mask,AND_PUT);
                    putimage(362,415,caixa3,OR_PUT);
                    OBc2 += 1;
                    if(OBc2 >= 10){

                        OBc2 = 0;
                        CaixaID1 += 1;

                    }

                }else{

                    putimage(350,500,caixa4Mask,AND_PUT);
                    putimage(350,500,caixa4,OR_PUT);
                    OBc2 += 1;
                    if(coluna == 1){

                        putimage(275,425,caixaSmashMask,AND_PUT);
                        putimage(275,425,caixaSmash,OR_PUT);
                        colidiu = true;

                    }
                    if(OBc2 >= 10){

                        OBc2 = 0;
                        CaixaID1 += 1;
                        Lane2 = false;
                        caixa = false;

                    }

                }

            }

            if(CaixaID1 > 3)CaixaID1 = 0;

        }
        if(Lane3){

        if(CaixaID2 <= 3){

            if(CaixaID2 == 0){

                putimage(415,386,caixa1Mask, AND_PUT);
                putimage(415,386,caixa1,OR_PUT);
                OBc3 += 1;
                if(OBc3 >= 10){

                    OBc3 = 0;
                    CaixaID2 += 1;

                }

            }else if(CaixaID2 == 1){

                putimage(430,384,caixa2Mask, AND_PUT);
                putimage(430,384,caixa2,OR_PUT);
                OBc3 += 1;
                if(OBc3 >= 10){

                    OBc3 = 0;
                    CaixaID2 += 1;

                }

            }else if(CaixaID2 == 2){

                putimage(462,415,caixa3Mask,AND_PUT);
                putimage(462,415,caixa3,OR_PUT);
                OBc3 += 1;
                if(OBc3 >= 10){

                    OBc3 = 0;
                    CaixaID2 += 1;

                }

            }else{

                putimage(510,500,caixa4Mask,AND_PUT);
                putimage(510,500,caixa4,OR_PUT);
                OBc3 += 1;
                if(coluna == 2){

                    putimage(435,425,caixaSmashMask,AND_PUT);
                    putimage(435,425, caixaSmash,OR_PUT);
                    colidiu = true;

                }
                if(OBc3 >= 10){

                    OBc3 = 0;
                    CaixaID2 += 1;
                    Lane3 = false;
                    caixa = false;

                }

            }

        }

        if(CaixaID2 > 3)CaixaID2 = 0;

    }

    }

    if(!Lane1 && !Lane2 && !Lane3){

        l1 = rand()%20; //37
        l2 = rand()%20; //37
        l3 = rand()%20; //37

        if(l1 == 6 || l1 == 4)Lane1 = true;
        if(l2 == 6 || l2 == 4)Lane2 = true;
        if(l3 == 6 || l2 == 4)Lane3 = true;
        caixa = ! caixa;

    }

}
//__________\\

//Carrega as Sprites da Pista:
void CarregaPistaReta(){

    setactivepage(16);

    if(pista == 0){

        readimagefile("Bitmap/InGame/Pista/Pista_campo1.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg1 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg1);
        cleardevice();

        readimagefile("Bitmap/InGame/Pista/Pista_campo2.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg2 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg2);
        cleardevice();

        readimagefile("Bitmap/InGame/Pista/Pista_campo3.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg3 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg3);
        cleardevice();

        readimagefile("Bitmap/InGame/Pista/Pista_campo4.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg4 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg4);
        cleardevice();

    }else if(pista == 1){

        readimagefile("Bitmap/InGame/Pista/Pista_deserto1.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg1 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg1);
        cleardevice();

        readimagefile("Bitmap/InGame/Pista/Pista_deserto2.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg2 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg2);
        cleardevice();

        readimagefile("Bitmap/InGame/Pista/Pista_deserto3.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg3 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg3);
        cleardevice();

        readimagefile("Bitmap/InGame/Pista/Pista_deserto4.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg4 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg4);
        cleardevice();

    }else if(pista == 2){

        readimagefile("Bitmap/InGame/Pista/Pista_neve1.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg1 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg1);
        cleardevice();

        readimagefile("Bitmap/InGame/Pista/Pista_neve2.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg2 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg2);
        cleardevice();

        readimagefile("Bitmap/InGame/Pista/Pista_neve3.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg3 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg3);
        cleardevice();

        readimagefile("Bitmap/InGame/Pista/Pista_neve4.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg4 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg4);
        cleardevice();

    }else{

        readimagefile("Bitmap/InGame/Pista/Pista_noite1.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg1 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg1);
        cleardevice();

        readimagefile("Bitmap/InGame/Pista/Pista_noite2.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg2 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg2);
        cleardevice();

        readimagefile("Bitmap/InGame/Pista/Pista_noite3.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg3 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg3);
        cleardevice();

        readimagefile("Bitmap/InGame/Pista/Pista_noite4.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        pistaRetaImg4 = malloc(imgSize);
        getimage(0,0,799,599,pistaRetaImg4);
        cleardevice();

    }

}
//______________\\

//Animação da Pista:
void PutPistaReta(){

    if(pistaReta <= 5){

        if(pistaReta == 1)putimage(0,0,pistaRetaImg1,0);
        else if(pistaReta == 2)putimage(0,0,pistaRetaImg2,0);
        else if(pistaReta == 3)putimage(0,0,pistaRetaImg3,0);
        else if(pistaReta == 4)putimage(0,0,pistaRetaImg4,0);
        else if(pistaReta == 5)putimage(0,0,pistaRetaImg1,0);

    }else{
    pistaReta = 1;
    PutPistaReta();
    }

}
//_______________\\

//Carregar bitmaps dos Carros:
void CarregaCarros(){

    setactivepage(2);

    if(servidor){

        if(playerServer == 0){

            readimagefile("Bitmap/InGame/Carros/Kombi.bmp",0,0,199,115);
            imgSize = imagesize(0,0,199,115);
            carro = malloc(imgSize);
            getimage(0,0,199,115,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/KombiMask.bmp",0,0,199,115);
            imgSize = imagesize(0,0,199,115);
            carroMask = malloc(imgSize);
            getimage(0,0,199,115,carroMask);
            cleardevice();

        }else if(playerServer == 1){

            readimagefile("Bitmap/InGame/Carros/MacLaren.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carro = malloc(imgSize);
            getimage(0,0,199,149,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/MacLarenMask.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carroMask = malloc(imgSize);
            getimage(0,0,199,149,carroMask);
            cleardevice();

        }else if(playerServer == 2){

            readimagefile("Bitmap/InGame/Carros/Ferrari.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carro = malloc(imgSize);
            getimage(0,0,199,149,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/FerrariMask.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carroMask = malloc(imgSize);
            getimage(0,0,199,149,carroMask);
            cleardevice();

        }else if(playerServer == 3){

            readimagefile("Bitmap/InGame/Carros/Lamborgini.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carro = malloc(imgSize);
            getimage(0,0,199,149,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/LamborginiMask.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carroMask = malloc(imgSize);
            getimage(0,0,199,149,carroMask);
            cleardevice();

        }else if(playerServer == 4){

            readimagefile("Bitmap/InGame/Carros/Eclipse.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carro = malloc(imgSize);
            getimage(0,0,199,149,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/EclipseMask.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carroMask = malloc(imgSize);
            getimage(0,0,199,149,carroMask);
            cleardevice();

        }else if(playerServer == 5){

            readimagefile("Bitmap/InGame/Carros/Mercedes.bmp",0,0,189,139);
            imgSize = imagesize(0,0,189,139);
            carro = malloc(imgSize);
            getimage(0,0,189,139,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/MercedesMask.bmp",0,0,189,139);
            imgSize = imagesize(0,0,189,139);
            carroMask = malloc(imgSize);
            getimage(0,0,189,139,carroMask);
            cleardevice();
        }else{

            readimagefile("Bitmap/InGame/Carros/Dodge.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carro = malloc(imgSize);
            getimage(0,0,199,149,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/DodgeMask.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carroMask = malloc(imgSize);
            getimage(0,0,199,149,carroMask);
            cleardevice();

        }

    }else{

        if(playerClient == 0){

            readimagefile("Bitmap/InGame/Carros/Kombi.bmp",0,0,199,115);
            imgSize = imagesize(0,0,199,115);
            carro = malloc(imgSize);
            getimage(0,0,199,115,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/KombiMask.bmp",0,0,199,115);
            imgSize = imagesize(0,0,199,115);
            carroMask = malloc(imgSize);
            getimage(0,0,199,115,carroMask);
            cleardevice();

        }else if(playerClient == 1){

            readimagefile("Bitmap/InGame/Carros/McLaren.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carro = malloc(imgSize);
            getimage(0,0,199,149,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/MacLarenMask.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carroMask = malloc(imgSize);
            getimage(0,0,199,149,carroMask);
            cleardevice();

        }else if(playerClient == 2){

            readimagefile("Bitmap/InGame/Carros/Ferrari.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carro = malloc(imgSize);
            getimage(0,0,199,149,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/FerrariMask.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carroMask = malloc(imgSize);
            getimage(0,0,199,149,carroMask);
            cleardevice();

        }else if(playerClient == 3){

            readimagefile("Bitmap/InGame/Carros/Lamborgini.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carro = malloc(imgSize);
            getimage(0,0,199,149,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/LamborginiMask.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carroMask = malloc(imgSize);
            getimage(0,0,199,149,carroMask);
            cleardevice();

        }else if(playerClient == 4){

            readimagefile("Bitmap/InGame/Carros/Eclipse.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carro = malloc(imgSize);
            getimage(0,0,199,149,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/EclipseMask.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carroMask = malloc(imgSize);
            getimage(0,0,199,149,carroMask);
            cleardevice();

        }else if (playerClient == 5){

            readimagefile("Bitmap/InGame/Carros/Mercedes.bmp",0,0,189,19);
            imgSize = imagesize(0,0,189,139);
            carro = malloc(imgSize);
            getimage(0,0,189,139,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/MercedesMask.bmp",0,0,189,139);
            imgSize = imagesize(0,0,189,139);
            carroMask = malloc(imgSize);
            getimage(0,0,189,139,carroMask);
            cleardevice();

        }else{

            readimagefile("Bitmap/InGame/Carros/Dodge.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carro = malloc(imgSize);
            getimage(0,0,199,149,carro);
            cleardevice();
            readimagefile("Bitmap/InGame/Carros/DodgeMask.bmp",0,0,199,149);
            imgSize = imagesize(0,0,199,149);
            carroMask = malloc(imgSize);
            getimage(0,0,199,149,carroMask);
            cleardevice();

        }

    }

    setactivepage(1);
    setvisualpage(1);


}
//______________\\//

void Gameplay(){

        pistaReta += 1;
        position += 1;
        if(position > 1800){

            volta +=  1;
            dif -= 5;
            vidas += 1;
            position = 0;
            if(vidas > 3) vidas = 3;

        }

        if(GetKeyState(VK_RIGHT)&0x80){
            if(!apertou){

                coluna += 1;
                if(coluna >= 3){

                    coluna = 3;
                    colidiu = true;

                }
                if(coluna == 0) posX = 145; else if (coluna == 1)posX = 300; else posX = 455;
                apertou = true;

            }

        }else if(GetKeyState(VK_LEFT)&0x80){
            if(!apertou){

                coluna -= 1;
                if(coluna <0){

                    coluna = 0;
                    colidiu = true;

                }
                if(coluna == 0) posX = 145; else if (coluna == 1)posX = 300; else posX = 455;
                apertou = true;

            }

        }else apertou = false;

}
//__________\\//

void CarregaHUD(){

    setactivepage(16);
    setvisualpage(1);

    readimagefile("Bitmap/InGame/Hud/3Vidas.bmp",0,0,74,74);
    imgSize = imagesize(0,0,74,74);
    vidas3 = malloc(imgSize);
    getimage(0,0,74,74,vidas3);
    cleardevice();

    readimagefile("Bitmap/InGame/Hud/2Vidas.bmp",0,0,74,74);
    imgSize = imagesize(0,0,74,74);
    vidas2 = malloc(imgSize);
    getimage(0,0,74,74,vidas2);
    cleardevice();

    readimagefile("Bitmap/InGame/Hud/1Vida.bmp",0,0,74,74);
    imgSize = imagesize(0,0,74,74);
    vidas1 = malloc(imgSize);
    getimage(0,0,74,74,vidas1);
    cleardevice();

    readimagefile("Bitmap/InGame/Hud/VidasMask.bmp",0,0,74,74);
    imgSize = imagesize(0,0,74,74);
    vidasMask = malloc(imgSize);
    getimage(0,0,74,74,vidasMask);
    cleardevice();

    readimagefile("Bitmap/InGame/Hud/Volta.bmp",0,0,99,49);
    imgSize = imagesize(0,0,99,49);
    voltaHud = malloc(imgSize);
    getimage(0,0,99,49,voltaHud);
    cleardevice();

    readimagefile("Bitmap/InGame/Hud/Volta2.bmp",0,0,99,49);
    imgSize = imagesize(0,0,99,49);
    volta2Hud = malloc(imgSize);
    getimage(0,0,99,49,volta2Hud);
    cleardevice();

    readimagefile("Bitmap/InGame/Hud/Volta3.bmp",0,0,99,49);
    imgSize = imagesize(0,0,99,49);
    volta3Hud = malloc(imgSize);
    getimage(0,0,99,49,volta3Hud);
    cleardevice();

}
//__________\\//

void DesenhaHUD(){

    putimage(700,25,vidasMask,AND_PUT);
    if(vidas == 3)putimage(700,25,vidas3,OR_PUT);
    else if(vidas == 2)putimage(700,25,vidas2,OR_PUT);
    else if(vidas == 1)putimage(700,25,vidas1,OR_PUT);

    if(volta == 1)putimage(25,25,voltaHud,0);
    else if(volta == 2)putimage(25,25,volta2Hud,0);
    else if(volta == 3)putimage(25,25,volta3Hud,0);

}
//_______________\\//

void Colisao(){

        if(colidiu){

            vidas -= 1;

            for(int i = 0; i<5; i++){

                setactivepage(1);
                setvisualpage(1);
                cleardevice();
                PutPistaReta();
                PutObstaculos();
                PutObstaculos();
                DesenhaHUD();
                delay(200);
                putimage(posX,posY,carroMask,AND_PUT);
                putimage(posX,posY,carro,OR_PUT);
                delay(100);

            }

            colidiu = false;

        }

}
//_________\\

void AnimaInicio(){

    cleardevice();

    putimage(0,0,pistaRetaImg1,1);
    putimage(posX,posY,carroMask,AND_PUT);
    putimage(posX,posY,carro,OR_PUT);
    putimage(174,0,partidaMask,AND_PUT);
    putimage(174,0,partida1,OR_PUT);
    delay(500);
    cleardevice();
    putimage(0,0,pistaRetaImg1,1);
    putimage(posX,posY,carroMask,AND_PUT);
    putimage(posX,posY,carro,OR_PUT);
    putimage(174,0,partidaMask,AND_PUT);
    putimage(174,0,partida2,OR_PUT);
    delay(500);
    cleardevice();
    putimage(0,0,pistaRetaImg1,1);
    putimage(posX,posY,carroMask,AND_PUT);
    putimage(posX,posY,carro,OR_PUT);
    putimage(174,0,partidaMask,AND_PUT);
    putimage(174,0,partida3,OR_PUT);
    delay(500);
    cleardevice();
    putimage(0,0,pistaRetaImg1,1);
    putimage(posX,posY,carroMask,AND_PUT);
    putimage(posX,posY,carro,OR_PUT);
    putimage(174,0,partidaMask,AND_PUT);
    putimage(174,0,partida4,OR_PUT);
    delay(500);
    cleardevice();
    putimage(0,0,pistaRetaImg1,1);
    putimage(posX,posY,carroMask,AND_PUT);
    putimage(posX,posY,carro,OR_PUT);
    putimage(174,0,partidaMask,AND_PUT);
    putimage(174,0,partida5,OR_PUT);
    delay(500);
    cleardevice();

}

//Função principal do jogo:
int main(){//||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\\//

    srand(time(NULL));

    int x, y, colisao;

    initwindow(800,600,"House of Wolves presents... Nostalgia Drive...");
    window = true;
    
    delay(6000);

    GetImage();

    cleardevice();

    //Começa o jogo aqui:

    if(servidor){

        CarregaPistaReta();

        CarregaObstaculos();

        CarregaCarros();

        CarregaHUD();

        Instrucoes();

        AnimaInicio();

    }

    //Laço do jogo:
    while(window){

        //Controle do jogo:
        Gameplay();

        //Controle de Fric
        if(screen == 2)screen = 1;else screen = 2;
        setactivepage(screen);
        cleardevice();

        fflush(stdin);

        Colisao();

        //Coloca as Imagens na tela:

        PutPistaReta();

        DesenhaHUD();

        PutObstaculos();
        PutObstaculos2();

        putimage(posX,posY,carroMask,AND_PUT);
        putimage(posX,posY,carro, OR_PUT);

        //Controle de Fric:
        setvisualpage(screen);

        //Delay:
        delay(50);

        if(vidas <= 0){

            cleardevice();
            ChamaPerda();

        }else if(position >= 1799 && volta ==3){

            ChamaVitoria();

        }

    }

    return 0;

}
//________\\

//Funçao de capturar imagens:
void GetImage(){

    setactivepage(2);

    //Chegada e partida;

    readimagefile("Bitmap/InGame/Objetos/PartidaMask.bmp",0,0,449,599);
    imgSize = imagesize(0,0,449,599);
    partidaMask = malloc(imgSize);
    getimage(0,0,449,599,partidaMask);
    cleardevice();

    readimagefile("Bitmap/InGame/Objetos/Partida1.bmp",0,0,449,599);
    imgSize = imagesize(0,0,449,599);
    partida1 = malloc(imgSize);
    getimage(0,0,449,599,partida1);
    cleardevice();

    readimagefile("Bitmap/InGame/Objetos/Partida2.bmp",0,0,449,599);
    imgSize = imagesize(0,0,449,599);
    partida2 = malloc(imgSize);
    getimage(0,0,449,599,partida2);
    cleardevice();

    readimagefile("Bitmap/InGame/Objetos/Partida3.bmp",0,0,449,599);
    imgSize = imagesize(0,0,449,599);
    partida3 = malloc(imgSize);
    getimage(0,0,449,599,partida3);
    cleardevice();

    readimagefile("Bitmap/InGame/Objetos/Partida4.bmp",0,0,449,599);
    imgSize = imagesize(0,0,449,599);
    partida4 = malloc(imgSize);
    getimage(0,0,449,599,partida4);
    cleardevice();

    readimagefile("Bitmap/InGame/Objetos/Partida5.bmp",0,0,449,599);
    imgSize = imagesize(0,0,449,599);
    partida5 = malloc(imgSize);
    getimage(0,0,449,599,partida5);
    cleardevice();

    //Titulo:

    readimagefile("Bitmap/Intro/Titulo.bmp",0,0,799,599);
    imgSize = imagesize(0,0,799,599);
    titulo = malloc(imgSize);
    getimage(0,0,799,599,titulo);
    cleardevice();

    //Ferrari:
    readimagefile("Bitmap/CarrosExibicao/FerrariEx.bmp",0,0,399,169);
    imgSize = imagesize(0,0,399,169);
    ferrariEx = malloc(imgSize);
    getimage(0,0,399,169,ferrariEx);
    cleardevice();
    //Lamborgini Exibiçao:
    readimagefile("Bitmap/CarrosExibicao/LamborginiEx.bmp",0,0,399,169);
    imgSize = imagesize(0,0,399,170);
    lamborginiEx = malloc(imgSize);
    getimage(0,0,399,169,lamborginiEx);
    cleardevice();
    //Dodge Exibicao:
    readimagefile("Bitmap/CarrosExibicao/DodgeEx.bmp",0,0,399,169);
    imgSize = imagesize(0,0,399,170);
    dodgeEx = malloc(imgSize);
    getimage(0,0,399,169,dodgeEx);
    cleardevice();
    //McLaren Exibicao:
    readimagefile("Bitmap/CarrosExibicao/McLarenEx.bmp",0,0,399,169);
    imgSize = imagesize(0,0,399,170);
    mcLarenEx = malloc(imgSize);
    getimage(0,0,399,169,mcLarenEx);
    cleardevice();
    //Eclipse Exibicao:
    readimagefile("Bitmap/CarrosExibicao/EclipseEx.bmp",0,0,399,169);
    imgSize = imagesize(0,0,399,170);
    eclipseEx = malloc(imgSize);
    getimage(0,0,399,169,eclipseEx);
    cleardevice();
    //Mercedes Exibicao:
    readimagefile("Bitmap/CarrosExibicao/MercedesEx.bmp",0,0,399,169);
    imgSize = imagesize(0,0,399,170);
    mercedesEx = malloc(imgSize);
    getimage(0,0,399,169,mercedesEx);
    cleardevice();

    //Mascaras Exibicao:

    //Ferrari:
    readimagefile("Bitmap/CarrosExibicao/FerrariMask.bmp",0,0,399,169);
    imgSize = imagesize(0,0,399,169);
    ferrariMask = malloc(imgSize);
    getimage(0,0,399,169,ferrariMask);
    cleardevice();
    //Lamborgini:
    readimagefile("Bitmap/CarrosExibicao/LamborginiMask.bmp",0,0,399,169);
    imgSize = imagesize(0,0,399,170);
    lamborginiMask = malloc(imgSize);
    getimage(0,0,399,169,lamborginiMask);
    cleardevice();
    //Dodge:
    readimagefile("Bitmap/CarrosExibicao/DodgeMask.bmp",0,0,399,169);
    imgSize = imagesize(0,0,399,170);
    dodgeMask = malloc(imgSize);
    getimage(0,0,399,169,dodgeMask);
    cleardevice();
    //McLaren:
    readimagefile("Bitmap/CarrosExibicao/McLarenMask.bmp",0,0,399,169);
    imgSize = imagesize(0,0,399,170);
    mcLarenMask = malloc(imgSize);
    getimage(0,0,399,169,mcLarenMask);
    cleardevice();
    //Eclipse:
    readimagefile("Bitmap/CarrosExibicao/EclipseMask.bmp",0,0,399,169);
    imgSize = imagesize(0,0,399,170);
    eclipseMask= malloc(imgSize);
    getimage(0,0,399,169,eclipseMask);
    cleardevice();
    //Mercedes:
    readimagefile("Bitmap/CarrosExibicao/MercedesMask.bmp",0,0,399,169);
    imgSize = imagesize(0,0,399,170);
    mercedesMask = malloc(imgSize);
    getimage(0,0,399,169,mercedesMask);
    cleardevice();

    //Backgroung exibicao:
    readimagefile("Bitmap/Menu/FundoExibicao.bmp",0,0,799,599);
    imgSize = imagesize(0,0,799,599);
    backGroundEx = malloc(imgSize);
    getimage(0,0,799,599,backGroundEx);
    cleardevice();

    //Imagens dos personagens:

    //Alucard
    readimagefile("Bitmap/Personagens/Alucard.bmp",0,0,99,149);
    imgSize = imagesize(0,0,99,149);
    alucard = malloc(imgSize);
    getimage(0,0,99,149,alucard);
    cleardevice();
    //Crono
    readimagefile("Bitmap/Personagens/Crono.bmp",0,0,99,149);
    imgSize = imagesize(0,0,99,149);
    crono = malloc(imgSize);
    getimage(0,0,99,149,crono);
    cleardevice();
    //Link
    readimagefile("Bitmap/Personagens/Link.bmp",0,0,99,149);
    imgSize = imagesize(0,0,99,149);
    link = malloc(imgSize);
    getimage(0,0,99,149,link);
    cleardevice();
    //PacMan
    readimagefile("Bitmap/Personagens/PacMan.bmp",0,0,99,149);
    imgSize = imagesize(0,0,99,149);
    pacman = malloc(imgSize);
    getimage(0,0,99,149,pacman);
    cleardevice();
    //Rin
    readimagefile("Bitmap/Personagens/Rin.bmp",0,0,99,149);
    imgSize = imagesize(0,0,99,149);
    rin = malloc(imgSize);
    getimage(0,0,99,149,rin);
    cleardevice();
    //Sonic
    readimagefile("Bitmap/Personagens/Sonic.bmp",0,0,99,149);
    imgSize = imagesize(0,0,99,149);
    sonic = malloc(imgSize);
    getimage(0,0,99,149,sonic);
    cleardevice();

    //Imagens Comentadas a parte:

    //Creditos:
    readimagefile("Bitmap/Menu/Credits.bmp",0,0,799,599);
    imgSize = imagesize(0,0,799,599);
    creditos = malloc(imgSize);
    getimage(0,0,799,599,creditos);
    cleardevice();
    //MainMenu:
    readimagefile("Bitmap/Menu/MainMenuBackGround.bmp",0,0,799,599);
    imgSize = imagesize(0,0,799,599);
    mainMenu = malloc(imgSize);
    getimage(0,0,799,599,mainMenu);
    cleardevice();
    //Selecionar Linguagem... Texto:
    readimagefile("Bitmap/Menu/Text.bmp",0,0,599,99);
    imgSize = imagesize(0,0,599,99);
    text = malloc(imgSize);
    getimage(0,0,599,99,text);
    cleardevice();
    //MenuBackGround:
    readimagefile("Bitmap/Menu/MenuBackGround.bmp",0,0,799,599);
    imgSize = imagesize(0,0,799,599);
    menuBG = malloc(imgSize);
    getimage(0,0,799,599,menuBG);
    cleardevice();
    void *aux = &button;
    //BotaoPrincipal:
    readimagefile("Bitmap/Menu/Button.bmp",0,0,399,74);
    imgSize = imagesize(0,0,399,74);
    button = malloc(imgSize);
    getimage(0,0,399,74,button);
    cleardevice();
    //Botao de voltar:
    readimagefile("Bitmap/Menu/Button.bmp",0,0,99,24);
    imgSize = imagesize(0,0,99,24);
    backButton = malloc(imgSize);
    getimage(0,0,99,24,backButton);
    cleardevice();

    readimagefile("Bitmap/Intro/HouseOfWolves.bmp",0,0,799,599);
    imgSize = imagesize(0,0,799,599);
    logo = malloc(imgSize);
    getimage(0,0,799,599,logo);
    cleardevice();

    // Inicia o jogo:
    setactivepage(1);
    setvisualpage(1);
    putimage(0,0,logo,0);
    delay(4000);
    cleardevice();
    settextjustify(CENTER_TEXT,CENTER_TEXT);
    settextstyle(3,HORIZ_DIR,15);
    setcolor(RED);
    outtextxy(400,50,"Giovani Mantovani");
    delay(300);
    outtextxy(400,150,"Guilherme Gondarez");
    delay(300);
    outtextxy(400,250,"Guilerme Henrique");
    delay(300);
    outtextxy(400,350,"Leandro Libanio");
    delay(300);
    outtextxy(400,450,"Igor S. Tolentino");
    delay(300);
    outtextxy(400,550,"Sergio Schapowal");
    delay(4000);
    putimage(0,0,titulo,0);
    delay(3000);
    cleardevice();
    settextjustify(LEFT_TEXT,10);
    SelectLanguage();

}
//______________\\

//Contorno do botão ao clicar:
void ClickDrainButton(int defRecX, int defRecY, int multiX, int multiY){

    for(int i = 0; i<5; i++){

        rectangle(defRecX,defRecY,defRecX+multiX,defRecY+multiY);
        defRecX-= 1;
        defRecY -= 1;
        multiX += 2;
        multiY += 2;

    }

    delay(500);

}
//___________\\

//Controle da tela de selação de servidor e definição do estado da maquina de rede:
void Server(){

    int xTextS;
    int xTextC;
    int xMessage;
    char *server;
    char *client;
    char *startAsText;
    bool clique = false;
    if(portuguese){
        server = "Jogar";
        client = "Fechar";
        startAsText = "Nostalgia Drive";
        xMessage = 220;
        xTextS = 330;
        xTextC = 310;

    }else{
        server = "Play";
        client = "Exit";
        startAsText = "Nostalgia Drive";
        xMessage = 290;
        xTextS = 340;
        xTextC = 340;
    }
    setcolor(RED);
    outtextxy(xTextS,240,server);
    outtextxy(xTextC,415,client);
    setcolor(WHITE);
    outtextxy(xMessage,50,startAsText);
    putimage(0,0,menuBG,1);
    putimage(200,225,button,1);
    putimage(200,400,button,1);

    int x, y;
    //__\\

    while(!clique){

        setcolor(RED);
        getmouseclick(WM_LBUTTONDOWN,x,y);

        if((x>200 && x<600)&&(y>225 && y<300)){

            clique = true;
            servidor = true;
            ClickDrainButton(200,225,400,75);
            cleardevice();
            SelecionaPlayer();

        }else if((x>200 && x<600)&&(y>400 && y<475)){

            clique = true;
            servidor = false;
            ClickDrainButton(200,400,400,75);
            cleardevice();
            window = false;

        }

    }
    //___\\

}
//_________\\

//Selecionar Linguagem:
void  SelectLanguage(){

    //Carregar imagens e textos na tela:
    settextstyle(DEFAULT_FONT,HORIZ_DIR,16);
    setcolor(9);
    outtextxy(290,465,"English");
    outtextxy(265,315,"Português");
    putimage(0,0,menuBG,1);
    putimage(200,300,button,1);
    putimage(200,450,button,1);
    putimage(100,100,text,1);

    //Clique:
    int x, y;
    bool selected = false;

    while(!selected){

        setcolor(RED);
        getmouseclick(WM_LBUTTONDOWN,x,y);
        //Portuguese Button:
        if((x>200 && x<600)&&(y>300&&y<375)){

            ClickDrainButton(200,300,400,75);
            selected = true;
            portuguese = true;

        }

        //English Button:
        if((x>200 && x<600)&&(y>450 && y<525)){

            ClickDrainButton(200,450,400,75);
            selected = true;
            portuguese = false;

        }

    }

    delay(500);
    cleardevice();
    Intro();

}
//_____________________\\

//Tela de creditos:
void Creditos(){

    char *bBack;
    if(portuguese) bBack = "VOLTA"; else bBack = "BACK";
    int x, y;
    bool clique = false;
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    outtextxy(665,530,bBack);
    putimage(0,0,creditos,1);
    putimage(650,525,backButton,1);

    while(!clique){

        getmouseclick(WM_LBUTTONDOWN,x,y);
        if((x>650 && x<750)&&(y>525 && y<550)){

            ClickDrainButton(650,525,100,25);
            clique = true;

        }

    }
    settextstyle(DEFAULT_FONT,HORIZ_DIR,16);
    cleardevice();
    MenuPrincipal();

}
//_________________\\

//Seleção do player:
void SelecionaPlayer(){

    for(int i = 0; i<6; i++){

        player[i] = false;

    }

    char *bBack, *text;
    if(portuguese) text = "Selecione seu personagem"; else text = "Select your character...";
    if(portuguese) bBack = "VOLTA"; else bBack = "BACK";
    setcolor(WHITE);
    outtextxy(50,290,text);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    setcolor(RED);
    outtextxy(675,530,bBack);
    putimage(0,0,menuBG,1);
    putimage(660,525,backButton,1);
    settextstyle(DEFAULT_FONT,HORIZ_DIR,16);
    bool clique = false;
    int x,y,z,w;

    ClickDrainButton(120,50,100,150);//
    putimage(120,50,alucard,0);
    ClickDrainButton(340,50,100,150);//
    putimage(340,50,crono,0);
    ClickDrainButton(540,50,100,150);//
    putimage(540,50,link,0);
    ClickDrainButton(120,400,100,150);//
    putimage(120,400,pacman,0);
    ClickDrainButton(340,400,100,150);//
    putimage(340,400,rin,0);
    ClickDrainButton(540,400,100,150);//
    putimage(540,400,sonic,0);

    while(!clique){

        getmouseclick(WM_LBUTTONDOWN,x,y);
        getmouseclick(WM_RBUTTONDOWN,z,w);
        if((x>660 && x<760)&&(y>525 && y<550)){

            ClickDrainButton(660,525,100,25);
            cleardevice();
            MenuPrincipal();
            clique = true;

        }else if(((x>120 && x<220)&&(y>50 && y<200))&& !player[0]){

            setcolor(BLUE);
            ClickDrainButton(120,50,100,150);
            player[0] = true;
            if(servidor) playerServer = 0; else playerClient = 0;
            clique = true;
            cleardevice();

        }else if(((x>120 && x<220)&&(y>400 && y<550))&& !player[3]){

            setcolor(BLUE);
            ClickDrainButton(120,400,100,150);
            player[3] = true;
            if(servidor) playerServer = 3; else playerClient = 3;
            clique = true;
            cleardevice();

        }else if(((x>340 && x<440)&&(y>50 && y<200))&& !player[1]){

            setcolor(BLUE);
            ClickDrainButton(340,50,100,150);
            player[1] = true;
            if(servidor) playerServer = 1; else playerClient = 1;
            clique = true;
            cleardevice();

        }else if(((x>540 && x<640)&&(y>50 && y<200))&& !player[2]){

            setcolor(BLUE);
            ClickDrainButton(540,50,100,150);
            player[2] = true;
            if(servidor) playerServer = 2; else playerClient = 2;
            clique = true;
            cleardevice();

        }else if(((x>340 && x<440)&&(y>400 && y<550))&& !player[4]){

            setcolor(BLUE);
            ClickDrainButton(340,400,100,150);
            player[4] = true;
            if(servidor) playerServer = 4; else playerClient = 4;
            clique = true;
            cleardevice();

        }else if(((x>540 && x<640)&&(y>400 && y<550))&& !player[5]){

            setcolor(BLUE);
            ClickDrainButton(540,400,100,150);
            player[5] = true;
            if(servidor) playerServer = 5; else playerClient = 5;
            clique = true;
            cleardevice();

        }else if(((z>120 && z<220)&&(w>50 && w<200))&& !player[0]){

            setcolor(BLUE);
            ClickDrainButton(120,50,100,150);
            player[0] = true;
            if(servidor) playerServer = 6; else playerClient = 6;
            clique = true;
            cleardevice();

        }

    }

    cleardevice();
    ConfirmarPersonagem();

}
//_________\\

// Confirmar o personagem:
void ConfirmarPersonagem(){

    char *text; // Texto dos botoes
    settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
    if(portuguese) text = "Volta"; else text = "Back";

    outtextxy(675,530,"Okay");
    outtextxy(525,530,text);

    settextstyle(DEFAULT_FONT,HORIZ_DIR,16);

    putimage(0,0,backGroundEx,1);
    putimage(660,525,backButton,1);
    putimage(510,525,backButton,1);

    bool clique = false;

    int carro, x, y;

    if(portuguese){

        setactivepage(2);


        //CronoCard:
        readimagefile("Bitmap/Menu/Cards/CardsPT/CronoCard.jpg",0,0,199,299);
        imgSize = imagesize(0,0,199,299);
        cronoCard = malloc(imgSize);
        getimage(0,0,199,299,cronoCard);
        cleardevice();
        //Zoom CronoCard;
        readimagefile("Bitmap/Menu/Cards/CardsPT/CronoCard.jpg",0,0,399,599);
        imgSize = imagesize(0,0,399,599);
        zoomCronoCard = malloc(imgSize);
        getimage(0,0,399,599,zoomCronoCard);
        cleardevice();
        //AlucardCard:
        readimagefile("Bitmap/Menu/Cards/CardsPT/AlucardCard.jpg",0,0,199,299);
        imgSize = imagesize(0,0,199,299);
        alucardCard = malloc(imgSize);
        getimage(0,0,199,299,alucardCard);
        cleardevice();
        //Zoom AlucardCard:
        readimagefile("Bitmap/Menu/Cards/CardsPT/AlucardCard.jpg",0,0,399,599);
        imgSize = imagesize(0,0,399,599);
        zoomAlucardCard = malloc(imgSize);
        getimage(0,0,399,599,zoomAlucardCard);
        cleardevice();
        //PacMAnCard:
        readimagefile("Bitmap/Menu/Cards/CardsPT/PacManCard.jpg",0,0,199,299);
        imgSize = imagesize(0,0,199,299);
        pacmanCard = malloc(imgSize);
        getimage(0,0,199,299,pacmanCard);
        cleardevice();
        //Zoom PacManCard:
        readimagefile("Bitmap/Menu/Cards/CardsPT/PacManCard.jpg",0,0,399,599);
        imgSize = imagesize(0,0,399,599);
        zoomPacmanCard = malloc(imgSize);
        getimage(0,0,399,599,zoomPacmanCard);
        cleardevice();
        //RinCard:
        readimagefile("Bitmap/Menu/Cards/CardsPT/RinCard.jpg",0,0,199,299);
        imgSize = imagesize(0,0,199,299);
        rinCard = malloc(imgSize);
        getimage(0,0,199,299,rinCard);
        cleardevice();
        //Zoom RinCard:
        readimagefile("Bitmap/Menu/Cards/CardsPT/RinCard.jpg",0,0,399,599);
        imgSize = imagesize(0,0,399,599);
        zoomRinCard = malloc(imgSize);
        getimage(0,0,399,599,zoomRinCard);
        cleardevice();
        //SonicCard:
        readimagefile("Bitmap/Menu/Cards/CardsPT/SonicCard.jpg",0,0,199,299);
        imgSize = imagesize(0,0,199,299);
        sonicCard= malloc(imgSize);
        getimage(0,0,199,299,sonicCard);
        cleardevice();
        //Zoom sonicCard:
        readimagefile("Bitmap/Menu/Cards/CardsPT/SonicCard.jpg",0,0,399,599);
        imgSize = imagesize(0,0,399,599);
        zoomSonicCard = malloc(imgSize);
        getimage(0,0,399,599,zoomSonicCard);
        cleardevice();
        //LinkCard:
        readimagefile("Bitmap/Menu/Cards/CardsPT/LinkCard.jpg",0,0,199,299);
        imgSize = imagesize(0,0,199,299);
        linkCard = malloc(imgSize);
        getimage(0,0,199,299,linkCard);
        cleardevice();
        //Zoom LinkCard:
        readimagefile("Bitmap/Menu/Cards/CardsPT/LinkCard.jpg",0,0,399,599);
        imgSize = imagesize(0,0,399,599);
        zoomLinkCard = malloc(imgSize);
        getimage(0,0,399,599,zoomLinkCard);
        cleardevice();

    }else{

        setactivepage(2);

        //CronoCard:
        readimagefile("Bitmap/Menu/Cards/CardsEN/CronoCard.jpg",0,0,199,299);
        imgSize = imagesize(0,0,199,299);
        cronoCard = malloc(imgSize);
        getimage(0,0,199,299,cronoCard);
        cleardevice();
        //Zoom CronoCard;
        readimagefile("Bitmap/Menu/Cards/CardsEN/CronoCard.jpg",0,0,399,599);
        imgSize = imagesize(0,0,399,599);
        zoomCronoCard = malloc(imgSize);
        getimage(0,0,399,599,zoomCronoCard);
        cleardevice();
        //AlucardCard:
        readimagefile("Bitmap/Menu/Cards/CardsEN/AlucardCard.jpg",0,0,199,299);
        imgSize = imagesize(0,0,199,299);
        alucardCard = malloc(imgSize);
        getimage(0,0,199,299,alucardCard);
        cleardevice();
        //Zoom AlucardCard:
        readimagefile("Bitmap/Menu/Cards/CardsEN/AlucardCard.jpg",0,0,399,599);
        imgSize = imagesize(0,0,399,599);
        zoomAlucardCard = malloc(imgSize);
        getimage(0,0,399,599,zoomAlucardCard);
        cleardevice();
        //PacMAnCard:
        readimagefile("Bitmap/Menu/Cards/CardsEN/PacManCard.jpg",0,0,199,299);
        imgSize = imagesize(0,0,199,299);
        pacmanCard = malloc(imgSize);
        getimage(0,0,199,299,pacmanCard);
        cleardevice();
        //Zoom PacManCard:
        readimagefile("Bitmap/Menu/Cards/CardsEN/PacManCard.jpg",0,0,399,599);
        imgSize = imagesize(0,0,399,599);
        zoomPacmanCard = malloc(imgSize);
        getimage(0,0,399,599,zoomPacmanCard);
        cleardevice();
        //RinCard:
        readimagefile("Bitmap/Menu/Cards/CardsEN/RinCard.jpg",0,0,199,299);
        imgSize = imagesize(0,0,199,299);
        rinCard = malloc(imgSize);
        getimage(0,0,199,299,rinCard);
        cleardevice();
        //Zoom RinCard:
        readimagefile("Bitmap/Menu/Cards/CardsEN/RinCard.jpg",0,0,399,599);
        imgSize = imagesize(0,0,399,599);
        zoomRinCard = malloc(imgSize);
        getimage(0,0,399,599,zoomRinCard);
        cleardevice();
        //SonicCard:
        readimagefile("Bitmap/Menu/Cards/CardsEN/SonicCard.jpg",0,0,199,299);
        imgSize = imagesize(0,0,199,299);
        sonicCard= malloc(imgSize);
        getimage(0,0,199,299,sonicCard);
        cleardevice();
        //Zoom sonicCard:
        readimagefile("Bitmap/Menu/Cards/CardsEN/SonicCard.jpg",0,0,399,599);
        imgSize = imagesize(0,0,399,599);
        zoomSonicCard = malloc(imgSize);
        getimage(0,0,399,599,zoomSonicCard);
        cleardevice();
        //LinkCard:
        readimagefile("Bitmap/Menu/Cards/CardsEN/LinkCard.jpg",0,0,199,299);
        imgSize = imagesize(0,0,199,299);
        linkCard = malloc(imgSize);
        getimage(0,0,199,299,linkCard);
        cleardevice();
        //Zoom LinkCard:
        readimagefile("Bitmap/Menu/Cards/CardsEN/LinkCard.jpg",0,0,399,599);
        imgSize = imagesize(0,0,399,599);
        zoomLinkCard = malloc(imgSize);
        getimage(0,0,399,599,zoomLinkCard);
        cleardevice();

    }

    setactivepage(1);

    for(int i =0; i<=5;i++){

        if(player[i])carro = i;

    }

    //Confirmar personagem:
    if(carro == 0){

        putimage(50,150,alucardCard,0);
        putimage(300,215,dodgeMask,AND_PUT);
        putimage(300,215,dodgeEx,OR_PUT);

    }else if(carro == 1){

        putimage(50,150,cronoCard,0);
        putimage(300,215,mcLarenMask,AND_PUT);
        putimage(300,215,mcLarenEx,OR_PUT);

    }else if(carro == 2){

        putimage(50,150,linkCard,0);
        putimage(300,215,ferrariMask,AND_PUT);
        putimage(300,215,ferrariEx,OR_PUT);

    }else if(carro == 3){

        putimage(50,150,pacmanCard,0);
        putimage(300,215,lamborginiMask,AND_PUT);
        putimage(300,215,lamborginiEx,OR_PUT);

    }else if(carro == 4){

        putimage(50,150,rinCard,0);
        putimage(300,215,eclipseMask,AND_PUT);
        putimage(300,215,eclipseEx,OR_PUT);

    }else{

        putimage(50,150,sonicCard,0);
        putimage(300,215,mercedesMask,AND_PUT);
        putimage(300,215,mercedesEx,OR_PUT);

    }

    //Laço da selecao de personagem:
    while(!clique){

        getmouseclick(WM_LBUTTONDOWN,x,y);
        if((x>50 && x<250 )&&(y>150 && y<450)){

            ClickDrainButton(50,150,200,300);

            if(carro == 0){

                cleardevice();
                putimage(0,0,backGroundEx,0);
                putimage(200,0,zoomAlucardCard,0);
                delay(5000);
                cleardevice();
                clique = true;
                ConfirmarPersonagem();

            }else if(carro == 1){

                cleardevice();
                putimage(0,0,backGroundEx,0);
                putimage(200,0,zoomCronoCard,0);
                delay(5000);
                cleardevice();
                clique = true;
                ConfirmarPersonagem();

            }else if(carro == 2){

                cleardevice();
                putimage(0,0,backGroundEx,0);
                putimage(200,0,zoomLinkCard,0);
                delay(5000);
                cleardevice();
                clique = true;
                ConfirmarPersonagem();

            }else if(carro == 3){

                cleardevice();
                putimage(0,0,backGroundEx,0);
                putimage(200,0,zoomPacmanCard,0);
                delay(5000);
                cleardevice();
                clique = true;
                ConfirmarPersonagem();

            }else if(carro == 4){

                cleardevice();
                putimage(0,0,backGroundEx,0);
                putimage(200,0,zoomRinCard,0);
                delay(5000);
                cleardevice();
                clique = true;
                ConfirmarPersonagem();

            }else{

                cleardevice();
                putimage(0,0,backGroundEx,0);
                putimage(200,0,zoomSonicCard,0);
                delay(5000);
                cleardevice();
                clique = true;
                ConfirmarPersonagem();

            }

        }else if((x>660 && x<760)&&(y>525 && y<550)){

            ClickDrainButton(660,525,100,25);
            clique = true;

        }else if((x>510 && x<610)&&(y>525 && y<550)){

            ClickDrainButton(510,525,100,25);
            clique = true;
            cleardevice();
            SelecionaPlayer();

        }

    }

    cleardevice();
    SelecionaPista();

}
//__________________\\

//Menu Principal do Jogo:
void MenuPrincipal(){

    bool clique = false;
    int x, y;
    //Configurações iniciais
    settextstyle(DEFAULT_FONT,HORIZ_DIR,16);
    setcolor(9);
    //Texto:
    if(portuguese){

        outtextxy(290,365,"Créditos");
        outtextxy(335,465,"Sair");
        outtextxy(300,265,"Iniciar");

    }else{

        outtextxy(300,365,"Credits");
        outtextxy(335,465,"Exit");
        outtextxy(330,265,"Start");

    }
    //BackGround e Botões Padrão
    putimage(0,0,mainMenu,1);
    putimage(200,450,button,1);
    putimage(200,350,button,1);
    putimage(200,250,button,1);
    //Laço do Menu:
    while(!clique){

        getmouseclick(WM_LBUTTONDOWN,x,y);

        if((x>200 && x<600)&&(y>450 && y<525)){// Botao de sair:

            ClickDrainButton(200,450,400,75);
            clique = true;
            closegraph();

        }else if((x>200 && x<600)&&(y>350 && y<425)){// Botao do creditos:

            ClickDrainButton(200,350,400,75);
            clique = true;
            cleardevice();
            Creditos();

        }else if((x>200 && x<600)&&(y>250 && y<325)){// Botao de iniciar:

            ClickDrainButton(200,250,400,75);
            clique = true;
            cleardevice();
            Server();

        }

    }

}
//___________\\//

void SelecionaPista(){

    int x, y;
    bool clique = false;

    setactivepage(15);

    if(portuguese){

        readimagefile("Bitmap/Menu/SelecaoDePista/SelecaoDeserto.bmp",0,0,349,249);
        imgSize = imagesize(0,0,349,249);
        deserto = malloc(imgSize);
        getimage(0,0,349,249,deserto);
        cleardevice();

        readimagefile("Bitmap/Menu/SelecaoDePista/SelecaoNoite.bmp",0,0,349,249);
        imgSize = imagesize(0,0,349,249);
        noite = malloc(imgSize);
        getimage(0,0,349,249,noite);
        cleardevice();

        readimagefile("Bitmap/Menu/SelecaoDePista/SelecaoNeve.bmp",0,0,349,249);
        imgSize = imagesize(0,0,349,249);
        neve = malloc(imgSize);
        getimage(0,0,349,249,neve);
        cleardevice();

        readimagefile("Bitmap/Menu/SelecaoDePista/SelecaoFloresta.bmp",0,0,349,249);
        imgSize = imagesize(0,0,349,249);
        campo = malloc(imgSize);
        getimage(0,0,349,249,campo);
        cleardevice();

    }else{

        readimagefile("Bitmap/Menu/SelecaoDePista/SelecaoDesert.bmp",0,0,349,249);
        imgSize = imagesize(0,0,349,249);
        deserto = malloc(imgSize);
        getimage(0,0,349,249,deserto);
        cleardevice();

        readimagefile("Bitmap/Menu/SelecaoDePista/SelecaoNight.bmp",0,0,349,249);
        imgSize = imagesize(0,0,349,249);
        noite = malloc(imgSize);
        getimage(0,0,349,249,noite);
        cleardevice();

        readimagefile("Bitmap/Menu/SelecaoDePista/SelecaoSnow.bmp",0,0,349,249);
        imgSize = imagesize(0,0,349,249);
        neve = malloc(imgSize);
        getimage(0,0,349,249,neve);
        cleardevice();

        readimagefile("Bitmap/Menu/SelecaoDePista/SelecaoForest.bmp",0,0,349,249);
        imgSize = imagesize(0,0,349,249);
        campo = malloc(imgSize);
        getimage(0,0,349,249,campo);
        cleardevice();

    }

    setactivepage(1);

    putimage(0,0,menuBG,0);
    putimage(25,25,campo,0);
    putimage(425,25,deserto,0);
    putimage(25,325,noite,0);
    putimage(425,325,neve,0);

    while(!clique){

        getmouseclick(WM_LBUTTONDOWN,x,y);

        if((x>25 && x<375)&&(y>25 && y<275)){
            ClickDrainButton(25,25,350,250);
            pista = 0;
            clique = true;
        }else if((x>425 && x<775)&&(y>25 && y<275)){
            ClickDrainButton(425,25,350,250);
            pista = 1;
            clique = true;
        }else if((x>25 && x< 375)&&(y>325 && y< 575)){
            ClickDrainButton(25,325,350,250);
            pista = 3;
            clique = true;
        }else if((x>425 && x<775)&&(y>325 && y< 575)){
            ClickDrainButton(425,325,350,250);
            pista = 2;
            clique =true;
        }

    }

}
//______________\\//

void Intro(){

    setactivepage(15);
    if(portuguese){

        readimagefile("Bitmap/Intro/IntroPT.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        intro1 = malloc(imgSize);
        getimage(0,0,799,599,intro1);
        cleardevice();

        readimagefile("Bitmap/Intro/IntroPT2.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        intro2 = malloc(imgSize);
        getimage(0,0,799,599,intro2);
        cleardevice();

    }else{

        readimagefile("Bitmap/Intro/IntroEN.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        intro1 = malloc(imgSize);
        getimage(0,0,799,599,intro1);
        cleardevice();

        readimagefile("Bitmap/Intro/IntroEN2.bmp",0,0,799,599);
        imgSize = imagesize(0,0,799,599);
        intro2 = malloc(imgSize);
        getimage(0,0,799,599,intro2);
        cleardevice();

    }

    setactivepage(1);

    putimage(0,0,intro1,0);
    delay(3000);
    cleardevice();
    putimage(0,0,menuBG,0);
    delay(250);
    cleardevice();
    putimage(0,0,intro2,0);
    delay(3000);
    cleardevice();
    MenuPrincipal();

}

void ChamaVitoria(){

    window = false;

    setactivepage(1);
    setvisualpage(1);

	bool clique = false;
	int x, y;

	cleardevice();

	if(portuguese){

	    readimagefile("Bitmap/Menu/Fim/Ganhou.bmp",0,0,799,599);
	    imgSize = imagesize(0,0,799,599);
	    vitoria = malloc(imgSize);
	    getimage(0,0,799,599,vitoria);
	    cleardevice();

	}else{

	    readimagefile("Bitmap/Menu/Fim/Win.bmp",0,0,799,599);
	    imgSize = imagesize(0,0,799,599);
	    vitoria = malloc(imgSize);
	    getimage(0,0,799,599,vitoria);
	    cleardevice();

	}

	putimage(0,0,vitoria,0);

	while(!clique){

        getmouseclick(WM_LBUTTONDOWN, x,y);

        if((x>295 && x<505)&& (y > 485 && y<540)){

        	ClickDrainButton(295,485,210,65);
        	clique = true;

		}

	}

	window = false;
	closegraph();

}

void ChamaPerda(){

    window = false;

    setactivepage(1);
    setvisualpage(1);

	bool clique = false;
	int x, y;

	if(portuguese){

	    readimagefile("Bitmap/Menu/Fim/Perdeu.bmp",0,0,799,599);
	    imgSize = imagesize(0,0,799,599);
	    derrota = malloc(imgSize);
	    getimage(0,0,799,599,derrota);
	    cleardevice();

	}else{

	    readimagefile("Bitmap/Menu/Fim/Lose.bmp",0,0,799,599);
	    imgSize = imagesize(0,0,799,599);
	    derrota = malloc(imgSize);
	    getimage(0,0,799,599,derrota);
	    cleardevice();

	}

	putimage(0,0,derrota,0);
	while(!clique){

        getmouseclick(WM_LBUTTONDOWN, x,y);

        if((x>295 && x<505)&& (y > 485 && y<540)){

        	ClickDrainButton(295,485,210,65);
        	clique = true;

		}

	}
	cleardevice();
	window = false;
	closegraph();

}

