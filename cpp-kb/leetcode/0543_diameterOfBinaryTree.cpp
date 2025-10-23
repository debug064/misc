#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/diameter-of-binary-tree/?envType=problem-list-v2&envId=rab78cw1

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
    int diam(TreeNode* root, int& max_edges) {
        if(!root)
            return 0;
        int le = 0, re = 0;
        if(root->left)
            le = diam(root->left, max_edges) + 1;
        if(root->right)
            re = diam(root->right, max_edges)+1;
        int me = max(le, re);
        if(max_edges < le + re)
            max_edges = le + re;
        return me;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_edges = 0;
        diam(root, max_edges);
        return max_edges;
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
    node1.left = &node2;

    auto res = sol.diameterOfBinaryTree(&node1);
    assert(1 == res);

    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    
    res = sol.diameterOfBinaryTree(&node1);
    assert(3 == res);

    node5.right = &node6;
    res = sol.diameterOfBinaryTree(&node1);
    assert(4 == res);

    cout << "end"<< endl;
    return 0;
}
