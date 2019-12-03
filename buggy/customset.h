#ifndef customset_h
#define customset_h

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
class CustomSet {
public:
// Constructors and destructor:
    /// Default constructor
    CustomSet() = default;

    /// Copy constructor. Should construct a copy of "other".
    CustomSet(const CustomSet &other) = default;

    /// Constructor using an array.
    /// Note that if there are duplicates in the array, you should ignore them.
    /// And then the size of your "CustomSet" will be different from the "size" given!
    CustomSet(T arr[], int size) : vector() {
        for (int i = 0; i < size; ++i) {
            add(std::move(arr[i]));
        }
    }

    /// Destructor. Pay attention to memory leaks!
    ~CustomSet() = default;

// Other member functions:
    /// Returns the size of the set.
    int size() const {
        return vector.size();
    }

    /// If "item" is already in the set, return false.
    /// Otherwise, add it to the set and return true.
    bool add(const T &item) {
        if (find(item)) {
            return false;
        } else {
            vector.push_back(item);
            return true;
        }
    }

    /// If an object in the set equals "item", return a pointer to it.
    /// If "item" is not found, return nullptr(NULL).
    T *find(const T &item) {
        return &*std::find(vector.begin(), vector.end(), item);
    }

    /// If an object in the set equals "item", return a pointer to it.
    /// If "item" is not found, return nullptr(NULL).
    const T *find(const T &item) const {
        return &*std::find(vector.cbegin(), vector.cend(), item);
    }

    /// If "item" is not in the set, return false.
    /// Otherwise, erase it from the set and return true.
    bool erase(const T &item) {
        auto iter = std::find(vector.begin(), vector.end(), item);
        if (iter == vector.end())
            return false;
        vector.erase(iter);
        return true;
    }

    /// This function returns the intersection of two sets (*this and other).
    /// In other words, the set of all objects that is in both *this and other.
    /// If there is no intersection, just return an empty set.
    CustomSet intersection(const CustomSet &other) const {
        CustomSet ret(*this);
        for (auto item : ret.vector) {
            if (other.find(item))
                ret.erase(item);
        }
        return ret;
    }

    /// This function sorts the objects in the set in ascending order.
    /// Directly using (std::)sort is enough, if you are using an STL container.
    void sortSet() {
        sort(vector.begin(), vector.end());
    }

    /// This function prints the set, seperating elements by { , , , }.
    /// It's safe to assume that it supports operator<< of ostream (cout).
    /// For example, Assume you've added 2, 4, -2, and 800 to the set, in this order.
    /// This function will print: "{2, 4, -2, 800}\n"
    /// Note that there are spaces between a comma(,) and the next object.
    /// Print a newline at the end. (indicated by the '\n' above)
    void printSet() const {
        cout << '{';
        auto iter = vector.cbegin();
        cout << *iter;
        iter++;
        for (; iter != vector.cend(); iter++) {
            cout << ", " << *iter;
        }
        cout << "}\n";
    }

// Operators:

    /// The operator+ and operator += are overloaded.
    /// They can be understood intuitively, or consider this:
    /// A set "plus" an item means adding in the item.
    /// A set "plus" a set means taking the union of two sets.
    /// However, the difference between + and += is not written here.
    /// Try to figure out on your own!
    CustomSet operator+(const T &item) {
        CustomSet ret(*this);
        ret.add(item);
        return ret;
    }

    CustomSet operator+(const CustomSet &that) {
        CustomSet ret(*this);
        for (auto item : that.vector)
            ret.add(item);
        return ret;
    }

    CustomSet &operator+=(const T &item) {
        add(item);
        return *this;
    }

    CustomSet &operator+=(const CustomSet &that) {
        for (auto item : that.vector)
            add(item);
        return *this;
    }

    /// The operator- and operator -= are overloaded.
    /// They can be understood intuitively, or consider this:
    /// A set "minus" an item means erasing the item.
    /// A set A "minus" a set B means subtracting B from A, or namely, A\B.
    /// However, the difference between - and -= is not written here.
    /// Try to figure out on your own!
    CustomSet operator-(const T &item) {
        CustomSet ret(*this);
        ret.erase(item);
        return ret;
    }

    CustomSet operator-(const CustomSet &that) {
        CustomSet ret(*this);
        for (auto item : that.vector)
            ret.erase(item);
        return ret;
    }

    CustomSet &operator-=(const T &item) {
        erase(item);
        return *this;
    }

    CustomSet &operator-=(const CustomSet &that) {
        for (auto item : that.vector)
            erase(item);
        return *this;
    }

    /// This function returns the Cartesian product of two sets (*this and that).
    /// The Cartesian product of two sets is the set of all ordered pairs that satisfy:
    /// 	The first element of the ordered pair belongs to first set (*this);
    /// 	The second element of the ordered pair belongs the second set (that).
    /// The (std::)pair (in header <utility>) helps representing the object in it.
    /// If you have any question with Cartesian products or std::pair, just look up on Internet!
    CustomSet<std::pair<T, T>> operator*(const CustomSet &that) {
        CustomSet<std::pair<T, T>> ret;
        for (auto lhs : vector) {
            for (auto rhs : that.vector) {
                ret.add(make_pair(lhs, rhs));
            }
        }
        return ret;
    }

private:
    std::vector<T> vector;
};

#endif
