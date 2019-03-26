#include "cshead.h"

int main()
{
    cout << "-------CS start-----" << endl;
    pthread_t tid;
    int getReturn;
    getReturn = pthread_create( &tid, nullptr, client, nullptr );
    if( getReturn ){
        cout << "creathe pthread error\n";
        exit( 0 );
    }

    cout << "------serve start-----" << endl;
    serve( tid );

    return 0;
}
