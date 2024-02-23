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

QUEUE_ReturnType newQueue(QUEUE_tstr** pqueue){
	QUEUE_ReturnType RetVal = QUEUE_NOK;
	*pqueue = malloc(sizeof( QUEUE_tstr ));
	if(*pqueue){
		(*pqueue)->size  = 0;
		(*pqueue)->front = NULL_PTR;
		(*pqueue)->rear  = NULL_PTR;
		RetVal = QUEUE_OK;
	}else{

	}

	return RetVal;
}
QUEUE_ReturnType deinitQueue(QUEUE_tstr *pqueue){
	QUEUE_ReturnType RetVal = clrQueue(pqueue);
	free(pqueue);
	return RetVal;
}
QUEUE_ReturnType clrQueue(QUEUE_tstr *pqueue){
	QUEUE_ReturnType RetVal = QUEUE_NOK;

	if(pqueue == NULL_PTR){

	}else{
		while(pqueue->front){
			if (pqueue->rear == pqueue->front){
				pqueue->rear = NULL_PTR;
			}
			QUEUE_tstrList * pitem = pqueue->front;
			pqueue->front = pqueue->front->next;
			pqueue->size--;

			free(pitem);
		}
		RetVal = QUEUE_OK;
	}

	return RetVal;
}

QUEUE_ReturnType isEmpty(QUEUE_tstr *pqueue){
	return (pqueue->size == QUEUE_Empty) ? QUEUE_Empty : QUEUE_NotFull;
}
QUEUE_ReturnType isFull (QUEUE_tstr *pqueue){
	return (pqueue->size == QUEUE_Full) ? QUEUE_Full : QUEUE_NotFull;
}

QUEUE_ReturnType Enqueue(QUEUE_tstr *pqueue ,QUEUE_DataType data){
	QUEUE_ReturnType RetVal = QUEUE_NOK;

	if (isFull(pqueue) == QUEUE_Full || (pqueue == NULL_PTR)){
#ifdef QUEUE_DEBUG
		printf("\nERROR !! Queue is FULL, can't Enqueue [%i]\n",data);
#endif // QUEUE_DEBUG
	}else{
		QUEUE_tstrList* pitem = (QUEUE_tstrList*)malloc(sizeof(QUEUE_tstrList));
		if(pitem){
			pitem->data = data;
			pitem->next = NULL_PTR;

			if(pqueue->front){
				pqueue->rear->next = pitem;
			}else{
				pqueue->front = pitem;
			}
			pqueue->rear  = pitem;
			pqueue->size++;
			RetVal = QUEUE_OK;
#ifdef QUEUE_DEBUG
			printf("Data [%i] is Enqueued in Queue\n",data);
#endif // QUEUE_DEBUG
		}else{
#ifdef QUEUE_DEBUG
			printf("\nERROR !! can't locate new item, can't Enqueued [%i]\n",data);
#endif // STACK_DEBUG
		}
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
		QUEUE_tstrList* pitem = pqueue->front;
		if(pitem != NULL_PTR){
			*pdata = pitem->data;

			if (pqueue->rear == pqueue->front){
				pqueue->rear = NULL_PTR;
			}
			pqueue->front = pqueue->front->next;
			pqueue->size--;

			free(pitem);
			RetVal = QUEUE_OK;
#ifdef QUEUE_DEBUG
			printf("Data [%i] is Dequeued from Queue\n",*pdata);
#endif // QUEUE_DEBUG
		}
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
		QUEUE_tstrList* pitem = pqueue->front;
		if(pitem != NULL_PTR){
			*pdata = pitem->data;
			RetVal = QUEUE_OK;
#ifdef QUEUE_DEBUG
			printf("QueueTop = %i\n",*pdata);
#endif // QUEUE_DEBUG
		}
	}

	return RetVal;
}

/* ************************************************************************** */

u16 queue_size(QUEUE_tstr *pqueue){
	return pqueue->size;
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
			for(QUEUE_tstrList* temp = pqueue->front ; temp ; temp = temp->next){
				printf(" [%i] ", temp->data);
			}
			printf("\n");
		}
		RetVal = QUEUE_OK;
	}

	return RetVal;
}


/*************************** E N D (Queue.c) ******************************/
