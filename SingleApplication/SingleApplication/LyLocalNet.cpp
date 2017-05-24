#include "LyLocalNet.h"

LyLocalNet::LyLocalNet(int port)
: m_is_client(false)
{

    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);


    sockaddr_in sockAddr;
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(port);

    int ret = connect(s, (SOCKADDR *)&sockAddr, sizeof(SOCKADDR));

    if (ret != -1)
    {
        m_is_client = true;
    }
    else
    {
        // Is Server
        s = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
        int ans = bind(s, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
        listen(s, 1);
        int nSize = sizeof(SOCKADDR);
        SOCKET clientSock;
        clientSock = accept(s, (SOCKADDR*)&sockAddr, &nSize);

        char szBuffer[MAXBYTE] = { 0 };
        recv(clientSock, szBuffer, MAXBYTE, NULL);

        std::cout << "OpenFile:  " << szBuffer << std::endl;

        closesocket(s);
        closesocket(clientSock);
        WSACleanup();
    }
}

bool LyLocalNet::sendMessage(const std::string& message)
{
    // Is Client
    int ret = send(s, message.c_str(), message.length() + 1, NULL);
    return ret != -1;
}