class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        while(j<s.size() && s[j]!=' '){
            while(s[j]!=' ' && (j<s.size())){
                j++;
            }
            if(s[j]==' ' || (j==s.size())){
                reverse(s.begin()+ i, s.begin()+j);
            }

            i=j+1;
            j=j+1;
        }
        return s;
    }
};