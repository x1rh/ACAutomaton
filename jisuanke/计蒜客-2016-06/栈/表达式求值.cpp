#include <iostream>
#include <string>
#include <cassert>

using namespace std;

template <class Type> class Stack{
private:
	int topIndex, maxSize;
	Type *data;
public:
	Stack(int _maxSize){
		topIndex = -1;
		maxSize = _maxSize;
		data = new Type[maxSize];
	}
	~Stack(){
		delete []data;
	}

	bool mypush(const Type element){
		if(topIndex < maxSize-1){
			topIndex++;
			data[topIndex] = element;
			return true;
		}
		else
			return false;
	}

	bool mypop(){
		if(topIndex>=0){
            topIndex--;
            return true;
		}
		else
			return false;
	}

	Type mytop(){
		assert(topIndex>=0);
		return data[topIndex];
	}

	bool isEmpty(){
		if(topIndex < 0)
			return true;
		else
			return false;
	}

};
    bool precede(char a, char b){
		if(a=='*')
			return true;
		else
			return false;
	}

	int operate(char theta, int a, int b){
		if(theta == '*')
			return a*b;
		if(theta == '+')
			return a+b;
	}


	void calculate(Stack<int> &numbers, Stack<char> &operators){
		int a = numbers.mytop();
		numbers.mypop();
		int b = numbers.mytop();
		numbers.mypop();
		numbers.mypush(operate(operators.mytop(), a, b) );
		operators.mypop();
	}

int main(){
	int n;
	string buffer;
	while(cin>>n){
		int i=0;
		cin>>buffer;
        Stack<int> numbers(n);
        Stack<char> operators(n);
		while(i<n){
			if(isdigit(buffer[i])){
				numbers.mypush(buffer[i]-'0');
				i++;
			}
			else{
				if(operators.isEmpty() || precede(buffer[i], operators.mytop()) ){
					operators.mypush(buffer[i]);
					i++;
				}
				else{
					calculate(numbers, operators);
				}

			}
		}
		while(!operators.isEmpty()){
			calculate(numbers, operators);
		}
		cout<<numbers.mytop()<<endl;
	}
	return 0;
}
