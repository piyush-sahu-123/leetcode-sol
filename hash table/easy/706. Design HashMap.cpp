/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//sol 1
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class MyHashMap {
    vector<int> v;
public:
    /** Initialize your data structure here. */
    
    //the colon after construcutor
    // it's an initialisation list. You can use it for two things:
    // Calling base class constructors
    // Initialising member variables before the body of the constructor executes.
    
    MyHashMap():v(1000001,-1) {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        v[key]=value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return v[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        v[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//sol 2
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//NOT WORKING THO
//SAME IDEA AS DISCUSS SECTION
//////
class MyHashMap {
    vector<list<pair<int,int>>> hm;
    int sz=10000;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        hm.resize(sz);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto list=hm[key%sz];
        for(auto i:list)
        {
            if(i.first==key)
            {
                i.second=value;
                return;
            }
        }
        list.emplace_back(key,value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto list=hm[key%sz];
        if(list.empty())
            return -1;
        
        for(auto i:list)
        {
            if(i.first==key)
                return i.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto list=hm[key%sz];
        for(auto i=list.begin();i!=list.end();i++ )
        {
            if(i->first==key){list.erase(i);}
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
