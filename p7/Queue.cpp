#include<iostream>
#define LEN 10
using namespace std;

int* q = new int[LEN];
int f = -1, b = -1; // f - front, b - back

void print(){
    if(f == -1) return;
    for(int i=b; i<= f; i++) cout<< q[i] << " ";
    cout<<endl;
}

void enqueue(int v) {
    if(f + 1 == LEN){
         cout<< "Overflow" << endl;
         return;
    }
    q[++f] = v;
    cout<< v << " enqueued" << endl;
    if(b == -1) b++;
}
int dequeue() {
    if(b == -1 || b > f){
        cout<< "Underflow" << endl;
        return -1;
    }
    int v = q[b++];
    cout<< v << " dequeued" << endl;
    // below line makes it optimised with circular
    // if(b > f) b = f = -1;
    return v;
}

void front() {
    if(f == -1) return;
    cout<<q[f]<< endl;
}

void rear() {
    if(b == -1) return;
    cout<<q[b]<< endl;
}

void printMenu() {
    cout<<"~~~~~~~ Menu ~~~~~~~"<< endl;
    cout<<"1. enqueue"<< endl;
    cout<<"2. dequeue"<< endl;
    cout<<"3. front"<< endl;
    cout<<"4. rear"<< endl;
    cout<<"7. view"<< endl;
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
                cout<<"Enter the value to enqueue : ";
                cin >> temp;
                enqueue(temp);
                break;
            case '2':
                dequeue();
                break;
            case '3':
                front();
                break;
            case '4':
                rear();
                break;                        
            case '7':
                print();
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
