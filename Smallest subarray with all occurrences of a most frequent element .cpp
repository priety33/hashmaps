#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>> n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    
	    // int : frequency,(first occurence, last occurence) == key : value
	    map<int,tuple<int,int,int>> m;
	    for(int i=0;i<n;i++)
	    {
	        if(m.find(a[i])==m.end())
	        {
	            m[a[i]]=make_tuple(1,i,i);
	        }
	        else
	        {
	            int f=get<0>(m[a[i]]); //frequency -needs to increased by 1
	            f++;
	            int s=get<1>(m[a[i]]);
	            m[a[i]]=make_tuple(f,s,i);
	        }
	    }
	    // find maximum frequency element, with smallest window
	    int max=0, l=INT_MAX,b=0;
	    int first=0;
	    for(auto it=m.begin();it!=m.end();it++)
	    {
	        //first priority- max freq
	        if(get<0>(it->second) >max)
	        {
	            max=get<0>(it->second);
	            first=get<1>(it->second);
	            l=get<2>(it->second)-get<1>(it->second);
	            b=it->first;
	        }
	        //second priority- smaller window
	        else if(get<0>(it->second) ==max && get<2>(it->second)-get<1>(it->second)<l)
	        {
	            max=get<0>(it->second);
	            first=get<1>(it->second);
	            l=get<2>(it->second)-get<1>(it->second);
	            b=it->first;
	        }
	        //third priority- which comes first
	        else if(get<0>(it->second) ==max && get<2>(it->second)-get<1>(it->second)==l && get<1>(it->second)<first)
	        {
	            max=get<0>(it->second);
	            first=get<1>(it->second);
	            l=get<2>(it->second)-get<1>(it->second);
	            b=it->first;
	        }
	    }
	    for(int j=get<1>(m[b]) ;j<=get<2>(m[b]); j++) cout<<a[j]<<" ";
	    cout<<endl;
	}
	return 0;
}
