UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return nullptr;
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
    m[node] = new UndirectedGraphNode(node->label);
    stack<UndirectedGraphNode*> q;
    q.push(node);
    while (!q.empty()) {
        UndirectedGraphNode *x = q.top(), *cx = m[x];
        q.pop();
        for (const auto &y : x->neighbors) {
            const auto &cyit = m.find(y);
            if (cyit == m.end()) {
                m[y] = new UndirectedGraphNode(y->label);
                q.push(y);
            }
            cx->neighbors.push_back(m[y]);
        }
    }
    return m[node];
}
