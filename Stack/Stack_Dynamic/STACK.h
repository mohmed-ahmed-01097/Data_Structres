/* ************************************************************************** */
/* ********************** FILE DEFINITION SECTION *************************** */
/* ************************************************************************** */
/* File Name   : STACK.h													  */
/* Author      : MAAM														  */
/* Version     : v00														  */
/* date        : Jun 10, 2023												  */
/* ************************************************************************** */
/* ************************ HEADER FILES INCLUDES **************************  */
/* ************************************************************************** */

#ifndef STACK_H_
#define STACK_H_

#define MAX_STACK 			100
#define STACK_DEBUG

/* ************************************************************************** */
/* ********************** TYPE_DEF/STRUCT/ENUM SECTION ********************** */
/* ************************************************************************** */

typedef s16 STACK_DataType;
typedef s8 STACK_ReturnType;

typedef enum{
	STACK_Empty      = -1,
	STACK_OneElement = 0,
	STACK_NotFull    = 1,
	STACK_Full       = MAX_STACK-1,
	STACK_Overflow   = MAX_STACK,
	STACK_Done       = MAX_STACK+1,
}STACK_tenumStatus;

typedef enum{
	STACK_NOK,
	STACK_OK,
}STACK_tenumReturnStatus;

typedef struct{
	s16				sp;
	u16				size;
	STACK_DataType*	data;
}STACK_tstr;

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

STACK_tstr* initStack(u16 size);
STACK_ReturnType deinitStack(STACK_tstr *pstack);
STACK_ReturnType clrStack(STACK_tstr *pstack);

STACK_ReturnType isEmpty(STACK_tstr *pstack);
STACK_ReturnType isFull (STACK_tstr *pstack);

STACK_ReturnType push(STACK_tstr *pstack ,STACK_DataType data);
STACK_ReturnType pop (STACK_tstr *pstack ,STACK_DataType* pdata);
STACK_ReturnType top (STACK_tstr *pstack ,STACK_DataType* pdata);

STACK_ReturnType stack_check(STACK_tstr *pstack);
STACK_ReturnType stack_display(STACK_tstr *pstack);


#endif /* STACK_H_ */
/*************************** E N D (STACK.h) ******************************/
