class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0)
                // Move 0 to the low region
                swap(nums[low++],nums[mid++]);
            else if(nums[mid]==1)
                // 1 is already in its correct position
                mid++;
            else
                // Move 2 to the high region (don't advance mid yet, check swapped element)
                swap(nums[mid],nums[high--]);           
        }
    }
};