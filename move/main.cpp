#include <iostream>
#include <vector>
#include "Month.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

/// Take all content out of from and push them to the back of to in reverse order.
/// \tparam T type of element in vector
/// \param to destination of data
/// \param from source of data
template<typename T>
void drain_reversed(vector<T>& to, vector<T> &&from) {
    cout << "draining" << endl;
    while (!from.empty()) {
        to.push_back(from.back());
        from.pop_back();
    }
    cout << "drained" << endl;
}

int main() {
    cout << "init" << endl;
    vector<Month> myvector = listOfMonths();
    drain_reversed(myvector, listOfMonths());
    cout << "printing" << endl;
    for (const auto& month: myvector)
        cout << month << endl;
    cout << "done" << endl;
    return 0;
}