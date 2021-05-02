class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        //for each wall[i] array keep on adding the previous element to get
        //sum of previous element for a particular element
        //eg [1,2,2,1] will be [1,3,5,6]
        //then find the number of times each number is occuring and find
        //the number that is occuring max number of times
        //then count in each wall[i] if max number of times occuring element occurs
        //if it occurs then that array brcik will not be crossed
        //thus subtract from total rows to get brick row that will be crossed
        unordered_map<int,int> um;
        int Max=0;
        for(int i=0;i<wall.size();i++)
        {
            int sum=0;
            for(int j=0;j<wall[i].size()-1;j++)
            {
                sum+=wall[i][j];
                um[sum]++;
                Max=max(Max,um[sum]);
            }
        }
        return wall.size()-Max;
        
        
    }
};
