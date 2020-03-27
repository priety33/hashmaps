class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> h;
        int ans=0;
        for(int i=0;i<answers.size();i++)
        {
            h[answers[i]]++;
        }
        for(auto i:h) 
        {
            if(i.first==0) //im the only rabbit of this colour.
            {
                ans+=i.second;
                continue;
            }
            int a= i.second/(i.first+1); //when all the rabbits of a colour say their colour- divide for total number of groups
            ans=ans+(i.first+1)*a; //multiplying with total number of groups
            if(i.second%(i.first+1)!=0) ans+=i.first+1; //when some of the rabbits from a group say their colour- modulus!=0
         }
        return ans;
    }
};
