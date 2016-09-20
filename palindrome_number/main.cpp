#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>

using namespace std;

// may overflow
bool isPalindrome1(int x) {
    if (x < 0) return false;
    int rev = 0, y = x;
    while (y != 0) {
        rev = rev * 10 + y % 10;
        y /= 10;
    }
    return x == rev;
}

bool isPalindrome2(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    int p = 10;
    while (x / p >= 10) p *= 10;
    while (x >= 10) {
        int ld = x / p;
        if (ld != x % 10) return false;
        x -= ld * p;
        x /= 10;
        p /= 100;
    }
    return p < 10 || x == 0;
}

bool isPalindrome(int x, int &y) {
    if (x == 0) return true;
    if (isPalindrome(x/10, y) && (x % 10 == y % 10)) {
        y /= 10;
        return true;
    }
    return false;
}

bool isPalindrome3(int x) {
    if (x < 0) return false;
    return isPalindrome(x, x);
}

bool isPalindrome(int x) {
    return isPalindrome3(x);
}

int main() {
    int x;

    x = numeric_limits<int>::max();
    cout << "x: " << x << ", test: " << !isPalindrome(x) << endl;
    
    x = numeric_limits<int>::min();
    cout << "x: " << x << ", test: " << !isPalindrome(x) << endl;
    
    x = 0;
    cout << "x: " << x << ", test: " << isPalindrome(x) << endl;

    x = 1;
    cout << "x: " << x << ", test: " << isPalindrome(x) << endl;
    
    x = 22;
    cout << "x: " << x << ", test: " << isPalindrome(x) << endl;
    
    x = 1001;
    cout << "x: " << x << ", test: " << isPalindrome(x) << endl;
    
    x = 100301;
    cout << "x: " << x << ", test: " << !isPalindrome(x) << endl;
    
    x = 1002201;
    cout << "x: " << x << ", test: " << !isPalindrome(x) << endl;
    
    x = 1003001;
    cout << "x: " << x << ", test: " << isPalindrome(x) << endl;
    
    x = 2147447412;
    cout << "x: " << x << ", test: " << isPalindrome(x) << endl;
}
