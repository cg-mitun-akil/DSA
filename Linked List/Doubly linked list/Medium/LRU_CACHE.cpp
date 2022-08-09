// 2 solutions dude
// https://leetcode.com/problems/lru-cache/submissions/


class LRUCache {
public:
    int capcity;
    int size;
    queue <pair<int, int>> q;
    unordered_map<int, int>m;
    unordered_map<int, int>thime;
    int time;
    LRUCache(int capacity) {
        capcity = capacity;
        time = 0;
        size = 0;
    }

    int get(int key) {
        if (m.find(key) == m.end())
            return -1;

        thime[key] = ++time;
        q.push({ key,time });


        return m[key];
    }

    void put(int key, int value) {
        if (m.find(key) != m.end())
        {
            m[key] = value;
            thime[key] = ++time;
            q.push({ key,time });
        }
        else {
            if (size < capcity)
            {
                m[key] = value;
                thime[key] = ++time;
                q.push({ key,time });
                size++;
            }
            else {
                while (!q.empty() and thime[q.front().first] != q.front().second)
                {
                    q.pop();
                }
                int a = q.front().first;
                m.erase(a);
                thime.erase(a);
                m[key] = value;
                thime[key] = ++time;
                q.push({ key,time });
                q.pop();

            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */



// another solution 

class ddDog {
public:
    int key;
    int val;
    ddDog* prev;
    ddDog* next;
    ddDog(int key, int val) {
        this->key = key;
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map< int, ddDog* >m;
    ddDog* start;
    ddDog* end;
    int size;
    LRUCache(int capacity) {
        this->capacity = capacity;
        start = NULL;
        end = NULL;
        size = 0;
        m.clear();
    }

    int get(int key) {//cout<<"ddog"<<endl;
        if (m.find(key) == m.end())
            return -1;
        if (start == m[key])
        {
            if (start == end)
            {
                return m[key]->val;
            }
            start = m[key]->next;
            start->prev = NULL;
            end->next = m[key];
            m[key]->prev = end;
            m[key]->next = NULL;
            end = end->next;
            return end->val;
        }
        else {
            if (m[key] == end) {
                return m[key]->val;
            }
            m[key]->next->prev = m[key]->prev;
            m[key]->prev->next = m[key]->next;
            end->next = m[key];
            m[key]->prev = end;
            m[key]->next = NULL;
            end = end->next;
            return end->val;
        }
    }

    void put(int key, int value) {//cout<<"pdog";

        if (m.find(key) != m.end())
        {
            if (m[key] == start)
            {
                if (start == end)
                {
                    start->val = value;
                    return;
                }
                start = m[key]->next;
                start->prev = NULL;
                end->next = m[key];
                m[key]->prev = end;
                m[key]->next = NULL;
                end = end->next;
                end->val = value;
            }
            else {
                if (m[key] == end)
                {
                    m[key]->val = value;
                    return;
                }
                m[key]->next->prev = m[key]->prev;
                m[key]->prev->next = m[key]->next;
                end->next = m[key];
                m[key]->prev = end;
                m[key]->next = NULL;
                end = end->next;
                end->val = value;
            }
            return;
        }
        if (size == 0)
        {
            ddDog* curr = new ddDog(key, value);
            m[key] = curr;
            start = curr;
            end = curr;
            size++;
            return;
        }
        if (size < capacity)
        {
            ddDog* curr = new ddDog(key, value);
            m[key] = curr;
            end->next = curr;
            curr->next = NULL;
            curr->prev = end;
            end = end->next;
            size++;
            return;
        }
        else {
            if (start == end)
            {
                m.erase(start->key);
                m[key] = start;
                start->val = value;
                start->key = key;
                return;
            }
            m.erase(start->key);
            start = start->next;
            delete(start->prev);
            start->prev = NULL;
            ddDog* curr = new ddDog(key, value);
            m[key] = curr;
            end->next = curr;
            curr->next = NULL;
            curr->prev = end;
            end = end->next;
            return;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */