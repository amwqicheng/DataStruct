#pragma once
#ifndef SqDualStack_H
#include"stdafx.h"
//��
#define SqDualStack_H
//�ṹ

//��ջ����ռ�
typedef struct {
	ElemType data[STACK_MAX_SIZE];
	Index
		top1,
		top2;

}SqDualStack;
//ԭ�ӷ���

//��������

Status Push_SDS(SqDualStack s, ElemType e, int stackNumber) {
	if (1 + s.top1 == s.top2)//ջ��
		return STACK_OVERFLOW;
	//ջ1��ջ
	if (stackNumber == 1)
		s.data[++s.top1] = e;
	//ջ2��ջ
	if (stackNumber == 2)
		s.data[--s.top2] = e;
	return STACK_PUSH_SUCCESSED;
}
Status Pop_SDS(SqDualStack s, ElemType& e, int stackNumber) {
	if (stackNumber == 1)
	{
		if (s.top1 == -1)//ջ��
			return STACK_OVERFLOW;
		e = s.data[s.top1--];
		return STACK_POP_SUCCESSED;
	}
	if (stackNumber == 2)
	{
		if (s.top2 == STACK_MAX_SIZE)//ջ��
			return STACK_OVERFLOW;
		e = s.data[s.top2++];
	}
	return STACK_POP_SUCCESSED;
}





#endif // !SqDualStack_H
