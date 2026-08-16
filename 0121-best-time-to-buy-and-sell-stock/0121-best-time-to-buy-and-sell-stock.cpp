class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxProfit=0;
        for(auto it:prices){
            //int cost=prices[i]-mini;
            maxProfit=max(maxProfit,it-mini);
            mini=min(mini,it);
        }
        return maxProfit;
    }
};