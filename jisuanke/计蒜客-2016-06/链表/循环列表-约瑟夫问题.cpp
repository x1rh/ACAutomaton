#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
public:
	Node(int _data){
		data = _data;
		next = NULL;
	}
};

class LinkList
{
private:
	Node *tail;
public:
	LinkList(){
		tail = NULL;
	}

	/*注意index的含义，这里将链表下标看成从1开始*/
	/*默认输入的n合法*/
	void insertNode(Node *node, int index){

	    /*当前链表为空，则将插进来的节点作为头节点，并且将它的指针指向自己，形成循环*/
		if(tail==NULL){
			tail = node;
			tail->next = tail;
			//cout<<"if(tail==NULL)"<<endl;
			return;
		}


		/*建表成功后的额外插入到链表首位置的判断语句*/
		/*tail->next表示第一个节点，那么node->next = tail->next则将node插到表头之前，形成新的表头*/
		/*tail为最后一个节点，表头更新了，所以tail->next=node*/
		if(index==1){
			node->next = tail->next;
			tail->next = node;
			return;
		}


		int tot = 1;
		Node *currentNode = tail->next;
		/*curentNode代表头结点*/

		/*注意判断条件*/
		while(currentNode != tail && tot < index-1){
			currentNode = currentNode->next;
			tot++;
		}


		/*理解currentNode代表的值*/
		if(tot == index-1){
			node->next = currentNode->next;
			currentNode->next = node;
			//cout<<"if(tot==index-1):"<<endl;
		}


		/*将node插入到当前链表末尾时，将进行这个判断*/
		/*判断时，tail还没更新，代表倒数第二个节点，而node代表最后一个节点*/
		if(node == tail->next){
			tail = node;
			//cout<<"if(node==tail->next)"<<endl;
		}
	}


	void deleteNode(int index){
		int tot = 1;
		Node *currentNode, *NodeOfDelete;

		if(tail==NULL){
            //cout<<"链表已空！！！"<<endl;
            return;
		}

        /*链表长度等于1时*/
		if(index==1 && (tail->next)==tail) {
            NodeOfDelete = tail;
            delete NodeOfDelete;
            tail = NULL;
            return;
		}

		/*链表长度大于等于2时*/
		if(index==1 && (tail->next->next)!=NULL ) {
			NodeOfDelete = tail->next;
			tail->next = NodeOfDelete->next;
			delete NodeOfDelete;
			return;
		}

		currentNode = tail->next;
		while(currentNode != tail && tot<index-1){
			currentNode = currentNode->next;
			tot++;
		}

        /*得在删除最后一个节点前更新tail*/
		if(currentNode->next == tail)
            tail = currentNode;

		/*包含尾节点删除*/
		if(tot==index-1){
			NodeOfDelete = currentNode->next;
			currentNode->next = NodeOfDelete->next;
			delete NodeOfDelete;
		}


	}

	void outputList(){
		int tot = 1;
		if(tail==NULL){
            cout<<"链表已空！！！"<<endl;
            return;
		}

		Node *currentNode = tail->next;
		while(currentNode != tail){
			cout<<currentNode->data<<" ";
			currentNode = currentNode->next;
		}
		/*尾节点由于循环条件影响需要额输出*/
		cout<<currentNode->data<<endl;
		cout<<"-------------分割线-------------------\n\n\n";
	}
};

int main()
{
	int n;
	while(cin>>n){
        LinkList linklist;
        for(int i=1; i<=n; i++){
            Node *node = new Node(i);
            linklist.insertNode(node, i);
        }

        linklist.outputList();


        /*下面的试验，n需要一定的大小*/
        cout<<"删除第一个节点:"<<endl;
        linklist.deleteNode(1);
        linklist.outputList();

        cout<<"删除第3个节点:"<<endl;
        linklist.deleteNode(3);
        linklist.outputList();

        cout<<"删除最后一个节点:"<<endl;
        linklist.deleteNode(n-2);
        linklist.outputList();

        cout<<"删除列表并且额外删除两次看看如何:"<<endl;
        for(int i=0; i<n;i++){
        	linklist.deleteNode(1);
        	linklist.outputList();
        }

        system("pause");
	}

	return 0;
}
