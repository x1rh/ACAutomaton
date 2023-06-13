#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

class Queue {
private:
    int *data;
    int head, tail, length, tot;
public:
    Queue(int length_input) {
        data = new int[length_input];
        length = length_input;
        head = 0;
        tail = -1;
        tot = 0;
    }
    ~Queue() {
        delete[] data;
    }

    bool myPush(int element) {
        if (tot < length) {
            /*tail从0开始,最大值为count-1*/
            /*当tot<length且tail等于length+1时，意味着队列是假上溢，前边的内存可以继续存放新入队的元素，tail重置为0*/
            tail = (tail + 1) % length;
            data[tail] = element;
            tot++;
            return true;
        }
        else {
            return false;
        }
    }


    /*队列不空，则可以继续pop()*/
    /*注意，当队列只剩下最后一个节点时，出队后head变回0,队列为空，*/
    /*但是tail值没变，而且内存里存储的每个元素还在，所以空队列输出时要另加判断*/
    void myPop() {
        assert(tot>0);
        head = (head+1)%length;
        tot--;
    }

    void myFront() {
        assert(tot>0);
        cout<< data[head] <<endl;
    }

    void myOutput() {
        if(tot==0){
            cout<<"队列已空！！！"<<endl;
            return;
        }
        /*防止循环输出*/
        if(tail == length-1){
            for(int i=head; i<=tail; i++)
                cout<<data[i]<<" ";
            cout<<endl;
            return;
        }
        /*分三种情况*/
        /*head<tail时，i的值最大为tail，那么(i+1)%length将使i一直增加*/
        /*head>tail时，i的值最大为length-1，然后（i+1）%length变成0，此时i<=tail,并且i这时的边界为tail,目标实现*/
        /*head=tail很显然成立*/
        for (int i = head; i != tail + 1; i = (i + 1) % length)
            cout << data[i] << " ";
        cout << endl;
    }
    void PrintTail(){
        cout<<head<<" "<<tail<<endl;
    }

};
int main() {
    int n;
    n = 10;
    /*要保证length大于0, 模0会出错*/
    Queue myqueue(10);
    for (int i=0; i<n; i++) {
        myqueue.myPush(i+1);
    }


    cout<<"--------------队列输出-------------------------\n";
    myqueue.myOutput();
    cout<<"--------------分割线---------------------------\n\n\n\n\n";


    cout<<"--------------当前队列队首元素是：-------------\n";
    myqueue.myFront();
    cout<<"--------------分割线---------------------------\n\n\n\n\n";



    cout<<"--------------执行一次pop()后的队列为：--------\n";
    myqueue.myPop();
    myqueue.myOutput();
    cout<<"--------------分割线---------------------------\n\n\n\n\n";


/*
    //执行这个操作，将把2333放到所开辟内存的第一个元素的位置
    cout<<"--------------执行一次push()后的队列为：--------\n";
    myqueue.myPush(2333);
    myqueue.myOutput();
    cout<<"--------------分割线---------------------------\n\n\n\n\n";
*/



    cout<<"--------------将队列删除得只剩下一个------------\n";
    for(int i=0; i<n-2; i++)
        myqueue.myPop();
    myqueue.myOutput();
    cout<<"--------------分割线----------------------------\n\n\n\n\n";


    cout<<"--------------删除最后一个元素后输出：---------\n";
    myqueue.myPop();
    myqueue.myOutput();
    cout<<"--------------分割线----------------------------\n\n\n\n\n";


    system("pause");
    return 0;
}
