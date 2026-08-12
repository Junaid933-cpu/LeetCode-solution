class Solution {
public:
    int canSplit(vector<int>& nums, int mSum){
        int currentSum=0;
        int subArray=1;
        for(int i=0;i<nums.size();i++){
            if(currentSum+nums[i]>mSum){
                subArray++;
                currentSum=nums[i];
            }
            else
                currentSum+=nums[i];
        }
        return subArray;
    }

    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int required=canSplit(nums,mid);
            if(required>k)  //if not possible
                low=mid+1;
            else //possible , looking for samller value
                high=mid-1;

        }
        return low;
    }
};