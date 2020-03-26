/*
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++)
        {
            string p=strs[i];
            sort(p.begin(),p.end()); //it two strings ara anagrams of each other, their sorted string will be same.
            m[p].push_back(strs[i]); // therefore use this sorted string as key of hashmap, to store all strings with same sorted string together.
        }
        vector<vector<string>> v;
        for(auto it=m.begin();it!=m.end();it++) v.push_back(it->second);
        return v;
    }
};
