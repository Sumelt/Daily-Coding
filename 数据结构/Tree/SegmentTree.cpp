/*----------------------------------------------------------------

* @Author: Su

* @Description: 

* @Creath Date:

----------------------------------------------------------------*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

template <typename T>
class Merger{
private:

public:
	T merge( T arg1, T arg2 ){
		return ( arg1 + arg2 );
	}
};

template <typename T>
class SegmentTree {
private:
	T* m_ptr_arry = nullptr;
	T* m_ptr_tree = nullptr;
	class Merger<T>* m_ptr_merger = nullptr;
	int m_size;

	//线段树根节点、线段树的左子节点、线段树的右子节点、访问的区间左坐标、访问的区间右坐标
	T m_query( int treeRootIndex, int treeLeftIndex, int treeRightIndex, int QindexL, int QindexR  ){
		//要访问的区间的左右坐标相等于线段树的左右节点的索引
        if( QindexL == treeLeftIndex && QindexR == treeRightIndex )
			return m_ptr_tree[ treeRootIndex ];//它的父节点就是我们想要的
			
		int treeMidIndex = treeLeftIndex + ( treeRightIndex - treeLeftIndex ) / 2;//线段树的中点
		int leftChildIndex = getLeftChildIndex( treeRootIndex );//左子树索引
		int rightChildIndex = getRightChildIndex( treeRootIndex );//右子树索引
		
		if( QindexL >= treeMidIndex + 1 ) //访问的区间在右子树
			return m_query( rightChildIndex, treeMidIndex + 1, treeRightIndex, QindexL, QindexR );
		else if( QindexR <= treeMidIndex ) //访问的区间在左子树
			return m_query( leftChildIndex, treeLeftIndex, treeMidIndex, QindexL, QindexR );
		
        //要访问的区间在左子树一半、另一半在右子树	
		T leftChildResult = m_query( leftChildIndex, treeLeftIndex, treeMidIndex, QindexL, treeMidIndex );
		T rightChildResult = m_query( rightChildIndex, treeMidIndex + 1, treeRightIndex, treeMidIndex + 1, QindexR );
		
		return m_ptr_merger->merge( leftChildResult, rightChildResult );//要做的业务逻辑操作
		
	}
	
public:
	SegmentTree( T *ary, int cnt, class	Merger<T>* merger ) : 
		m_size( cnt ), m_ptr_merger( merger ) {
		
		m_ptr_arry = new T[ cnt ]();
		
		for( int i = 0; i < cnt; ++i )
			m_ptr_arry[ i ] = ary[ i ];//拷贝数据副本 
			
		m_ptr_tree = new T[ 4 * cnt ]();//创建树的空间容量 
		buildSegmentTree( 0, 0, m_size - 1 );//构造函数里构建线段树
	} 
	
	~SegmentTree(){
		delete m_ptr_arry;
		delete m_ptr_tree;
	}
	//创建线段树
	void buildSegmentTree( int indexRoot, int indexL, int indexR ){
		//左区间等于右区间说明区间长度只有1
        if( indexL == indexR ) {
			m_ptr_tree[ indexRoot ] = m_ptr_arry[ indexL ];//直接将数组的元素复制到线段树上对应的位置
			return ;
		}
			
		int indexMid = indexL + ( indexR - indexL ) / 2;
		int leftChildIndex = getLeftChildIndex( indexRoot );
		int rightChildIndex = getRightChildIndex( indexRoot );
		
		buildSegmentTree( leftChildIndex, indexL, indexMid );//继续递归左子树
		buildSegmentTree( rightChildIndex, indexMid + 1, indexR );//继续递归右子树
		
		//业务逻辑
        //这里表示线段树的父节点存储的是两个左右子节点的元素之和
        m_ptr_tree[ indexRoot ] = \
			m_ptr_merger->merge( m_ptr_tree[ leftChildIndex ], m_ptr_tree[ rightChildIndex ] );
	}
	
	int getSize(){
		return m_size;
	}
	
	T get( int index ){
		assert( index < 0 || index >= m_size );
		
		return m_ptr_arry[ index ];
	}
	
	int getLeftChildIndex( int index ){
		return ( 2 * index +  1 );
	}
	
	int getRightChildIndex( int index ){
		return ( 2 * index +  2 );
	}
	//查询区间操作
	T query( int QindexL, int QindexR ){
		assert( QindexL >= 0 || QindexL < m_size || 
			QindexR >= 0 || QindexR < m_size || QindexL <= QindexR );
		return m_query( 0, 0, m_size - 1, QindexL, QindexR );
	}
	
};

int main(int argc, char *argv[])
{
	int arry[] = {
		-2, 0, 3, -5, 2, -1
	};
	Merger<int> merger;
	SegmentTree<int> tr( arry, ( sizeof( arry ) / sizeof( *arry ) ), &merger );
	cout << tr.query( 0, 2 ) << endl;
	cout << tr.query( 2, 5 ) << endl;
	cout << tr.query( 0, 5 ) << endl;
	
	return 0;
}