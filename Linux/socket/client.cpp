#include "cshead.h"
#define MAXSIZE 4096

void *client( void *value )
{
    sleep( 2 );

    int sockfd;
    char sendLine[ MAXSIZE ];
    char serIp[] = "127.0.0.1";//服务器IP地址
    int getReturn;
    struct sockaddr_in seraddr;//套接字结构体

    sockfd = socket( AF_INET, SOCK_STREAM, 0 );
    if( sockfd < 0 ) {
        cout << "socket creath faile from client" << endl;
        exit( 0 );
    }

    memset( &seraddr, 0, sizeof ( seraddr ) );
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons( 6666 );//服务器端口号
    getReturn =  inet_pton( AF_INET, serIp, &seraddr.sin_addr );//点十分到二进制转换
    if( getReturn <= 0 ) {
        cout << "inet_pton failefrom client" << endl;
        exit( 1 );
    }

    getReturn = connect( sockfd, ( struct sockaddr* )&seraddr, sizeof ( seraddr ) );//套接字连接，需要进行结构体强制转换
    if( getReturn < 0 ) {
        cout << "connect faile from client" << endl;
        exit( 0 );
    }

    cout << "----Successfully connected to the server " << endl
         << "  please input string send to server---" << endl;
    fgets( sendLine, MAXSIZE, stdin );//获取标准输入
    if( send( sockfd, sendLine, strlen( sendLine ), 0 ) < 0 ) {//向套接字发送数据
        cout << "send faile from client" << endl;
        exit( 0 );
    }
    close( sockfd );//关闭套接字
    pthread_exit( ( void* )0 );
}
