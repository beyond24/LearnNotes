#include <stdio.h>
typedef struct LNode{
	int data;	//data为数据域
	struct LNode *next;		//定义一个next的指针变量用来指向下一个节点。结构体类型的变量，指针也用结构体声明
}LNode, *LinkList;	//这里语义为把结构体重命名为LNode,指向结构体的指针重命名为LinkList

//一般用LinkList定义单链表，用LNode *定义指向单链表中某一节点的指针变量

bool InitList(LinkList &L){
	L = NULL;	//头指针指向null，空表
	return true;
}
//判断单链表是否为空
bool Empty(LinkList L){
	return (L == NULL);
}

int main(){
	LinkList L;		//声明一个指针变量L指向单链表，注意此时并非创建一个节点
	InitList(L);	//初始化一个空表，完成后只有一个头指针L且指向NULL
	if (Empty(L) == true)
		printf("Link is null");
	return 0;
}