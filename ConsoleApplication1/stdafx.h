#pragma once
#include<iostream>

typedef int 
	Status,
	ElemType,
	Index,
	Num;

//È«¾Öºê
#define SQLIST_MAX_SIZE 100
#define SQLIST_INCR_SIZE 50

#define STACK_MAX_SIZE 100
#define STACK_INCR_SIZE 50

#define STRING_MAX_SIZE 255
#define abs(x) if (x < 0)x = -x
#define _CHECK_PTR_(p,reOrExit,ER_CODE) if(!p)reOrExit(ER_CODE)
#define _MALLOC_(pNode,type) pNode=(type*)malloc(sizeof(type));_CHECK_PTR_(pNode,exit,NODE_CREATE__FAILED)
#define _MALLOC_N(pNode,type,num) pNode=(type*)malloc(sizeof(type)*num);_CHECK_PTR_(pNode,exit,NODE_CREATE__FAILED)
#define _REALLOC_N(pNew,pOld,type,num) pNew=(type*)realloc(pOld,sizeof(type)*num);_CHECK_PTR_(pNew,exit,NODE_CREATE__FAILED)
#define _NEXT_PTR_(p) p=p->next
 
//×´Ì¬Âë
//ERROR
#define OK                                  0x0000
#define ERROR                               0x0001
#define PTR_ERROR                           0x0002
#define NUM_DEL_ERROR                       0x0003
#define NUM_INS_ERROR                       0x0004
#define NUM_INIT_ERROR                      0x0005
#define NUM_SET_ERROR                       0x0006
#define NUM_SET_ERROR                       0x0007
#define NUM_GET_ERROR                       0x0008
#define NUM_REM_ERROR                       0x0009
#define STACK_EMPTY                         0x000A
#define STACK_OVERFLOW                      0X000B
//SUCCESS
#define INSERT_SUCCESSED                    0x0110
#define DELETE_SUCCESSED                    0x0111
#define REMOVE_SUCCESSED                    0x0112
#define DESTROY_SUCCESSED                   0x0113
#define INIT_SUCCESSED                      0x0114
#define CREATE_ELEM__SUCCESSED              0x0115
#define SET_ELEM_VAL_SUCCESSED              0x0116
#define SET_ELEM_POS_SUCCESSED              0x0117
#define GET_ELEM_VAL_SUCCESSED              0x0118
#define GET_ELEM_POS_SUCCESSED              0x0119
#define SET_LENGTH___SUCCESSED              0x011A
#define GET_STACK_TOP_SUCCESSED             0x011B
#define STACK_PUSH_SUCCESSED                0x011C
#define STACK_POP_SUCCESSED                 0x011D
//FAILED
#define INSERT_FAILED                       0x1001
#define DELETE_FAILED                       0x1002
#define DESTROY_FAILED                      0x1003
#define REMOVE_FAILED                       0x1004
#define SET_ELEM_VAL_FAILED                 0x1005
#define SET_ELEM_POS_FAILED                 0x1006
#define NODE_CREATE__FAILED                 0x1007
#define GET_ELEM_VAL_FAILED                 0x1008
#define GET_ELEM_POS_FAILED                 0x1009
#define SET_LENGTH___FAILED                 0x100A






