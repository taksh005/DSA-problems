class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int left =0 , right = 0;
        if(n<m) return -1;
        while(left<=n-m){
            if(haystack[left + right] == needle[right]){
                right++;
                if(right == m){
                    return left;
                }
            }else{
                left++;
                right = 0;
            }
        }
        return -1;
    }
};