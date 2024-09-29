#include <iostream>
#include <map>
#include <set>
#include <string>

class Node
{
public:
    int freq;
    Node *next;
    Node *prev;
    std::set<std::string> bucket;

    Node(int frequency) : freq(frequency), next(nullptr), prev(nullptr) {}
};

class AllOne
{
private:
    Node *head;
    Node *tail;
    std::map<std::string, Node *> keyToNodeMap; // Maps keys to their corresponding nodes

    // Helper function to remove a node from the linked list
    void removeNode(Node *node)
    {
        if (node == head)
        {
            head = head->next;
            if (head)
                head->prev = nullptr;
        }
        else if (node == tail)
        {
            tail = tail->prev;
            if (tail)
                tail->next = nullptr;
        }
        else
        {
            if (node->prev)
                node->prev->next = node->next;
            if (node->next)
                node->next->prev = node->prev;
        }
        delete node;
    }

public:
    AllOne() : head(nullptr), tail(nullptr) {}

    void inc(const std::string &key)
    {
        // If the key doesn't exist, initialize it with frequency 1
        if (keyToNodeMap.find(key) == keyToNodeMap.end())
        {
            if (!head)
            { // Empty list
                head = new Node(1);
                tail = head;
                head->bucket.insert(key);
            }
            else if (head->freq == 1)
            { // Head has frequency 1
                head->bucket.insert(key);
            }
            else
            { // Create new head for frequency 1
                Node *newNode = new Node(1);
                newNode->bucket.insert(key);
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            keyToNodeMap[key] = head; // Map key to node
        }
        else
        {
            // Key exists; increase its frequency
            Node *currentNode = keyToNodeMap[key];
            int currentFreq = currentNode->freq;
            currentNode->bucket.erase(key);

            // If there's a next node with the incremented frequency
            if (currentNode->next && currentNode->next->freq == currentFreq + 1)
            {
                currentNode->next->bucket.insert(key);
                keyToNodeMap[key] = currentNode->next; // Update mapping
            }
            else
            {
                // Create a new node for the incremented frequency
                Node *newNode = new Node(currentFreq + 1);
                newNode->bucket.insert(key);
                newNode->next = currentNode->next;
                if (currentNode->next)
                {
                    currentNode->next->prev = newNode;
                }
                currentNode->next = newNode;
                newNode->prev = currentNode;

                if (newNode->next == nullptr)
                { // Update tail if needed
                    tail = newNode;
                }
                keyToNodeMap[key] = newNode; // Update mapping
            }
            if (currentNode->bucket.empty())
            {
                removeNode(currentNode);
            }
        }
    }

    void dec(const std::string &key)
    {
        auto it = keyToNodeMap.find(key);
        if (it == keyToNodeMap.end())
            return; // Key doesn't exist

        Node *currentNode = it->second;
        int currentFreq = currentNode->freq;
        currentNode->bucket.erase(key);

        if (currentFreq == 1)
        {
            // Frequency is 1; remove the key from the structure
            keyToNodeMap.erase(key);
        }
        else
        {
            // Handle decrementing the frequency
            Node *prevNode = currentNode->prev;
            if (prevNode && prevNode->freq == currentFreq - 1)
            {
                // Previous node exists and has the expected frequency
                prevNode->bucket.insert(key);
                keyToNodeMap[key] = prevNode; // Update mapping
            }
            else
            {
                // Create a new node for the decremented frequency
                Node *newNode = new Node(currentFreq - 1);
                newNode->bucket.insert(key);
                newNode->next = currentNode;
                newNode->prev = prevNode;

                if (prevNode)
                {
                    prevNode->next = newNode;
                }
                currentNode->prev = newNode;

                if (currentNode == head)
                { // Update head if necessary
                    head = newNode;
                }
                keyToNodeMap[key] = newNode; // Update mapping
            }
        }

        // Clean up the current node if it has no keys left
        if (currentNode->bucket.empty())
        {
            removeNode(currentNode);
        }
    }

    std::string getMaxKey()
    {
        // Return the first element in the tail's bucket if it exists
        if (tail && !tail->bucket.empty())
        {
            return *tail->bucket.begin();
        }
        return ""; // Return empty string if no keys exist
    }

    std::string getMinKey()
    {
        // Return the first element in the head's bucket if it exists
        if (head && !head->bucket.empty())
        {
            return *head->bucket.begin();
        }
        return ""; // Return empty string if no keys exist
    }
};
