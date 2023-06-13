#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;
const int maxn = 100;
const int Null = -1;

struct node
{
	int root, lchild, rchild;
};

node tree[maxn];

int input(int n){
	char l, r;
	bool *check = new bool[n];
	memset(check, 0, n);
	for(int i=0; i<n; i++){
		scanf(" %c %c", &l, &r);
		tree[i].root = i;
		if(l!='-'){
			tree[i].lchild = l-'0';
			check[tree[i].lchild] = true;
		}
		else{
			tree[i].lchild = Null;
		}
		if(r!='-'){
			tree[i].rchild = r-'0';
			check[tree[i].rchild] = true;
		}
		else{
			tree[i].rchild = Null;
		}
	}
	int root = -2;
	for(int i=0; i<n; i++){
		if(!check[i]){
			root = i;
			break;
		}
	}
	return root;
}

void print(int root){
	queue<node> q;
	q.push(tree[root]);
	bool flag = true;
	while(!q.empty()){
		node tmp = q.front(); q.pop();
		if(tmp.lchild==Null && tmp.rchild==Null){
			if(flag){
				printf("%d", tmp.root);
				flag = !flag;
			}
			else{
				printf(" %d", tmp.root);
			}
		}
		if(tmp.lchild != Null)
			q.push(tree[tmp.lchild]);
		if(tmp.rchild != Null)
			q.push(tree[tmp.rchild]);
	}
	printf("\n");
}

int main(){
	int n, root;
	scanf("%d", &n);
	root = input(n);
	print(root);
	return 0;
}
