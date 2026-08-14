#include "header.h"


class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> idx;
public:
    RandomizedSet() {
        srand((unsigned int)time(NULL));
    }
    
    bool insert(int val) {
        if(idx.count(val))return false;
        nums.push_back(val);
        idx[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!idx.count(val))return false;
        int id = idx[val];
        idx[nums.back()] = id;
        idx.erase(val);

        nums[id] = nums.back();
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        int randIdx = rand() % nums.size();
        return nums[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */