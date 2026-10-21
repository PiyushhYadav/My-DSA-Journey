class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1=0;
        int p2=0;

        while(p1<t.length()){
            if(t[p1]==s[p2]){
                p1++;
                p2++;
            }
            else if(t[p1]!=s[p2]){
                p1++;
            }
        }
        if(p2==s.length()){
            return true;
        }
        return false;
    }
};
//TC- O(n+m)
