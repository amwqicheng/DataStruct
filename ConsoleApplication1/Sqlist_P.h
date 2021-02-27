#pragma once
#ifndef SqList_P_H
#define SqList_P_H
#include"stdafx.h"

//宏
#define _CHECK_POS_SL(sl,pos,ER_CODE) if(pos<1||pos-1>sl.length)return ER_CODE
//状态码

//定义结构
typedef  struct SL_Node_P {
	ElemType* space;
	Num length,//当前长度
		maxSize;//总长度
}SL_Node_P,SqList_P;
typedef SL_Node_P* pSL;


//原子方法
//移动第start至stop个元素
Status RemoveElem_SL(SqList_P &SL,Index indexOfBegin,Index indexOfStop) {
	Num remove = indexOfBegin - indexOfStop;
	if (remove == 0|| SL.length == 0)return OK;
	ElemType
		* p = SL.space + indexOfStop;
	abs(remove);
	while (remove)
	{
		//右移
		if (indexOfBegin < indexOfStop)
		{
			*(p) = *(p - 1);
			--p;
			
		}
		//左移
		else 
		{
			*(p) = *(p + 1);
			++p;
		}
		--remove;
	}
	return OK;
}
//基本方法

//创建链表
Status InitList_SL(SqList_P&SL,Num initSize= SQLIST_MAX_SIZE) {
	_MALLOC_N(SL.space, ElemType, initSize);
	SL.length = 0;
	SL.maxSize = initSize;
	return INIT_SUCCESSED;
}
//删除位置pos数据
Status DeleteBeforePos_SL(SqList_P&SL, Num pos, ElemType& rdata) {
	_CHECK_PTR_(SL.space, return, PTR_ERROR);
	_CHECK_POS_SL(SL, pos+1, NUM_DEL_ERROR);
	rdata = *(SL.space + pos - 1);
	if (SL.length &&RemoveElem_SL(SL,(Index)(SL.length),(Index)(pos - 1)) == OK)
	{
		--SL.length;
		return DELETE_SUCCESSED;
	}
	return DELETE_FAILED;
}
//在第pos个之前插入数据
Status InsertBeforePos_SL(SqList_P& SL,Num pos,ElemType data) {
	_CHECK_PTR_(SL.space, return, PTR_ERROR);
	_CHECK_POS_SL(SL, pos, NUM_INS_ERROR);
	if (SL.maxSize <= SL.length)
	{
		ElemType* space;
		Num size = SL.maxSize + SQLIST_INCR_SIZE;
		_REALLOC_N(space,SL.space, ElemType, size);
		SL.space = space;
		SL.maxSize = size;
	}
	if (RemoveElem_SL(SL, (Index)(pos - 1), (Index)(SL.length)) == OK)
	{
		++SL.length;
		*(SL.space+pos - 1) = data;
		return INSERT_SUCCESSED;
	}
	return INSERT_FAILED;
}
//在第值为val之前插入数据
Status ListInsertByVal_SL(SqList_P& SL,ElemType tag, ElemType data) {
	return INSERT_FAILED;
}
//遍历
Status ListTraverse_SL(const SqList_P& SL,void (*f_visit)(ElemType)) {
	int i = SL.length;
	ElemType* phead = SL.space;
	while (i)
	{
		(*f_visit)(*(phead++));
		--i;
	}
	return OK;
}
//销毁
void DestoryList_SL( SqList_P& SL) {
	free(SL.space);
	SL.length = 0;
	SL.maxSize = 0;
}
//修改某位置数值
Status SetElemValueByPos_SL(SqList_P& SL,Index pos,ElemType data) {
	_CHECK_POS_SL(SL, pos, NUM_SET_ERROR);
	*(SL.space + pos - 1) = data;
	return SET_ELEM_VAL_SUCCESSED;
}
#endif
