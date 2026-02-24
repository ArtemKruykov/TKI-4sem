#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

template<typename T>
class ptout_iterator {
private:
    bool first;

public:
    using iterator_category = output_iterator_tag;
    using value_type = void;
    using difference_type = void;
    using pointer = void;
    using reference = void;

    ptout_iterator() : first(true) {}

    ptout_iterator& operator=(const T& value) {
        if (!first) {
            cout << " ";
        }
        cout << value;
        first = false;
        return *this;
    }

    ptout_iterator& operator*() { return *this; }
    ptout_iterator& operator++() { return *this; }
    ptout_iterator operator++(int) { return *this; }
};

int main() {
    string name1 = "a.txt";
    string name2 = "b.txt";

    ifstream file_a(name1);
    ifstream file_b(name2);

    if (!file_a.is_open() || !file_b.is_open()) {
        cerr << "Ошибка открытия файлов" << endl;
        return 1;
    }

    istream_iterator<double> it_a(file_a);
    istream_iterator<double> it_b(file_b);
    istream_iterator<double> end;

    vector<double> A, B;

    copy(it_a, end, back_inserter(A));
    copy(it_b, end, back_inserter(B));

    if (A.size() != B.size()) {
        cerr << "Файлы содержат разное количество чисел" << endl;
        return 1;
    }

    vector<double> differences(A.size());

    // ВАЖНО: B - A
    transform(B.begin(), B.end(), A.begin(), differences.begin(), minus<double>());

    ptout_iterator<double> out;
    copy(differences.begin(), differences.end(), out);
    cout << endl;

    return 0;
}