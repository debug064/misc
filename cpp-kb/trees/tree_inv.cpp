//module;

 #include <iostream>
 #include <format>
 #include <memory>
 #include <vector>

//module std.core;

using namespace std;

struct Node
{
    int val;
    unique_ptr<Node> left;
    unique_ptr<Node> right;
    Node(): val(0) { }
    //Node() = default;
};

struct Tree
{
    unique_ptr<Node> root;

    Tree(): root(nullptr) {};
    void add(int val);
    void add(std::vector<int> const& v);
    void print();
    Node* get(size_t i);
};

void Tree::add(int val)
{
    if(root)
    {
        unique_ptr<Node>* node = &root;
        do
        {
            if((*node)->val > val)
                node = &(*node)->left;
            else if((*node)->val < val)
                node = &(*node)->right;
            else
                return;
        } while (*node);
        *node = make_unique<Node>();
        (*node)->val = val;
    }
    else 
    {
        root = make_unique<Node>();
        root->val = val;
    }
}

void Tree::add(std::vector<int> const& v)
{
    for (const auto val : v)
        add(val);
}

void printPostorderTraversal(unique_ptr<Node>& node)
{
    if(!node)
        return;
    printPostorderTraversal(node->left);
    printPostorderTraversal(node->right);
    std::cout<< node->val << " ";
}

void inverTree(unique_ptr<Node>& node)
{
    if(!node)
        return;
    if(!node->left && !node->right)
        return;
    inverTree(node->left);
    inverTree(node->right);
    swap(node->left, node->right);
}

int main()
{
    Tree tree;
    tree.add({11,22,7,4, 5,8,12,16});
   printPostorderTraversal(tree.root);
   cout << endl;
   inverTree(tree.root);
   printPostorderTraversal(tree.root);
   cout << endl;
}