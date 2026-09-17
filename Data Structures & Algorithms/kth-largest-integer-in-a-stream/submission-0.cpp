class KthLargest {
public:
    priority_queue<int , vector<int> , greater<int>> pq;
    int m;
    KthLargest(int k, vector<int>& nums) {
        m = k;
        for(int i : nums){
            pq.push(i);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > m) pq.pop();
        return pq.top();
    }
};
