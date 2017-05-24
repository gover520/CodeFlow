#include "LySingleApplication.h"
#include <stdio.h>

int main(int argc, char ** argv)
{
    LySingleApplication sa("123", argc, argv);
    if (sa.isRunning())
    {
        if (argc >= 1)
        {
            std::string appid = argv[1];
            sa.sendMessage(appid);
        }
    }

    /*WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKET s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in sockaddr;
    sockaddr.sin_family = PF_INET;
    sockaddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    sockaddr.sin_port = htons(2004);

    bind(s, (SOCKADDR*)&sockaddr, sizeof(SOCKADDR));
    listen(s, 1);
    SOCKADDR client;
    int nSize = sizeof(SOCKADDR);
    SOCKET clientSock;
    clientSock = accept(s, (SOCKADDR*)&client, &nSize);

    send(clientSock, "hello \r\n", strlen("hello \r\n") + 1, NULL);
    closesocket(clientSock);
    closesocket(s);

    WSACleanup();*/

    getchar();
    return 0;
}