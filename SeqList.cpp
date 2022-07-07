	#include<stdlib.h>
#define InitSize 10
typedef struct{
	int *data;
	int MaxSize;
	int length;
}SeqList;
int main(){
	SeqList l;
	InitList(SeqList &L);
	IncreaseSize(L,5);
	return 0;
}

void InitList(SeqList &L){		//初始化，构造一个空的线性表 
	L.data=(int *)malloc(InitSize*sizeof(int));		//给data元素分配10个int类型的存储空间（40字节） 
	L.length=0;		//初始长度为0 
	L.MaxSize=InitSize;		//表容量为10（也只申请了10个长度的空间） 
}

void IncreaseSize(SeqList &L,int len){		//扩容 
	int *p=L.data;
	L.data=(int *)malloc((L.MaxSize+len)*sizeof(int));
	for(int i=0;i<L.length;i++)
	L.data[i]=p[i];
	L.MaxSize=L.MaxSize+len;
	free(p);
}
int Length(SeqList L){			//求表长，返回线性表L的长度，即L中数据元素的个数 
	return L.length;
}
int  LocateElem(SeqList L,int e){		//安置查找，在L中查找居于给定关键字值的元素 
	int i;
	for(i=0;i<L.length,i++)			//从头遍历 
		if(L.data[i] == e)			 
		return i+1;					//返回下表加一 
	return 0; 						//查找失败退出循环 
}
int GetElem(SeqList L,int i){		//按位查找，获取表L中地i个位置的元素的值 
	return L.data[i-1];
}
bool ListInsert(SeqList &L, int i,int e){		//插入 
	if(i<1||i>L.Length+1)		//判断插入位置的有效性 
	return false;
	if(L.length>MaxSize)		//判断是否溢出 
	return false;
	for(int j=L.length;j>=i;j--)		//将 第i个元素之后的元素后移 
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;		//在第i个位置插入e 
	L.length++;				//别忘了表长要加1 
	return true;			//时间复杂度O(n) 
}
bool ListDelete(SeqList &L,int i,int &e){		//删除第i个元素 
	if(i<1||i>L.Length+1)		//判断删除位置的有效性 
	return false;
	e = L.data[i-1];		//将该位置的元素值赋给e 
	for(int j=i;j<L.length;j++)
		L.data[j-1] = L.data[j];	//前赋后值 
	L.length--;		//长度减1 
	return true;
}
int PrintList(SeqList L){				//输出，按前后顺序输出线性表L的所有元素值 
	for(int i = 0;i<L.length;i++)
		printf("%d",L.data[i]);
	return 0;
}
bool Empty(SeqList L){					//判空，若L为空表，则返回true，否则返回false 
	if(L.length == 0)
		return true;
	return false;
}
void DestroyList(SeqList &L){			//销毁，销毁线性表，释放表L所占用的内存空间 
	for(i=0;i<=L.length;i++)
		int *p=L.data[i];

		free(p);
}

