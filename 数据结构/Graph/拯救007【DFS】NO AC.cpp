/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date: 

----------------------------------------------------------------*/

#include <iostream>
#include <cmath>
using namespace std;
#define MINLEN 42.5
int N; //鳄鱼数目 
int jumpDistance; //跳跃距离 
bool answer = false;
struct point{
	int x, y;  // x y下标  
	bool visted;
	point( int _x, int _y )	: x( _x ) ,y( _y ){}
	point(){}
};

bool Jump( point currPoint, point nextPoint )
{
	double length = sqrt( pow( nextPoint.x - currPoint.x ,2 )
		 + pow( nextPoint.y - currPoint.y ,2 )); //两点间距离公式
		 //cout <<endl <<"TTTT"<<length;
	if( jumpDistance >= length ) return true; //能跳 
	else return false;
}

bool Saft( point currPoint )
{
	point shore; //按的坐标
	if( currPoint.x < 0 ) shore.x = -50;
	else shore.x = 50;
	shore.y = currPoint.y;
	if( Jump( shore, currPoint ) ) return true;//和岸边比较是否安全 
	else return false;
}

bool DFS( point *GPoint, point *currPoint )
{
	currPoint->visted = true;
	if( Saft( *currPoint ) ) answer = true;
	else
	{
		for( int i = 0; i < N; ++i )
			if( !GPoint[ i ].visted && Jump( *currPoint, GPoint[ i ] ) )
			{
				//cout << GPoint[i].x  << " "<< GPoint[i].y << "-----" <<endl;
				answer = DFS( GPoint, &GPoint[ i ] );
				if( answer ) break;
			}
	}
	return answer;
}

bool fistJump(point nextPoint)
{
	int ShortestPath = pow( nextPoint.x, 2 ) + pow( nextPoint.y, 2 ); //垂直三角形 
	int MaximumJump = pow( 7.5 + jumpDistance, 2 );
	//cout << ShortestPath <<' ' << MaximumJump;
	if( MaximumJump >= ShortestPath ) return true;
	else return false;
	
}

void DFSlist( point *GPoint )
{
	for( int i = 0; i < N; ++i )
	{
		if( !GPoint[ i ].visted && fistJump(GPoint[ i ] ) )
		{
			//cout << GPoint[i].x  << " "<< GPoint[i].y << "-----" << endl;
			cout << "yyyyyy";
			answer = DFS( GPoint, &GPoint[ i ] );
			if( answer ) break;
		}
			
	}
	if( answer ) cout << "Yes";
	else cout << "No";
		
}

int main(int argc, char *argv[])
{	
	cin >> N >> jumpDistance; //跳跃距离 
	point G[ N ];  //结构体数组存储 
	
	for( int i = 0; i < N; ++i )
		cin >> G[ i ].x >> G[ i ].y;
	if( jumpDistance >= MINLEN ) //直接从岛上跳到岸边 
	{
		cout << "Yes";
		return 0;
	}	
	DFSlist( G );
	
	return 0;
}

