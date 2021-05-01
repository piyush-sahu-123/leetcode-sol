//////////////////////////////////////////////////////////////////////////////////////
// sol-1
/////////////////////////////////////////////////////////////////////////////////////
//ascii value of a is 97 therefore %97 and array of size 26 (number of alphabets
//and finding ascii value of each char of array and then hashing it
//then reducing the value for string t
//and then cheking if each entry of array is 0
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hm(26,0);
        for(int i=0;i<s.size();i++)
        {
            hm[(s[i]-0)%97]++;
        }
        for(int i=0;i<t.size();i++)
        {
            hm[(t[i]-0)%97]--;
        }
        for(int i=0;i<26;i++)
        {
            if(hm[i]!=0)
                return false;
        }
        return true;
    }
};
/////////////////////////////////////////////////////////////////////////////////////
//sol2
///////////////////////////////////////////////////////////////////////////////////
//using sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};
