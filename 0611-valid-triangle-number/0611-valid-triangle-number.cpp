class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //sum of two sides must be strictly greater than the third side
        int n=nums.size();
        sort(nums.begin(),nums.end());//so that largest side can be at last
        int count=0;

        for(int k=n-1;k>=2;k--){
            int i=0, j=k-1; //reset i,j for each kth cycle
            while(i<j){
                if(nums[i]+nums[j]>nums[k]){
                count+=j-i;
                j--;
            }
            else{//not valid pair
                i++;
            }
            }
        }
        return count;
    }
};