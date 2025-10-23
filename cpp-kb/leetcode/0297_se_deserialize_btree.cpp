#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/?envType=problem-list-v2&envId=rab78cw1


/**
 * Definition for a binary tree node.
 */ 
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    inline bool get_num(const string& str, size_t& i, int& num)
    {
        bool res = false;
        num = 0;
        bool negative = false;
        if(str[i] == '-') {
            ++i;
            negative = true;
        }
        for (; i < str.size() && std::isdigit(static_cast<unsigned char>(str[i])); ++i)
        {
            res = true;
            int digit = str[i] - '0';
            num *= 10;
            num += digit; // calculate in negatives to support INT_MIN, LONG_MIN,..
        }
        if(res && negative)
            num = -num;
        return res;
    }

    void make_tree(TreeNode* node, const string& str, size_t& i) {
        char c = str[i++];
        
        if(c == '<') {
            int num = 0;
            if(!get_num (str, i, num))
                return;
            node->left = new TreeNode(num);
            make_tree(node->left, str, i);
            if(i < str.size())
                c = str[i++];
        }

        if(c == '>') {
            int num = 0;
            if(!get_num (str, i, num))
                return;
            node->right = new TreeNode(num);
            make_tree(node->right, str, i);
            if(i < str.size())
                c = str[i++];
        }

        if( c == '^') 
            return;
    }

    void make_str(TreeNode* node, string& str) {
        if(!node) return;
        str.append(to_string(node->val));
        if(node->left) {
            str.append("<");
            make_str(node->left, str);
        }
        if(node->right) {
            str.append(">");
            make_str(node->right, str);
        }
        str.append("^");
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return  {};
        string str;
        make_str(root, str);
        size_t i = 0;
        for(auto it = str.rbegin(); it != str.rend(); ++it) {
            if(*it == '^')
                ++i;
            else
                break;
        }
        if(i > 0) {
            str.erase(str.size() - i);
        }
        return str;
    }

    TreeNode* deserialize(string data) {
        size_t i = 0;
        int num = 0;
        stringstream ss(data);
        ss >> num;
        if(!get_num (data, i, num))
            return nullptr;
        TreeNode* root = new TreeNode(num);
        make_tree(root, data, i);
        
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize2(string data) {
        size_t i = 0;
        int num = 0;
        if(!get_num (data, i, num))
            return nullptr;
        TreeNode* root = new TreeNode(num);
        make_tree(root, data, i);
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


int main()
{
    cout << "begin"<< endl;
    vector<int> height ;
    Codec sol;
    
    {
        string st = "4<-7^>-3<-9<9<6<0>-1^^>6<-4^^^^>-7<-6<5^^>-6<9<-2^^^^^>-3<-4";
        auto tree = sol.deserialize(st);
        assert(tree);
        auto str = sol.serialize(tree);
        delete tree;
        assert(st == str);
    }
    {
        string st = "1<2>21^^>3<4^>5";
        auto tree = sol.deserialize(st);
        assert(tree);
        auto str = sol.serialize(tree);
        delete tree;
        assert(st == str);
    }
    {
        string st = "4<-7^>-3<-9<9^>-7^^>-3<-4";
        auto tree = sol.deserialize(st);
        assert(tree);
        auto str = sol.serialize(tree);
        delete tree;
        assert(st == str);
    }
    cout << "end" << endl;
    return 0;
}