class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        unordered_map< string, unordered_map<string,int> > m;
        map<int, string> table;
        set<string> dish;
        for(int i=0; i<orders.size(); i++)
        {
            m[orders[i][1]][orders[i][2]]++;
            table[stoi(orders[i][1])]=orders[i][0];
            dish.insert(orders[i][2]);
        }
        vector<vector<string>> ans;
        vector<string> head;
        head.push_back("Table");
        for(auto it=dish.begin(); it!=dish.end(); it++) head.push_back(*it);
        ans.push_back(head);
        for(auto it:table)
        {
            vector<string> v;
            string s=to_string(it.first);
            v.push_back(s);
            for(int i=1; i<head.size(); i++)
            {
                if(m[s].find(head[i])!=m[s].end()) v.push_back(to_string(m[s][head[i]]));
                else v.push_back("0");
            }
            ans.push_back(v);
        }
        return ans;
    }
};
