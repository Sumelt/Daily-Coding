class Solution {public: //length为数组的容量	void replaceSpace(char *str,int length) {        if(  length <= 0 || !str  )            return;                int spaceCnt, newStrLength, originStrLength;		spaceCnt = newStrLength = originStrLength = 0;		int ptr1, ptr2;				//存储*str = '\0'，的地址str不为空，str != nullptr不能作为结束条件		while( *str != '\0' ) {			if( *str == ' ' )				++spaceCnt;			++originStrLength;			++str;		}				newStrLength = originStrLength + spaceCnt * 2;		if( newStrLength > length )			return;		ptr2 = newStrLength - 1;		ptr1 = originStrLength - 1;				while( spaceCnt > 0 ) {			if( str[ ptr1 ] == ' ' ) {				str[ ptr2-- ] = '0';				str[ ptr2-- ] = '2';				str[ ptr2-- ] = '%';				--spaceCnt;			}			else				str[ ptr2-- ] = str[ ptr1-- ];		}		} };/*复杂度为O（N）*/