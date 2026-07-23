/*
Problem:Two sum
platform:LeetCode
Difficulty:Easy

Approach
    
 
Time Complexity:o(n)
Space complexity:o(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int complement=target- nums[i];
            if(mp.find(complement)!=mp.end())
                return {mp[complement],i};
            mp[nums[i]]=i;
        }
        return {}; //return empty vector if no solution
    }
};
