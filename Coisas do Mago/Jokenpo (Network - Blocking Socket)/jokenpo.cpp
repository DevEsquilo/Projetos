#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <winuser.h>
#pragma comment(lib,"ws2_32.lib")

#pragma comment(lib, "ws2_32.lib")

using namespace std;
int entrada;
int escolha;
bool client = false;
bool server = false;

int main()
{
    printf("\t\t\t|----*----*----*----*----*----*----|\n");
    printf("\t\t\t|         Modo de Programa         |\n");
    printf("\t\t\t|----*----*----*----*----*----*----|\n");
    printf("\t\t\t|    Client      |       Server    |\n");
    printf("\t\t\t|----*----*----*----*----*----*----|\n");
    printf("\t\t\t|       0        |          1      |\n");
    printf("\t\t\t|----*----*----*----*----*----*----|\n");
    printf("\n\n\tEscolha o modo de programa: ");
    scanf("%d",&entrada);
    
    printf("\t\n");
    
    printf("\t\t\t|----*----*----*----*----*----*----|\n");
    printf("\t\t\t|        Jokenpo - Escolhas        |\n");
    printf("\t\t\t|----*----*----*----*----*----*----|\n");
    printf("\t\t\t|     Papel      |          1      |\n");
    printf("\t\t\t|----*----*----*----*----*----*----|\n");
    printf("\t\t\t|     Pedra      |          2      |\n");
    printf("\t\t\t|----*----*----*----*----*----*----|\n");
    printf("\t\t\t|    Tesoura     |          3      |\n");
    printf("\t\t\t|----*----*----*----*----*----*----|\n");
    
    printf("\n\n\tEscolha uma opcao: ");
    scanf("%d",&escolha);

    
    if(entrada == 0)  //Verifica se o usuário escolheu usar o jogo como Client;
    {
        client = true; //Define o funcionamento do jogo como Client;
               
        while (client)
        {
            WSADATA WsaDat;
            if(WSAStartup(MAKEWORD(2,2), &WsaDat)!=0) //Inicializa a biblioteca Winsock2.h;
            {
                  printf("Winsock error - Winsock initialization failed\r\n");
                  WSACleanup();
                  system("PAUSE");
                  return 0;
            }
            
            SOCKET Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //Cria o socket;
            
            if(Socket == INVALID_SOCKET) //Verifica se o socket foi criado com sucesso;
            {
                  printf("Winsock error - Socket creation Failed!\r\n");
                  WSACleanup();
                  system("PAUSE");
                  return 0;
            }
            
            struct hostent *host;
            
            if((host = gethostbyname("localhost")) == NULL) //Inicializa o modo de rede local;
            {
                  printf("Failed to resolve hostname.\r\n");
                  WSACleanup();
                  system("PAUSE");
                  return 0;
            }
            
            /* Configuracao de porta, familia de socket e endereco de IP do server; */
            
            SOCKADDR_IN SockAddr;
            SockAddr.sin_port = htons(8888); // Configuracao de porta;
            SockAddr.sin_family = AF_INET; //Configuracao de familia de socket;
            SockAddr.sin_addr.s_addr = *((unsigned long*) host -> h_addr); //Configuracao de endereco de IP, substituir depois do igual por: inet_addr("192.168.0.101"); para poder se conectar ao IP do server;
            
            if(connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr))!=0) //Verifica se a conexao com o server foi bem sucedida;
            {
                  printf("Failed to establish connection with server\r\n");
                  WSACleanup();
                  system("PAUSE");
                  return 0;
            }
            
            if(escolha == 1){     //Verifica a escolha feita.
                       
                char *mensagem = "1";        //Ponteiro que armazena o valor da escolha em forma de char;
                send(Socket, mensagem, strlen(mensagem), 0);         //Comando que envia a escolha para o endereco de IP configurado;
            
            }
            
            if(escolha == 2){
                       
                char *mensagem = "2";
                send(Socket, mensagem, strlen(mensagem), 0);
            
            }
            
            if(escolha == 3){
                       
                char *mensagem = "3";
                send(Socket, mensagem, strlen(mensagem), 0);
            
            }
            
            /*Recepcao dos dados; */
            
            char buffer[1000];    //String que ira receber o valor da escolha do outro jogador;
            memset(buffer, 0, 999);        
            int inDataLength = recv(Socket, buffer, 1000, 0);      //recv: funcao que insere o valor da escolha do outro jogador na string buffer[1000];
            int data = atoi(buffer);        //atoi(string): funcao que converte para inteiro o conteudo de uma string;
            
            cout << "\t\n";
            
            if(escolha == data) cout << "\tEmpate\n";
            
            if(escolha == 1 && data == 2) cout << "\tVoce ganhou ! - Sua jogada: Papel - Jogada Inimiga: Pedra\n";
            if(escolha == 2 && data == 3) cout << "\tVoce ganhou ! - Sua jogada: Pedra - Jogada Inimiga: Tesoura\n";
            if(escolha == 3 && data == 1) cout << "\tVoce ganhou ! - Sua jogada: Tesoura - Jogada Inimiga: Papel\n";
            
            if(escolha == 1 && data == 3) cout << "\tVoce perdeu ! - Sua jogada: Papel - Jogada Inimiga: Tesoura\n";
            if(escolha == 2 && data == 1) cout << "\tVoce perdeu ! - Sua jogada: Pedra - Jogada Inimiga: Papel\n";
            if(escolha == 3 && data == 2) cout << "\tVoce perdeu ! - Sua jogada: Tesoura - Jogada Inimiga: Pedra\n";
            
            cout << "\t\n";
            
            shutdown(Socket, SD_SEND);
            
            closesocket(Socket);
            
            WSACleanup();
            system("PAUSE");
            return 0;
            
        }
    }
    
    if(entrada == 1)
    {
        server = true;
            
        while(server)
        {
            WSADATA WsaDat;
            
            if(WSAStartup(MAKEWORD(2,2), &WsaDat)!=0)
            {
                  printf("WSA Initialization failed!\r\n");
                  WSACleanup();
                  system("PAUSE");
                  return 0;
            }
            
            SOCKET Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            
            if(Socket == INVALID_SOCKET)
            {
                  printf("Socket creation failed.\r\n");
                  WSACleanup();
                  system("PAUSE");
                  return 0;        
            }
            
            SOCKADDR_IN serverInf;
            serverInf.sin_family = AF_INET;
            serverInf.sin_addr.s_addr = INADDR_ANY;
            serverInf.sin_port = htons(8888);
            
            if(bind(Socket, (SOCKADDR*)(&serverInf), sizeof(serverInf)) == SOCKET_ERROR)
            {
                  printf("Unable to bind socket!\r\n");
                  WSACleanup();
                  system("PAUSE");
                  return 0; 
            }
            
            listen(Socket, 1);
            
            SOCKET TempSock = SOCKET_ERROR;
            
            while (TempSock == SOCKET_ERROR)
            {
                  printf("\n\tEsperando por conexoes...");
                  TempSock = accept(Socket, NULL, NULL);
            }
            
            Socket = TempSock;
            
            printf("\n\tClient Conectado !\n\n");
            
            if(escolha == 1){
                       
                char *mensagem = "1";
                send(Socket, mensagem, strlen(mensagem), 0);
            
            }
            
            if(escolha == 2){
                       
                char *mensagem = "2";
                send(Socket, mensagem, strlen(mensagem), 0);
            
            }
            
            if(escolha == 3){
                       
                char *mensagem = "3";
                send(Socket, mensagem, strlen(mensagem), 0);
            
            }
                
            char buffer[1000];
            memset(buffer, 0, 999);
            int inDataLength = recv(Socket, buffer, 1000, 0);
            int data = atoi(buffer);
            
            if(escolha == data) cout << "\tEmpate\n";
            
            if(escolha == 1 && data == 2) cout << "\tVoce ganhou ! - Sua jogada: Papel - Jogada Inimiga: Pedra\n";
            if(escolha == 2 && data == 3) cout << "\tVoce ganhou ! - Sua jogada: Pedra - Jogada Inimiga: Tesoura\n";
            if(escolha == 3 && data == 1) cout << "\tVoce ganhou ! - Sua jogada: Tesoura - Jogada Inimiga: Papel\n";
            
            if(escolha == 1 && data == 3) cout << "\tVoce perdeu ! - Sua jogada: Papel - Jogada Inimiga: Tesoura\n";
            if(escolha == 2 && data == 1) cout << "\tVoce perdeu ! - Sua jogada: Pedra - Jogada Inimiga: Papel\n";
            if(escolha == 3 && data == 2) cout << "\tVoce perdeu ! - Sua jogada: Tesoura - Jogada Inimiga: Pedra\n";
            
            printf("\n\t");
            
            shutdown(Socket, SD_SEND);
            
            closesocket(Socket);
            
            WSACleanup();
            system("PAUSE");
            return 0;
        }
    }
}
