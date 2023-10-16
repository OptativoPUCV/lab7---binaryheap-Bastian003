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

  int indice=pq->size;
  pq->size++;
  pq->heapArray[indice].data=data;
  pq->heapArray[indice].priority=priority;
  
  while(indice>0){
    int indicepapa=(indice-1)/2;
    if(pq->heapArray[indice].priority < pq->heapArray[indicepapa].priority){

      heapElem cont=pq->heapArray[indice];
      pq->heapArray[indice]=pq->heapArray[indicepapa];
      pq->heapArray[indicepapa]=cont;
      indice=indicepapa;
    }else{
      break;
    }
  }

  
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
