#pragma once
#ifndef QUEUE_P_H
#define QUEUE_P_H
#include"stdafx.h"
//��

//�ṹ
typedef struct QNode_P {
	ElemType data;
	QNode_P* next;
}QNode_P, * QNode_PTR;
typedef struct {
	QNode_PTR front;
	QNode_PTR rear;
}LinkQueue_P;

//ԭ�ӷ���

//��������

#endif // !QUEUE_P_H

