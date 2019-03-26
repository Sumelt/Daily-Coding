#include "cshead.h"

#define MaxLINE 4096
#define MaxBuff 4096

void serve( pthread_t tid )
{
    int listenfd, connfd;//监听套接字 连接套接字
    int getReturn;
    char buff[ MaxBuff ];//缓冲区
    ssize_t byteSize;//接收的字节数
    struct sockaddr_in servaddr;//套接字结构体

    listenfd = socket( AF_INET, SOCK_STREAM, 0 );//创建套接字：IPV4协议 TCP套接字 自动选择协议
    if( listenfd == -1 ){
        cout << "creath socket faile from server" << endl;
        exit( 0 );
    }

    memset( &servaddr, 0, sizeof ( servaddr ) );//初始化套接字结构体
    servaddr.sin_family = AF_INET;//IPV4协议
    servaddr.sin_addr.s_addr = htonl( INADDR_ANY );//多网卡
    servaddr.sin_port = htons( 6666 );//服务器端口号

    getReturn =  bind( listenfd, ( struct sockaddr* )&servaddr, sizeof ( servaddr ) );//将结构体信息绑定到该套接字上
    if( getReturn == -1 ){
        cout << "bind socket faile from server" << endl;
        exit( 0 );
    }

    getReturn = listen( listenfd, 10 );//创建监听套接字 监听指定端口的请求，10个请求队列
    if( getReturn == -1 ){
        cout << "listen socket faile from server" << endl;
        exit( 0 );
    }

    cout << "------serve waiting client request---------" << endl;
    int countClient = 0;
    while ( countClient != 1 ) {
        connfd = accept( listenfd, ( struct sockaddr* )nullptr, nullptr );//等待客户端请求，连接成功创建连接套接字
        if( connfd == -1 ){
            cout << "accept faile from server" << endl;
            continue;
        }
        ++countClient;
        byteSize = recv( connfd, buff, MaxLINE, 0 );//利用连接套接字，读取缓冲区的字节数
        buff[ byteSize ] = '\0';
        string receStr( buff );
        cout << "recv msg from client: "<< receStr << endl;
        close( connfd );//关闭连接套接字
        pthread_join( tid, nullptr );//等待子线程退出
    }
    close( listenfd );//关闭监听套接字
}
