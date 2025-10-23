#include "Problems.h"

using namespace std;

// https://leetcode.com/problems/time-based-key-value-store/?envType=problem-list-v2&envId=rab78cw1

class TimeMap {
    unordered_map<string, vector< pair<int, string>> > vals;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto& vec = vals[key];
        vec.push_back({timestamp, value});

        // {
        //     auto it = upper_bound(vec.begin(), vec.end(), timestamp, [](auto timestamp, const auto& p) {return p.first < timestamp;});
        //     vec.insert(it, {timestamp, value});
        // }
    }

    string get(string key, int timestamp) {
        auto it = vals.find(key);
        if(it == vals.end())
            return "";
        auto& vec = vals[key];
        if(vec.empty())
            return "";
        // !!! upper_bound better that lower_bound
        auto it2 = upper_bound(vec.begin(), vec.end(), timestamp, [](auto timestamp, const auto& p) {return timestamp < p.first;});
        if(it2 == vec.begin()) 
            return "";
        it2 = prev(it2);
        return it2->second;
    }
    
    string get2(string key, int timestamp) {
        auto it = vals.find(key);
        if(it == vals.end())
            return "";
        auto& vec = vals[key];
        if(vec.empty())
            return "";
        auto it2 = lower_bound(vec.begin(), vec.end(), timestamp, [](const auto& p, auto timestamp) {return p.first < timestamp;});
        if(it2 == vec.begin()) 
        {
            if(it2->first > timestamp)
                return "";
        }
        else if(it2 == vec.end()) 
        {
            if(prev(it2)->first > timestamp)
                return "";
            else
                it2 = prev(it2);
        }
        if(it2->first > timestamp)
            it2 = prev(it2);
        return it2->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */


int main()
{
    cout << "begin"<< endl;

    TimeMap sol;
    sol.set("love","high",10);
    sol.set("love","low",20);

    auto res = sol.get("love",5);
    assert("" == res);
    res = sol.get("love",10);
    assert("high" == res);
    res = sol.get("love",15);
    assert("high" == res);
    res = sol.get("love",20);
    assert("low" == res);
    res = sol.get("love",25);
    assert("low" == res);

    sol.set("foo","bar",1);
    res = sol.get("foo",1);
    assert("bar" == res);
    res = sol.get("foo",3);
    assert("bar" == res);

    sol.set("foo","bar2",4);
    res = sol.get("foo",4);
    assert("bar2" == res);
    res = sol.get("foo",5);
    assert("bar2" == res);

    cout << "end"<< endl;
    return 0;
}
