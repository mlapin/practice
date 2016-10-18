bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    if (numCourses < 1) return true;
    vector<vector<int>> e(numCourses);
    for (const auto &p : prerequisites) {
        e[p.second].push_back(p.first);
    }
    enum VertexState { unknown = 0, visiting, visited };
    vector<VertexState> v(numCourses);
    for (int i = 0; i < numCourses; ++i) {
        if (v[i] == visited) continue;
        stack<int> q;
        q.push(i);
        while (!q.empty()) {
            int j = q.top();
            if (v[j] == unknown) {
                v[j] = visiting;
                for (int k : e[j]) {
                    switch (v[k]) {
                        case unknown: q.push(k); break;
                        case visiting: return false;
                        case visited: break;
                    }
                }
            } else {
                v[j] = visited;
                q.pop();
            }
        }
    }
    return true;
}
