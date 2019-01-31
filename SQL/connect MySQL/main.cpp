#include <iostream>
#include <iomanip>
#include <winsock2.h>  
#include <mysql.h>
#include <string>
#include <vector>
#define Address "localhost"
#define Username "root"
#define Password "best"
#define DB "shop"
#define Port 3306
using namespace std;
string commad = "select product_id, product_name, product_type,\
	sale_price,COALESCE(purchase_price, 'NULL') as purchase_price,\
	COALESCE(regist_date, 'NULL') as regist_date from product;";

int main()  
{  
    MYSQL mysql;
    MYSQL_RES *result; //save table result 
    MYSQL_ROW sql_row; //save a row message
	MYSQL_FIELD *fd; //  
    mysql_init( &mysql );
    vector<string>columnName;
    unsigned rowNum = 0;
    
    if(!mysql_real_connect( &mysql, Address, Username, 
		Password, DB, Port, NULL, 0) )
    {  
        printf( "MySQL connect error!\n" );
    }  
    else
    {  
        printf( "MySQL connect success!\n" );
        mysql_query( &mysql, "SET NAMES GBK" ); // set code format
        int res = mysql_query(&mysql, commad.c_str()); // search table
        if( !res ) //success
		{
			result = mysql_store_result( &mysql );
			rowNum = mysql_num_rows( result );
			if( result )
			{				
				cout << "number of result: " << rowNum << endl;
				for( int i = 0; fd = mysql_fetch_field( result ); i++ )
					columnName.push_back( fd->name );
				for( auto name : columnName )
					cout << setw(15) << left << name;
				cout << endl;
				while( rowNum )  
				{
					sql_row = mysql_fetch_row( result ); // get one row mes 
					for( unsigned i = 0; i < columnName.size(); i++ )
						cout << setw(15) << left << sql_row[i];
					cout << endl;
					--rowNum;
				}
			}
		} 
        
    }  
    mysql_close(&mysql);
    return 0;
}  

