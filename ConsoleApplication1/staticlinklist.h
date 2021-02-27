#pragma once
#ifndef SLL_H
#define SLL_H
#include"stdafx.h"

#define SLL_MAXSIZE 1000

//备用链表头节点位置0
//数据链表头节点位置SLL_MAXSIZE-1
typedef struct SLL_Node {
	ElemType data;
	int NextCur;
}SLL_Node,SLL[SLL_MAXSIZE];
typedef struct  {
	Index prev;
	Index self;
	Index next;
}SLL_Relation;

#define indexOfHead SLL_MAXSIZE-1
#define ER_EMPTY_SLL -105

//原子函数

//静态表长度
const int ListLength_SLL(SLL& L) {
	int
		i = L[indexOfHead].NextCur,
		num = 0;
	while (i)
	{
		i = L[i].NextCur;
		++num;
	}
	L[indexOfHead].data = num;
	return num;
}
int malloc_SLL(SLL& space) {
	int i = space[0].NextCur;
	if (i)
		space[0].NextCur = space[i].NextCur;
	return i;
}
void free_SLL(SLL& space, int FreePos) {
	space[FreePos].NextCur = space[0].NextCur;
	space[0].NextCur = FreePos;
}
//原子方法:插入
inline Status operate_ins_SLL(SLL& L, int &indexOfLastElem, int &indexOfnewElem) {
	L[indexOfnewElem].NextCur = L[indexOfLastElem].NextCur;
	L[indexOfLastElem].NextCur = indexOfnewElem;
	return INSERT_SUCCESSED;
}
//原子方法:删除
inline Status operate_del_SLL(SLL& L, int &indexBeforeDel, int &indexOfDel){
	if (indexOfDel == 0 || indexOfDel == indexOfHead)
		return NUM_DEL_ERROR;
	L[indexBeforeDel].NextCur = L[indexOfDel].NextCur;
	free_SLL(L, indexOfDel);//释放空间
	return DELETE_SUCCESSED;
}
//查找第num个元素的NextCur
inline int getElementCur(SLL& L, int num) {
	int i = indexOfHead;
	if (ListLength_SLL(L) == 0)return i;
	while (num > 1)
	{
		i = L[i].NextCur;
		--num;
	}
	return i;
}
Index getLastElmentIndexByValue(SLL& L, ElemType value) {
	int indexBeforeDel = 0,
		next = 0;
	for (next = L[indexOfHead].NextCur; next; next = L[next].NextCur)
	{
		if (L[next].data == value)
			break;
		indexBeforeDel = next;
	}
	indexBeforeDel == 0 ? indexBeforeDel = indexOfHead : indexBeforeDel= indexBeforeDel;
	return indexBeforeDel;
}
//定位某元素
Index getElementIndexByValue(SLL&L,ElemType value) {
	if (ListLength_SLL(L) == 0)
	return indexOfHead;
	int i = L[indexOfHead].NextCur;
	while (i)
	{
		i = L[i].NextCur;
		if (L[i].data == value)
			break;
	}
	i == 0 ? i = indexOfHead : i = i;
	return i;
}

//基本函数

//初始化静态表
void InitList_SLL(SLL& space) {
	//组成备用链表
	for (int index = 0; index < SLL_MAXSIZE - 1; ++index)
	space[index].NextCur = index + 1;
	space[indexOfHead].NextCur = 0;
	space[indexOfHead].data = 0;
}
//静态表插入数据
Status InsertBeforePos_SLL(SLL& L, int insPos, ElemType data) {
	if (insPos<1 || insPos - 1>ListLength_SLL(L))
		return NUM_INS_ERROR;
	int indexBeforeIns= getElementCur(L,insPos),
		indexIns=malloc_SLL(L);//分配空间
	L[indexIns].data = data;
	++L[indexOfHead].data;
	return operate_ins_SLL(L, indexBeforeIns,indexIns);
}

//静态表删除元素
Status DeleteInPos_SLL(SLL& L, int delPos, ElemType& re) {
	if (delPos<1 || delPos >ListLength_SLL(L))
	return NUM_DEL_ERROR;
	int indexBeforeDel = getElementCur(L, delPos),
		indexOfDel=L[indexBeforeDel].NextCur;
	re = L[indexOfDel].data;
	return operate_del_SLL(L, indexBeforeDel, indexOfDel);
}
//
SLL_Relation getRelationIndexByValue(SLL& L, ElemType value) {
	int indexBeforeDel = 0,
		next = 0;
	for (next = L[indexOfHead].NextCur; next; next = L[next].NextCur)
	{
		if (L[next].data == value)
			break;
		indexBeforeDel = next;
	}
	indexBeforeDel == 0 ? indexBeforeDel = indexOfHead : indexBeforeDel = indexBeforeDel;
	SLL_Relation s;
	s.prev = indexBeforeDel;
	s.self = next;
	s.next = L[next].NextCur;
	return s;
}
//删除某值元素
Status ListDeleteByVal_SLL(SLL& L, ElemType tag) {
	if (ListLength_SLL(L) == 0)
		return ER_EMPTY_SLL;
	SLL_Relation s= getRelationIndexByValue(L, tag);
	return operate_del_SLL(L, s.prev, s.self);
}
//静态表修改数据
void ListChange_SLL(SLL& L, ElemType newdata, int modifyPos) {
	L[modifyPos].data = newdata;
}
//静态表遍历
void ListTraverse_SLL(SLL& L, void (*func)(ElemType)) {
	for (int i = L[indexOfHead].NextCur; i; i = L[i].NextCur)
		(*func)(L[i].data);
}

#endif // !SLL_H
