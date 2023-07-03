class RandomizedCollection {
public:
    unordered_map<int,int>mp;
    vector<int>ans;
    RandomizedCollection() {
        mp.clear();
        ans.clear();
    }
    
    bool insert(int val) {
        bool f=true;
        if(mp[val]>0) f=false;
         ans.push_back(val);
        mp[val]++;
        return f;
    }
    
    bool remove(int val) {
        if(mp[val]==0) return false;
          mp[val]--;
       auto it = std::find(ans.begin(), ans.end(), val);
       ans.erase(it);
        return true;
    }

    int getRandom() {
        return ans[rand()%ans.size()];
    }
};
//https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
//https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/discuss/85541/C%2B%2B-128m-Solution-Real-O(1)-Solution