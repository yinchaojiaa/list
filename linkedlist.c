#include <stdlib.h>
#include "linkedlist.h"

//创建一个新链表
List *createList(void)
{
	//1.创建链表
	List *listp = malloc(sizeof(List));

	//2.创建链表的头节点
	listp->phead = malloc(sizeof(Node));	
	
	//2.1 给节点的每个成员赋值
	listp->phead->data = -1;		//代表无效数据
	
	listp->phead->next = NULL;		

	//3.给链表的size成员赋值
	listp->size = 0;

	return listp;
}

//添加数据(追加)
void append(List *listp,char data)
{
	//1.将数据封装到一个新节点中
	Node *newNode = malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	//2.找到最后的那个节点
	Node *temp = listp->phead;
	while(temp->next)
		temp = temp->next;

	//3.将新节点追加到最后一个节点之后			
	temp->next = newNode;

	//4.将list的size++
	listp->size++;
}

//添加数据(在指定位置添加)
void insert(List *listp,char data,int index)
{
	//1.将数据封装到一个新节点中
	Node *newNode = malloc(sizeof(Node));
	newNode->data = data;
	//newNode->next = NULL;

	//2.找到要插入的位置的前一个节点
	if(index > listp->size)
		index = listp->size;
	if(index < 0)
		index = 0;

	Node *temp = listp->phead;
	while(index--)
		temp = temp->next;

	//3.插入节点
	newNode->next = temp->next;
	temp->next = newNode;

	//4.list的size成员++
	listp->size++;
}

//删除数据(删除找到的第一个指定数据)
int removeData(List *listp,char data)
{
	//1.找到第一个存放该数据的节点
	int flag = 0;
	Node *temp,*previous;
	temp = previous = listp->phead;
	while(temp->next)
	{
		previous = temp;
		temp = temp->next;
		if(temp->data == data)
		{
			flag = 1;
			break;
		}
	}
	
	//2.删除找到的节点
	if(flag)
	{
		previous->next = temp->next;	
		free(temp);
	}
	else
		return -1;		//没有找到该数据
	
	//3.size--
	listp->size--;

	return 0;
}

//根据下标找节点
Node* getNodeByIndex(List *listp,int index)
{
	Node *temp = listp->phead;
	while(index--)
		temp = temp->next;
	temp = temp->next;

	return temp;
}

//删除数据(依据下标进行删除)
int removeAt(List *listp,int index)
{
	if(index>=listp->size || index<0)
		return -1;

	//找到该节点 
	Node *node;
	if(index==0)
		node = listp->phead;
	else
		node = getNodeByIndex(listp,index-1);
	
	//删除
	Node *temp = node->next;
	node->next = node->next->next;
	free(temp);	

	//size--	
	listp->size --;
	
	return 0;
}

//获取数据(根据下标获取数据)
char getData(List *listp,int index)
{
	if(index>=listp->size || index<0)
		return -1;
	Node *node = getNodeByIndex(listp,index);

	return node->data;
}

//获取链表的长度
int getSize(List *listp)
{
	return listp->size;
}

//查找数据
int find(List *listp,char data)
{
	int index = 0;
	
	Node *temp = listp->phead;

	while(temp->next)
	{
		temp = temp->next;
		if(temp->data == data)
			return index;
		index++;
	}
	return -1;
}

//清空链表
void removeAll(List *listp)
{
	while(listp->size)
		removeAt(listp,0);
}

//销毁一个链表
void destroyList(List *listp)
{
	//1.删除每个数据节点
	removeAll(listp);
	
	//2.释放phead空间
	free(listp->phead);

	//3.释放list空间
	free(listp);
	listp = NULL;
}

