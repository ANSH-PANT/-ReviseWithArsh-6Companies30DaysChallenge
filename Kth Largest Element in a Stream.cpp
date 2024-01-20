class KthLargest {
    priority_queue<int, vector<int>, greater<int>> largestKElems;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums) {
            largestKElems.push(num);
            if(largestKElems.size() > k) {
                largestKElems.pop();
            }
        }
    }
    int add(int val) {
        largestKElems.push(val);
        if(largestKElems.size() > k) {
            largestKElems.pop();
        }
        return largestKElems.top();
    }
};
