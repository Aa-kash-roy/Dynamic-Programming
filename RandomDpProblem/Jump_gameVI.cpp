// link : https://leetcode.com/problems/jump-game-vi/
/*  
    It is based on Sliding window MAXIMUM ( try using deque to optimise further ) and maintaining simple dp
    state dp[i] = maximum ans to reach the ith index.
    
*/
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
            
            int n = nums.size();
            int dp[100005] = {0};
            
            dp[0] = nums[0];
            multiset<int> ms;
            ms.insert(nums[0]);
            for(int i=1;i<n;i++)
            {
                if(ms.size() > k)
                {
                    ms.erase(ms.find(dp[i-k-1]));
                }
                
                int val = *ms.rbegin();
                dp[i] = val + nums[i];
                ms.insert(dp[i]);
                
            }
        
            return dp[n-1];
        }
};
