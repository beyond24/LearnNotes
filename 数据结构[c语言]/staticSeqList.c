#include <stdio.h>
#define MaxSize 10
typedef struct{
	int data[MaxSize]; //用静态的“数组”存放数据元素，Elemtype代表抽象的数据类型
	int length;	//顺序表的当前长度
}SqList;	//顺序表的类型定义

void InitList(SqList &L){
	for (int i = 0; i < MaxSize; i++)
		 L.data[i] = 0;	//将所有元素初始值设为0，防止存在“垃圾值”
	L.length = 0; //初始长度为0
}

bool ListInsert(SqList &L, int i, int e){
	if (i < 1  || i > L.length + 1 || L.length >= MaxSize)	// 处理输入不合法的数据
		return false;
	for (int j = L.length - 1; j >= i - 1; j--)		//从线性表的末尾处开始处理依次将前一个数据向后移一位，直到第i个移动完成
		L.data[j+1] = L.data[j];
	L.data[i-1] = e;	//将新元素插入
	L.length++;
	return true;
} 

bool ListDelete(SqList &L, int i){
	if (i < 1  || i > L.length)
		return false;
	for (int j = i; j <= L.length; j++)
		L.data[j-1] = L.data[j];
	L.length--;
	return true;
}


int main(){
	SqList L;
	InitList(L);
	ListInsert(L, 1, 2);
	ListInsert(L, 2, 3);
	ListInsert(L, 1, 4);
	ListInsert(L, 1, 1);
	ListDelete(L, 1);
	ListDelete(L, 3);

	for (int i = 0; i < L.length; i++)
	{
		printf("%d\n", L.data[i]);
	}
	return 0;
}