class Solution {
public:
    int numTeams(vector<int>& arr) {
        unordered_map<int, vector<int>> g;
        unordered_map<int, vector<int>> s;
        int ans=0;
        for(int i=0; i<arr.size(); i++)
        {
            for(int j=i+1; j<arr.size(); j++){
                if(arr[j]>arr[i]) g[arr[i]].push_back(arr[j]);
                else if(arr[j]<arr[i]) s[arr[i]].push_back(arr[j]);
            }
        }
        for(auto i : g)
        {
            for(auto j: i.second) if(g.find(j)!=g.end()) ans+= g[j].size();
        }
        for(auto i : s)
        {
            for(auto j: i.second) if(s.find(j)!=s.end()) ans+= s[j].size();
        }
        return ans;
    }
};
