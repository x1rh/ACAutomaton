#include <iostream>
#include <cstring>

using namespace std;

class Node{
public:
	int data;
	Node *next;
	Node(int first_node){
		data = first_node;
		next = NULL;
	}
};

class LinkList{
private:
	Node *head;
public:
	LinkList(){
		head = NULL;
	}

	/*searchNode方法是寻找index前一个节点*/
	Node *searchNode(int index){
		int tot = 1;
		Node *currentNode = head;
		/*注意寻找节点时，什么时候用currentNode->next!=NULL或者currentNode != NULL*/
		/*注意，当tot等于index-1时循环结束，此时，currentNode为目标位置的前一个节点*/
		while(currentNode->next != NULL && tot<index-1){
			currentNode = currentNode->next;
			tot++;
		}
		/*这里防止index为超出链表长度的非法数据*/
		if(tot==index-1)
			return currentNode;
		else
            return NULL;


	}

	/*这个插入函数既可以在构造链表的时候使用，也可以在构造之后单独拿来插入节点*/
	/*所以两个if语句没有多余。链表第一个节点不是空节点，index的含义是插入到链表中第index个位置*/
	/*注意函数调用时index传进来时的值*/
	void insertNode(Node *node, int index){
		Node *currentNode;
		if(head==NULL){
			head = node;
			return;
		}
		/*这里我直接把第一个节点认为是1号，而非0号*/
		if(index==1){
			node->next = head;
			head = node;
			return;
		}

		currentNode = searchNode(index);

		/*新节点插入后，所插入位置的原来节点相当于后移一位*/
		/*currentNode->next相当于插入位置的原来节点*/
		if(currentNode != NULL){
			node->next = currentNode->next;
			currentNode->next = node;
		}
		return;
	}

	/*currentNode为要删除节点的前一个节点*/
	void deleteNode(int index){
	    Node *NodeOfDelete, *currentNode=head;
	    if(head==NULL)
            return;
        if(index==1){
            head = head->next;
            delete currentNode;
            return;
        }

		currentNode = searchNode(index);
		if(currentNode != NULL){
            NodeOfDelete = currentNode->next;
            currentNode->next = NodeOfDelete->next;
            delete NodeOfDelete;
		}
		return;
	}

	void outputList(){
	    int tot = 0;
		Node *currentNode = head;
		/*这里包含了为空表的情况*/
		while(currentNode != NULL){
			cout<<currentNode->data<<" ";
			currentNode = currentNode->next;
		}
		cout<<endl;
	}

	/*注意此处会改变head的值*/
	void reverseList(){
        if(head==NULL)
			return;
		Node *currentNode = head->next, *nextNode;

		/*注意把head的指针域置为NULL*/
		head->next = NULL;
		while(currentNode != NULL){
			nextNode = currentNode->next;
			currentNode->next = head;
			head = currentNode;
			currentNode = nextNode;
		}
	}
};

int main()
{
	int n=6;

    LinkList linklist;
    for(int i=1; i<=n; i++){
        Node *node = new Node(i);
        linklist.insertNode(node, i);
    }
    cout<<"---------------建表成功输出-----------------------"<<endl;
    linklist.outputList();
    cout<<"------------------分割线--------------------------"<<"\n\n";



    cout<<"----------------------------------元素删除--------------------------------------"<<endl;

    cout<<"删除第1个元素后为：";
    linklist.deleteNode(1);
    linklist.outputList();
    cout<<endl;

    /*注意此时第5个元素已经不是5了，而是6 */
    cout<<"删除此时表中的第5个元素后得到：";
    linklist.deleteNode(5);
    linklist.outputList();
    cout<<"-----------------------------------分割线----------------------------------------"<<"\n\n";


    cout<<"--------------------------------翻转列表输出-------------------------------------"<<endl;
    /*注意翻转后head将会改变，可以适当改变函数参数来保证head不变*/
    linklist.reverseList();
    linklist.outputList();
    cout<<"-----------------------------------分割线----------------------------------------"<<"\n\n";




    cout<<"--------------------------检测边界值，继续执行元素删除---------------------------"<<endl;

    cout<<"删除第1个元素后：";
    linklist.deleteNode(1);
    linklist.outputList();

    cout<<"删除第1个元素后：";
    linklist.deleteNode(1);
    linklist.outputList();

    cout<<"删除第1个元素后：";
    linklist.deleteNode(1);
    linklist.outputList();

    cout<<"删除第1个元素后：";
    linklist.deleteNode(1);
    linklist.outputList();

    /*以下为表空之后的操作*/
    cout<<"删除第1个元素后：";
    linklist.deleteNode(1);
    linklist.outputList();

    cout<<"执行一次翻转:"<<endl;
    linklist.reverseList();
    linklist.outputList();

    cout<<"删除第1个元素后：";
    linklist.deleteNode(1);
    linklist.outputList();


    cout<<"-----------------------------------分割线-----------------------------------------"<<endl;

	return 0;
}
