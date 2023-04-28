#include<iostream>
using namespace std;

class LinkedList {
    public: 

    int data;
    LinkedList *next;

    LinkedList(int v, LinkedList* next) {
        data = v;
        this->next = next;
    }
};

int length = 0;
LinkedList* head, * tail;

void print(){
    for(LinkedList *temp = head; temp != NULL;temp = temp->next) cout<< temp->data << " ";
    cout<<endl;
}

int search(int v) {
    LinkedList *temp = head;
    for(int pos= 0; temp != NULL; pos++, temp = temp->next) if(v == temp->data) return pos;
    return -1;
}

void insert(int val, int pos) {
    if(pos > length) return;
    if(pos == 0){ // insert at start
        head = new LinkedList(val, head);
        if(tail == NULL) tail = head;
    }
    else if(pos == length){   // insert at last
        tail->next = new LinkedList(val, NULL);
        tail = tail->next;
    }else {
        LinkedList *temp = head;
        for(;pos > 0; pos--, temp = temp->next) temp = temp->next;
        temp->next = new LinkedList(val, temp->next);
    }
    length++;
}

void removeAt(int pos) {
    if(length == 0) {
        cout<<"empty so can't remove" << endl;
        return;
    }
    if(pos < 0) return;
    if(pos == 0) head = head->next;
    else {
        LinkedList *temp = head;
        for(;pos > 1; pos--, temp = temp->next);
        temp->next = temp->next == NULL ? NULL : temp->next->next;
    }
    length--;
}


void removeVal(int v) {
    int pos = search(v);
    if(pos == -1) cout<<"Not Found"<< endl;
    else removeAt(pos);
}

int main() {

    cout<<"~~~~~~~ Menu ~~~~~~~"<< endl;
    cout<<"1. insert at any pos"<< endl;
    cout<<"2. insert at start"<< endl;
    cout<<"3. insert at end"<< endl;
    cout<<"4. remove value"<< endl;
    cout<<"5. remove start"<< endl;
    cout<<"6. remove end"<< endl;
    cout<<"7. view"<< endl;
    cout<<"8. clear screen"<< endl;
    cout<<"9. exit"<< endl;

    while(1) {

        cout<<"Enter your choice: ";
        char choice;
        cin >> choice;

        switch (choice)
        {
        case '1':
            int temp;
            cout<<"Enter the value to insert : ";
            cin >> temp;

            int pos;
            cout<<"Enter the position (index 1 based) : ";
            cin >> pos;
            if(pos > length+1) cout<< "out of bound .. cannot insert at " << pos << endl;
            else insert(temp, --pos);
            break;

        case '2':
            cout<<"Enter the value to insert : ";
            cin >> temp;
            insert(temp, 0);
            break;

        case '3':
            cout<<"Enter the value to insert : ";
            cin >> temp;
            insert(temp, length == 0 ? 0 : length);
            break;

        case '4':
            cout<<"Enter the value to remove : ";
            cin >> temp;
            removeVal(temp);
            break;
        case '5':
            removeAt(0);
            break;
        case '6':
            removeAt(length-1);
            break;
        case '7':
            print();
            break;
        case '8':
            system("clear"); // clear the screen

            cout<<"\n~~~~~~~ Menu ~~~~~~~"<< endl;
            cout<<"1. insert at any pos"<< endl;
            cout<<"2. insert at start"<< endl;
            cout<<"3. insert at end"<< endl;
            cout<<"4. remove value"<< endl;
            cout<<"5. remove start"<< endl;
            cout<<"6. remove end"<< endl;
            cout<<"7. view"<< endl;
            cout<<"8. clear screen"<< endl;
            cout<<"9. exit"<< endl;
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
