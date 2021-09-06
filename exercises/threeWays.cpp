/* Use STL algorithm to check if all elements are divisible by 3.
   Implement 3 versions:
   - lambda
   - functor
   - function
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

struct DivisibleByThree {
    bool operator()(int value) {
        return value % 3 == 0;
    }
};

bool divisibleByThree(int value) {
    return value % 3 == 0;
}

template<typename T>
void print(const std::vector<T>& v, std::function<bool(int)> func) {
    std::copy_if(begin(v), end(v),
                 std::ostream_iterator<T>(std::cout, " "),
                 func);
    std::cout << std::endl;
}

int main() {
    std::vector numbers = {18, 21, 36, 90, 27, 14, 103};

    auto divisibleByThree_l = [](int value) {
        return value % 3 == 0;
    };

    print(numbers, divisibleByThree);                                           // by function
    print(numbers, divisibleByThree_l);                                         // by lambda
    print(numbers, DivisibleByThree());                                         // by functor

    return 0;
}
