/*
解题思路：
记忆化搜索，记忆更新的要求为v[idx-1] + v[idx-2] >v[idx]， 这样做可以剪枝。
写完我仔细思考发现，这题就是一题递推题。。。
*/

/*******解法1*********/
class Solution {
public:
    void dfs(vector<int> &v, int idx, int n){
        if(idx > n) return;
        if(v[idx-1] + v[idx-2] > v[idx]){
            v[idx] = v[idx-1] + v[idx-2];
            dfs(v, idx+1, n);
            dfs(v, idx+2, n);
        }
    }
    int jumpFloor(int number) {
        if(number <= 2) return number;
        vector<int> arr(number+1, 0);
        arr[1] = 1;
        arr[2] = 2;
        dfs(arr, 3, number);
        return arr[number];
    }
};

/********解法2*********/
class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 2) return number;
        vector<int> arr(number+1, 0);
        arr[1] = 1;
        arr[2] = 2;
        for(int i=3; i<=number; ++i){
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[number];
    }
};
