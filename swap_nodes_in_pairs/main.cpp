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

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode a(0);
    a.next = head;
    ListNode *p = &a;
    while (p->next && p->next->next) {
        ListNode *r = p->next, *q = p->next->next->next;
        p->next = r->next;
        p->next->next = r;
        r->next = q;
        p = r;
    }
    return a.next;
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
    for (int i = 1; i < 2; ++i) {
        p->next = new ListNode(i);
        p = p->next;
    }

    print(head, 10);

    head = swapPairs(head);
    print(head, 10);
}
