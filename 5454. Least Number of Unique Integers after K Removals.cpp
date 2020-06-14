class Solution {
public:
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for(auto i: arr) m[i]++;
        //bucket sort using frequency
        vector<vector<int>> v(arr.size()+1, vector<int>());
        for(auto i: m) v[i.second].push_back(i.first);
        int ans=m.size(), i=0;
        for( i; i<v.size(); i++) {
            if(v[i].size()==0) continue;
            int j=v[i].size()-1;
            while(j>=0 && i<=k) {
                k-=i;
                ans--; j--;
            }
            if(k<i) break;
        }
        return ans;
    }
};
