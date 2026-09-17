#include <bits/stdc++.h>
class KthLargest {
public:
    int t ;
    vector<int> a;
    KthLargest(int k, vector<int>& nums) {
        for(int i : nums) a.push_back(i);
        t = k;
    }
    
    int add(int val) {
        a.push_back(val);
        sort(a.begin() , a.end());
        return a[a.size() - t];
    }
};
