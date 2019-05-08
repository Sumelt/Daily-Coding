/*
 *带权图的边 
 */
 
#ifndef __EDGE_H__ 
#define __EDGE_H__ 

#include<iostream>
#include<cassert>

template<typename Weight>
class Edge{
private:
	int v, w; //连接的两点
	Weight weight; //边上的权值
	
public:
	Edge( int v, int w, Weight weight ) {
		this->v = v;
		this->w = w;
		this->weight = weight;
	}
	
	Edge(){
	}
	
	~Edge(){
	}
	
	int retV(){
		return v;
	}
	
	int retW() {
		return w;
	}
	
	Weight retWeight() {
		return weight;
	}
	
	int retOtherVertex( int vertex ) {
		assert( vertex == v || vertex == w );
		return ( vertex == v ? v : w );
	}
	
	friend iostream& operator << ( iostream& os, Edge edge ){
		os << edge.v << " - " << edge.w << " weight: " << edge.weight;
		return os;
	}
	
	bool operator < ( Edge &edge ) {
		return this->weight < edge.weight;
	}
	
	bool operator <= ( Edge &edge ) {
		return this->weight <= edge.weight;
	}
	
	bool operator > ( Edge &edge ) {
		return this->weight > edge.weight;
	}
	
	bool operator >= ( Edge &edge ) {
		return this->weight >= edge.weight;
	}
	
	bool operator == ( Edge &edge ) {
		return this->weight == edge.weight;
	}			
};



#endif