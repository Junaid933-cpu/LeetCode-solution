class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            // Find first element >= nums[i]
            auto it=lower_bound(temp.begin(),temp.end(),nums[i]);
            if(it==temp.end())
                temp.push_back(nums[i]); // Extend sequence length
            else
                *it=nums[i]; // Replace to maintain smaller tail value
            
        }
        return temp.size();
    }
};