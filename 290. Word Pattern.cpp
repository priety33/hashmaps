class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, string> m;
        unordered_set<string> s;
        int j=0, k=0;
        for(int i=0; i<pattern.size(); i++) {
            while(k<str.size() && str[k]!=' ') k++;
            string a= str.substr(j, k-j);
            string b=pattern.substr(i,1);
            k++; j=k;
            if(m.find(b)!=m.end() && m[b]!=a) return false;
            else if(m.find(b)==m.end() && s.find(a)!=s.end()) return false;
            if(j>=str.length() && i!=pattern.size()-1) return false;
            m[b]=a;
            s.insert(a);
        }
        if(j<str.length()) return false;
        return true;
    }
};
