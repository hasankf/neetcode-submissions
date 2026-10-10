

class Solution {
public:

    bool preorder(TreeNode* root, long long left, long long right ) {

        if(!root) return true;

        if(root->val <= left || root->val >= right ) return false ;

        return preorder(root->left, left, root->val) && preorder(root->right, root->val, right) ;
        
    }

    bool isValidBST(TreeNode* root) {

        return preorder(root,-1e18, 1e18) ;
    }
};
