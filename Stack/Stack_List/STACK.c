/* ************************************************************************** */
/* ********************** FILE DEFINITION SECTION *************************** */
/* ************************************************************************** */
/* File Name   : STACK.c													  */
/* Author      : MAAM														  */
/* Version     : v00														  */
/* date        : Jun 10, 2023												  */
/* ************************************************************************** */
/* ************************ HEADER FILES INCLUDES **************************  */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "Platform_Types.h"
#include "STACK.h"

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

STACK_ReturnType initStack(STACK_tstr **pstack){
	STACK_ReturnType RetVal = STACK_NOK;

	*pstack = (STACK_tstr *)malloc(sizeof(STACK_tstr));
	if(pstack){
		(*pstack)->sp   = -1;
		(*pstack)->head = NULL_PTR;
		RetVal = STACK_OK;
	}else{
	}

	return RetVal;
}
STACK_ReturnType deinitStack(STACK_tstr *pstack){
	STACK_ReturnType RetVal = clrStack(pstack);
	free(pstack);
	pstack = NULL;
	return RetVal;
}
STACK_ReturnType clrStack(STACK_tstr *pstack){
	STACK_ReturnType RetVal = STACK_NOK;

	if(pstack == NULL_PTR){

	}else{
		while(pstack->head){
			STACK_tstrList * pitem = pstack->head;
			pstack->head = pstack->head->next;
			pstack->sp--;

			free(pitem);
		}
		RetVal = STACK_OK;
	}

	return RetVal;
}

STACK_ReturnType isEmpty(STACK_tstr *pstack){
	return ((s16)pstack->sp == (s16)-1) ? STACK_Empty : STACK_NotFull;
}
STACK_ReturnType isFull (STACK_tstr *pstack){
	return ((s16)pstack->sp == (s16) MAX_STACK-1) ? STACK_Full : STACK_NotFull;
}

STACK_ReturnType push(STACK_tstr *pstack ,STACK_DataType data){
	STACK_ReturnType RetVal = STACK_NOK;

	if (isFull(pstack) == STACK_Full || pstack == NULL_PTR){
#ifdef STACK_DEBUG
		printf("\nERROR !! Stack NullL, can't Push [%i]\n",data);
#endif // STACK_DEBUG
	}else{
		STACK_tstrList * pitem = (STACK_tstrList*) malloc(sizeof(STACK_tstrList));
		if(pitem){
			pitem->data = data;
			pitem->next = pstack->head;
			pstack->head  = pitem;
			pstack->sp++;
			RetVal = STACK_OK;
#ifdef STACK_DEBUG
			printf("Data [%i] is Pushed in Stack\n",data);
#endif // STACK_DEBUG
		}else{
#ifdef STACK_DEBUG
			printf("\nERROR !! can't locate new item, can't Push [%i]\n",data);
#endif // STACK_DEBUG
		}
	}

	return RetVal;
}
STACK_ReturnType pop (STACK_tstr *pstack ,STACK_DataType* pdata){
	STACK_ReturnType RetVal = STACK_NOK;

	if(isEmpty(pstack) == STACK_Empty || (pstack == NULL_PTR) || (pdata == NULL_PTR)){
#ifdef STACK_DEBUG
		printf("\nERROR !! can't POP from Stack\n");
#endif // STACK_DEBUG
	}else{
		STACK_tstrList * pitem = pstack->head;
		if(pstack->head != NULL_PTR){
			*pdata  = pstack->head->data;
			pstack->head = pstack->head->next;
			pstack->sp--;

			free(pitem);
			RetVal = STACK_OK;
#ifdef STACK_DEBUG
			printf("Data [%i] is POPED from Stack\n",*pdata);
#endif // STACK_DEBUG
		}
	}

	return RetVal;
}
STACK_ReturnType top (STACK_tstr *pstack ,STACK_DataType* pdata){
	STACK_ReturnType RetVal = STACK_NOK;

	if (isEmpty(pstack) == STACK_Empty || (pstack == NULL_PTR) || (pdata == NULL_PTR)){
#ifdef STACK_DEBUG
		printf("\nERROR !! Stack is Empty\n");
#endif // STACK_DEBUG
	}else{
		*pdata  = pstack->head->data;
		RetVal = STACK_OK;
#ifdef STACK_DEBUG
		printf("StackTop = %i\n",*pdata);
#endif // STACK_DEBUG
	}

	return RetVal;
}

/* ************************************************************************** */

STACK_ReturnType stack_check(STACK_tstr *pstack){
	STACK_ReturnType RetVal = STACK_NOK;

	if(pstack == NULL_PTR){

	}else{
		if(isFull(pstack) == STACK_Full){
			printf("\nThe Stack is FULL \n");
		}else if(isEmpty(pstack) == STACK_Empty){
			printf("\nThe Stack is Empty \n");
		}else{
			printf("\nThe Stack Size = %i\n",pstack->sp);
		}
		RetVal = STACK_OK;
	}

	return RetVal;
}
STACK_ReturnType stack_display(STACK_tstr *pstack){
	STACK_ReturnType RetVal = STACK_NOK;

	if(pstack == NULL_PTR){

	}else{
		if(isEmpty(pstack)){
			for(STACK_tstrList* temp = pstack->head ; temp ; temp = temp->next){
				printf(" [%i] ", temp->data);
			}
			printf("\n");
		}
		RetVal = STACK_OK;
	}

	return RetVal;
}

/*************************** E N D (STACK.c) ******************************/
