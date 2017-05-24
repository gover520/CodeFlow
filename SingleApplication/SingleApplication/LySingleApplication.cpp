#include "LySingleApplication.h"
#include <stdio.h>

LySingleApplication::LySingleApplication(int& argc, char ** argv)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("Argument %d is %s.\n", i, argv[i]);
    }
    int port = convertAppId2Port(argv[0]);
    printf("Port: %d.\n", port);

    m_net = new LyLocalNet(port);
}

LySingleApplication::LySingleApplication(const char* id, int& argc, char ** argv)
{
    printf("Id: \n", id);

    int i;
    for (i = 0; i < argc; i++)
    {
        printf("Argument %d is %s.\n", i, argv[i]);
    }

    int port = convertAppId2Port(id);
    printf("Port: %d.\n", port);

    m_net = new LyLocalNet(port);
}