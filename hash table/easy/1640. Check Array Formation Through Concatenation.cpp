class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<int> vec(101,-1);
        //storing only the first element's postion in vec array
        for(int i=0;i<pieces.size();i++)
        {
            vec[pieces[i][0]]=i;
        }
        //here if for loop dont put i++ cuz we are doing it in while loop @ line 22
        for(int i=0;i<arr.size();)
        {
            //pos represents postion of arr[i] in pieces
            //if postion is -1 as put defaulty then false
            int pos=vec[arr[i]];
            int j=0;
            if(pos==-1)
                return false;
            //j is the size of inner array in pieces
            
            while(j<pieces[pos].size())
            {
                //checking if the next item in arr is
                //not equal to inside array of pieces
                //that is i is pointer to arr and pos is pointer to 
                // pieces and j is pointer to array inside array and 
                //checking value on eby one
                if(arr[i++]!=pieces[pos][j++])
                    return false;
            }
        }
        return true;
    }
};
