/************************************************************************
** 单进程应用程序
** 主要原理：
**      用id作为本地port 程序监听socket作为server
**      第二次打开时发现端口被占用 成为client连接并发送参数给server 并结束
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
     * 支持不同路径下的同一个应用程序
     */
    LySingleApplication(int& argc, char ** argv);

    /**
     * @brief
     * 仅支持一个应用程序
     */
    LySingleApplication(const char* id, int& argc, char ** argv);

    bool isRunning() { return m_net->isClient(); };

    bool sendMessage(std::string& message)
    {
        return m_net->sendMessage(message);
    }
private:
    /**
     * @brief 将AppId 转化成 数字(port)
     * 系统保留[0-1024,65535] 用户可用 [1025,65534]
     * 换算算法 将每个字符相加 % 65536 如果在不可用区间内 则+10000 
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