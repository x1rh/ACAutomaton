#include <iostream>

using namespace std;

template<class T>
class node
{
public:
	T val;
	node *next;
	node(int _val):val(_val),next(NULL){}
	node():next(NULL){}
};

template<class T>
class List
{
private:
    node<T> *head, *tail;
public:
	List(){head=tail=NULL;}
	void Build(T val);
	void DeleteNode(int pos);
	void DeleteList();
	void OutputList();
	void Reverse();
	void PreInsert(T val, int pos);
};

template<class T>
void List<T>::Build(T val){
	if(head==NULL)
		head = tail = new node<T>();
	node<T> *tmp = new node<T>(val);
	tail->next = tmp;
	tail = tmp;
}

template<class T>
void List<T>::DeleteNode(int pos){
	if(head==NULL) {cout<<"list is empty, can not delete node!!!"<<endl; return;}
	int cnt = 0;
	node<T> *tmp = head->next;
	while(tmp->next && cnt!=pos-1)
		cnt++, tmp = tmp->next;
	if(cnt==pos-1){
		node<T> *Del = tmp->next;
		tmp->next = Del->next;
		delete Del;
	}
}

template<class T>
void List<T>::DeleteList(){
	if(head==NULL) return;
	node<T> *Del, *tmp = head->next;
	while(tmp){
		Del = tmp;
		tmp = tmp->next;
		cout<< Del->val <<" is deleted!!"<<endl;
		delete Del;
	}
	cout<<"head is deleted!!"<<endl;
	delete head;
	head = NULL;
}

template<class T>
void List<T>::OutputList(){
    if(head==NULL) {cout<<"list is empty!!!"<<endl; return;}
	node<T> *cur = head->next;
	while(cur){
		cout<< cur->val <<" ";
		cur = cur->next;
	}
	cout<<endl;
}

template<class T>
void List<T>::Reverse(){
	if(head==NULL) return;
	node<T> *cur = (tail=head->next);
	node<T> *tmp = NULL;
	node<T> *Rev = NULL;
	while(cur){
		tmp = cur;
		cur = cur->next;
		tmp->next = Rev;
		Rev = tmp;
	}
	head->next = Rev;
}

template<class T>
void List<T>::PreInsert(T val, int pos){
	int cnt = 0;
	node<T> *pre = new node<T>(val);
	if(head==NULL){
		head = tail = new node<T>();
		tail->next = pre;
		tail = pre;
	}
	else if(pos==1){
		pre->next = head->next;
		head->next = pre;
	}
	else{
		node<T> *tmp = head;
		while(tmp && cnt!=pos-1)
			cnt++, tmp = tmp->next;
		if(cnt=pos-1){
			pre->next = tmp->next;
			tmp->next = pre;
		}
	}
}

int main(){
	int n;
	while(cin>>n){
		List<int> mylist;
		for(int i=0; i<n; i++)
			mylist.Build(i+1);

		mylist.OutputList();

        mylist.DeleteNode(3);
        mylist.OutputList();

		mylist.PreInsert(0, 1);
		mylist.OutputList();

		mylist.PreInsert(5, 6);
		mylist.OutputList();

		mylist.Reverse();
		mylist.OutputList();

		mylist.DeleteList();
		mylist.OutputList();
	}
	return 0;
}

//
//#include <iostream>
//
//using namespace std;
//
//template<class T>
//class node
//{
//public:
//	T val;
//	node *next;
//	node():next(NULL){}
//	node(T _val):val(_val),next(NULL){}
//};
//
//template<class T>
//class List
//{
//private:
//    int len;
//	node<T> *head, *tail;
//public:
//
//	List(){head=tail=NULL;len=0;}
//
//	void Build(T val){
//		if(head==NULL)
//			head = tail = new node<T>();
//		node<T> *cur = new node<T>(val);
//		tail->next = cur;
//		tail = cur;
//		len++;
//	}
//
//	void Insert(int pos, T val){
//		node<T> *pre = new node<T>(val);
// 		if(pos==1){
//			pre->next = head->next;
//			head->next = pre;
//		}
//		else{
//			int cnt = 0;
//			node<T> *tmp = head;
//			while(tmp && cnt!=pos-1)
//				cnt++, tmp = tmp->next;
//			if(cnt==pos-1){
//				pre->next = tmp->next;
//				tmp->next = pre;
//			}
//		}
//	}
//
//	void DeleteNode(int pos){
//		if(head==NULL) {cout<<"List is empty, can not delete node!!"<<endl; return;}
//		int cnt = 0;
//		node<T> *tmp = head;
//		while(tmp && cnt!=pos-1)
//			cnt++, tmp = tmp->next;
//		if(cnt==pos-1){
//			node<T> *Del = tmp->next;
//			tmp->next = Del->next;
//			delete Del;
//		}
//	}
//
//	void DeleteList(){
//		if(head==NULL) {cout<<"List is empty now!!"<<endl; return;}
//		node<T> *Del, *cur = head->next;
//		while(cur){
//			Del = cur;
//			cur = cur->next;
//			delete Del;
//		}
//		delete head;
//		head = NULL;
//	}
//
//	void Reserve(){
//		if(head==NULL) {cout<<"list is empty, can not reserve"<<endl; return;}
//		node<T> *cur=NULL, *res=NULL, *tmp = head->next;
//		while(tmp){
//			cur = tmp;
//			tmp = tmp->next;
//			cur->next = res;
//			res = cur;
//		}
//		head->next = res;
//	}
//
//	void OutputList(){
//		if(head==NULL) {cout<<"List is empty, can not print"<<endl; return;}
//		node<T> *cur = head->next;
//		while(cur){
//			cout<< cur->val <<" ";
//			cur = cur->next;
//		}
//		cout<<endl;
//	}
//};
//
//int main(){
//	int n;
//	while(cin>>n){
//		List<int> mylist;
//		for(int i=0; i<n; i++)
//			mylist.Build(i+1);
//
//		mylist.OutputList();
//
////		mylist.DeleteNode(1);
////		mylist.OutputList();
////		mylist.DeleteNode(9);
////		mylist.OutputList();
//
////		mylist.Insert(1,1);
////		mylist.OutputList();
//		mylist.Insert(11, 11);
//		mylist.OutputList();
//
//		mylist.Reserve();
//		mylist.OutputList();
//
//		mylist.DeleteList();
//		mylist.OutputList();
//	}
//	return 0;
//}
