#include <iostream>
#include <string>
#include <cstring>
const int maxn = 500;
int arr[maxn];

using namespace std;

template <class Type>class Stack
{
private:
	Type *data;
	int maxSize, topIndex;
public:
	Stack(int _maxSize){
		topIndex = -1;
		maxSize = _maxSize;
		data = new int[maxSize];
	}
	~Stack(){
		delete []data;
	}

	bool mypush(Type element){
		if(topIndex < maxSize-1){
			topIndex++;
			data[topIndex] = element;
			return true;
		}
		else
			return false;
	}

	bool mypop(){
		if(topIndex >= 0){
            topIndex--;
			return true;
		}
		else
			return false;
	}

	Type mytop(){
		if(topIndex >= 0)
			return data[topIndex];
			/*
		else
			cout<<"error"<<endl;*/
	}

	bool isEmpty(){
		if(topIndex<0)
			return true;
		else
			return false;
	}

};

int main(){
	int n, temp;
	while(cin>>n){
		Stack<int> s1(n);
		Stack<int> s2(n);

		for(int i=0; i<n; i++)
			cin	>>arr[i];

		for(int i=n-1; i>=0; i--)
			s1.mypush(arr[i]);

		for(int i=0; i<n; i++){
			s2.mypush(i+1);
			while(s2.mytop()==s1.mytop() && !s1.isEmpty()){
				s1.mypop();
				s2.mypop();
			}
		}

		if(s1.isEmpty())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
