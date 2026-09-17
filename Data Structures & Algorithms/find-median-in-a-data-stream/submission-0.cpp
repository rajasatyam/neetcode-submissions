class MedianFinder {
    vector<int> v;
public:
    priority_queue<int> pq;
    MedianFinder() {
    }
    
    void addNum(int num) {
        v.push_back(num);
    }
    
    double findMedian() {
        int n = v.size();
        if(n == 0) return 0;
        sort(v.begin() , v.end());
        if(n % 2 != 0) return double(v[n/2]);
        int x = n/2;
        return ((double)(v[x] + v[x - 1]))/2;
        // for(int i : v){
        //     pq.push(i);
        //     if(pq.size() > n/2) pq.pop();
        // }
        // if(n % 2 != 0) return pq.top();
        // double ans = pq.top();
        // pq.pop();
        // ans += pq.top();
        // return ans/2;
    }
};
