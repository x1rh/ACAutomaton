#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

struct node{
	int data;
	node *next;
};

void creatList(node *head, int n){
	node *tail = head;
	for(int i=1; i<=n; i++){
		node *p = new node;
		p->next = NULL;
		p->data = i;
		tail->next = p;
		tail = p;
	}
}

void outputList(node *head){
	node *currentNode = head->next;
	while(currentNode!=NULL){
		cout<<currentNode->data<<" ";
		currentNode = currentNode->next;
	}
	cout<<endl;
}


void deleteNode(node *head, int index){
	int tot=1;
	node *currentNode = head->next, *NodeOfDelete;
	if(index==1){
        NodeOfDelete = head->next;
        head->next = NodeOfDelete->next;
        delete NodeOfDelete;
        return;
	}
	while(currentNode!=NULL && tot<index-1){
		currentNode = currentNode->next;
		tot++;
	}
	NodeOfDelete = currentNode->next;
	currentNode->next = NodeOfDelete->next;
	delete NodeOfDelete;
}

int searchNode(node *head, int index){
	int tot = 0;
	node *currentNode = head->next;
	while(currentNode != NULL && tot<index-1){
		currentNode = currentNode->next;
		tot++;
	}
	return currentNode->data;
}

void solu(node *head){
	int tot = 0;
	node *currentNode = head->next;
	while(currentNode!=NULL){
		tot++;
		currentNode = currentNode->next;
	}
	cout<< searchNode(head, ((tot+1)/2)) <<endl;
}



int main()
{
	int n, m, temp;
	while(cin>>n>>m){
		node *head = new node;
		creatList(head, n);

		for(int i=0; i<m; i++){
			cin>>temp;
			deleteNode(head, temp);
			//outputList(head);
		}
		solu(head);
	}
	return 0;
}
