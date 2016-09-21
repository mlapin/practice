#include <ctime>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (n < 1) return head;
    ListNode *b = head;
    while (n > 0 && b != nullptr) {
        --n;
        b = b->next;
    }
    if (n > 0) return head;
    ListNode *r = new ListNode(0), *a = r;
    r->next = head;
    while (b != nullptr) {
        a = a->next;
        b = b->next;
    }
    b = a->next;
    if (b != nullptr) b = b->next;
    a->next = b;
    return r->next;
}

int main() {
    ListNode *head = new ListNode(1), *p = head;
    for (int i = 2; i <= 7; ++i) {
        p = p->next = new ListNode(i);
    }

    int n = 5;

    clock_t startcputime;
    double cpu_duration;
    
    p = head;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    cout << "n = " << n << endl;

    startcputime = clock();
    p = removeNthFromEnd(head, n);
    cpu_duration = (clock() - startcputime) / (double) CLOCKS_PER_SEC;
    cout << "ms: " << cpu_duration*1000.0 << endl;

    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
