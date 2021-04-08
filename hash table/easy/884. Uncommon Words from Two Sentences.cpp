class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string,int> um;
        istringstream ss(A+" "+B);
        while(ss>>A)um[A]++;
        vector<string> res;
        for(auto i:um)
        {
            if(i.second==1)
                res.push_back(i.first);
        }
        return res;
    }
};

// sol explaination
//https://leetcode.com/problems/uncommon-words-from-two-sentences/discuss/158967/C%2B%2BJavaPython-Easy-Solution-with-Explanation
