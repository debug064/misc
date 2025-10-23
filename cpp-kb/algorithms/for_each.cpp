#include <algorithm>
#include <execution>
#include <chrono>
#include <functional>
#include <iostream>
#include <string_view>
#include <thread>
#include <vector>
 
void print(std::string_view text, std::vector<int> const& v = {}) {
    std::cout << text << ": ";
    for (const auto& e : v) std::cout << e << ' ';
    std::cout << '\n';
}

struct Custom
{
    void expensive_operation()
    {
        print("expensive_operation", {reinterpret_cast<int>(this)});
        std::this_thread::sleep_for(std::chrono::seconds(5));
        print("done", {reinterpret_cast<int>(this)});
    }
};

int main()
{
    print("for_each");

    std::vector<Custom> data(10);
// https://stackoverflow.com/questions/39954678/difference-between-execution-policies-and-when-to-use-them#:~:text=par_unseq%20requires%20stronger%20guarantees%20than%20par%2C%20but%20allows,Let%20us%20illustrate%20the%20difference%20with%20an%20example.
    std::for_each(std::execution::par_unseq,
                  data.begin(), data.end(),
                  [](Custom &el)
                  {
                      el.expensive_operation();
                  });

    return 0;
}