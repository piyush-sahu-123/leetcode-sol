////////////////////////////////////////////////////
//sol1
////////////////////////////////////////////////
//refer to video https://www.youtube.com/watch?v=WGm4Kj3lhRI
////////////////////////////////////////////////////////////
// if colder in top of stack then keep on popping until hotter is found and then push the current one that was being
//compared to stack elements
//if hotter in tos then res=day part of tos-day part of current and push curr in stack


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int>> stk;
        vector<int> res;
        stk.push({T[T.size()-1],T.size()-1});
        res.push_back(0);
        for(int i=T.size()-2;i>=0;i--)
        {
            if(stk.top().first<=T[i])
            {

                while(!stk.empty())
                {
                    if(stk.top().first<=T[i])
                    {
                        stk.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                if(stk.empty())
                    res.push_back(0);
                else
                    res.push_back(stk.top().second-i);
                stk.push({T[i],i});
                
            }
            else
            {
                res.push_back(stk.top().second-i);
                stk.push({T[i],i});
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};


/////////////////////////////////////
//better code same idea
/////////////////////////////////////
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s; //First is the number while second is the position
        
        int n= temperatures.size();
        vector<int> result(n,0);
        
        for(int i=n-1;i>=0;i--)
        {
            int curr = temperatures[i];
            while(!s.empty() && s.top().first <= curr) s.pop();
            
            result[i] = s.empty() ? 0 : s.top().second - i;

            s.push({curr,i});
        }
        
        return result;
    }
};
