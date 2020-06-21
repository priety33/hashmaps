#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int freq[26]={0};
        map<int, int> m;
        for(auto &c : s) freq[c-'a']++;
        for(auto i : freq) {
            if(i>0) m[i]++;
        } 
        if(m.size()>2) cout<<"0"<<endl;
        else if(m.size()<2) cout<<"1"<<endl;
        else {
            if(m.begin()->second>1 && m.rbegin()->second>1) cout<<"0"<<endl;
            else if(abs(m.rbegin()->first-m.begin()->first)==1 || (m.begin()->first==1 && m.begin()->second==1)) cout<<"1"<<endl;
            else cout<<"0"<<endl;
        }
    }
    return 0;
}
