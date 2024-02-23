/* ************************************************************************** */
/* ********************** FILE DEFINITION SECTION *************************** */
/* ************************************************************************** */
/* File Name   : Queue..h													  */
/* Author      : MAAM														  */
/* Version     : v00														  */
/* date        : Jun 10, 2023												  */
/* ************************************************************************** */
/* ************************ HEADER FILES INCLUDES **************************  */
/* ************************************************************************** */

#ifndef QUEUE_H_
#define QUEUE_H_

#define MAX_QUEUE 			100
#define QUEUE_DEBUG

/* ************************************************************************** */
/* ********************** TYPE_DEF/STRUCT/ENUM SECTION ********************** */
/* ************************************************************************** */

typedef s16 QUEUE_DataType;
typedef s8 QUEUE_ReturnType;

typedef enum{
	QUEUE_Empty      = 0,
	QUEUE_OneElement = 1,
	QUEUE_NotFull    = 2,
	QUEUE_Full       = MAX_QUEUE-1,
	QUEUE_Done       = MAX_QUEUE,
}QUEUE_tenuStatus;

typedef enum{
	QUEUE_NOK,
	QUEUE_OK,
}QUEUE_tenumReturnStatus;

typedef struct {
    u16  size;
    s16  front;
    s16  rear;
    QUEUE_DataType* data;
}QUEUE_tstr;

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

QUEUE_tstr* newQueue(u16 size);
QUEUE_ReturnType deinitQueue(QUEUE_tstr *pqueue);
QUEUE_ReturnType clrQueue(QUEUE_tstr *pqueue);

QUEUE_ReturnType isEmpty(QUEUE_tstr *pqueue);
QUEUE_ReturnType isFull (QUEUE_tstr *pqueue);

QUEUE_ReturnType Enqueue(QUEUE_tstr *pqueue ,QUEUE_DataType data);
QUEUE_ReturnType Dequeue(QUEUE_tstr *pqueue ,QUEUE_DataType *pdata);
QUEUE_ReturnType top(QUEUE_tstr *pqueue ,QUEUE_DataType *pdata);

QUEUE_ReturnType queue_check(QUEUE_tstr *pqueue);
QUEUE_ReturnType queue_display(QUEUE_tstr *pqueue);

#endif /* QUEUE_H_ */
/*************************** E N D (Queue..h) ******************************/
