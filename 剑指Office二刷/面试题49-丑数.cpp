//丑数生成丑数，但要保持丑数的序列大小 
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if( index == 0 )
            return 0;
        int *uglyArray = new int[ index ]();
        uglyArray[ 0 ] = 1;

        int *twoPtr = uglyArray;
        int *threePtr = uglyArray;
        int *fivePtr = uglyArray;
        int curIndex = 1;
        
        while( curIndex < index ) {
            //找到各个因子序列下最小的丑数作为真正的丑数 
			int minUgly = min( *twoPtr * 2, min( *threePtr * 3, *fivePtr * 5 ) );
            uglyArray[ curIndex ] = minUgly;//保存真正的丑数 
            
            //找出该因子序列中大于当前丑数的丑数 
			while( *twoPtr * 2 <= uglyArray[ curIndex ] )
                ++twoPtr;//get next uglynumber;
            while( *threePtr * 3 <= uglyArray[ curIndex ] )
                ++threePtr;
            while( *fivePtr * 5 <= uglyArray[ curIndex ]  )
                ++fivePtr;
            ++curIndex;            
        }
        int res = uglyArray[ curIndex - 1 ];
        delete []uglyArray;
        return res;
    }
};