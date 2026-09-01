class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();

        map<char,int> freq;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }

        int ans=0;
        bool odd=false;
        for(auto x:freq){
            if(x.second%2==0){
                ans+=x.second;
            }
            else{
                ans+=x.second-1;//for pairing
                odd=true;
            }
        }

        if(odd){
            ans++;//after pairing, leftover must be in middle
        }
        return ans;
    }
};