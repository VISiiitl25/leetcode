class RandomizedSet {
public:
    map<int,int>mp;
    unordered_set<int>s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp[val])return false;
        mp[val]++;
        s.insert(val);
        return true;
    
    }
    
    bool remove(int val) {
        if(!mp[val])return false;
        mp.erase(val);
        s.erase(val);
        return true;

    }
    
    int getRandom() {
        int idx = rand()%s.size();
        auto it = s.begin();
        for (int i = 0; i < idx; i++)
        {
            it++;
        }
        return *it;
    }
};
