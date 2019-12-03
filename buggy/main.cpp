#include <utility>
#include <iostream>
#include <cassert>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <memory>
#include <algorithm>
#include <string>
#include "customset.h"

using namespace std;


template<typename T>
ostream &operator<<(ostream &os, pair<T, T> p) {
    return os << "'" << p.first << " " << p.second << "'";
}


int main() {
    int a[5] = {3, 5, 3, 10, -2};
    CustomSet<int> foo(a, 5);
    int b[5] = {13, 35, 3, 10, -2};
    CustomSet<int> bar(b, 5);
    assert(*foo.find(3) == 3);
    assert(*foo.find(5) == 5);
    assert(foo.find(12) == nullptr);
    CustomSet<int> intersect = foo.intersection(bar);
    assert(intersect.erase(3));
    assert(intersect.erase(-2));
    assert(intersect.size() == 0);
    assert(foo.size() == 4);
    assert(bar.size() == 5);
}
