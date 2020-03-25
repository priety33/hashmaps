#include <bits/stdc++.h>
using namespace std;

int main() {
    
    //time without these lines- 0.43, with these- 0.32
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int t; cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int s[n];
	    for(int i=0;i<n;i++){
	        cin >> s[i];
	    }
	    int count=0;
	    unordered_map<int,int> prefixsum;
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]==0) sum=sum-1; //considering 0 as -1 and storing prefixsum of every index in map.
	        else sum=sum+1;
	        
	        prefixsum[sum]++;
	    }
	    for(auto it=prefixsum.begin(); it!=prefixsum.end();it++)
	    {
	        // no of 0,1 in window[i,j]= no of 0,1 in window[0,j]-window[0,i]
	        // if prefixsum at two indices are equal, this means prefix sum between them would be zero, this means equal number of 0,1
	        // therefore one of these indices can be taken as start and other as end of window
	        // out of n indices with same prefix sum, any two can be chosen for a window
	        // this can be done nC2 ways.
	        count+=(it->second*(it->second-1))/2;
	    }
	    //indices with zero prefixsum shouls also be added since this window starts from beginning of array, and sum from start till this index is zero
	    // this means equal no of 0,1
	    count+=prefixsum[0]; 
	    cout<<count<<endl;
	}
	return 0;
}
