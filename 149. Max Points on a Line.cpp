
class Solution {
public:
    
    long double slope(vector<int> a, vector<int> b)
    {
        long double x=b[0]-a[0];
        long double y=b[1]-a[1];
        if(b[1]==a[1] && b[0]==a[0]) return INT_MAX; //same points
        else if(b[0]==a[0]) return INT_MIN; //same x coordinate (slope=inf)
        else return y/x;
    }
    
    int maxPoints(vector<vector<int>>& points) {
        
        if(points.size()==0) return 0;
        int mp=0;
        map<long double,int> m;
        for(int i=0;i<points.size();i++)
        {
            int same=0;
            int h=0;
            for(int j=0;j<points.size();j++)
            {
                if(j==i) continue;
                long double s=slope(points[i],points[j]);
                if(s==INT_MAX) same++; //number of duplicate points of i.
                else
                {
                    m[s]++;
                    if(m[s]>h) h=m[s];
                }
            }
            h=h+same;
            if(h>mp) mp=h;
            m.clear();
        }
        return mp+1;
    }
};
/* [[0,0],[94911151,94911150],[94911152,94911151]] to handle such cases use long double */
