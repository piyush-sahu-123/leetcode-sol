////////////////////////////////////////////////////////////////
//this sol requires only one traveersal of string
////////////////////////////////////////////////////////////////
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hm(26,-1);
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            hm[c-'a']=(hm[c-'a']==-1)?i:-2;
        }
        int res=INT_MAX;
        for(int s:hm) if(s>=0) res=min(s,res);
        return (res==INT_MAX)?-1:res;
    }
};

/////////////////////////
//other sol of leetcode requires 2 trversal of string
// one more solution uses comple data structure with extra storage for how many time
//a character is being repeated
