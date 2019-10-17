#include <conio.h>
#include <graphics.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <winuser.h>
#pragma comment(lib,"ws2_32.lib")

#define LEFT   	75
#define RIGHT  	77
#define UP     	72
#define DOWN   	80
#define ESC    	27
#define ENTER   13
#define A       97
#define S       115
#define J       106
#define L       108
#define BKSP    8
#define TAB     9

using namespace std;

/*Variáveis Boleanas.*/

bool on = false;
bool on1 = false;

/*Variáveis para controle de fluxo.*/

int i;
int shoot;
int trajetoria = 0;
/*Variáveis para controlar a movimentação de imagens.*/

//##############################################################################//

/*Coordenadas X e Y da imagem de fundo.*/

int fx = 0;                                      //Coordenada X da imagem de fundo.
int fy = -1320;                                  //Coordenada Y da imagem de fundo.

/*Coordenadas X e Y da primeira nave.*/

int nx_1 = 150;                                  //Coordenada X da primeira nave.
int ny_1 = 400;                                  //Coordenada Y da primeira nave.

/*Coordenadas X e Y da segunda nave.*/

int nx_2 = 550;                                  //Coordenada X da segunda nave.
int ny_2 = 400;                                  //Coordenada Y da segunda nave.

/*Coordenadas X e Y do primeiro inimigo.*/

int ix_1 = 0;                                    //Coordenada X do primeiro inimigo.
int iy_1 = 0;                                    //Coordenada Y do primeiro inimigo.

/*Coordenadas X e Y do segundo inimigo.*/

int ix_2 = 0;                                    //Coordenada X do segundo inimigo.
int iy_2 = 0;                                    //Coordenada Y do segundo inimigo.

/*Coordenadas X e Y do terceiro inimigo.*/

int ix_3 = 0;                                    //Coordenada X do terceiro inimigo.
int iy_3 = 0;                                    //Coordenada Y do terceiro inimigo.

/*Coordenadas X e Y do quarto inimigo.*/

int ix_4 = 0;                                    //Coordenada X do quarto inimigo.
int iy_4 = 0;                                    //Coordenada Y do quarto inimigo.

/*Coordenadas X e Y do tiro.*/

int tx = 0;                                      //Coordenada X do tiro.
int ty = 350;                                    //Coordenada Y do tiro.

//##############################################################################//

/*Variáveis para controle de E/S.*/

char t = 0;

/*Variáveis para armazenar o tamanho das imagens.*/

int size;

/*Ponteiros.*/

void *background;
void *p1;
void *p2;
void *p3;
void *p4;
void *p5;
void *p6;
void *p7;
void *p8;
void *p9;
void *p10;
void *p11;
void *p12;
void *p13;
void *p14;
void *p15;
void *p16;
void *p17;
void *p18;
void *nv_bulma;
void *nv_kagome;
void *nv_motoko;
void *nv_rei;
void *nv_sailormoon;
void *nv_sakura;
void *nv_sombra;



/*Função Void que aloca as imagens.*/

