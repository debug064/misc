#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/balanced-binary-tree/?envType=problem-list-v2&envId=rab78cw1


/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};






void print2(deque<TreeNode*>& list) {
        deque<TreeNode*> nlist;
        for(auto node : list) {
            cout << node->val<< "  ";
            if(node->left)
                nlist.push_back(node->left);
            if(node->right)
                nlist.push_back(node->right);
        }
        cout << endl;
        if(!nlist.empty())
            print2(nlist);
    }

void print(TreeNode* node) {
    deque<TreeNode*> list;
    
    if(node) {
        list.push_back(node);
        print2(list);
    }
}

class Solution {
public:

    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        if(isBalanced(root->left) == false || isBalanced(root->right) == false)
            return false;
        return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1;
    }
};

int main()
{
    cout << "begin"<< endl;
    Solution sol;

    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node9(9);

    node4.left = &node2;
    node4.right = &node7;

    // node2.left = &node1;
    // node2.right = &node3;

    node7.left = &node6;
    node7.right = &node9;

    node6.left = &node3;

    print(&node4);
    auto res = sol.isBalanced(&node4);
    cout << res<< endl;
    
    cout << "end"<< endl;
    return 0;
}