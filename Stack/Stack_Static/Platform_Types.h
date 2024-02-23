/* ************************************************************************** */
/* ********************** FILE DEFINITION SECTION *************************** */
/* ************************************************************************** */
/* File Name   : Std_Types.h												  */
/* Author      : MAAM														  */
/* Version     : v00														  */
/* date        : Jun 10, 2023												  */
/* ************************************************************************** */
/* ************************ HEADER FILES INCLUDES **************************  */
/* ************************************************************************** */

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

/* ************************************************************************** */
/* ********************** TYPE_DEF/STRUCT/ENUM SECTION ********************** */
/* ************************************************************************** */

/** Data Types New Definitions **/
/** Standard Unsigned Byte/Word/Long_Word **/
typedef unsigned char     		u8 ;
typedef unsigned short int  	u16;
typedef unsigned long int    	u32;
typedef unsigned long long int 	u64;

/** Standard Signed Byte/Word/Long_Word **/
typedef signed char				s8 ;
typedef signed short int      	s16;
typedef signed long int      	s32;
typedef signed long long int	s64;

/** Standard Real Decimal number **/
typedef float       f32;
typedef double      f64;

/** Standard Pointer to Unsigned Byte/Word/Long_Word **/
typedef u8*			pu8 ;
typedef u16*		pu16;
typedef u32*		pu32;
typedef u64*		pu64;

/** Standard Pointer to Signed Byte/Word/Long_Word **/
typedef s8*			ps8 ;
typedef s16*		ps16;
typedef s32*		ps32;
typedef s64*		ps64;

/* ************************************************************************** */
/* ************************** MACRO/DEFINE SECTION ************************** */
/* ************************************************************************** */

/** SWS_Std_00031 **/
#ifndef NULL_PTR
#define NULL_PTR					((void *) 0U)
#endif

/** Data Types Limitation "Ranges" **/
#define UINT8_MIN					((uint8)0x00U)
#define UINT8_MAX					((uint8)0xFFU)
#define SINT8_MIN					((sint8)0x80 )
#define SINT8_MAX					((sint8)0x7F )

#define UINT16_MIN					((uint16)0x0000U)
#define UINT16_MAX					((uint16)0xFFFFU)
#define SINT16_MIN					((sint16)0x8000 )
#define SINT16_MAX					((sint16)0x7FFF )

#define UINT32_MIN					((uint32)0x00000000UL)
#define UINT32_MAX					((uint32)0xFFFFFFFFUL)
#define SINT32_MIN					((sint32)0x80000000L )
#define SINT32_MAX					((sint32)0x7FFFFFFFL )

#define UINT64_MIN					((uint64)0x0000000000000000ULL)
#define UINT64_MAX					((uint64)0xFFFFFFFFFFFFFFFFULL)
#define SINT64_MIN					((sint64)0x8000000000000000LL )
#define SINT64_MAX					((sint64)0x7FFFFFFFFFFFFFFFLL )

#define FLOAT32_MIN					((float32)1.17549435e-38)
#define FLOAT32_EPSILON				((float32)1.19209290e-07)
#define FLOAT32_MAX					((float32)3.40282347e+38)

#define FLOAT64_MIN					((float64)2.2250738585072014e-308)
#define FLOAT64_EPSILON				((float64)2.2204460492503131e-16)
#define FLOAT64_MAX					((float64)1.7976931348623157e+308)

/* ************************************************************************** */
/* ***************************** CONST SECTION ****************************** */
/* ************************************************************************** */

/* ************************************************************************** */
/* ***************************** VARIABLE SECTION *************************** */
/* ************************************************************************** */

/* ************************************************************************** */
/* **************************** FUNCTION SECTION **************************** */
/* ************************************************************************** */


#endif /* PLATFORM_TYPES_H_ */
/*************************** E N D (Std_Types.h) ******************************/
