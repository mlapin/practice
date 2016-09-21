#include <vector>
#include <queue>
#include <ctime>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
     ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
struct Compare {
    bool operator()(const ListNode *a, const ListNode *b) const {
        if (!a) return true;
        if (!b) return false;
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*> &a) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> q(Compare(), a);
    ListNode r(0), *i = &r;
    while (!q.empty()) {
        ListNode *t = q.top();
        q.pop();
        if (!t) continue;
        i = i->next = t;
        if (t->next) q.push(t->next);
    }
    return r.next;
}

int main() {
    vector<ListNode*> a;
    for (int n = 0; n < 5; ++n) {
        ListNode *head = (n > 0) ? new ListNode(n) : nullptr, *p = head;
        for (int i = 1; i < n; ++i) {
            p = p->next = new ListNode(i+n);
        }
        a.push_back(head);
    }

    priority_queue<ListNode*, vector<ListNode*>, Compare> q(Compare(), a);
    while (!q.empty()) {
        if (q.top())
            cout << q.top()->val << " ";
        else
            cout << "null ";
        q.pop();
    }
    cout << endl;

    clock_t startcputime;
    double cpu_duration;

    startcputime = clock();
    auto r = mergeKLists(a);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    while (r) {
        cout << r->val << " ";
        r = r->next;
    }
    cout << endl;
}
