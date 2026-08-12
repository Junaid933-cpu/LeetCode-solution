class Solution {
public:
    int countPartition(vector<int>& nums, int mSum){
        int currentSum=0;
        int partition=1;
        for(int i=0;i<nums.size();i++){
            if(currentSum+nums[i]>mSum){
                partition++;
                currentSum=nums[i];
            }
            else
                currentSum+=nums[i];
        }
        return partition;
    }

    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int required=countPartition(nums,mid);
            if(required>k)  //if not possible
                low=mid+1;  //too many pieaces needed, allow a bigger sum
            else //possible , looking for samller value
                high=mid-1;   //fits within k pieaces, try smaller sum

        }
        return low;
    }
};