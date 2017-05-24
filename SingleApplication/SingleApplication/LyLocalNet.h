/************************************************************************
**�������� ���ڽ��̼�ͨѶ
** 
**  ��Ϊ������ �����������socket
**  ��Ϊ�ͻ��� ��������socket
**
************************************************************************/
#ifndef _LY_LOCAL_NET_H_
#define _LY_LOCAL_NET_H_
#include <winsock2.h>
#include <iostream>
#include <cstring>
#include <windows.h>
#pragma comment (lib,"WS2_32.lib")

class LyLocalNet
{
public:
    LyLocalNet(int port);

    bool isClient(){ return m_is_client; };

    bool sendMessage(const std::string& message);
private:
    bool m_is_client;
    SOCKET s;
};
#endif