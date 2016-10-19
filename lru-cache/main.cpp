/*
146. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache.
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key
    if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present.
    When the cache reached its capacity, it should invalidate
    the least recently used item before inserting a new item.
*/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <list>
#include <cassert>

using namespace std;

class LRUCache {
    typedef list<pair<int, int>>::iterator q_iter_t;
    typedef unordered_map<int, q_iter_t>::iterator m_iter_t;
    int n_;
    list<pair<int, int>> q_;
    unordered_map<int, q_iter_t> m_;
public:
    LRUCache(int capacity) : n_(max(0, capacity)) {
        m_.reserve(n_); // ensure no re-hashing
    }

    int get(int key) {
        auto it = m_.find(key);
        if (it != m_.end()) {
            touch(it);
            return q_.begin()->second;
        }
        return -1;
    }

    void set(int key, int value) {
        auto it = m_.find(key);
        if (it != m_.end()) {
            touch(it);
            q_.begin()->second = value;
        } else if (ensure_capacity()) {
            q_.emplace_front(key, value);
            m_.emplace(key, q_.begin());
        }
    }

protected:
    void touch(m_iter_t &it) {
        if (it->second != q_.begin()) {
            q_.push_front(*(it->second));
            q_.erase(it->second);
            it->second = q_.begin();
        }
    }

    bool ensure_capacity() {
        if (m_.size() >= n_ && !q_.empty()) {
            int key = q_.back().first;
            q_.pop_back();
            auto it = m_.find(key);
            if (it != m_.end()) m_.erase(it);
        }
        return m_.size() < n_;
    }
};

class LRUCache2 {
    typedef list<pair<int, int>>::iterator q_iter_t;
    typedef unordered_map<int, q_iter_t>::iterator m_iter_t;
    int n_;
    list<pair<int, int>> q_;
    unordered_map<int, q_iter_t> m_;
public:
    LRUCache2(int capacity) : n_(max(0, capacity)) {
        m_.reserve(n_); // ensure no re-hashing
    }

    int get(int key) {
        auto it = m_.find(key);
        if (it == m_.end()) return -1;
        touch(it);
        return q_.begin()->second;
    }

    void set(int key, int value) {
        auto it = m_.find(key);
        if (it == m_.end()) {
            if (ensure_capacity()) {
                q_.push_front({key, value});
                m_[key] = q_.begin();
            }
        } else {
            touch(it);
            q_.begin()->second = value;
        }
    }

protected:
    void touch(m_iter_t &it) {
        if (it->second != q_.begin()) {
            auto v = *(it->second);
            q_.erase(it->second);
            q_.push_front(v);
            it->second = q_.begin();
        }
    }

    bool ensure_capacity() {
        if (m_.size() >= n_ && !q_.empty()) {
            int key = q_.back().first;
            q_.pop_back();
            auto it = m_.find(key);
            if (it != m_.end()) m_.erase(it);
        }
        return m_.size() < n_;
    }
};

// TLE
class LRUCache1 {
    typedef unordered_map<int, int>::iterator iter_t;
    unordered_map<int, int> m_;
    list<iter_t> q_;
    int n_;
public:
    LRUCache1(int capacity) : n_(max(0, capacity)) {
        m_.reserve(n_);
    }

    int get(int key) {
        auto it = m_.find(key);
        if (it == m_.end()) return -1;
        touch(it);
        return it->second;
    }

    void set(int key, int value) {
        auto it = m_.find(key);
        if (it == m_.end()) {
            if (ensure_capacity()) {
                it = m_.insert({key, value}).first;
                add(it);
            }
        } else {
            it->second = value;
            touch(it);
        }
    }

protected:
    void add(iter_t it) {
        q_.push_front(it);
    }

    void touch(iter_t it) {
        auto i = find(q_.begin(), q_.end(), it);
        if (i != q_.begin() && i != q_.end()) {
            q_.erase(i);
            q_.push_front(it);
        }
    }

    bool ensure_capacity() {
        if (m_.size() >= n_ && !q_.empty()) {
            m_.erase(q_.back());
            q_.pop_back();
        }
        return m_.size() < n_;
    }
};


int main() {
    LRUCache c(3);
    assert(c.get(1) == -1);
    c.set(1, 1);
    assert(c.get(1) == 1);
    c.set(2, 2);
    c.set(3, 3);
    c.set(4, 4);
    assert(c.get(1) == -1);
    assert(c.get(2) == 2);
    c.set(5, 5);
    assert(c.get(2) == 2);
    assert(c.get(3) == -1);
    
    cout << "All done." << endl;
}
