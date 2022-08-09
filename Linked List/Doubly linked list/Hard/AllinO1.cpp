//https://leetcode.com/problems/all-oone-data-structure/

struct incomp {
    bool operator()(pair<string, int> const& a, pair<string, int> const& b) {
        return a.second > b.second;
    }
};

struct decomp {
    bool operator()(pair<string, int> const& a, pair<string, int> const& b) {
        return a.second < b.second;
    }
};

class AllOne {
public:
    priority_queue< pair<string, int>, vector<pair<string, int>>, incomp >minh;
    priority_queue< pair<string, int>, vector<pair<string, int>>, decomp >maxh;
    map<string, int>m;
    int size;
    AllOne() {
        //minh.clear();
        //maxh.clear();
        m.clear();
        size = 0;
    }

    void inc(string key) {
        m[key]++;
        if (m[key] == 1)
        {
            size++;
        }
        minh.push({ key , m[key] });
        maxh.push({ key , m[key] });
    }

    void dec(string key) {
        m[key]--;
        if (m[key] == 0)
        {
            m.erase(key);
            size--;
            return;
        }
        minh.push({ key , m[key] });
        maxh.push({ key , m[key] });
    }

    string getMaxKey() {
        if (size == 0)
            return "";
        while (maxh.top().second != m[maxh.top().first])
            maxh.pop();
        //cout<<maxh.top().first<<" "<<maxh.top().second<<endl;
        return maxh.top().first;
    }

    string getMinKey() {
        if (size == 0)
            return "";
        while (minh.top().second != m[minh.top().first])
            minh.pop();
        //cout<<minh.top().first<<" "<<minh.top().second<<endl;
        return minh.top().first;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */