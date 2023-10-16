#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq->size>0){
    return pq->heapArray[0].data;
  }else{
    return NULL;
  }
  
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->size==pq->capac){

    pq->capac=(pq->capac * 2 +1);
    pq->heapArray=(heapElem*)realloc(pq->heapArray,sizeof(heapElem)* pq->capac);
  }

  heapElem nuevo;
  nuevo.data=data;
  nuevo.priority=p

  
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* reserva=(Heap*)malloc(sizeof(Heap));
  reserva->heapArray=(heapElem*)malloc(sizeof(heapElem)*3);
  reserva->size=0;
  reserva->capac=3;
  
  return  reserva;
}
