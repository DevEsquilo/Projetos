#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;
int entrada;
bool receptor = false;
bool transmissor = false;

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
    
    if(entrada == 0)
    {
        transmissor = true;
               
        while (transmissor)
        {
            WSADATA WsaDat;
            if(WSAStartup(MAKEWORD(2,2), &WsaDat)!=0)
            {
                  printf("Winsock error - Winsock initialization failed\r\n");
                  WSACleanup();
                  system("PAUSE");
                  return 0;
            }
            
            SOCKET Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            
            if(Socket == INVALID_SOCKET)
            {
                  printf("Winsock error - Socket creation Failed!\r\n");
                  WSACleanup();
                  system("PAUSE");
                  return 0;
            }
            
            struct hostent *host;
            
            if((host = gethostbyname("localhost")) == NULL)
            {
                  printf("Failed to resolve hostname.\r\n");
                  WSACleanup();
                  system("PAUSE");
                  return 0;
            }
            
            SOCKADDR_IN SockAddr;
            SockAddr.sin_port = htons(8888);
            SockAddr.sin_family = AF_INET;
            SockAddr.sin_addr.s_addr = *((unsigned long*) host -> h_addr);
            
            if(connect(Socket, (SOCKADDR*)(&SockAddr), sizeof(SockAddr))!=0)
            {
                  printf("Failed to establish connection with server\r\n");
                  WSACleanup();
                  system("PAUSE");
                  return 0;
            }
            
            u_long iMode = 1;
            ioctlsocket(Socket, FIONBIO, &iMode);
            
            for(;;)
            {
                char buffer[1000];
                memset(buffer, 0, 999);
                int inDataLength = recv(Socket, buffer, 1000, 0);
                printf(buffer);
                printf("\n\t");
                
                int error = WSAGetLastError();
                
                if(error != WSAEWOULDBLOCK&&error!=0)
                {
                    std::cout<<"Winsock error code: "<<error<<"\r\n";
                    std::cout<<"Server disconnected!\r\n";
                    // Shutdown our socket
                    shutdown(Socket,SD_SEND);
                    // Close our socket entirely
                    closesocket(Socket);
                    break;
                }
                Sleep(1000);
            }
            //shutdown(Socket, SD_SEND);
            
            closesocket(Socket);
            
            WSACleanup();
            system("PAUSE");
            return 0;
            
        }
    }
    
    if(entrada == 1)
    {
        receptor = true;
            
        while(receptor)
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
                
            u_long iMode=1;
            ioctlsocket(Socket,FIONBIO,&iMode);
            
            Socket = TempSock;
            
            printf("\n\tClient Conectado !\n\n");
            
            for(;;)
            {
                char *mensagem = "\n\tPudim !";
                send(Socket, mensagem, strlen(mensagem), 0);
                printf("\n\t");
                
                int Error = WSAGetLastError();
                
                if(Error!=WSAEWOULDBLOCK&&Error!=0)
                {
                    std::cout<<"Winsock error code: "<<Error<<"\r\n";
                    std::cout<<"Server disconnected!\r\n";
                    // Shutdown our socket
                    shutdown(Socket,SD_SEND);
                    // Close our socket entirely
                    closesocket(Socket);
                    break;
                }
                Sleep(1000);
            }
            
            shutdown(Socket, SD_SEND);
            
            closesocket(Socket);
            
            WSACleanup();
            system("PAUSE");
            return 0;
        }
    }
}
