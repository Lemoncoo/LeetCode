#ifndef task538_hpp
#define task538_hpp
#include <iostream>
#endif /* task538_hpp */
using  namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
public:
    int reversemidorder(TreeNode *root,int sum){
        if(root == nullptr) return sum;
        sum = reversemidorder(root->right,sum);
        root->val = sum+root->val;
        sum = reversemidorder(root->left,root->val);
        return sum;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr) return nullptr;
        reversemidorder(root,0);
        return root;
    }
    void Test(){}
};
