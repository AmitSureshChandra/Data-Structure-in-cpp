#include<iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int key;
    string value;
    Node* prev;
    Node* next;
    Node(int k, string v): key(k), value(v), prev(NULL), next(NULL) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> map;
    Node* head;
    Node* tail;

public:
    LRUCache(int cap) {
        capacity = cap;
        head = NULL;
        tail = NULL;
    }

    void moveToHead(Node* node) {
        if(head == NULL) {
            head = node;
            tail = node;
        }
        if (node == head) {
            return;
        } else if (node == tail) {
            tail = node->prev;
            tail->next = NULL;
        } else {
            if(node->prev != NULL) node->prev->next = node->next;
            if(node->next != NULL) node->next->prev = node->prev;
        }

        node->next = head;
        node->prev = NULL;

        if (head != NULL) {
            head->prev = node;
        }

        head = node;

        if (tail == NULL) {
            tail = head;
        }
    }

    void removeTail() {
        if (tail == NULL) {
            return;
        }

        map.erase(tail->key);

        if (tail == head) {
            delete tail;
            head = NULL;
            tail = NULL;
        } else {
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
        }
    }
    string get(int key) {
        if (map.find(key) == map.end()) {
            return NULL;
        }

        Node* node = map[key];
        moveToHead(node);

        return node->value;
    }

    void print() {
        Node* temp = head;
        while(temp != NULL) {
            cout<< temp->value<< " ";
            temp = temp->next;
        }

        cout<< endl;
    }

    void put(int key, string value) {
        if (map.find(key) != map.end()) {
            Node* node = map[key];
            node->value = value;
            moveToHead(node);
        } else {
            Node* node = new Node(key, value);
            map[key] = node;

            if (map.size() > capacity) {
                removeTail();
            }

            moveToHead(node);
        }
    }

    void printMenu() {
        cout<<"~~~~~~~ Menu ~~~~~~~"<< endl;
        cout<<"1. add data"<< endl;
        cout<<"2. get data"<< endl;
        cout<<"7. view"<< endl;
        cout<<"8. clear screen"<< endl;
        cout<<"9. exit"<< endl;
    }

};

int main() {
    

    int capacity;
    cout<<"Enter the capacity : ";
    cin >> capacity;

    LRUCache cache(capacity); 

    cache.printMenu();

    int key;
    string value;

    while(1) {
        cout<<"Enter your choice: ";
        char choice;
        cin >> choice;
        switch (choice){
            case '1':
                cout<<"Enter the key and value to add : ";
                cin >> key;
                cin >> value;
                cache.put(key, value);
                break;

            case '2':
                cout<<"Enter the key to fetch : ";
                cin >> key;
                cout<< cache.get(key) << endl;
                break;
                      
            case '7':
                cache.print();
                break;

            case '8':
                system("clear"); // clear the screen
                cache.printMenu();
                break;

            case '9':
                exit(0);
                break;

            default:
                cout<<"Invalid Choice"<< endl;
                break;
        }
    }

    // cache.put(1, 1);
    // cache.put(2, 2);

    // cout << cache.get(1) << endl; // 1

    // cache.put(3, 3);

    // cout << cache.get(2) << endl; // -1

    // cache.put(4, 4);

    // cout << cache.get(1) << endl; // -1
    // cout << cache.get(3) << endl; // 3
    // cout << cache.get(4) << endl; // 4

    return 0;
}
