#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    int rem[n];
	    unordered_map<int,int> m;
	    for(int i=0;i<n;i++)
	    {
	         rem[i]=a[i]%4;
	         m[rem[i]]++;
	    }
	    int ans=0;
	    ans+=((m[0]*(m[0]-1))+(m[2]*(m[2]-1)))/2; // pairs from 0remainder=nc2, pairs from 2rem= nc2
	    int b=m[1]*m[3];
	    ans=ans+b;
	    cout<<ans<<endl;
	}
	return 0;
}
