
/*
Given an array arr, return the number of triplets (i, j, k), i < j <= k that satisfy
a = arr[i]^arr[i+1]^...^arr[j-1] == arr[j]^arr[j+1]^...^arr[k] = b.

Explanation

It is obvious that every triplet (i, j, k) satisfies arr[i]^arr[i+1]^...^arr[k] == 0, 
and every pair (i, k) that satisfies arr[i]^arr[i+1]^...^arr[k] == 0 can be splitted into k-i triplets, 
because when j=i+1, i+2, ..., k, it is easy to find out that a=b

To find out the pairs (i, k) that satisfy arr[i]^arr[i+1]^...^arr[k] == 0, 
we can use a map to store the xor of prefixes, and when two prefixes are equal, 
like arr[0]^arr[1]^...^arr[i-1] == arr[0]^arr[1]^...^arr[k], 
we can conclude that (arr[0]^arr[1]^...^arr[i-1]) ^ (arr[0]^arr[1]^...^arr[k]) = arr[i]^arr[i+1]^...^arr[k].
*/



class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        unordered_map< int, vector<int>> prefix_xor;
        prefix_xor[0].push_back(-1);
        int x=0, ans=0;
        for(int i=0; i<n; i++)
        {
            x=x^arr[i];
            if(prefix_xor.find(x)!=prefix_xor.end())
            {
                for(auto j: prefix_xor[x])
                {
                    int start=j+1, end=i;
                    ans+= end-start;
                }
            }
            prefix_xor[x].push_back(i);
        }
        return ans;
    }
};
