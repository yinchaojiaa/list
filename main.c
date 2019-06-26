#include <stdio.h>
#include "linkedlist.h"

void print_list(List *listp);

int main(int argc,char *argv[])
{
	//1.创建一个新链表
	List *listp = createList();

	//2.追加数据
	char i;
	for(i='a';i<'k';i++)
		append(listp,i);			

	//3.打印链表
	print_list(listp);

	//4.插入一个数据
	insert(listp,'z',3);
	insert(listp,'x',7);

	//5.打印
	printf("-----------------------------------\n");
	print_list(listp);

	//6.删除
	removeData(listp,'e');
	removeData(listp,'g');
	removeAt(listp,2);

	//7.打印
	printf("-----------------------------------\n");
	print_list(listp);

	//8.清空
	removeAll(listp);
	
	//9.打印
	printf("-----------------------------------\n");
	print_list(listp);

	//10.销毁
	destroyList(listp);

	return 0;
}

void print_list(List *listp)
{
	int i;
	int len = getSize(listp);
	for(i=0;i<len;i++)
		printf("%c\t",getData(listp,i));
	putchar('\n');
}
