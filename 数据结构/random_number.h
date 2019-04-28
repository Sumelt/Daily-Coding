﻿#ifndef __RANDOM_NUMBER_H__
#define __RANDOM_NUMBER_H__

#include <iostream>
#include <random>
#include <ctime>
#include <cassert>
using namespace std;
//随机数产生 
template <typename T = int>
T *Generate_random_numbers( int startRange, int endRange, int sumCount = 10 );

template <typename T = int>
T *Generate_random_numbers( int startRange, int endRange, int sumCount )
{
	T *array = new T[ sumCount ]();
	
	default_random_engine e;
	uniform_int_distribution<T> u( startRange, endRange );
	
	for( int i = 0; i < sumCount; ++i )
		array[ i ]  = u( e );
		
	return array;
	
}
//元素顺序测试 
template<typename T>
bool isSorted(T arr[], int n) {

    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;

    return true;
}
//耗时测试 
template<typename T>
void testSort(const string &sortName, void (*sort)(T[], int), T arr[], int n) {
	
    clock_t startTime = clock();
    sort(arr, n);
    clock_t endTime = clock();
    
    cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC 
			<< " s" <<endl;

    assert(isSorted(arr, n));
    	
    return;
}

/*
void print() {
	
	cout << "Sort before: " ;
	for( int i = 0; i < n; ++i )
		cout << arr[ i ] << ends;
	cout << endl;

	cout << "Sorted after: ";
	for( int i = 0; i < n; ++i )
		cout << arr[ i ] << ends; 	
}*/


#endif