#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head) {
    ListNode *p = head, *q = head;
    while (p && p->next) {
        p = p->next->next;
        q = q->next;
        if (p == q) return true;
    }
    return false;
}

void print(const ListNode *p, int n) {
    while (p && n-- > 0) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    ListNode *head = new ListNode(0), *p = head;
    for (int i = 1; i < 5; ++i) {
        p->next = new ListNode(i);
        p = p->next;
    }

    p->next = head->next->next->next;
    print(head, 10);

    cout << "has cycle: " << hasCycle(head) << endl;
}
