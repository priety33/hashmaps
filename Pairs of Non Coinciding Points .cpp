#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    int a[n][2];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i][0]>>a[i][1];
	    }
	    map<long long int,long long int>x;
	    map<long long int,long long int>y;
	    map<pair<long long int,long long int>,long long int>visited;
	    for(int i=0;i<n;i++)
	    {
	        pair<long long int,long long int> point=make_pair(a[i][0],a[i][1]);
	        if(!visited[point])
	        {
	            x[a[i][0]]++;
	            y[a[i][1]]++;
	            visited[point]=true; //to take care of duplicate points
	        }
	    }
	    int count=0;
	    for(auto it=x.begin();it!=x.end();it++)
	    {
	        if(it->second>1)
	        {
	            count=count+(it->second)*(it->second-1)/2;
	        }
	    }
	    for(auto it=y.begin();it!=y.end();it++)
	    {
	        if(it->second>1)
	        {
	            count=count+(it->second)*(it->second-1)/2;
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}
