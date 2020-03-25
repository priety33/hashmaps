class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        int ps[n+1];
        ps[0]=0;
        for(int i=1;i<=n;i++) ps[i]=ps[i-1]+nums[i-1];
        int count=0;
        for(int i=0;i<=n;i++)
        {
            if(m.find(ps[i]-k)!=m.end())
            {
                count+=m[ps[i]-k];
            }
            m[ps[i]]++;
        }
        return count;
    }
};
