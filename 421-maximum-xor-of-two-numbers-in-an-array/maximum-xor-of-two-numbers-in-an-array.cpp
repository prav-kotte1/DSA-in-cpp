class Trie {
private: 
    struct TrieNode{
        TrieNode* children[2];
        TrieNode(){
            children[0] = children[1] = nullptr;
        }
    };
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(int num){
        TrieNode* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num >> i)&1;
            if(node->children[bit] == nullptr)
                node->children[bit] = new TrieNode();
            node = node->children[bit];
        }
    }

    int getMax(int num){
        TrieNode* node = root;
        int ans =0;
        for(int i=31; i>=0; i--){
            int bit = (num>>i) &1;
            if(node->children[1-bit]){
                ans = ans | (1 <<i);
                node = node->children[1-bit];
            } else {
                node = node->children[bit];
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int x:nums) trie.insert(x);

        int ans=0;
        for(int x:nums) ans = max(ans, trie.getMax(x));
        return ans;
    }
};