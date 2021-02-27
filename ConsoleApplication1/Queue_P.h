#pragma once
#ifndef QUEUE_P_H
#define QUEUE_P_H
#include"stdafx.h"
//宏

//结构
typedef struct QNode_P {
	ElemType data;
	QNode_P* next;
}QNode_P, * QNode_PTR;
typedef struct {
	QNode_PTR front;
	QNode_PTR rear;
}LinkQueue_P;

//原子方法

//基本方法

#endif // !QUEUE_P_H

