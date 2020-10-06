#ifndef task701_hpp
#define task701_hpp
#endif /* task701_hpp */
using namespace::std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *p = new TreeNode(val) ;
        TreeNode *before,*head = root;
        if(root == nullptr) return p;
        while (root != nullptr) {
            before = root;
            if(root->val > val)
                root = root->left;
            else
                root = root->right;
        }
        if(before->val > val)
            before->left = p;
        else
            before->right = p;
        return head;
    }
};

