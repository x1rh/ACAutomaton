#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Node
{
	int data, height, count;
	Node* lchild, *rchild;
	Node(int x){
		data = x;
		lchild = NULL;
		rchild = NULL;
		height = 1;
		count  = 1;
	}
};

typedef Node* Tree;

class AVL
{
public:
	Tree rt;

	AVL(){rt=NULL;}
	~AVL() {Destroy(rt);}

	Tree Insert(Tree root, int x){
		if(root==NULL)
			return (root = new Node(x));
		else if(x == root->data){
			(root->count) += 1;
			return root;
		}
		else if(x < root->data)
			root->lchild = Insert(root->lchild, x);
		else if(x > root->data)
			root->rchild = Insert(root->rchild, x);

		root->height = max(height(root->lchild), height(root->rchild)) + 1;

		int balance = getBalance(root);

		if(balance > 1){
			if(x < root->lchild->data)
				return rightRoate(root);
			else if(x > root->lchild->data){
				root->lchild = leftRoate(root->lchild);
				return rightRoate(root);
			}
		}
		else if(balance < -1){
			if(x > root->rchild->data)
				return leftRoate(root);
			else if(x < root->rchild->data){
				root->rchild = rightRoate(root->rchild);
				return leftRoate(root);
			}
		}

		return root;
	}

	void Destroy(Tree root){
		if(root!=NULL){
			Destroy(root->lchild);
			Destroy(root->rchild);
			delete root;
		}
	}

	int height(Tree root){
		if(root == NULL)
			return 0;
		return root->height;
	}

	int getBalance(Tree root){
		if(root == NULL)
			return 0;
		return (height(root->lchild) - height(root->rchild));
	}

	Tree rightRoate(Tree y)
	{
	    Tree x = y->lchild;
	    Tree T2 = x->rchild;
	    x->rchild = y;
	    y->lchild = T2;
	    y->height = max(height(y->lchild), height(y->rchild))+1;
	    x->height = max(height(x->lchild), height(x->rchild))+1;
		return x;
	}

	Tree leftRoate(Tree x)
	{
	    Tree y = x->rchild;
	    Tree T2 = y->lchild;
	    y->lchild = x;
	    x->rchild = T2;
	    x->height = max(height(x->lchild), height(x->rchild))+1;
	    y->height = max(height(y->lchild), height(y->rchild))+1;
		return y;
	}
};

int main(){
    int n, input;
    while(cin>>n){
        AVL avl;
        for(int i=0; i<n; i++){
            cin>>input;
            avl.rt = avl.Insert(avl.rt, input);
        }
        cout<<avl.rt->data<<endl;
    }
	return 0;
}
