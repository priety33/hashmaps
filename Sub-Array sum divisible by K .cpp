/*
Let there be a subarray (i, j) whose sum is divisible by k
  sum(i, j) = sum(0, j) - sum(0, i-1)
Sum for any subarray can be written as q*k + rem where q 
is a quotient and rem is remainder
Thus,     
    sum(i, j) = (q1 * k + rem1) - (q2 * k + rem2)
    sum(i, j) = (q1 - q2)k + rem1-rem2
     
We see, for sum(i, j) i.e. for sum of any subarray to be
divisible by k, the RHS should also be divisible by k.
(q1 - q2)k is obviously divisible by k, for (rem1-rem2) to 
follow the same, rem1 = rem2 where
    rem1 = Sum of subarray (0, j) % k
    rem2 = Sum of subarray (0, i-1) % k 
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n,k; cin>>n>>k;
	    
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    
	    //prefix sum
	    int ps[n];
	    ps[0]=a[0];
	    for(int i=1;i<n;i++) ps[i]=ps[i-1]+a[i];
	    
	    //map of remainder frequency
	    int count=0;
	    unordered_map<int,int> m;
	    for(int i=0;i<n;i++)
	    {
	        int rem=ps[i]%k;
	        
	        if(rem==0) count++;
	        if(m.find(rem)!=m.end()) count+=m[rem];
	        
	        m[rem]++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}
