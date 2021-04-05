class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                    continue;
                p+=4;
                //checking for each swuare its neighbour and subtracting one
                // no need to check for boundary snce laked ends there therefore if present they will always be
                //counted as perimeter
                //eg grid[0][0] left and above side will be alwas counted in perimeter
                if(i>0) p-=grid[i-1][j];
                if(j>0) p-=grid[i][j-1];
                if(i<grid.size()-1) p-=grid[i+1][j];
                if(j<grid[0].size()-1) p-=grid[i][j+1];
            
            }
        }
        return p;
        
    }
};

////////////////////////////////////////////////////////////////////

//shorter sol

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0)
                    continue;
                p+=4;
                
                //rather than checking for each left, right, above and below
                //just check for right and below and subtract twice
                if(i<grid.size()-1) p=p-2*grid[i+1][j];
                if(j<grid[0].size()-1) p=p-2*grid[i][j+1];
            }
        }
        return p;
        
    }
};
