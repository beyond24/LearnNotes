#include <stdio.h>
#include <stdlib.h>
#define InitSize 10
typedef struct{
	int *data;	//定义指针变量data，它始终指向动态数组的区域
	int MaxSize; 
	int length; //当前长度
}SeqList;

void InitList(SeqList &L){
	L.data = (int *)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
}
//增加动态数组的长度
void IncreaseSize(SeqList &L, int len){
	int *p = L.data;
	L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
	for(int i = 0; i < L.length; i++){
		L.data[i] = p[i];	//依次将数据复制到新的区域
	}
	L.MaxSize = L.MaxSize + len; //重置最大长度
	free(p);	//释放原来的内存空间
}

int main(){
	SeqList L;
	InitList(L);
	IncreaseSize(L, 5);
	printf("%d\n", L.MaxSize);
	return 0;
}