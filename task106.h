#ifndef task106_hpp
#define task106_hpp

#include<vector>
#include<unordered_map>
#endif /* task106_hpp */
using namespace::std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution{
public:
    TreeNode* head;
    vector<int> inorder;
    vector<int> postorder;
    unordered_map<int,int> location;
    TreeNode *getTree(int begin,int end){
        TreeNode *p = nullptr;
        if(begin == end){
            p = new TreeNode(inorder[begin]);
            return p;
        }
        if(begin > end) return nullptr;
        int max = location.at(inorder[begin]);
        int maxnum = begin;
        for(int i = begin;i<= end;i++){
            if(max < location.at(inorder[i])){
                max = location.at(inorder[i]);
                maxnum = i;
            }
        }
        p = new TreeNode(inorder[maxnum]);
        p->left = getTree(begin, maxnum-1);
        p->right = getTree(maxnum+1, end);
        return p;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) return nullptr;
        this->inorder = inorder;
        this->postorder = postorder;
        int i = 0;
        for(i = 0;i<inorder.size();i++){
            location.insert({postorder[i],i});
        }
        head = new TreeNode(postorder[postorder.size()-1]);
        for(i = 0;inorder[i]!=head->val;i++){};
        head->left = getTree(0, i-1);
        head->right = getTree(i+1, postorder.size()-1);
        return  head;
    }
    void Test(){
        vector<int> inorder{1,3,2};
        vector<int> postorder{3,2,1};
        buildTree(inorder, postorder);
    }
};
