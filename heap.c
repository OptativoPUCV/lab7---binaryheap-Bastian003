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
    pq->capac=pq->capac*2+1;
    pq->heapArray=(heapElem*)realloc(pq->heapArray,sizeof(heapElem)*pq->capac);
  }

  
  int indice = pq->size;
  pq->heapArray[indice].data=data;
  pq->heapArray[indice].priority=priority;
  pq->size = pq->size+1;
  heapElem papaindice,cont;

  
  while(indice!=0){
    papaindice=pq->heapArray[(indice-1)/2];
    if(papaindice.priority>pq->heapArray[indice].priority)break;
    cont=papaindice;
    pq->heapArray[(indice-1)/2]=pq->heapArray[indice];
    pq->heapArray[indice]=cont;
    indice = (indice-1)/2;

  }

  
}

void heap_pop(Heap* pq){
  if(pq->size==0){
    return;
  }
  
  pq->heapArray[0]=pq->heapArray[pq->size-1];
  pq->size=pq->size-1;

  int cont=0;
  int hijo , hijito,papa;
  while(1){
    hijo=2*cont+1;
    hijito=2*cont+2;
    if(hijo< pq->size && pq->heapArray[hijo].priority >pq>heapArray[cont].priority)papa=hijo;
    else papa=cont;

    if(hijito< pq->size && pq->heapArray[hijito].priority > pq->heapArray[papa].priority)papa=hijito;

    if(cont==papa)break;

    heapElem nuevo=pq->heapArray[cont];
    pq->heapArray[cont]=pq->heapArray[papa];
    pq->heapArray[papa]=nuevo;
    cont=papa;
  }

}



Heap* createHeap(){
  Heap* reserva=(Heap*)malloc(sizeof(Heap));
  reserva->heapArray=(heapElem*)malloc(sizeof(heapElem)*3);
  reserva->size=0;
  reserva->capac=3;
  
  return  reserva;
}
