class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector <int> arr (65,0);
      //using ascii char num
      //and then hashing by using remainder
        for(char a:stones)
        {
            arr[(a-'0')%65]++;
        }
        int count=0;
        for(char st:jewels)
        {
            count+=arr[(st-'0')%65];
        }
        return count;
    }
};
