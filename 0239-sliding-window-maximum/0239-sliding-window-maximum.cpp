class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int head=-1,tail=0;
        vector<int> ans;
        multiset<int> window;

        while(tail<n-k+1){
            while(head-tail+1<k){
                head++;
                window.insert(nums[head]);
            }
            //update ans
            auto it=window.rbegin();
            if(it!=window.rend())
                ans.push_back(*it);
            
            //remove one element from tail
            if(tail<=head){
                auto it=window.find(nums[tail]);
                window.erase(it);
                tail++;
            }
            else{
                tail++;
                head=tail-1;
            }
        }
        return ans;

    }
};