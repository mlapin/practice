#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

struct Node {
  int val;
  Node *next;
  Node(int x) : val(x), next(nullptr) {}
};

Node* find_middle(Node *head) {
  Node *p = head, *m = head;
  bool flag = false;
  while (p) {
    if (flag) m = m->next;
    p = p->next;
    flag = !flag;
  }
  return m;
}

void print(Node *p) {
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << endl;
}

int main() {
  Node *head = new Node(0), *p = head;
  for (int i = 1; i < 10; ++i) {
    p->next = new Node(i);
    p = p->next;
  }
  print(head);
  Node *m = find_middle(head);
  print(m);
}
