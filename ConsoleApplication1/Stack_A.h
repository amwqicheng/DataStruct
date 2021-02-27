#pragma once
#include"stdafx.h"
#ifndef STACK_A_H
#define STACK_A_H
//宏
//结构
typedef struct {
	ElemType data[STACK_MAX_SIZE];
	Index top;
}SqStack_A;
//原子方法

//基本方法
Status Push_Sq(SqStack_A s, ElemType data) {
	if (s.top == STACK_MAX_SIZE - 1)
		return STACK_OVERFLOW;
	++s.top;
	s.data[s.top] = data;
	return STACK_PUSH_SUCCESSED;
}
Status Pop_Sq(SqStack_A s, ElemType& rdata) {
	if (s.top == 1)
		return STACK_EMPTY;
	rdata = s.data[s.top];
	--s.top;
	return  STACK_POP_SUCCESSED;
}
#endif // !STACK_A_H
