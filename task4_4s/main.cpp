#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;
using namespace std::placeholders; 

struct less_abs : public function<bool(int, int)> {
    bool operator()(int a, int b) const {
        return abs(a) < abs(b);
    }
};

int main() {
    int K = 5;
    vector<int> V = { -3, 5, -1, 8, -7, 2, -4, 10, -6 };

    
    auto it = find_if(V.rbegin(), V.rend(),
        bind(less_abs(), K, _1));

    if (it != V.rend())
        cout << *it << endl;
    else
        cout << 0 << endl;

    return 0;
}