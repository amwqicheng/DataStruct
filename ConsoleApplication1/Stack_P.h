#pragma once
#include"stdafx.h"
#ifndef STACK_H
#define STACH_H

//宏
#define _STACK_EMPTY_(pTop,pBase,ER_CODE) if(pTop==pBase)return ER_CODE;
//定义结构
typedef struct {
	ElemType
		* base,
		*top;
	Num maxsize;
}SqStack_P;



//原子方法

//基本方法
Status InitStack_Sq(SqStack_P &s) {
	_MALLOC_N(s.base, ElemType, STACK_MAX_SIZE);
	s.top = s.base;
	s.maxsize = STACK_MAX_SIZE;
	return INIT_SUCCESSED;
}
Status GetTop_Sq(SqStack_P& s,ElemType &rdata) {
	_STACK_EMPTY_(s.top, s.base, STACK_EMPTY);
	rdata= *(s.top - 1);
	return GET_STACK_TOP_SUCCESSED;
}
Status Push_Sq(SqStack_P& s, ElemType data) {
	if (s.top - s.base > s.maxsize)
	{
		ElemType* space;
		_REALLOC_N(space, s.base, ElemType, s.maxsize + STACK_INCR_SIZE);
		s.base = space;
		s.top = s.base + s.maxsize;
		s.maxsize += STACK_INCR_SIZE;
	}
	*s.top++ = data;
	return STACK_PUSH_SUCCESSED;
}
Status Pop_Sq(SqStack_P& s, ElemType& rdata) {
	_STACK_EMPTY_(s.top, s.base, STACK_EMPTY);
	rdata = *--s.top;
	return STACK_POP_SUCCESSED;
}












































#endif // !STACK_H


