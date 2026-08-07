class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best=0;//best profit
        int minseen=prices[0];//or 1e9
        //min price seen so far
        //using contribution technique, Commulative DS
        for(int j=1;j<prices.size();j++){
            best=max(best,prices[j]-minseen);
            minseen=min(minseen,prices[j]);
        }
        return best;
    }
};
