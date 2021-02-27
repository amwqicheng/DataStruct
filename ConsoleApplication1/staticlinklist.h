#pragma once
#ifndef SLL_H
#define SLL_H
#include"stdafx.h"

#define SLL_MAXSIZE 1000

//��������ͷ�ڵ�λ��0
//��������ͷ�ڵ�λ��SLL_MAXSIZE-1
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

//ԭ�Ӻ���

//��̬����
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
//ԭ�ӷ���:����
inline Status operate_ins_SLL(SLL& L, int &indexOfLastElem, int &indexOfnewElem) {
	L[indexOfnewElem].NextCur = L[indexOfLastElem].NextCur;
	L[indexOfLastElem].NextCur = indexOfnewElem;
	return INSERT_SUCCESSED;
}
//ԭ�ӷ���:ɾ��
inline Status operate_del_SLL(SLL& L, int &indexBeforeDel, int &indexOfDel){
	if (indexOfDel == 0 || indexOfDel == indexOfHead)
		return NUM_DEL_ERROR;
	L[indexBeforeDel].NextCur = L[indexOfDel].NextCur;
	free_SLL(L, indexOfDel);//�ͷſռ�
	return DELETE_SUCCESSED;
}
//���ҵ�num��Ԫ�ص�NextCur
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
//��λĳԪ��
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

//��������

//��ʼ����̬��
void InitList_SLL(SLL& space) {
	//��ɱ�������
	for (int index = 0; index < SLL_MAXSIZE - 1; ++index)
	space[index].NextCur = index + 1;
	space[indexOfHead].NextCur = 0;
	space[indexOfHead].data = 0;
}
//��̬���������
Status InsertBeforePos_SLL(SLL& L, int insPos, ElemType data) {
	if (insPos<1 || insPos - 1>ListLength_SLL(L))
		return NUM_INS_ERROR;
	int indexBeforeIns= getElementCur(L,insPos),
		indexIns=malloc_SLL(L);//����ռ�
	L[indexIns].data = data;
	++L[indexOfHead].data;
	return operate_ins_SLL(L, indexBeforeIns,indexIns);
}

//��̬��ɾ��Ԫ��
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
//ɾ��ĳֵԪ��
Status ListDeleteByVal_SLL(SLL& L, ElemType tag) {
	if (ListLength_SLL(L) == 0)
		return ER_EMPTY_SLL;
	SLL_Relation s= getRelationIndexByValue(L, tag);
	return operate_del_SLL(L, s.prev, s.self);
}
//��̬���޸�����
void ListChange_SLL(SLL& L, ElemType newdata, int modifyPos) {
	L[modifyPos].data = newdata;
}
//��̬�����
void ListTraverse_SLL(SLL& L, void (*func)(ElemType)) {
	for (int i = L[indexOfHead].NextCur; i; i = L[i].NextCur)
		(*func)(L[i].data);
}

#endif // !SLL_H
