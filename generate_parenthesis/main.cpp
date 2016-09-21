#include <vector>
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

void generate(int n, int m, int i, vector<char> &a, vector<string> &res) {
    if (n == 0 && m == 0) {
        res.emplace_back(a.begin(), a.end());
        return;
    }
    if (n > 0) {
        a[i] = '(';
        generate(n-1, m+1, i+1, a, res);
    }
    if (m > 0) {
        a[i] = ')';
        generate(n, m-1, i+1, a, res);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    if (n < 1) return res;
    vector<char> a(2*n, ')');
    generate(n, 0, 0, a, res);
    return res;
}

int main() {
    int n = 10;

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto r = generateParenthesis(n);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << "num solutions: " << r.size() << endl;
}
