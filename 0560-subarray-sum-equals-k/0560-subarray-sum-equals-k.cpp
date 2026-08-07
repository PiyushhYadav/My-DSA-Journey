class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //make prefix sum array
        int n=nums.size();
        int p[n];
        for(int i=0;i<n;i++){
            p[i]=nums[i];
            if (i>0) p[i]+=p[i-1];
        }
        //prefix sum bet l to r= p[r]-p[l-1]
        int ans=0;
        map<int,int> freq;//freq map
        freq[0]=1;//for -1 index
        for(int r=0;r<n;r++){
            //p[r]-p[l-1]=k
            //p[l-1]=p[r]-k
            //now just find the no.of pair which satisfies this eqn
            ans+=freq[p[r]-k];
            freq[p[r]]++;
        }
        return ans;

    }
};