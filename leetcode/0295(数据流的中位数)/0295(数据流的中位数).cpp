class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> mx;
    priority_queue<int, vector<int>, greater<int>> mn;

    MedianFinder() {}

    void addNum(int num) {
        if (mx.empty() || num <= mx.top()) {
            mx.push(num);
            if (mn.size() + 1 < mx.size()) {   
                mn.push(mx.top());
                mx.pop();
            }
        } else {
            mn.push(num);
            if (mn.size() > mx.size()) {
                mx.push(mn.top());
                mn.pop();
            }
        }
    }

    double findMedian() {
        if (mx.size() > mn.size()) {
            return mx.top();
        }
        return (mx.top() + mn.top()) / 2.0;
    }
};