void img()
{
     setvisualpage(15);
     setactivepage(16);
     
     
     //Fundo.
     
     readimagefile("f.bmp", 0, 0, 799, 599);
     size = imagesize(0, 0, 799, 599);
     p1 = malloc(size);
     getimage(0, 0, 799, 599, p1);
     cleardevice();
     
     //Máscara da Nave.
     
     readimagefile("ns.bmp", 0, 0, 99, 167);
     size = imagesize(0, 0, 99, 167);
     p2 = malloc(size);
     getimage(0, 0, 99, 167, p2);
     cleardevice();
     
     //Nave - Player 1.
     
     readimagefile("n1.bmp", 0, 0, 99, 167);
     size = imagesize(0, 0, 99, 167);
     p3 = malloc(size);
     getimage(0, 0, 99, 167, p3);
     cleardevice();
     
     //Máscara do Tiro.
     
     readimagefile("ts.bmp", 0, 0, 14, 47);
     size = imagesize(0, 0, 14, 47);
     p4 = malloc(size);
     getimage(0, 0, 14, 47, p4);
     cleardevice();
     
     //Tiro.
     
     readimagefile("t.bmp", 0, 0, 14, 47);
     size = imagesize(0, 0, 14, 47);
     p5 = malloc(size);
     getimage(0, 0, 14, 47, p5); 
     cleardevice();
     
     //Obstáculo.
     
     readimagefile("obs.bmp", 0, 0, 39, 39);
     size = imagesize(0, 0, 39, 39);
     p6 = malloc(size);
     getimage(0, 0, 39, 39, p6);
     cleardevice();
     
     //Rayearth - Sombra.
     
     readimagefile("rs.bmp", 0, 0, 499, 732);
     size = imagesize(0, 0, 499, 732);
     p7 = malloc(size);
     getimage(0, 0, 499, 732, p7);
     cleardevice();
     
     //Rayearth.
     
     readimagefile("r.bmp", 0, 0, 499, 732);
     size = imagesize(0, 0, 499, 732);
     p8 = malloc(size);
     getimage(0, 0, 499, 732, p8);
     cleardevice(); 
     
     //Nave - Player 2.
     
     readimagefile("n2.bmp", 0, 0, 99, 167);
     size = imagesize(0, 0, 99, 167);
     p9 = malloc(size);
     getimage(0, 0, 99, 167, p9);
     cleardevice();
     
     //Inimigo 1 - Máscara.
     
     readimagefile("a1s.bmp", 0, 0, 79, 151);
     size = imagesize(0, 0, 79, 151);
     p10 = malloc(size);
     getimage(0, 0, 79, 151, p10);
     cleardevice();
     
     //Inimigo 1.
     
     readimagefile("a1.bmp", 0, 0, 79, 151);
     size = imagesize(0, 0, 79, 151);
     p11 = malloc(size);
     getimage(0, 0, 79, 151, p11);
     cleardevice();
     
     //Inimigo 2 - Máscara.
     
     readimagefile("a2s.bmp", 0, 0, 124, 237);
     size = imagesize(0, 0, 124, 237);
     p12 = malloc(size);
     getimage(0, 0, 124, 237, p12);
     cleardevice();
     
     //Inimigo 2.
     
     readimagefile("a2.bmp", 0, 0, 124, 237);
     size = imagesize(0, 0, 124, 237);
     p13 = malloc(size);
     getimage(0, 0, 124, 237, p13);
     cleardevice();
     
     //Inimigo 3 - Máscara.
     
     readimagefile("a3s.bmp", 0, 0, 124, 237);
     size = imagesize(0, 0, 124, 237);
     p14 = malloc(size);
     getimage(0, 0, 124, 237, p14);
     cleardevice();
     
     //Inimigo 3.
     
     readimagefile("a3.bmp", 0, 0, 124, 237);
     size = imagesize(0, 0, 124, 237);
     p15 = malloc(size);
     getimage(0, 0, 124, 237, p15);
     cleardevice();
     
     //Inimigo 4 - Máscara.
     
     readimagefile("a4s.bmp", 0, 0, 113, 199);
     size = imagesize(0, 0, 113, 199);
     p16 = malloc(size);
     getimage(0, 0, 113, 199, p16);
     cleardevice();
     
     //Inimigo 4.
     
     readimagefile("a4.bmp", 0, 0, 113, 199);
     size = imagesize(0, 0, 113, 199);
     p17 = malloc(size);
     getimage(0, 0, 113, 199, p17);
     cleardevice();
     
     //Nave Bulma.
     
     readimagefile("n_bulma.bmp", 0, 0, 99, 167);
     size = imagesize(0, 0, 99, 167);
     nv_bulma = malloc(size);
     getimage(0, 0, 99, 167, nv_bulma);
     cleardevice();
     
     //Nave Kagome.
     
     readimagefile("n_kagome.bmp", 0, 0, 99, 167);
     size = imagesize(0, 0, 99, 167);
     nv_kagome = malloc(size);
     getimage(0, 0, 99, 167, nv_kagome);
     cleardevice();
     
     //Nave Motoko.
     
     readimagefile("n_motoko.bmp", 0, 0, 99, 167);
     size = imagesize(0, 0, 99, 167);
     nv_motoko = malloc(size);
     getimage(0, 0, 99, 167, nv_motoko);
     cleardevice();
     
     //Nave Rei.
     
     readimagefile("n_rei.bmp", 0, 0, 99, 167);
     size = imagesize(0, 0, 99, 167);
     nv_rei = malloc(size);
     getimage(0, 0, 99, 167, nv_rei);
     cleardevice();
     
     //Nave Sailor Moon.
     
     readimagefile("n_sailormoon.bmp", 0, 0, 99, 167);
     size = imagesize(0, 0, 99, 167);
     nv_sailormoon = malloc(size);
     getimage(0, 0, 99, 167, nv_sailormoon);
     cleardevice();
     
     //Nave Sakura.
     
     readimagefile("n_sakura.bmp", 0, 0, 99, 167);
     size = imagesize(0, 0, 99, 167);
     nv_sakura = malloc(size);
     getimage(0, 0, 99, 167, nv_sakura);
     cleardevice();
     
     //Máscara das naves das Waifus.
     
     readimagefile("n_s.bmp", 0, 0, 99, 167);
     size = imagesize(0, 0, 99, 167);
     nv_sombra = malloc(size);
     getimage(0, 0, 99, 167, nv_sombra);
     cleardevice();
     
     
}

