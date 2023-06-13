#include <cstdio>
#include <iostream>

using namespace std;


struct node
{
	int data;
	bool flag;
	node *lchild, *rchild;
	node(int in){
		data = in;
		flag = false;
		lchild = rchild = NULL;
	}
};

typedef node* tree;

void Insert(tree &root, int in){
	if(root==NULL)
		root = new node(in);
	else if(in < root->data)
		Insert(root->lchild, in);
	else if(in > root->data)
		Insert(root->rchild, in);
}

void Build(int N, tree &root){
	int in;
	for(int i=0; i<N; i++){
		scanf("%d", &in);
		Insert(root, in);
	}
}

bool visit(tree &root, int in){
    if(root->flag){
        if(in < root->data)
            visit(root->lchild, in);
        else if(in > root->data)
            visit(root->rchild, in);
        else
            return false;
    }
    else{
        if(root->data == in){
            root->flag = true;
            return true;
        }
        else
            return false;
    }
}

bool check(int N, tree &root){
	int *arr = new int[N];
	for(int i=0; i<N; i++)
		scanf("%d", &arr[i]);
	for(int i=0; i<N; i++){
		if(!visit(root, arr[i])){
			delete []arr;
			return false;
		}
	}
	delete []arr;
	return true;
}

void setflag(tree &root){
	if(root!=NULL){
		root->flag = false;
		setflag(root->lchild);
		setflag(root->rchild);
	}
}

int main(){
	int N, L;
	while(~scanf("%d", &N) && N){
		scanf("%d", &L);
		node *root = NULL;
		Build(N, root);
		for(int i=0; i<L; i++){
			if(i) setflag(root);
			if(check(N, root))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}
