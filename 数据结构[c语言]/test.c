#include <stdio.h>
#include <stdlib.h>
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

int main(){
	LinkList L;
	InitList(L);
	if (Empty(L) == true)
		printf("Link is null");
	return 0;
}