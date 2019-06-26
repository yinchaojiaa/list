#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//定义一个Node结构
typedef struct node
{
	char data;				//数据
	struct node *next;		//指向下一个节点的指针	
}Node;

typedef struct
{
	Node *phead;			//头节点的位置，头节点不用于存放数据
	int size;				//链表的有效节点个数
}List;

//创建一个新链表
List *createList(void);

//添加数据(追加)
void append(List *listp,char data);

//添加数据(在指定位置添加)
void insert(List *listp,char data,int index);

//删除数据(删除找到的第一个指定数据)
int removeData(List *listp,char data);

//根据下标找节点
Node* getNodeByIndex(List *listp,int index);

//删除数据(依据下标进行删除)
int removeAt(List *listp,int index);

//获取数据(根据下标获取数据)
char getData(List *listp,int index);

//获取链表的长度
int getSize(List *listp);

//查找数据
int find(List *listp,char data);

//清空链表
void removeAll(List *listp);

//销毁一个链表
void destroyList(List *listp);

#endif
