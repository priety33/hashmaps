//hard coded
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        unordered_map<int,unordered_set<int>> m;
        for(int i=0;i<r.size();i++) m[r[i][0]].insert(r[i][1]);
        int ans=0;
        for(auto i: m)
        {
            unordered_set s= i.second;
            bool left=false, right=false;
            if(s.find(2)== s.end() && s.find(3)==s.end() && s.find(4)== s.end() && s.find(5)==s.end())
            {
                ans++;
                left=true;
            }
            if(s.find(6)== s.end() && s.find(7)==s.end() && s.find(8)== s.end() && s.find(9)==s.end())
            {
                ans++;
                right=true;
            }
            if(left || right) continue;
            if(s.find(6)== s.end() && s.find(7)==s.end() && s.find(4)== s.end() && s.find(5)==s.end()) ans++;
        }
        int a=m.size();
        if(a!=n) ans+=2*(n-a);
        return ans;
    }
};

//using bits
