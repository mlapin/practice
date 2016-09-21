#include <stack>
#include <string>
#include <ctime>
#include <iostream>

using namespace std;

bool notValidOrPop(stack<pair<size_t,size_t>> &s, size_t a, size_t b) {
    if (s.empty()) return true;
    auto t = s.top();
    if (t.first != a || t.second != b) return true;
    s.pop();
    return false;
}

bool isValid(string s) {
    stack<pair<size_t,size_t>> p, q, r;
    for (char c : s) {
        switch (c) {
            case '(': p.emplace(q.size(), r.size());
                break;
            case '[': q.emplace(p.size(), r.size());
                break;
            case '{': r.emplace(p.size(), q.size());
                break;
            case ')':
                if (notValidOrPop(p, q.size(), r.size())) return false;
                break;
            case ']':
                if (notValidOrPop(q, p.size(), r.size())) return false;
                break;
            case '}':
                if (notValidOrPop(r, p.size(), q.size())) return false;
                break;
            default:
                return false;
        }
    }
    return p.empty() && q.empty() && r.empty();
}

int main() {
    string s = "{()}[[][()()]{}]({(){}[]})";

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto b = isValid(s);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    cout << s << endl;
    cout << "isValid: " << b << endl;
}
