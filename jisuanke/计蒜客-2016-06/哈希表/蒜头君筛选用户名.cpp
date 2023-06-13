#include <iostream>
#include <string>

using namespace std;

class HashTable{
private:
	string *data;
	int mysize;
public:
	HashTable(){
		mysize = 100010;
		data = new string[mysize];
		for(int i=0; i<mysize; i++){
			data[i] = "#";
		}

	}

	~HashTable(){
		delete []data;
	}
    int myhash(string& index) {
        int code = 0;
        for (size_t i = 0; i < index.length(); i++) {
            code = (code * 256 + index[i] + 128) % mysize;
        }
        return code;
    }

    bool mySearch(string &index, int &pos, int &times){

    	pos = myhash(index);
    	times = 0;
    	while(data[pos]!="#" && data[pos]!=index){
        	times++;
        	if(times < mysize)
        		pos = (pos+1) % mysize;
        	else
        		return false;
        }
    	if(data[pos]==index)
    		return true;
    	else
    		return false;
    }

    int myInsert(string &index){
    	int pos, times;
    	if(mySearch(index, pos, times)){
    		return 2;
    	}
    	else if(times < mysize/2){
    		data[pos] = index;
    		return 1;
    	}
    	else{
    		reCreate();
    		return 0;
    	}
    }

    void reCreate(){
    	int    tempSize = mysize;
    	string *tempData = new string[mysize];

    	for(int i=0; i<mysize; i++)
    		tempData[i] = data[i];

    	mysize = tempSize * 2;
    	delete []data;
    	data = new string[mysize];

    	for(int i=0; i<mysize; i++)
    		data[i] = "#";

    	for(int i=0; i<tempSize; i++){
    		if(tempData[i]!="#")
    			myInsert(tempData[i]);
    	}
    	delete []tempData;
    }

};

void toLower(string &index){
	for(size_t i=0; i<index.length(); i++){
		if('A'<=index[i] && index[i]<='Z')
			index[i] = index[i]-'A'+'a';
	}
}

int main()
{
	int n;
	string buffer;
	HashTable hashtable;

	cin>>n;

	for(int i=0; i<n; i++){
        cin>>buffer;
		toLower(buffer);
		int check = hashtable.myInsert(buffer);
		if(check==2)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