/*Função Void que aloca a imagem de fundo.*/

void first_background()
{
    setvisualpage(15);
    setactivepage(16);
    readimagefile("p.bmp", 0, 0, 1079, 1919);
    size = imagesize(0, 0, 1079, 1919);
    background = malloc(size);
    getimage(0, 0, 1079, 1919, background);
}

/*Função Void que exibe na tela todas as imagens usadas em simulação.*/

void game()
{
    putimage(fx, fy, background, 0);           //Exibe a imagem de fundo.
    putimage(nx_1, ny_1, nv_sombra, 3);               //Exibe a máscara da primeira nave.
    putimage(nx_1, ny_1, nv_sailormoon, 2);               //Exibe a imagem da primeira nave.
    putimage(nx_2, ny_2, nv_sombra, 3);               //Exibe a máscara da segunda nave.
    putimage(nx_2, ny_2, nv_sakura, 2);               //Exibe a imagem da segunda nave. 
}

void enemy()
{
     putimage(ix_3, iy_3, p14, 3);
     putimage(ix_3, iy_3, p15, 2);
}

void enemies()
{
     putimage(ix_1, iy_1, p10, 3);
     putimage(ix_1, iy_1, p11, 2);
}

void tiro()
{
     tx = nx_1 + 43;
     ty -= 10;
     putimage(tx, ty, p4, 3);
     putimage(tx, ty, p5, 2);
}

/*Função int que estabelece uma conexão como servidor.*/

int network_server()
{
    WSADATA WsaDat;
    if(WSAStartup(MAKEWORD(2,2),&WsaDat)!=0)
    {
         std::cout<<"WSA Initialization failed!\r\n";
         WSACleanup();
         system("PAUSE");
         return 0;
    }
    
    SOCKET Socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
                        
    if(Socket==INVALID_SOCKET)
    {
         std::cout<<"Socket creation failed.\r\n";
         WSACleanup();
         system("PAUSE");
         return 0;
    }
	
    SOCKADDR_IN serverInf;
    serverInf.sin_family=AF_INET;
    serverInf.sin_addr.s_addr=INADDR_ANY;
    serverInf.sin_port=htons(8888);

    if(bind(Socket,(SOCKADDR*)(&serverInf),sizeof(serverInf))==SOCKET_ERROR)
    {
         std::cout<<"Unable to bind socket!\r\n";
         WSACleanup();
         system("PAUSE");
         return 0;
    }

    listen(Socket,1);

    SOCKET TempSock=SOCKET_ERROR;
    while(TempSock==SOCKET_ERROR)
    {
         std::cout<<"\nAlcateia iniciada !\n";
         std::cout<<"Waiting for incoming connections...\r\n";
         TempSock=accept(Socket,NULL,NULL);
    }
                        
    Socket=TempSock;
}

