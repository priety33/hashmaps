class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> full;
        set<int> zero;
        vector<int> ans(rains.size());
        for(int i=0; i<rains.size(); i++) {
            if(rains[i]==0) {
                zero.insert(i);
                ans[i]= 1;
            }
            else {
                if(full.find(rains[i])!=full.end()) {
                    int lastIndex = full[rains[i]];
                    auto zeroIndex = zero.upper_bound(lastIndex); //finding some day to empty this lake, after it was filled (upper-bound)
                    if(zeroIndex == zero.end())
                    {
                        return {};
                    }
                    ans[*zeroIndex] = rains[i];
                    zero.erase(zeroIndex);
                }
                ans[i]= -1;
                full[rains[i]]= i;
            }
        }
        return ans;
    }
};
