#include <stdio.h>
#include <stdlib.h>
#include "linksInsert.c"
typedef struct LNode{
	int data;	//data为数据域
	struct LNode *next;		//定义一个next的指针变量用来指向下一个节点。结构体类型的变量，指针也用结构体声明
}LNode, *LinkList;	//这里语义为把结构体重命名为LNode,指向结构体的指针重命名为LinkList

//一般用LinkList定义单链表，用LNode *定义指向单链表中某一节点的指针变量

bool InitList(LinkList &L){
	L = (LNode *)malloc(sizeof(LNode)); //分配一个头节点，并使头指针指向头节点
	if (L==NULL)	//内存空间不足，分配失败
		return false;
	L->next = NULL;		//L指向一个头节点结构体，所以使用“->”运算符代表L指向的头节点的next指针为NULL
	return true;
}
//判断单链表是否为空
bool Empty(LinkList L){
	return (L->next == NULL);
}

// //按位序插入
// bool LinkInsert(LinkList &L, int i, int e){
// 	if (i < 1)
// 		return false;
// 	LNode *p;	
// 	int j = 0; //j为p指向第几个结点，从头节点开始
// 	p = L;	//L指向头结点，头结点是第0个元素（不存数据）
// 	while (p != NULL && j < i-1){
// 		p = p->next;
// 		j++;
// 	}
// 	if (p==NULL)	//输入不合法
// 		return false;
// 	LNode *s = (LNode *)malloc(sizeof(LNode));	//定义指针变量s，指向一块新的结构体区域
	
// 	s->data = e;	//填入新数据
// 	s->next = p->next;	//新数据的指针指向需要定位元素p的后一个元素
// 	p->next = s;	//p的指针指向新元素

// 	return true;	//插入成功
// }

int main(){
	LinkList L;
	InitList(L);
	if (Empty(L) == true)
		printf("Link is null");
	LinkInsert(L, 1, 21);
	LinkInsert(L, 2, 30);
	
	LNode *p;
	p = L;	//L指向头结点，头结点是第0个元素（不存数据）
	while (p != NULL){
		p = p->next;
		printf("%d\n", p->data);
	}
	return 0;
}