/*Função int que estabelece uma conexão como client.*/

int network_client()
{
    WSADATA WsaDat;
    if(WSAStartup(MAKEWORD(2,2),&WsaDat)!=0)
    {
         std::cout<<"Winsock error - Winsock initialization failed\r\n";
         WSACleanup();
         system("PAUSE");
         return 0;
    }
    
    SOCKET Socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
                        
    if(Socket==INVALID_SOCKET)
    {
         std::cout<<"Winsock error - Socket creation Failed!\r\n";
         WSACleanup();
         system("PAUSE");
         return 0;
    }
                        
    struct hostent *host;
    if((host=gethostbyname("localhost"))==NULL)
    {
         std::cout<<"Failed to resolve hostname.\r\n";
         WSACleanup();
         system("PAUSE");
         return 0;
    }

    SOCKADDR_IN SockAddr;
    SockAddr.sin_port=htons(8888);
    SockAddr.sin_family=AF_INET;
    SockAddr.sin_addr.s_addr = *((unsigned long*) host -> h_addr);//inet_addr("192.168.0.101");
                        
    if(connect(Socket,(SOCKADDR*)(&SockAddr),sizeof(SockAddr))!=0)
    {
         std::cout<<"Failed to establish connection with server\r\n";
         WSACleanup();
         system("PAUSE");
         return 0;
    }
}

/*Função Principal.*/

