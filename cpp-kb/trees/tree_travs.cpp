#include <iostream>
#include <iomanip>
#include <vector>
#include <span>
#include <stack>

void print(std::string_view text, std::vector<int> const& v = {}) {
    std::cout << text << ": ";
    for (const auto& e : v) std::cout << e << ' ';
    std::cout << '\n';
}


struct Node
{
    int val;
    Node* left;
    Node* right;
    Node(): val(0), left(nullptr), right(nullptr) { }
    //Node() = default;
};

struct Tree
{
    Node* root;

    Tree(): root(nullptr) {};
    void add(int val);
    void add(std::vector<int> const& v);
    size_t levels();
    size_t levels(Node* node, size_t deep);
    void print();
    Node* get(size_t i);
};

void Tree::add(int val)
{
    if(root)
    {
        Node** node = &root;
        do
        {
            if((*node)->val > val)
                node = &(*node)->left;
            else if((*node)->val < val)
                node = &(*node)->right;
            else
                return;
        } while (*node);
        *node = new Node();
        (*node)->val = val;
    }
    else 
    {
        root = new Node();
        root->val = val;
    }
}

void Tree::add(std::vector<int> const& v)
{
    for (const auto val : v)
        add(val);
}

size_t Tree::levels()
{
    return levels(root, 0);
}

size_t Tree::levels(Node* node, size_t deep)
{
    if(node == nullptr)
        return deep;
    size_t l = levels(node->left, deep+1);
    size_t r = levels(node->right, deep+1);
    if( l < r) 
        return r;
    else
        return l;
}

Node* Tree::get(size_t i)
{
    if(i == 0)
        return root;
    std::stack<bool> lr;
    while(i > 0)
    {
        if(i % 2 == 1)
        {
            lr.push(false);
            i -= 1;
        }
        else
        {
            lr.push(true);
            i -= 2;
        }
        i /= 2;
    }
    if(lr.empty())
        return nullptr;
    Node* node = root;
    while(!lr.empty())
    {
        if(node == nullptr)
            return node;
        if(lr.top())
            node = node->right;
        else
            node = node->left;
        lr.pop();
    }
    return node;
}

void Tree::print()
{
    size_t deep = levels();
    size_t nums = pow(2, deep) - 1;
    std::cout<<"Max nums: " << nums << std::endl;
    size_t nl = 2;
    size_t width =  deep  * 2* 4/*4 spaces per num*/;
    size_t level = 0;
    //std::cout<<std::setw(width / 2);
    for(size_t i = 0; i < nums; ++i)
    {
        if(i+1 == nl)
        {
            std::cout<<std::endl;
            nl *= 2;
            ++level;
        }
        std::cout<<std::setw(width / (pow(2, level) + 1) );
        Node* node = get(i);
        if(node)
            std::cout<<node->val ;
        else
            std::cout<<"-";

    }
    std::cout<<std::endl;
}

// traversals
// https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

void printInorderTraversal(Node* node)
{
    if(!node)
        return;
    printInorderTraversal(node->left);
    std::cout<< node->val << " ";
    printInorderTraversal(node->right);
}

void printPreorderTraversal(Node* node)
{
    if(!node)
        return;
    std::cout<< node->val << " ";
    printPreorderTraversal(node->left);
    printPreorderTraversal(node->right);
}

void printPostorderTraversal(Node* node)
{
    if(!node)
        return;
    printPostorderTraversal(node->left);
    printPostorderTraversal(node->right);
    std::cout<< node->val << " ";
}

/// @brief 
/// @return 
int main()
{
    Tree tree;
    std::cout<<"Deep: " << tree.levels() << std::endl;
    tree.add(10);
    std::cout<<"Deep: " << tree.levels() << std::endl;
    tree.add(15);
    tree.add(5);
    tree.add({5,8,12,16});
    tree.add(9);
    tree.add({1,2});
    std::cout<<"Deep: " << tree.levels() << std::endl;
    tree.print();

    printInorderTraversal(tree.root);
    std::cout<< std::endl;

    printPreorderTraversal(tree.root);
    std::cout<< std::endl;

    printPostorderTraversal(tree.root);
    std::cout<< std::endl;
    return 0;
}