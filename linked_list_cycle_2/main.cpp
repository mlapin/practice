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

ListNode* detectCycle(ListNode *head) {
    ListNode *p = head, *q = head;
    while (p && p->next) {
        p = p->next->next;
        q = q->next;
        if (p == q) break;
    }
    if (!p || !p->next) return nullptr;
    int n = 1;
    while (p->next != q) {
        p = p->next;
        ++n;
    }
    p = q = head;
    while (n-- > 0) p = p->next;
    while (p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}

void print(const ListNode *p, int n) {
    while (p && n-- > 0) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

void print(const ListNode *head, const ListNode *q) {
    const ListNode *p = head;
    while (p && p != q) {
        cout << p->val << " ";
        p = p->next;
    }
    if (p) {
        cout << "| ";
        do {
            cout << p->val << " ";
            p = p->next;
        } while (p && p != q);
    }
    cout << endl;
}

int main() {
    ListNode *head = new ListNode(1), *p = head;
    for (int i = 1; i < 5; ++i) {
        p->next = new ListNode(i+1);
        p = p->next;
    }

    p->next = p;
    print(head, 10);

    ListNode *l = detectCycle(head);
    if (l) {
        cout << "cycle starts at: " << l->val << endl;
    } else {
        cout << "no cycle" << endl;
    }
    print(head, l);
}
