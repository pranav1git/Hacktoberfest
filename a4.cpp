
//One approach is to use inorder traversal of tree
//Check for duplicates also
void checkBT(Node* root,vector<int>&V){
        if(!root)
            return;
        checkBT(root->left,V);
        V.push_back(root->data);
        checkBT(root->right,V);
    }
    bool isBST(Node* root) 
    {
        vector<int>V;
        checkBT(root,V);
        for(int i=1;i<V.size();i++)
            if(V[i-1]>=V[i])
                return false;
        return true;
    }
//Second approach is to use min and max varriables which holds the value of the minimum found so far
bool BSTUtil(Node *root,int min,int max){
        if(!root)
            return true;
        if(root->data < min || root->data > max)
            return false;
        else
            return BSTUtil(root->left,min,root->data-1) &&
                    BSTUtil(root->right,root->data+1,max);
    }
    bool isBST(Node* root) 
    {
        return BSTUtil(root,INT_MIN,INT_MAX);
    }
