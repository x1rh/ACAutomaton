#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
const int maxn = 1000;
const int Null = -1;

struct Tree
{
	char Element;
	int left;
	int right;
};

Tree T1[maxn], T2[maxn];

int input(Tree* const &T, int n){
	char l, r;
	bool *check = new bool[n];
	memset(check, 0, n);
	for(int i=0; i<n; i++){
		scanf(" %c %c %c", &T[i].Element, &l, &r);
		if(l!='-'){

			int reall = l-'0';
			check[reall] = 1;
			T[i].left = reall;
		}
		else{
			T[i].left = Null;
		}
		if(r!='-'){
			int realr = r-'0';
			check[realr] = 1;
			T[i].right = realr;
		}
		else{
			T[i].right = Null;
		}
	}
	int root = -2;
	for(int i=0; i<n; i++){
		if(!check[i]){
			root = i;
			break;
		}
	}
	delete []check;
	return root;
}

bool CheckTheTree(int R1, int R2){
    if(R1==-2 && R2==-2)
        return true;
	if(R1==Null && R2==Null)
		return true;
	if((R1==Null && R2!=Null) || (R1==Null && R2!=Null))
		return false;
	if(T1[R1].Element != T2[R2].Element)
		return false;
	if(T1[R1].left==Null && T2[R2].left==Null)
		return CheckTheTree(T1[R1].right, T2[R2].right);
	if((T1[R1].left!=Null && T2[R2].left!=Null)&&
		(T1[T1[R1].left].Element == T2[T2[R2].left].Element))
		return (CheckTheTree(T1[R1].left, T2[R2].left) &&
				CheckTheTree(T1[R1].right, T2[R2].right));
	else
		return (CheckTheTree(T1[R1].left, T2[R2].right) &&
				CheckTheTree(T1[R1].right, T2[R2].left));
}

int main(){
	int n, m, FirstRoot, SecondRoot;

	scanf("%d", &n);
	FirstRoot = input(T1, n);

	scanf("%d", &m);
	SecondRoot = input(T2, m);

	if(CheckTheTree(FirstRoot, SecondRoot))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