int main()
{
    
    WSADATA WsaDat;
    if(WSAStartup(MAKEWORD(2,2),&WsaDat)!=0)
    {
         std::cout<<"Winsock error - Winsock initialization failed\r\n";
         WSACleanup();
         system("PAUSE");
         return 0;
    }
    
    SOCKET Socket = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
                        
    if(Socket==INVALID_SOCKET)
    {
         std::cout<<"Winsock error - Socket creation Failed!\r\n";
         WSACleanup();
         system("PAUSE");
         return 0;
    }
    
    bool jogo_offline = false;
    bool servidor = false;
    bool cliente = false;
    
    /*Inicializa a imagem de fundo em outra janela*/
    
    initwindow(1080, 1920);
    first_background();
    closegraph();
    
    /*Faz uma pausa com o tempo determinado pelo programador.*/ 
    
    delay(100);
    
    /*Inicializa a janela onde o jogo será exibido.*/
    
    initwindow(800, 600, "Waifu Wars !");
    img();                                       //Chama a função "void img()".
    //network_server();                          //Chama a função "void network_server()".
    
    setactivepage(15);
    
    /*Exibição de imagens.*/
    
    putimage(fx, fy, background, 0);           //Exibe a imagem de fundo.
    putimage(nx_1, ny_1, nv_sombra, 3);               //Exibe a máscara da primeira nave.
    putimage(nx_1, ny_1, nv_sailormoon, 2);               //Exibe a imagem da primeira nave.
    putimage(nx_2, ny_2, nv_sombra, 3);               //Exibe a máscara da segunda nave.
    putimage(nx_2, ny_2, nv_sakura, 2);               //Exibe a imagem da segunda nave.
    
    /*Linhas de referência.*/
    
    line(200, 0, 200, 600);                      //Exibe uma linha de corte vertical y/4
    line(400, 0, 400, 600);                      //Exibe uma linha de corte vertical y/2.
    line(600, 0, 600, 600);                      //Exibe uma linha de corte vertical y/0,5.
    
    setvisualpage(15);
    //while(!kbhit());                           //Espera o usuário entrar com uma tecla.
    
    getch();
    
    if(GetKeyState(BKSP)&0x80)
    {                         
                              SOCKADDR_IN serverInf;
                              serverInf.sin_family=AF_INET;
                              serverInf.sin_addr.s_addr=INADDR_ANY;
                              serverInf.sin_port=htons(8888);

                              if(bind(Socket,(SOCKADDR*)(&serverInf),sizeof(serverInf))==SOCKET_ERROR)
                              {
                                       std::cout<<"Unable to bind socket!\r\n";
                                       WSACleanup();
                                       system("PAUSE");
                                       return 0;
                              }

                              listen(Socket,1);

                              SOCKET TempSock=SOCKET_ERROR;
                              while(TempSock==SOCKET_ERROR)
                              {
                                       std::cout<<"\nAlcateia iniciada !\n";
                                       std::cout<<"Waiting for incoming connections...\r\n";
                                       TempSock=accept(Socket,NULL,NULL);
                              }
                        
                              Socket=TempSock;
                              on = true;
                              servidor = true;
    }
    
    if(GetKeyState(TAB)&0x80)
    {
                             struct hostent *host;
                             if((host=gethostbyname("localhost"))==NULL)
                             {
                                       std::cout<<"Failed to resolve hostname.\r\n";
                                       WSACleanup();
                                       system("PAUSE");
                                       return 0;
                             }

                             SOCKADDR_IN SockAddr;
                             SockAddr.sin_port=htons(8888);
                             SockAddr.sin_family=AF_INET;
                             SockAddr.sin_addr.s_addr = inet_addr("192.168.0.101");
                        
                             if(connect(Socket,(SOCKADDR*)(&SockAddr),sizeof(SockAddr))!=0)
                             {
                                       std::cout<<"Failed to establish connection with server\r\n";
                                       WSACleanup();
                                       system("PAUSE");
                                       return 0;
                             }
                             
                             on = true;
                             cliente = true;
                             
    }
    
    if(GetKeyState(ENTER)&0x80)
    {
                               on = true;
                               on1 = true;
    }
    
    while(on)                                    //Loop usado para realizar simulações.
    {
             while(jogo_offline)                 //Verifica se a tecla ENTER foi pressionada.
             {
                   on1 = true;                   //Define como verdadeira a variável boleana "on1".
                   jogo_offline = false;                   
             }
             
             while(servidor)
             {
                        bool server = true;
                        while(server)
                        {
                             cout<<"Alcateia Conectada !";
                             bool server_test = true;
                             
                             while(server_test)
                             {
                                  char *rede;
                                  if(GetKeyState(VK_LEFT)&0x80)
                                  {
                                       nx_1 -= 10;
                                       if(i == 2) i = 1; else i = 2;
                                       setactivepage(i);
                                       game();             //Chama a função "void game()".
                                       setvisualpage(i);
                                       rede = "75";
                                       send(Socket, rede, strlen(rede), 0);
                                       std::cout<<"\nLeft";
                                  }
                                  
                                  if(GetKeyState(VK_RIGHT)&0x80)
                                  {
                                       nx_1 += 10;
                                       if(i == 2) i = 1; else i = 2;
                                       setactivepage(i);
                                       game();             //Chama a função "void game()".
                                       setvisualpage(i);
                                       rede = "77";
                                       send(Socket, rede, strlen(rede), 0);
                                       std::cout<<"\nRight";
                                  }
                             }
                        }
             }
             
             while(cliente)
             {          
                        bool client = true;
                        
                        while(client)
                        {
                             cout<<"Lobo Conectado !";
                             bool client_test = true;
                             
                             while(client_test)
                             {
                                  char pacote[1000];
                                  memset(pacote, 0, 999);
                                  int r = recv(Socket, pacote, 1000, 0);
                                  int c = atoi(pacote);
                                  
                                  if(c == 75)
                                  {
                                       
                                       nx_1 -= 10;
                                       if(i == 2) i = 1; else i = 2;
                                       setactivepage(i);
                                       game();             //Chama a função "void game()".
                                       setvisualpage(i);
                                       cout<<"\nLEFT Recebido!";
                                  }
                                  
                                  if(c == 77)
                                  {
                                       nx_1 += 10;
                                       if(i == 2) i = 1; else i = 2;
                                       setactivepage(i);
                                       game();             //Chama a função "void game()".
                                       setvisualpage(i);
                                       cout<<"\nRIGHT Recebido!";
                                  }
                                               
                             }          
                        }
             }
             
             if(on1)
             {
                   bool offline = true;              //Declara uma variável boleana e define como verdadeira.  
                   bool inimigo = false;
                   bool inimigos = false;
                   i = 1;
                   
                   int a = 1;
                   while(offline)                    //Loop usado para simular a movimentação de cenário.
                   {
                             //i = 1;            //Variável usada para controlar a troca de páginas.
                             bool movimento = true;
                             
                             if(i == 2) i = 1; else i = 2;
                             
                             setactivepage(i);   
                             trajetoria += 10;
                             fy += 10;           //Movimenta a imagem de fundo em 10 pixels a cada ciclo.
                             game();             //Chama a função "void game()".
                             //enemy();
                             
                             cout << trajetoria << "\n";
                             
                             if(trajetoria >= 2000)
                             {
                                     enemies();
                                     inimigos = true;      
                             }
                             
                             if(inimigos) 
                             {
                                     ix_1 = nx_1;
                                     iy_1 += 10;
                             }
                             
                             if(inimigo == false) 
                             {
                                     ix_3 += 10;
                                     //cout << "\nMovimento feito." << a;
                                     a += 1;
                                     if(ix_3 >= 675) 
                                     {
                                             inimigo = true;
                                             //cout << "\nFinal Alcançado !";
                                     }
                             }
                             
                             if(ix_3 <= 0) inimigo = false;
                             
                             if(inimigo == true)
                             {
                                     ix_3 -= 10;
                                     //cout << "\nInimigo Verdadeira.";
                             }
                             setvisualpage(i);
                             
                             
                             if(fy >= 0) fy = -1320;           //Verifica se a imagem chegou ao fim e reseta sua posição original.
                             if(nx_1 <= 0) nx_1 = 0;           //Verifica se a imagem da primeira nave ultrapassou o limite de 0.
                             if(nx_1 >= 700) nx_1 = 700;       //Verifica se a imagem da primeira nave ultrapassou o limite de 700.
                             if(nx_2 <= 0) nx_2 = 0;           //Verifica se a imagem da segunda nave ultrapassou o limite de 0.
                             if(nx_2 >= 700) nx_2 = 700;       //Verifica se a imagem da segunda nave ultrapassou o limite de 700.
                             if(ix_1 == 0) ix_1 = 0;           //Verifica se a imagem do primeiro inimigo ultrapassou o limite de 0.
                             if(ix_1 >= 634)                   //Verifica se a imagem do primeiro inimigo ultrapassou o limite de 634.
                             {
                                     ix_1 -= 10;
                             }
                             
                             /*Parte que controla a E/S de dados durante a simulação.*/
                             
                             if(GetKeyState(VK_LEFT)&0x80)  nx_1 -= 10;
                             if(GetKeyState(VK_RIGHT)&0x80) nx_1 += 10;
                             if(GetKeyState(VK_UP)&0x80)    nx_2 -= 10;
                             if(GetKeyState(VK_DOWN)&0x80)  nx_2 += 10;
                             if(GetKeyState(ENTER)&0x80)
                             {
                                  //ty -= 10;
                                  tiro();
                                  cout << tx << "  " << ty << "\n";
                                  if(ty <= 0) ty = 350;
                                  if(ty == iy_3 + 238) cout << "\nAtingido.";
                             }
                   }
             }
    }
    
    
}




/*
if(i == 2) i = 1; else i = 2;
setactivepage(i);   
fy += 10;           //Movimenta a imagem de fundo em 10 pixels a cada ciclo.
game();             //Chama a função "void game()".
setvisualpage(i);
                             
if(fy >= 0) fy = -1320; //Verifica se a imagem chegou ao fim e reseta sua posição original.
*/
                               
