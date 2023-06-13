#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int _data) {
        data = _data;
        next = NULL;
    }
};
class LinkList {
private:
    Node* head;
public:
    LinkList() {
        head = NULL;
    }

    /*把构造列表看出多个插入，第一和第二个if不矛盾，这种构造出来的列表第一个节点不是空节点*/
    /*插入到第index个位置*/
    void insert(Node *node, int index) {
        if (head == NULL) {
            head = node;
            //cout<<"node是："<<node->data<<endl;
            return;
        }
        if (index == 0) {
            node->next = head;
            head = node;
            return;
        }
        Node *current_node = head;
        int count = 0;

        /*寻找插入的位置。*/
        /*这里count小于index-1是为了防止出现不合理的index，即index大于链表长度的情况*/
        while (current_node->next != NULL && count < index - 1) {
            current_node = current_node->next;
            count++;
        }
        /*注意current_node现在是目标插入位置的前一个节点*/
        /*代码的意思是，当前节点要插到current_node的后面*/
        if (count == index - 1) {
            node->next = current_node->next;
            current_node->next = node;
        }
    }

    /*遍历输出*/
    void output() {
        if (head == NULL) {
            return;
        }
        Node *current_node = head;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }

    void delete_node(int index) {
        if (head == NULL) {
            return;
        }
        Node *current_node = head;
        int count = 0;
        if (index == 0) {
            head = head->next;
            delete current_node;
            return;
        }
        while (current_node->next != NULL && count < index -1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1 && current_node->next != NULL) {
            Node *delete_node = current_node->next;
            current_node->next = delete_node->next;
            delete delete_node;
        }
    }

    void reverse(){
        if(head==NULL){
            return;
        }
        Node *next_node, *current_node;
        current_node = head->next;
        head->next = NULL;
        while(current_node!=NULL){
            next_node = current_node->next;
            current_node->next = head;
            head = current_node;
            current_node = next_node;
        }
    }

};
int main() {
    LinkList linklist;
    for (int i = 1; i <= 10; i++) {
        Node *node = new Node(i);
        linklist.insert(node, i - 1);
    }
    linklist.output();
    linklist.delete_node(3);
    linklist.output();
    linklist.reverse();
    linklist.output();
    return 0;
}
