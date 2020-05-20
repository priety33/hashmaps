class UndergroundSystem {
public:
    unordered_map< int, pair<string, int> > in; //id- station, time
    unordered_map< string, pair<int, int> > out; //station-id-time
    map< pair<string,string>, vector<double>> m; // s-e, time
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string s, int t) {
        in[id]={s, t};
    }
    
    void checkOut(int id, string s, int t) {
        pair<string, int> p= in[id];
        s=p.first+"-"+s;
        out[s].first+=t-p.second;
        out[s].second++;
    }
    
    double getAverageTime(string s, string e) {
        s=s+'-'+e;
        return out[s].first/(double)out[s].second;
    }
};
