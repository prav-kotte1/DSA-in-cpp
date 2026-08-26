class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
    };
    void backtrack(int index, string& digits, string& current){
        if(index == digits.size()){
            ans.push_back(current);
            return;
        }
        string letters = mp[digits[index] - '0'];
        for(char c : letters){
            current.push_back(c);
            backtrack(index+1, digits, current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string current = "";
        backtrack(0, digits, current);
        return ans;
    }
};