#include "ConjuntoDisjunto.hpp" 
#include <iostream>
	
ConjuntoDisjunto::ConjuntoDisjunto(){}

ConjuntoDisjunto::~ConjuntoDisjunto(){}

void ConjuntoDisjunto::makeSet(long x){
    conj[x] = new No(x, 0);
}

void ConjuntoDisjunto::unionSet(long x, long y){
    No *xRoot = conj[findSet(x)];
    No *yRoot = conj[findSet(y)];

    if(xRoot->rank > yRoot->rank){
        yRoot->father = xRoot;
    }else{
        xRoot->father = yRoot;
        if(xRoot->rank == yRoot->rank){
            yRoot->rank++;
        }
    }
}

long ConjuntoDisjunto::findSet(long x){
    No* ptx = conj[x];

    while(ptx->father != ptx)
        ptx = ptx->father;
    
    return ptx->value;
}

