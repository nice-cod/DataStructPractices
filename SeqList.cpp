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

void InitList(SeqList &L){		//��ʼ��������һ���յ����Ա� 
	L.data=(int *)malloc(InitSize*sizeof(int));		//��dataԪ�ط���10��int���͵Ĵ洢�ռ䣨40�ֽڣ� 
	L.length=0;		//��ʼ����Ϊ0 
	L.MaxSize=InitSize;		//������Ϊ10��Ҳֻ������10�����ȵĿռ䣩 
}

void IncreaseSize(SeqList &L,int len){		//���� 
	int *p=L.data;
	L.data=(int *)malloc((L.MaxSize+len)*sizeof(int));
	for(int i=0;i<L.length;i++)
	L.data[i]=p[i];
	L.MaxSize=L.MaxSize+len;
	free(p);
}
int Length(SeqList L){			//������������Ա�L�ĳ��ȣ���L������Ԫ�صĸ��� 
	return L.length;
}
int  LocateElem(SeqList L,int e){		//���ò��ң���L�в��Ҿ��ڸ����ؼ���ֵ��Ԫ�� 
	int i;
	for(i=0;i<L.length,i++)			//��ͷ���� 
		if(L.data[i] == e)			 
		return i+1;					//�����±��һ 
	return 0; 						//����ʧ���˳�ѭ�� 
}
int GetElem(SeqList L,int i){		//��λ���ң���ȡ��L�е�i��λ�õ�Ԫ�ص�ֵ 
	return L.data[i-1];
}
bool ListInsert(SeqList &L, int i,int e){		//���� 
	if(i<1||i>L.Length+1)		//�жϲ���λ�õ���Ч�� 
	return false;
	if(L.length>MaxSize)		//�ж��Ƿ���� 
	return false;
	for(int j=L.length;j>=i;j--)		//�� ��i��Ԫ��֮���Ԫ�غ��� 
		L.data[j] = L.data[j-1];
	L.data[i-1] = e;		//�ڵ�i��λ�ò���e 
	L.length++;				//�����˱�Ҫ��1 
	return true;			//ʱ�临�Ӷ�O(n) 
}
bool ListDelete(SeqList &L,int i,int &e){		//ɾ����i��Ԫ�� 
	if(i<1||i>L.Length+1)		//�ж�ɾ��λ�õ���Ч�� 
	return false;
	e = L.data[i-1];		//����λ�õ�Ԫ��ֵ����e 
	for(int j=i;j<L.length;j++)
		L.data[j-1] = L.data[j];	//ǰ����ֵ 
	L.length--;		//���ȼ�1 
	return true;
}
int PrintList(SeqList L){				//�������ǰ��˳��������Ա�L������Ԫ��ֵ 
	for(int i = 0;i<L.length;i++)
		printf("%d",L.data[i]);
	return 0;
}
bool Empty(SeqList L){					//�пգ���LΪ�ձ��򷵻�true�����򷵻�false 
	if(L.length == 0)
		return true;
	return false;
}
void DestroyList(SeqList &L){			//���٣��������Ա��ͷű�L��ռ�õ��ڴ�ռ� 
	for(i=0;i<=L.length;i++)
		int *p=L.data[i];

		free(p);
}

