class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1; // Base case: prefix sum of 0 appears once before array starts
        int curr_sum=0,count=0;
        
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            // Check if there is a prefix sum that completes the target sum k
            if(mp.count(curr_sum-k)){
                count+=mp[curr_sum-k];
            }
            // Record current prefix sum frequency
            mp[curr_sum]++;
        }
        return count;
    }
};