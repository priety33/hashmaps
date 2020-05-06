class Solution {
public:
    
      struct pairHash {
      size_t operator()(const pair<int, int> &x) const { return x.first ^ x.second; }
    };
    
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_set<pair<int,int>, pairHash> lamp;
        unordered_map<int,int> row, col, neg, pos;
        for(int i=0;i<lamps.size();i++)
        {
            int x=lamps[i][0], y=lamps[i][1];
            if(lamp.insert({x,y}).second)
            {
                row[x]++;
                col[y]++;
                neg[x-y]++;
                pos[x+y]++;
            }
        }
        vector<int> ans;
        for(int i=0; i<queries.size(); i++)
        {
            int x=queries[i][0], y=queries[i][1];
            if(row[x] || col[y] || neg[x-y] || pos[x+y])
            {
                ans.push_back(1);
                //we cannot use static array of size 8 like we normally do because in this case we have to switch off lamps 
                //at 8 adjacents, plus the lamp at current position therefore make array of size 9.
                // x=[-1,-1,-1,0,0,0,1,1,1]
                // y=[-1,0,1,-1,0,1,-1,0,1]
                for(int j=x-1; j<=x+1; j++) 
                {
                    for(int k=y-1; k<=y+1; k++)
                    {
                       if(lamp.find({j,k})!=lamp.end())
                       {
                           row[j]--;
                           col[k]--;
                           neg[j-k]--;
                           pos[j+k]--;
                           lamp.erase({j,k});
                       }
                    }
                }
            }
            else ans.push_back(0);
        }
        return ans;
    }
};
