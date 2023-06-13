#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

template<class Type> class Stack
{
private:
	Type *data;
	int topIndex, maxSize;
public:
	Stack(int _maxSize){
	    topIndex = -1;
		maxSize = _maxSize;
		data = new Type[maxSize];

	}
	~Stack(){
		delete []data;
	}

	bool myPush(Type element){
		if (topIndex < maxSize-1){
			topIndex++;
			data[topIndex] = element;
			return true;
		}
		else{
			return false;
		}
	}

	bool myPop(){
		if(topIndex >= 0){
			cout<<data[topIndex]<<endl;
			topIndex--;
			return true;
		}
		else{
			return false;
		}
	}

	bool myTop(){
		if(topIndex >= 0){
			cout<<data[topIndex]<<endl;
			return true;
		}
		else{
			return false;
		}
	}

};

int main(){
	int n;
	cin>>n;
	Stack<int> mystack(n);
	for(int i=0; i<n; i++){
        if(mystack.myPush(i+1))
            cout<<"------------------\n入栈成功"<<endl;
        else
            cout<<"------------------\n入栈失败"<<endl;
	}

    cout<<"\n当前栈顶为：";
    mystack.myTop();
    cout<<"---------------\n\n\n";

    /*额外入栈*/
    if(mystack.myPush(2333))
        cout<<"额外入栈成功"<<endl;
    else
        cout<<"额外入栈失败\n\n"<<endl;


	for(int i=0; i<n; i++){
            cout<<"-----出栈元素为：--------"<<endl;
        if(mystack.myPop())
            cout<<"-------出栈成功----------\n\n\n";
        else
            cout<<"-------出栈失败----------\n\n\n";
	}

	/*额外出栈*/
	if(mystack.myPop())
        cout<<"额外出栈成功\n\n\n";
    else
        cout<<"额外出栈失败\n\n\n";


	system("pause");
	return 0;
}
