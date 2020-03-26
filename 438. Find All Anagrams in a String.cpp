class Solution {
public:
   vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if(s.length()==0 || p.length()==0) return v;
        map<char,int> m;
        for(int i=0;i<p.length();i++) m[p[i]]++;
        int n=p.length();
        int count=0; //keeping count of number of matched chars.
        int end=0;
        int start= end-n+1; //fixed length window- of strings size.
        map<char,int> temp;
       
       //putting first n chars in temp
        while(start<0) 
        {
            temp[s[end]]++;
            if(m[s[end]] && m[s[end]]>=temp[s[end]]) count++;
            end++;
            start++;
        }
            temp[s[end]]++;
            if(m[s[end]] && m[s[end]]>=temp[s[end]]) count++;
            if(count==n) v.push_back(start);
       
        while(end<s.length()-1)
        {
            temp[s[start]]--; //remove char at start, because start will be incremented now.
            if(m[s[start]] && temp[s[start]]<m[s[start]]) count--; //checking if removing this will make an impact on our matched count or not
            start++;
            end++;
            temp[s[end]]++;
            if(m[s[end]] && m[s[end]]>=temp[s[end]]) count++;
            if(count==n) v.push_back(start);
        }
       return v;
    }
};
