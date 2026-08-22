class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;//last actual element nums1 ka
        int j=n-1;//last element of nums2
        int k=m+n-1;//last position of nums1

        while(i>=0 && j>=0){
            if(nums1[i]<nums2[j]){
                nums1[k]=nums2[j];
                j--;
            }
            else{//nums1[i]>nums2[j]
                nums1[k]=nums1[i];
                i--;
            }
            k--;
        }

        //for 3rd case or when nums1 exhausted, but nums2 have still more elements
        while(j>=0){
            nums1[k]=nums2[j];
            j--;
            k--;
        }
    }
};