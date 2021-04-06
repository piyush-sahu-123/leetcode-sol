class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bro=0;
        for(int i=0;i<nums.size();i++)
            bro=bro^nums[i];
        return bro;
    }
};