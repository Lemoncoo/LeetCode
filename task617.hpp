#ifndef task617_hpp
#define task617_hpp

#include <stdio.h>
#endif /* task617_hpp */
using  namespace::std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};
class Solution{
public:
        TreeNode* frontorder(TreeNode *t1,TreeNode *t2){
            if(t1 == nullptr && t2 == nullptr) return nullptr;
            TreeNode *p1 = new TreeNode(0);
            if(t1 == nullptr){
                p1->val = t2->val;
                p1->left = frontorder(nullptr, t2->left);
                p1->right = frontorder(nullptr, t2->right);
            }else if(t2 == nullptr){
                p1->val = t1 ->val;
                p1->left = frontorder(t1->left, nullptr);
                p1->right = frontorder(t1->right, nullptr);
            }else{
                p1->val = t1 ->val+t2->val;
                p1->left = frontorder(t1->left, t2->left);
                p1->right = frontorder(t1->right, t2->right);
            }
            return p1;
        }
        TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
            if(t1 == nullptr && t2 == nullptr) return nullptr;
            TreeNode *head = new TreeNode(0);
            if(t1 == nullptr){
                head->val = t2->val;
                head->left = frontorder(nullptr, t2->left);
                head->right = frontorder(nullptr, t2->right);
            }else if(t2 == nullptr){
                head->val = t1 ->val;
                head->left = frontorder(t1->left, nullptr);
                head->right = frontorder(t1->right, nullptr);
            }else{
                head->val = t1 ->val+t2->val;
                head->left = frontorder(t1->left, t2->left);
                head->right = frontorder(t1->right, t2->right);
            }
            return head;
        }
    void Test(){}
};
