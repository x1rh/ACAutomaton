#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

class Graph
{
private:
	int n;
	bool *visited;
	vector<int> *edges;
public:
	Graph(int _n){
		n = _n;
		edges = new vector<int>[n];
		visited = new bool[n];
	}
	~Graph(){
		delete[] edges;
		delete[] visited;
	}

	void myInsert(int x, int y){
		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	void dfs(int value){
		cout << value << endl;
		visited[value] = true;
		for(){
			if(!visited[i])
				dfs(i);
		}
	}
};

int main(){
	/*n:点  m:边 k:要查询的数*/
	int n, m, k;
	cin>>n>>m;

	Graph g(n);

	int x, y;
	for(int i=0; i<m; i++){
		cin >> x >> y;
		g.myInsert(x, y);
	}

	cin>>k;
	g.dfs(k);

	system("pause");
	return 0;
}
