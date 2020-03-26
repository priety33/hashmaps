#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    map<char,int> freq;
	    for(int i=0;i<s.length();i++) freq[s[i]]++;
	    int a=0;
	    for(auto it=freq.begin(); it!=freq.end(); it++) a=max(a,it->second);
	    if(a>s.length()/2) cout<<"0"<<endl;
	    else cout<<"1"<<endl;
	}
	return 0;
}
