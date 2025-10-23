#include <unordered_map>

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

struct Val
{
    string yes;
};

void test_unordered_map()
{
  unordered_map<string, Val> res;

}

int main() 
{
    test_unordered_map();
}