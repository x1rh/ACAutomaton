#include <iostream>
#include <cstring>

using namespace std;

typedef int ElemType;
struct SqList
{
	ElemType *elem;
	int length;
};

void ClearList(SqList &L){
	if(L.elem==NULL){
		return;
	}
	else{
		delete []L.elem;
		L.elem = NULL;
	}
}

bool ListEmpty(SqList &L){
	if(L.elem==NULL)
		return true;
	else
		return false;
}

int ListLength(SqList &L){
	if(L.elem==NULL)
		return -1;
	else
		return L.length;
}

void GetElem(SqList &L, ElemType i, ElemType &e){
	e = L.elem[i-1]; //第i个元素在i-1的位置
	return;
}

void PriorElem(SqList &L, ElemType &cur_e, ElemType &pre_e){
	for(int i=0; i<L.length; i++){
		if(L.elem[i]==cur_e && i!=0){
			pre_e = L.elem[i-1];
			return;
		}
	}
}

void NextElem(SqList &L, ElemType &cur_e, ElemType &next_e){
	for(int i=0; i<L.length; i++){
		if(L.elem[i]==cur_e && i!=L.length-1){
			next_e = L.elem[i+1];
			return;
		}
	}
}

void ListTraverse(SqList &L){
	for(int i=0; i<L.length; i++)
		cout<<L.elem[i]<<" ";
	cout<<endl;
	return;
}

int main(){
    SqList lrh;
    cout << ListEmpty(lrh) <<endl;
	return 0;
}
