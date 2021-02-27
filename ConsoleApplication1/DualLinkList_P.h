#pragma once
#include"stdafx.h"
#ifndef DUALLINKLIST_H
#define DUALLINKLIST_H
#define LIST_INIT_NUM 10
#define isDualLinkList_P true
#define isLoopList false
#define _CHECKPOS_DLL(pos,pHead,ER_CODE) if(pos<1||pos>ListLength_DLL(pHead))return ER_CODE
typedef struct DualNode 
{
	ElemType data;//头节点存储长度
	#if isDualLinkList_P
		DualNode* prev;
	#endif // DualLinkList_P
	DualNode* next;
}DLL_Node_P,*DualLinkList_P;
typedef  DLL_Node_P* pDLL;
//状态码

//原子方法
//返回长度
inline const Num ListLength_DLL(const pDLL& pHead) {
	return pHead->data;
}
Status operate_del_DLL(pDLL& prev, pDLL& next, ElemType &rdata) {
	_CHECK_PTR_(next,return, DELETE_FAILED);	//保证被删除节点有效
	if(prev)
	prev->next = next->next;
	#if isDualLinkList_P
	if (next->next)
	next->next->prev = prev;
	#endif // isDualLinkList_P
	rdata = next->data;
	free(next);
	return DELETE_SUCCESSED;
}
//增加
Status operate_ins_DLL(pDLL&prev,pDLL&next,ElemType data) {
	pDLL p;
	_MALLOC_(p,DLL_Node_P);
	p->data = data;
	p->next = next;
	if(prev)
	prev->next = p;
	#if isDualLinkList_P
	if(next)
	next->prev = p;
	p->prev = prev;
	#endif // DualLinkList_P
	return INSERT_SUCCESSED;
}
//返回第num个节点地址
Status getElemntByPos_DLL(const pDLL& pHead,Num num,pDLL& rPrev,pDLL&rNext,pDLL&rLater) {
	rNext =pHead,
	rPrev =NULL,
	rLater = NULL;
	_CHECKPOS_DLL(num, pHead, NUM_GET_ERROR);
	while (rNext&&num)
	{
		rPrev = rNext;
		_NEXT_PTR_(rNext);
		--num;
	}
	if (rNext)
		return GET_ELEM_POS_SUCCESSED;
	return GET_ELEM_POS_FAILED;
}
//检测是否有某值节点并返回地址
Status getElemntByVal_DLL(pDLL& pHead, ElemType val, pDLL& rPrev, pDLL&rAddress) {
	rAddress = pHead;
	while (rAddress)
	{
		rPrev = rAddress;
		_NEXT_PTR_(rAddress);
		if (rAddress && rAddress->data == val)
			break;
	}
	if (rAddress)
		return GET_ELEM_POS_SUCCESSED;
	rAddress=NULL;
	rPrev = NULL;
	return GET_ELEM_POS_FAILED;
}




//基本方法

//初始化链表
void InitList_DLL(pDLL &pHead,Num initSize=LIST_INIT_NUM) {
	//创建头节点
	_MALLOC_(pHead,DLL_Node_P);
	pHead->data = 0;
	#if isDualLinkList_P
		pHead->prev = NULL;
	#endif // DualLinkList_P
	pHead->next = NULL;
	pDLL 
		pLast=pHead,
		pCur;
	for (int i = 0; i < initSize; ++i)
	{
		_MALLOC_(pCur, DLL_Node_P);
		#if isDualLinkList_P
		pCur->prev = pLast;
		#endif // DualLinkList_P
		pLast->next = pCur;
		pLast = pCur;
	}
	pLast->next = NULL;
	pHead->data = initSize;
}
//向某值前插入元素
Status ListInsert_DLL( ElemType tag, ElemType data,pDLL& pHead) {
	pDLL ptagNode,
		prev;
	getElemntByVal_DLL(pHead, tag,prev,ptagNode);
	_CHECK_PTR_(ptagNode,return,INSERT_FAILED);
	if (operate_ins_DLL(ptagNode->prev, ptagNode, data) == INSERT_SUCCESSED)
	{
		++pHead->data;
		return INSERT_SUCCESSED;
	}
	return INSERT_FAILED;
}
//向某个位置前插入元素
Status ListInsert_DLL(pDLL& pHead,Index pos,ElemType data) {
	pDLL
		p,
		prev,
		later;
	getElemntByPos_DLL(pHead, pos, prev, p, later);
	if (operate_ins_DLL(prev, p, data) == INSERT_SUCCESSED)
	{
		++pHead->data;
		return INSERT_SUCCESSED;
	}
	return INSERT_FAILED;
}
//删除某节点
Status ListDelete_DLL(pDLL& pHead, Num pos, ElemType& re) {
	pDLL
		p,
		prev,
		later;
	getElemntByPos_DLL(pHead, pos, prev, p,later);
	if (pHead->data > 0 && operate_del_DLL(prev, p, re) == DELETE_SUCCESSED)
	{
		--pHead->data;
		return DELETE_SUCCESSED;
	}
	return DELETE_FAILED;
}
//销毁表
Status DestroyList_DLL(pDLL& pHead) {
	
	pDLL
		pNext,
		pDel=pHead;
	_CHECK_PTR_(pHead,return,DESTROY_FAILED);
	while (pDel)
	{
		pNext = pDel->next;
		free(pDel);
		pDel = pNext;
	}
	pHead = nullptr;
	return DESTROY_SUCCESSED;
}
//修改某位置数据
Status setElementByPos_DLL(pDLL& pHead,Num pos,ElemType data) {
	pDLL
		p,
		prev,
		later;
	getElemntByPos_DLL(pHead, pos, prev, p, later);
	_CHECK_PTR_(p,return, PTR_ERROR);
	p->data = data;
	return SET_ELEM_VAL_SUCCESSED;
}
//修改某值
Status setElementByVal_DLL(pDLL& pHead, ElemType val , ElemType data) {
	pDLL p,
		 prev;
	getElemntByVal_DLL(pHead, val,prev,p);
	_CHECK_PTR_(p,return, PTR_ERROR);
	p->data = data;
	return SET_ELEM_VAL_SUCCESSED;
}
//跟新表长
const Num UpdateLength_DLL(pDLL& pHead) {
	Num count = 0;
	pDLL pcur = pHead;
	while (pcur)
	{
		++count;
		_NEXT_PTR_(pcur);
	}
	_CHECK_PTR_(pHead,return,PTR_ERROR);
	pHead->data = count;
	return count;
}

//遍历链表
void ListTraverse_DLL(pDLL pHead,void (*visit)(ElemType)) {
	_NEXT_PTR_(pHead);
	while (pHead)
	{
		(*visit)(pHead->data);
		_NEXT_PTR_(pHead);
	}
}
#endif // !DUALLINKLIST_H