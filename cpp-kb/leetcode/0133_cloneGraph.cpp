#include "Problems.h"
#include <set>
#include <queue>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/clone-graph/?envType=problem-list-v2&envId=rab78cw1


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        queue<Node*> nodes;
        unordered_map<Node*, Node*> nodes_map;
        nodes.push(node);
        Node* new_node = new Node(node->val);
        nodes_map[node] = new_node;
        while(!nodes.empty())
        {
            node = nodes.front();
            nodes.pop();
            Node* clone_node = nodes_map[node] ;
            for(auto& n : node->neighbors)
            {
                if(!nodes_map.contains(n))
                {
                    nodes_map[n] = new Node(n->val);
                    nodes.push(n);
                }
                clone_node ->neighbors.push_back(nodes_map[n]);
            }
        }
        return new_node;
    }

    void print(Node* node)
    {
        queue<Node*> nodes;
        set<Node*> nodes_v;
        nodes.push(node);
        nodes_v.insert(node);
        std::cout << "[";
        while(!nodes.empty())
        {
            node = nodes.front();
            nodes.pop();
            std::cout  << node->val<< "[";
            for(auto& n : node->neighbors)
            {
                std::cout << n->val << " ";
                if(!nodes_v.contains(n))
                {
                    nodes_v.insert(n);
                    nodes.push(n);
                }
            }
            std::cout << "]";
        }
        std::cout << "]";
        std::cout << std::endl;
    }
};

int main()
{
    
    auto node1 = make_unique<Node>(1);
    auto node2 = make_unique<Node>(2);
    auto node3 = make_unique<Node>(3);
    auto node4 = make_unique<Node>(4);
    // Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
    // Output: [[2,4],[1,3],[2,4],[1,3]]
    node1->neighbors.push_back(node2.get());
    node1->neighbors.push_back(node4.get());

    node2->neighbors.push_back(node1.get());
    node2->neighbors.push_back(node3.get());

    node3->neighbors.push_back(node2.get());
    node3->neighbors.push_back(node4.get());

    node4->neighbors.push_back(node1.get());
    node4->neighbors.push_back(node3.get());

    Solution sol;
    sol.print(node1.get());
    sol.print(sol.cloneGraph( node1.get()));
}


/*
// hacked io
// https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull

static const int __ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
int init = []{
    ofstream out("user.out");
    cout.rdbuf(out.rdbuf());
    for(string str;getline(cin,str);){
        cout<<str<<"\n";
    }
    exit(0);
    return 0;
}();
class Solution {
public:
    Node* cloneGraph(Node* node) {
        return nullptr;
    }
};

*/