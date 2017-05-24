/************************************************************************
** ������Ӧ�ó���
** ��Ҫԭ��
**      ��id��Ϊ����port �������socket��Ϊserver
**      �ڶ��δ�ʱ���ֶ˿ڱ�ռ�� ��Ϊclient���Ӳ����Ͳ�����server ������
**
************************************************************************/
#ifndef _LY_SINGLE_APPLICATION_H_
#define _LY_SINGLE_APPLICATION_H_
#include "LyLocalNet.h"
class LySingleApplication
{
public:
    /**
     * @brief
     * ֧�ֲ�ͬ·���µ�ͬһ��Ӧ�ó���
     */
    LySingleApplication(int& argc, char ** argv);

    /**
     * @brief
     * ��֧��һ��Ӧ�ó���
     */
    LySingleApplication(const char* id, int& argc, char ** argv);

    bool isRunning() { return m_net->isClient(); };

    bool sendMessage(std::string& message)
    {
        return m_net->sendMessage(message);
    }
private:
    /**
     * @brief ��AppId ת���� ����(port)
     * ϵͳ����[0-1024,65535] �û����� [1025,65534]
     * �����㷨 ��ÿ���ַ���� % 65536 ����ڲ����������� ��+10000 
     */
    int convertAppId2Port(const std::string& appid)
    {
        int port = 0;
        for (auto ch : appid)
        {
            port = (port + ch) % 65536;
        }

        if (port <= 1024 || port == 65535)
        {
            port = (port + 10000) % 65536;
        }

        return port;
    }
private:
    LyLocalNet* m_net;
};
#endif