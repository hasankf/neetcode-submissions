
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        int currentnode = root->val ;

        if(currentnode > p->val && currentnode > q->val ) 
            return lowestCommonAncestor(root->left, p, q ) ;

        if(currentnode < p->val && currentnode < q->val ) 
            return lowestCommonAncestor(root->right, p, q ) ;
        
        return root ;
        


        
    }
};
