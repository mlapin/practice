#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string reverse_words(const string &s) {
    string r(s.size(), ' ');
    int n = s.size(), i = 0, j = n-1;
    while (i < n) {
        while (j >= 0 && s[j] == ' ') --j;
        if (j < 0) break;
        int k = j;
        while (k > 0 && s[k-1] != ' ') --k;

        copy(&s[k], &s[j] + 1, &r[i]);
        i += j - k + 2;
        j = k - 1;
    }
    if (i > 0) --i;
    r.resize(i);
    return r;
}

int main() {
    string s(" a foo bar  ");
    string r = reverse_words(s);
    cout << "\"" << s << "\"" << endl;
    cout << "\"" << r << "\"" << endl;
}
