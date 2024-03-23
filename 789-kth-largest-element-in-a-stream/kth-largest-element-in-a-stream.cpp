class KthLargest {
private:
    priority_queue <int, vector<int>, greater<int>> minHeap;
    int index;
public:
    KthLargest(int k, vector<int>& nums) {
        index = k;
        for(int ele: nums)
        {
            minHeap.push(ele);
        }
        while(minHeap.size() > k)   minHeap.pop();
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > index)   minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */