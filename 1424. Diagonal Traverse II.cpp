class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> v;
        map< int, vector<int> >m;
        for(int i=nums.size()-1; i>=0; i--)
        {
            for(int j=0; j<nums[i].size(); j++)
            {
                m[i+j].push_back(nums[i][j]);
            }
        }
        for(auto i:m)
        {
            for(int s=0; s<i.second.size(); s++) v.push_back(m[i.first][s]);
        }
        return v;
    }
};
