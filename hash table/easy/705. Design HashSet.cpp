class MyHashSet {
    //initalsing matrix vector and array size
    //cuz we are using sepearte chaining for hashing
    int bucket_size;
    vector<vector<int>> bucket;
    
    //to find the postion of key at array use this function
    int find_pos(int key)
    {
        return key%bucket_size;
    }
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        bucket_size=15000;
        bucket=vector<vector<int>>(bucket_size,vector<int>{});
        
    }
    
    void add(int key) {
        int i=find_pos(key);
        if(find(bucket[i].begin(),bucket[i].end(),key)==bucket[i].end())
            bucket[i].push_back(key);
    }
    
    void remove(int key) {
        int i=find_pos(key);
        auto it=( find ( bucket[i].begin() , bucket[i].end() , key ) );
        if(it!=bucket[i].end())
            bucket[i].erase(it);
            
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int i=find_pos(key);
        auto it=( find ( bucket[i].begin() , bucket[i].end() , key ) );
        if(it!=bucket[i].end())
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
