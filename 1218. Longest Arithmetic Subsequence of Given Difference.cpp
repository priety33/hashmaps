class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++)
        {
            if(m.find(arr[i]-d)==m.end()) m[arr[i]]=1;
            else
            {
                m[arr[i]]=m[arr[i]-d]+1;
            }
            ans=max(ans, m[arr[i]]);
        }
        return ans;
    }
};
