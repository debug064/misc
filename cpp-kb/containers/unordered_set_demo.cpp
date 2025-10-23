#include <unordered_set>
#include <set>
//#include <algorithm>

using namespace std;

struct VectorHash {
  size_t operator()(const std::vector<int>& v) const {
    std::hash<int> hasher;
    size_t seed = 0;
    for (int i : v) {
      seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

void test_unordered_set()
{
  unordered_set<vector<int>, VectorHash> res;
  set<vector<int>> ress;
}

int main() 
{
    test_unordered_set();
}