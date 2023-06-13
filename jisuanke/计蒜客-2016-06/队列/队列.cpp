#include <iostream>
#include <stdlib.h>
#include <cassert>

using namespace std;

class Queue
{
private:
	int length;
	int head;
	int tail;
	int *data;
public:
	Queue(int _length){
		length = _length;
		data = new int[length];
		head = 0;
		/*tail表示队列最后一名，所以在构造函数中置*/
		tail = -1;
	}
	~Queue(){
		delete []data;
	}

	/*注意为什么要tail+1小于length呢？因为tail初始值为-1而length最小为0*/
	/*当length等于0时，此时不能建立这个队列*/
	/*相当于队列元素下标从0开始，且由于if条件的限制，只能到length-1，但是实际长度仍然为length*/
	void myPush(int element){
		if(tail+1 < length){
			tail++;
			data[tail] = element;
		}
		else
            cout<<"队列已满！！！"<<endl;
	}

	/*assert用法详情百度*/
	/*用head来表示队首，pop出一个后便加一*/
	/*没必要每次pop都释放对应的内存，最后直接用析构函数回收整块内存*/
	void myPop(){
		if(head<=tail)
            head++;
        else
            cout<<"队列为空！！！"<<endl;
	}

	/*由于pop操作可能导致队列为空，所以必须判断head是否小于等于tail*/
	int myFront(){
		/*若队列为空，那么head大于tail*/
		assert(head<=tail);
		return data[head];
	}

	void myOutput(){
	    if(head>tail)
            cout<<"队列已空，无输出！！！"<<endl;
		for(int i=head; i<=tail; i++){
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
};

int main()
{
	Queue lrhQueue(10);
	/*这里的i的最大值大于队列长度10*/
	for(int i=0; i<12; i++)
		lrhQueue.myPush(i+1);
	cout<<"建队成功后输出为："<<endl;
	lrhQueue.myOutput();
	cout<<"队首元素是："<<lrhQueue.myFront()<<endl;
	cout<<"-------------------\n\n\n\n";

	for(int i=0; i<9; i++){
        cout<<"第"<<i+1<<"次pop()后的队列为:"<<endl;
        lrhQueue.myPop();
        lrhQueue.myOutput();
        cout<<"此时队首元素是："<<lrhQueue.myFront()<<endl;
        cout<<"-------------------\n\n\n\n";
	}

    cout<<"此时队列还剩下一个元素，尝试继续\n\n";
    lrhQueue.myPop();
	cout<<"assert要起作用了，boom!!!\n\n";
	cout<<"队首元素是："<<lrhQueue.myFront()<<endl;
	cout<<"-------------------\n\n\n\n";

	system("pause");
	return 0;
}
