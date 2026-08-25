class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();

        int head=n-1;
        int tail=0;
        int ans=0;

        while(tail<head){
            int hight=min(height[head],height[tail]);
            int width=head-tail;
            int water=hight*width;

            ans=max(ans,water);

            if(height[tail]<height[head]){
                tail++;//jo kam h usko badhao
            }
            else{//height[tail]>height[head]
                head--;
            }
        }

        return ans;
    }
};