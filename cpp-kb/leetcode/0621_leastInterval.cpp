#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<char> output;
        map<char, int> groups;
        for(auto c : tasks) {
            if(auto it = groups.find(c); it != groups.end()) {
                it->second += 1;
                continue;
            }
            groups[c] = 1;
        }

        vector<pair<char, int>> groups2;
        for( auto it = groups.begin(); it != groups.end(); ++it) {
            groups2.push_back(*it);
        }
        sort(groups2.begin(), groups2.end(), [](const auto &v1, const auto &v2) {
            return v1.second > v2.second; }
        );
        groups.clear();

        while(!groups2.empty()) {
            auto it = groups2.begin();
            for(int i = 0; i <= n; ++i) {
                if(groups2.empty())
                    break;
                if(it == groups2.end()) {
                    output.push_back(' ');
                    continue;
                }
                output.push_back(it->first);
                it->second -= 1;
                if(it->second == 0)
                    it = groups2.erase(it);
                else
                    ++it;
            }
            sort(groups2.begin(), groups2.end(), [](const auto &v1, const auto &v2) {
            return v1.second > v2.second; }
        );
        }
        return (int)output.size();
    }
};

// for( ; it != groups2.end(); ) {
            //     output.push_back(it->first);
            //     it->second -= 1;
            //     if(it->second == 0)
            //         it = groups2.erase(it);
            //     else
            //         ++it;
            // }
        
        // while(!groups.empty()) {
        //     auto it = groups.begin();
        //     for(int i = 0; i <= n; ++i) {
        //         if(groups.empty())
        //             break;
        //         if(it == groups.end()) {
        //             output.push_back(' ');
        //             continue;
        //         }
        //         output.push_back(it->first);
        //         it->second -= 1;
        //         if(it->second == 0)
        //             it = groups.erase(it);
        //         else
        //             ++it;
        //     }
        //     for( ; it != groups.end(); ) {
        //         output.push_back(it->first);
        //         it->second -= 1;
        //         if(it->second == 0)
        //             it = groups.erase(it);
        //         else
        //             ++it;
        //     }
        // }

int main()
{
    cout << "begin"<< endl;
    Solution sol;
    vector<char> tasks ;

    tasks = {'B','C','D','A','A','A','A','G'};
    assert(8 == sol.leastInterval(tasks, 1));

    tasks = {'A','A','A','B','B','B','C','C','C', 'D', 'D', 'E'};
    assert(12 == sol.leastInterval(tasks, 3));

    tasks = {'A','C','A','B','D','B'};
    assert(6 == sol.leastInterval(tasks, 1));
    
    tasks = {'A','A','A','B','B','B'};
    assert(8 == sol.leastInterval(tasks, 2));

    cout << "end"<< endl;
    return 0;
}
