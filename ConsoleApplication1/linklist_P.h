#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"stdafx.h"

#define LIST_INIT_NUM 10

typedef struct LNode_P {
	ElemType data;
	LNode_P* next;
}LNode_P,*LinkList_P;
typedef LNode_P* pLNode;
//��ʼ������
Status ListInit(pLNode&rHead,const int createNum= LIST_INIT_NUM) {
	if (createNum<1 || createNum>LIST_INIT_NUM)
		exit(NUM_INIT_ERROR);
	pLNode
		head, 
		node,
		cur;
	_MALLOC_(head,LNode_P);
	cur = head;
	for (int i = 0; i < createNum; ++i)
	{
		_MALLOC_(node, LNode_P);
		#if _DEBUG
		node->data = i+1;
		#endif // _DEBUG	
		cur->next = node;
		cur = cur->next;
	}
	cur->next = NULL;
	rHead = head;
	rHead->data = createNum;
}
//�������Ԫ��
void ListInsert(pLNode&head,ElemType data,int nPos) {
	if (nPos<1 || nPos>head->data)
		exit(NUM_INS_ERROR);
	pLNode
		node,
		cur=head;
	_MALLOC_(node, LNode_P);
	node->data = data;
	nPos > 1 ? ++nPos : nPos = 1;//����ɾ��ͷ�ڵ�
	while (nPos>1 && cur->next != NULL)
	{
		cur = cur->next;
		--nPos;
	}
	node->next = cur->next;
	cur->next = node;
	++head->data;
}
//����ɾ��Ԫ��
void ListDelete(pLNode& head,ElemType&rData,int nPos) {
	
	if (nPos<1 || nPos>head->data)
		exit(NUM_DEL_ERROR);
	pLNode
		del,
		cur = head;
	while (nPos>1)
	{
		cur = cur->next;
		--nPos;
	}
	del = cur->next;
	rData = del->data;
	cur->next = cur->next->next;
	free(del);
	--head->data;
}
//��������
void ListDestroy(pLNode &head) {
	pLNode
		cur,
		pre;
	cur = head;
	pre = cur;
	while (cur->next!=NULL)
	{
		cur = cur->next;
		free(pre);
		pre = cur;
	}
}
//����Ϊ��
bool ListEmpty(const pLNode& head) {
	return head->data > 0 ? false : true;
}
//����Ԫ��
void LocateElem() {

}
//������
int ListLength(const pLNode& head) {
	return head->data;
}
//��������
void ListTraverse(const pLNode& head,void (*visitFun)(int)) {
	pLNode
		node=head;
	node = node->next;
	while (node)
	{
		(*visitFun)(node->data);
		node = node->next;
	}
}
#endif // !LINKEDLIST_H
