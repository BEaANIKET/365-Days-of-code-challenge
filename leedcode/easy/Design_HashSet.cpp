class MyHashSet {
public:
     set<int>s;
    MyHashSet() {
       
    }
    
    void add(int key) {
        s.insert(key);
    }
    
    void remove(int key) {
        auto it = s.find(key);
        if (it != s.end()) {
            s.erase(it);
        }
    }
    
    bool contains(int key) {
       
       return s.find(key) != s.end();
              
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */