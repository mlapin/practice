RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return nullptr;
    unordered_map<RandomListNode*, RandomListNode*> m;
    RandomListNode *p = head;
    while (p) {
        m[p] = new RandomListNode(p->label);
        p = p->next;
    }
    p = head;
    while (p) {
        RandomListNode *cp = m[p];
        if (p->next) cp->next = m[p->next];
        if (p->random) cp->random = m[p->random];
        p = p->next;
    }
    return m[head];
}

RandomListNode *copyRandomList2(RandomListNode *head) {
    if (!head) return nullptr;
    unordered_map<RandomListNode*, RandomListNode*> m;
    RandomListNode *p = head, *cp = new RandomListNode(head->label);
    m[p] = cp;
    p = p->next;
    while (p) {
        cp->next = new RandomListNode(p->label);
        cp = cp->next;
        m[p] = cp;
        p = p->next;
    }
    p = head;
    while (p) {
        if (p->random) m[p]->random = m[p->random];
        p = p->next;
    }
    return m[head];
}
