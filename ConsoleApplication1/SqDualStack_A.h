#pragma once
#ifndef SqDualStack_H
#include"stdafx.h"
//宏
#define SqDualStack_H
//结构

//两栈共享空间
typedef struct {
	ElemType data[STACK_MAX_SIZE];
	Index
		top1,
		top2;

}SqDualStack;
//原子方法

//基本方法

Status Push_SDS(SqDualStack s, ElemType e, int stackNumber) {
	if (1 + s.top1 == s.top2)//栈满
		return STACK_OVERFLOW;
	//栈1进栈
	if (stackNumber == 1)
		s.data[++s.top1] = e;
	//栈2进栈
	if (stackNumber == 2)
		s.data[--s.top2] = e;
	return STACK_PUSH_SUCCESSED;
}
Status Pop_SDS(SqDualStack s, ElemType& e, int stackNumber) {
	if (stackNumber == 1)
	{
		if (s.top1 == -1)//栈空
			return STACK_OVERFLOW;
		e = s.data[s.top1--];
		return STACK_POP_SUCCESSED;
	}
	if (stackNumber == 2)
	{
		if (s.top2 == STACK_MAX_SIZE)//栈空
			return STACK_OVERFLOW;
		e = s.data[s.top2++];
	}
	return STACK_POP_SUCCESSED;
}





#endif // !SqDualStack_H
