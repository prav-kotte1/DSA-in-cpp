class Solution {
public:
    int expand(int left, int right, string& s){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int start = 0, end = 0;

        for(int i=0; i<s.size(); i++){
            int odd = expand(i, i, s);
            int even = expand(i, i+1, s);

            int length = max(odd, even);
            if(length > end-start+1){
                start = i-(length-1)/2;
                end = i+length/2;
            }
        }
        return s.substr(start, end-start+1);
    }
};