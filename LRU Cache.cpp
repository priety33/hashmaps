class LRUCache {
    private:
    list<int> dq; //least recently used items lie at the back of list
    unordered_map<int, pair<int,list<int>::iterator>> m;
    int cap;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        else //element accessed => move to start of list because it got most recently used
        {
            int value=m[key].first;
            dq.erase(m[key].second);
            dq.push_front(key);
            m[key]={value, dq.begin()};
            return value;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key)==m.end())
        {
            if(dq.size()==cap)
            {
                m.erase(dq.back());
                dq.pop_back();
            }
        }
        else dq.erase(m[key].second);
        
        dq.push_front(key);
        m[key]={value, dq.begin()};
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
