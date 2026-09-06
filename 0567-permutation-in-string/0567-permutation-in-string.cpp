class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length();
        int n2=s2.length();
        //approach- will make a fixed window of n1 size and traverse it over the string s2 and compare their freq of characters
        int freq1[26]={};//freq of character in s1
        int freq2[26]={};//freq of character in current window
        for(auto ch:s1){
            freq1[ch-'a']++;
        }

        int head=-1,tail=0;
        while(tail<n2){
            //eat as much as you can
            while(head+1<n2 && head-tail+1<n1){
                head++;
                freq2[s2[head]-'a']++;
            }
            //compare frequencies
            bool same=true;
            for(int i=0;i<26;i++){
                if(freq1[i]!=freq2[i]){
                    same=false;
                    break;
                }
            }
            if(same){
                return true;
            }
            //remove one ellement from tail
            if(tail<=head){
                freq2[s2[tail]-'a']--;
                tail++;
            }
            else{
                tail++;
                head=tail-1;
            }
        }
        return false;
    }
};