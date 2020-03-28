class Solution {
public:
    string minWindow(string s, string t) {
        
        string p="";
        int n=t.length();
        if(n==0) return p;
        unordered_map<char,int> pattern;
        for(int i=0;i<n;i++) pattern[t[i]]++;
        
        unordered_map<char,int> temp;
        int ans=INT_MAX, count=0,start=0;
        for(int i=0;i<s.length();i++)
        {
            if(pattern[s[i]])
            {
                temp[s[i]]++;
                if(temp[s[i]]<=pattern[s[i]]) count++;
                
                while(!pattern[s[start]] || temp[s[start]]>pattern[s[start]]) 
                    {
                        if(temp[s[start]]) temp[s[start]]--;
                        start++;
                    }
                
            }
            
            if(count==n && i-start+1<ans)
            {
                ans=min(ans, i-start+1);
                p=s.substr(start,i-start+1);
            }
        }
        return p;
    }
};
