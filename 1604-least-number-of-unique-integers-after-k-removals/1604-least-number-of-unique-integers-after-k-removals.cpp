class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;

        for(int n : arr)
            m[n]++;

        priority_queue<int, vector<int>, greater<>> pq; // min-heap
        
        for(auto it : m)
            pq.push(it.second);
        
        while(!pq.empty() && k){
            if(k >= pq.top()){
                k -= pq.top();
                pq.pop();
            }else{
                k = 0;
            }
        }

        return pq.size();
    }
};