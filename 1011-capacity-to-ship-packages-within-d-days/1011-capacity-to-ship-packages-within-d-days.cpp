class Solution {
public:
    int canShip(vector<int>& weights,int capacity){
        int days=1,load=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            if(load+weights[i]>capacity){
                days++;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights,int days){
        int low=*max_element(weights.begin(),weights.end());
        //int high=0; for(int x:weights) high+=x
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int daysRequired=canShip(weights,mid);
            if(daysRequired<=days)  //possible to go for
                                  //looking for least capacity
                high=mid-1;
            else
                //not possible, increase the least cap
                low=mid+1;
        }
        return low;     //low will endup at least elem
    }
};