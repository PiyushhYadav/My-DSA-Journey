class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        //fixing first element
        for(int i=0;i<n-2;i++){
            //skip duplicate first element
            if(i>0 && nums[i]==nums[i-1]) continue;

            int tail=i+1;
            int head=n-1;

            while(tail<head){
                long long sum=1LL* nums[i]+nums[head]+nums[tail];
                
                if(sum<0) tail++;
                else if(sum>0) head--;
                else{//sum==0
                    ans.push_back({nums[i],nums[tail],nums[head]});

                    tail++;
                    head--;

                    //skip duplicate tail elements
                    while(tail<head && nums[tail]==nums[tail-1]) tail++;

                    //skip duplicate head elements
                    while(tail<head && nums[head]==nums[head+1]) head--;
                }
            }
        }
        return ans;
    }
};