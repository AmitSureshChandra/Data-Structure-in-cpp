#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data, Node *l, Node *r) {
            this->data = data;
            left = l;
            right = r;
        }

        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};
Node* root;
Node* addNode(Node* p, Node* n) {
    if(p == NULL) return n;
    if(p->data > n->data) p->left = addNode(p->left, n);
    else p->right = addNode(p->right, n);
    return p;
}

void add(int v) {
    root = addNode(root, new Node(v));
}

void preorder(Node* n){
    if(n == NULL) return;
    cout<< n->data << " ";
    preorder(n->left);
    preorder(n->right);
}

void inorder(Node* n){
    if(n == NULL) return;
    inorder(n->left);
    cout<< n->data << " ";
    inorder(n->right);
}

void postorder(Node* n){
    if(n == NULL) return;
    postorder(n->left);
    postorder(n->right);
    cout<< n->data << " ";
}

void printMenu() {
    cout<<"~~~~~~~ Menu ~~~~~~~"<< endl;
    cout<<"1. Add node"<< endl;
    cout<<"2. preorder"<< endl;
    cout<<"3. inorder"<< endl;
    cout<<"4. postorder"<< endl;
    cout<<"8. clear screen"<< endl;
    cout<<"9. exit"<< endl;
}

int main() {
    printMenu();
    while(1) {
        cout<<"Enter your choice: ";
        char choice;
        cin >> choice;
        switch (choice){
            case '1':
                int temp;
                cout<<"Enter the node value to add : ";
                cin >> temp;
                add(temp);
                break;
            case '2':
                cout<< "Preorder : ";
                preorder(root);
                cout<< endl;
                break;
            case '3':
                cout<< "Inorder : ";
                inorder(root);
                cout<< endl;
                break;
            case '4':
                cout<< "Postorder : ";
                postorder(root);
                cout<< endl;
                break;                        
            case '8':
                system("clear"); // clear the screen
                printMenu();
                break;
            case '9':
                exit(0);
            default:
                cout<<"Invalid Choice"<< endl;
                break;
        }
    }
    return 0;
}