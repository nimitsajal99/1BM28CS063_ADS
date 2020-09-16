#include <bits/stdc++.h> 
using namespace std; 

class Node{ 
	public: 
	int data; 
	Node* next; 
}; 

Node *reverse (Node* head, int k) 
{ 
	Node* current = head; 
	Node* next = NULL; 
	Node* prev = NULL; 
	int count = 0; 
	
	while (current != NULL && count < k) 
	{ 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
		count++; 
	} 
	
	if (next != NULL) 
	head->next = reverse(next, k); 

    head = prev;
	return head; 
} 

Node* push(Node* head, int data){ 
	Node* new_node = new Node(); 
	new_node->data = data; 
	new_node->next = head;	 
	head = new_node; 
    return head;
} 

void display(Node* node){ 
	while (node != NULL){ 
		cout<<node->data<<" "; 
		node = node->next; 
	} 
} 

int main(){ 
	Node* head = NULL; 

	head = push(head, 9); 
	head = push(head, 8); 
	head = push(head, 7); 
	head = push(head, 6); 
	head = push(head, 5); 
	head = push(head, 4); 
	head = push(head, 3); 
	head = push(head, 2); 
	head = push(head, 1);	 

	cout<<"Original linked list \n"; 
	display(head); 

	head = reverse(head, 2); 

	cout<<"\nReversed Linked list \n"; 
	display(head); 

	return 0; 
} 

