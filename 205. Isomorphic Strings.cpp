class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> m;
        map<char,bool> visited;
        int n=s.length();
        int i=0,j=0;
        while(i<n)
        {
            if(m.find(s[i])==m.end() && !visited[t[j]])
            {
                m[s[i]]=t[j];
                visited[t[j]]=true;
                i++;
                j++;
            }
            else if(m[s[i]]==t[j])
            {
                i++;
                j++;
            }
            else return false;
        }
        return true;
    }
};
