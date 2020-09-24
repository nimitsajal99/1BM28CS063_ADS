#include<iostream>
#include<string>
#include<inttypes.h>

using namespace std;

class Node{
    public:
        int data;
        Node* npx;
};

Node* XOR(Node* a, Node* b){
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

Node* insertBeginning(Node* head, int data){
    Node* newNode = new Node();
    newNode->data = data;

    newNode->npx = head;

    if(head != NULL){
        head->npx = XOR(newNode, head->npx);
    }

    head = newNode;

    return head;
}

Node* insertEnd(Node* head, int data){
    Node* newNode = new Node();
    newNode->data = data;

    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    if(curr == NULL){
        head = insertBeginning(head, data);
    }
    else{
        while(curr->npx != prev){
            next = XOR(prev, curr->npx);
            prev = curr;
            curr = next;
        }
        newNode->npx = curr;
        curr->npx = XOR(newNode, curr->npx);
    }

    return head;
}

Node* deleteBeginning(Node* head){
    if(head == NULL){
        cout<<"Empty List."<<endl;
    }
    else{
        Node* temp = head;
        Node* next = NULL;
        temp = head->npx;
        next = XOR(head, temp->npx);
        temp->npx = next;
        free(head);
        head = temp;
    }
    
    return head;
}

Node* deleteEnd(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* temp = NULL;
    Node* next;

    while(curr->npx != prev){
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    
    temp = XOR(curr, prev->npx);
    prev->npx = temp;
    free(curr);
    return head;
}

void display(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next;

    if(curr == NULL){
        cout<<"Empty List."<<endl;
    }   

    else{
        while(curr != NULL){
            cout<<curr->data<<" -> ";
            next = XOR(prev, curr->npx);
            prev = curr;
            curr = next;
        }
        cout<<endl;
    }
}

// int main(){
//     Node* head = NULL;
//     display(head);
//     head = insertBeginning(head, 11);
//     head = insertBeginning(head, 22);
//     head = insertBeginning(head, 33);
//     display(head);
//     head = insertEnd(head, 44);
//     head = insertEnd(head, 55);
//     head = insertEnd(head, 66);
//     display(head);
//     head = deleteBeginning(head);
//     head = deleteBeginning(head);
//     head = deleteBeginning(head);
//     display(head);
//     head = deleteEnd(head);
//     head = deleteEnd(head);
//     display(head);

//     return 0;
// }

int main(){
    Node* head = NULL;
    int select, value;
    bool isRunning = true;
    while(isRunning == true){
        cout<<"Select the Operation :"<<endl;
        cout<<"[1] INSERT AT BEGINNING"<<endl;
        cout<<"[2] INSERT AT END"<<endl;
        cout<<"[3] DELETE FROM BEGINNING"<<endl;
        cout<<"[4] DELETE FROM END"<<endl;
        cout<<"[5] DISPLAY"<<endl;
        cout<<"[6] END"<<endl<<endl;
        cin>>select;
        switch(select){
            case 1:
                cout<<"Enter Value to be Inserted :"<<endl;
                cin>>value;
                head = insertBeginning(head, value);
                break;

            case 2:
                cout<<"Enter Value to be Inserted :"<<endl;
                cin>>value;
                head = insertEnd(head, value);
                break;
            
            case 3:
                head = deleteBeginning(head);
                break;

            case 4:
                head = deleteBeginning(head);
                break;

            case 5:
                display(head);
                break;

            case 6:
                isRunning = false;
                break;

            default:
                cout<<"Wrong Input"<<endl;
        }
    }
    return 0;
}