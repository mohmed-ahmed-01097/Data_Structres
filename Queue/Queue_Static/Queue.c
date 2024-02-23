/* ************************************************************************** */
/* ********************** FILE DEFINITION SECTION *************************** */
/* ************************************************************************** */
/* File Name   : Queue.c													  */
/* Author      : MAAM														  */
/* Version     : v00														  */
/* date        : Jun 10, 2023												  */
/* ************************************************************************** */
/* ************************ HEADER FILES INCLUDES **************************  */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "Platform_Types.h"
#include "Queue.h"

/* ************************************************************************** */
/* ********************** TYPE_DEF/STRUCT/ENUM SECTION ********************** */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************** MACRO/DEFINE SECTION ************************** */
/* ************************************************************************** */

/* ************************************************************************** */
/* ***************************** CONST SECTION ****************************** */
/* ************************************************************************** */

/* ************************************************************************** */
/* ***************************** VARIABLE SECTION *************************** */
/* ************************************************************************** */

/* ************************************************************************** */
/* **************************** FUNCTION SECTION **************************** */
/* ************************************************************************** */

QUEUE_tstr* initQueue(u16 size){
	static QUEUE_DataType array[MAX_QUEUE];
	static QUEUE_tstr queue;

	queue.size  = size;
	queue.front = 0;
	queue.rear  = 0;
	queue.data  = array;

	return (size <= MAX_QUEUE) ? (QUEUE_tstr*)&queue : NULL_PTR;
}
QUEUE_ReturnType clrQueue(QUEUE_tstr *pqueue){
	QUEUE_ReturnType RetVal = QUEUE_NOK;

	if(pqueue == NULL_PTR){

	}else{
		pqueue->front = -1;
		pqueue->rear  = -1;
		RetVal = QUEUE_OK;
	}

	return RetVal;
}

QUEUE_ReturnType isEmpty(QUEUE_tstr *pqueue){
	return ((s16)pqueue->front == -1) && ((s16)pqueue->rear == -1) ? QUEUE_Empty : QUEUE_NotFull;
}
QUEUE_ReturnType isFull (QUEUE_tstr *pqueue){
	if ((pqueue->rear > pqueue->front) || (((s16)pqueue->front == -1) && ((s16)pqueue->rear == -1)))
		return (pqueue->rear - pqueue->front == pqueue->size) ? QUEUE_Full : QUEUE_NotFull;
	return ((pqueue->size + pqueue->rear - pqueue->front) == pqueue->size) ? QUEUE_Full : QUEUE_NotFull;
}

QUEUE_ReturnType Enqueue(QUEUE_tstr *pqueue ,QUEUE_DataType data){
	QUEUE_ReturnType RetVal = QUEUE_NOK;

	if (isFull(pqueue) == QUEUE_Full || (pqueue == NULL_PTR)){
#ifdef QUEUE_DEBUG
		printf("\nERROR !! Queue is FULL, can't Enqueue [%i]\n",data);
#endif // QUEUE_DEBUG
	}else{
		if(++pqueue->rear >= pqueue->size)     pqueue->rear = 0;
		pqueue->data[pqueue->rear] = data;
		RetVal = QUEUE_OK;
#ifdef QUEUE_DEBUG
		printf("Data [%i] is Enqueued in Queue\n",data);
#endif // QUEUE_DEBUG
	}

	return RetVal;
}
QUEUE_ReturnType Dequeue(QUEUE_tstr *pqueue ,QUEUE_DataType *pdata){
	QUEUE_ReturnType RetVal = QUEUE_NOK;

	if(isEmpty(pqueue) == QUEUE_Empty || (pqueue == NULL_PTR) || (pdata == NULL_PTR)){
#ifdef QUEUE_DEBUG
		printf("\nERROR !! can't Dequeue from Queue\n");
#endif // QUEUE_DEBUG
	}else{
		if (++pqueue->front >= pqueue->size)     pqueue->front = 0;
		*pdata = pqueue->data[pqueue->front];
		if(pqueue->front == pqueue->rear)		 clrQueue(pqueue);
		RetVal = QUEUE_OK;
#ifdef QUEUE_DEBUG
		printf("Data [%i] is Dequeued from Queue\n",*pdata);
#endif // QUEUE_DEBUG
	}

	return RetVal;
}
QUEUE_ReturnType top(QUEUE_tstr *pqueue ,QUEUE_DataType *pdata){
	QUEUE_ReturnType RetVal = QUEUE_NOK;

	if (isEmpty(pqueue) == QUEUE_Empty || (pqueue == NULL_PTR) || (pdata == NULL_PTR)){
#ifdef QUEUE_DEBUG
		printf("\nERROR !! Queue is Empty\n");
#endif // QUEUE_DEBUG
	}else{
		*pdata = pqueue->data[pqueue->front + 1];
		RetVal = QUEUE_OK;
#ifdef QUEUE_DEBUG
		printf("QueueTop = %i\n",*pdata);
#endif // QUEUE_DEBUG
	}

	return RetVal;
}

/* ************************************************************************** */

u16 queue_size(QUEUE_tstr *pqueue){
	if (pqueue->rear > pqueue->front){
		return (pqueue->rear - pqueue->front);
	}else{
		return (pqueue->size + pqueue->rear - pqueue->front);
	}

}
QUEUE_ReturnType queue_check(QUEUE_tstr *pqueue){
	QUEUE_ReturnType RetVal = QUEUE_NOK;

	if(pqueue == NULL_PTR){

	}else{
		if(isFull(pqueue) == QUEUE_Full){
			printf("\nThe Queue is FULL \n");
		}else if(isEmpty(pqueue) == QUEUE_Empty){
			printf("\nThe Queue is Empty \n");
		}else{
			printf("\nThe Queue Size = %i\n",queue_size(pqueue));
		}
		RetVal = QUEUE_OK;
	}

	return RetVal;
}
QUEUE_ReturnType queue_display(QUEUE_tstr *pqueue){
	QUEUE_ReturnType RetVal = QUEUE_NOK;

	if(pqueue == NULL_PTR){

	}else{
		if(isEmpty(pqueue)){
			for(u16 i = queue_size(pqueue), temp = pqueue->front ; i-- ; temp++){
				if(temp >= pqueue->size)	temp = 0;
				printf(" [%i] ", pqueue->data[temp]);
			}
			printf("\n");
		}
		RetVal = QUEUE_OK;
	}

	return RetVal;
}


/*************************** E N D (Queue.c) ******************************/
