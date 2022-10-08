class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l=0, r=numbers.size()-1, mid;
        while(l<r){
            mid = l + (r-l)/2;
            if(numbers[mid] < numbers[r]){
                r = mid; 
            }
            else if(numbers[mid] > numbers[r]){
                l = mid + 1;
            }
            else{
                --r;
            }
        }
        return numbers[l];
    }
};