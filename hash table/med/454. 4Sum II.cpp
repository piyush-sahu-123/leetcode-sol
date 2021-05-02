class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        //having all the combination of sum of elements
        //of array nums1 and nums2 and storing its number of occurence
        //in unordered map
        int res=0;
        unordered_map<int,int> AB;
        for(int a:nums1)
        {
            for(int b:nums2)
            {
                AB[a+b]++;
            }
        }
        //since num1+num2+num3+num4=0
        //thus we will find in AB such that whose sum is 0-(num3+num4)
        //thus finding it and adding it to res
        for(int c:nums3)
        {
            for(int d:nums4)
            {
                res+=AB[-(c+d)];
            }
        }
        return res;
    }
};
