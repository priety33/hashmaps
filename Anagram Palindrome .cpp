//https://practice.geeksforgeeks.org/problems/anagram-palindrome/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    string s; cin>>s;
	    map<char,int> m;
	    int c=0;
	    for(int i=0;i<s.length();i++) m[s[i]]++;
	    for(auto it=m.begin();it!=m.end();it++) 
	    {
	        if(it->second%2!=0) c++;
	    }
	    if(c>1) cout<<"No"<<endl; //atmost one element can have odd frequency in a palindrome.
	    else cout<<"Yes"<<endl;
	}
	return 0;
}
