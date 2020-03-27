class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        if(A.size()==0) return true;
        map<int,int> h;
        int j=0;
        for(int i=0;i<A.size();i++)
        {
            h[A[i]]++;
        }
        for(auto it=h.begin();it!=h.end();it++)
        {
            int i=it->first;
            if((i==0 && h[i]<2) || (i<0 && (!h[i/2] || h[i/2]<h[i])) || (i>0 && (!h[2*i] || h[2*i]<h[i])) ) return false;
            
            if(i==0)
            {
                h[i]=h[i]-2;
                j++;
            }
            else if(i>0)
            {
                int n= it->second;
                h[2*i]=h[2*i]-n; //2*i will come after i, because in map elements are in ascending order
                if(h[2*i]==0) h.erase(2*i);
                j=j+n;
            }
            else
            {
                int n= it->second;
                h[i/2]=h[i/2]-n; //i/2 will come after i, whein i<0
                if(h[i/2]==0) h.erase(i/2);
                j=j+n;
            }
        }
        return j=A.size()/2;
    };
};
