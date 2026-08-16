class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end()); // Store unique numbers for O(1) lookups
        int max_len=0;
        for(int num:st){
            // Only start counting if 'num' is the beginning of a sequence
            if(!st.count(num-1)){
                int curr_num=num;
                int curr_len=1;
                // Count consecutive numbers
                while(st.count(curr_num+1)){
                    curr_num++;
                    curr_len++;
                }
                max_len=max(max_len,curr_len);
            }
        }
        return max_len;
    }
};