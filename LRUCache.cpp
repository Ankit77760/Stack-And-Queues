class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node *newNode)
    {
        node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(node *delNode)
    {
        node *delPrev = delNode->prev;
        node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            node *resNode = m[key];
            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            m[key] = head->next;
            return resNode->val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            node *existingNode = m[key];
            m.erase(key);
            deleteNode(existingNode);
        }

        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key, value));
        m[key] = head->next;
    }
};
