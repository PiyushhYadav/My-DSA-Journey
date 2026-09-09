class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int n=nums.size();
        /*for exactly k odd numbers- we will subtract
        = atmost K odd numbers- atmost k-1 odd numbers
         */
        int oddcount=0;
        int head=-1,tail=0;
        int ans=0;
        while(tail<n){
            //eat as much as you can
            while(head+1<n && oddcount + (nums[head+1] % 2) <= k){
                head++;
                if(nums[head]%2!=0){//means odd
                    oddcount++;
                }
            }
            //update ans
            ans+=head-tail+1;

            //remove one element from tail
            if(tail<=head){
                if(nums[tail]%2!=0){
                    oddcount--;
                }
                tail++;
            }
            else{
                tail++;
                head=tail-1;
            }
        }
        return ans;
        
    }
    int numberOfSubarrays(vector<int>& nums, int k){
        return atmost(nums,k) - atmost(nums,k-1);
    }

};