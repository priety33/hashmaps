class Solution {
public:
    
    vector<int> peopleIndexes(vector<vector<string>>& f) {
        vector<int> ans;
        int n=f.size();
        vector<unordered_set<string>> v;
        for(int i=0; i<n; i++)
        {
            unordered_set<string> s;
            for(int j=0; j<f[i].size(); j++) s.insert(f[i][j]);
            v.push_back(s);
        }
        for(int i=0; i<n; i++)
        {
            bool yes=true;
            for(int j=0; j<n; j++)
            {
                if(i!=j && f[i].size()<=f[j].size())
                {
                    int temp=0;
                    for(int k=0; k<f[i].size(); k++)
                    {
                        if(v[j].find(f[i][k])!=v[j].end()) temp++;
                    }
                    if(temp==f[i].size())
                    {
                        yes=false;
                        break;
                    }
                }
            }
            if(yes) ans.push_back(i);
        }
        return ans;
    }
};
