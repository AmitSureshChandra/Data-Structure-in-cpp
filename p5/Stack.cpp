#include<iostream>
#define size 10

using namespace std;

int* stack = new int[size];
int top = -1;

void push(int temp) {
    if(top + 1 >= size) 
        cout<<"Overflow" << endl;
    else
        stack[++top] = temp;
}

void pop(){
    if(top == -1) cout<<"Underflow"<< endl;
    else cout<<"popped : "<< stack[top--] << endl;
}

void print(){
    for(int i=0; i<= top; i++) cout<< stack[i] << " ";
    cout<< endl;
}

void printTop() {
    if(top == -1) return;
    cout<<"top : " << stack[top]<< endl;
}

void printMenu() {
    cout<<"~~~~~~ Menu ~~~~~~~" << endl;
    cout<<"1. push"<< endl;
    cout<<"2. pop"<< endl;
    cout<<"3. print"<< endl;
    cout<<"4. top"<< endl;

    cout<<"8. clear screen"<< endl;
    cout<<"9. exit"<< endl;
}

int main() {
    int temp;
    printMenu();

    while(1){
        char choice;
        cout<<"Choose your choice : ";
        cin >> choice;

        switch(choice) {
            case '1': 
                cout<<"Enter data : ";
                cin>> temp;
                push(temp);
                break;
            case '2':
                pop();
                break;
            case '3':
                print();
                break;
            case '4':
                printTop();
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