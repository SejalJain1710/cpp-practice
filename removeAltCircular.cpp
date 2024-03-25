#include <bits/stdc++.h> 
using namespace std; 

class Node { 
    public:
    int data; 
    struct Node* next; 
};

void push(Node **head_ref, int data)  
{  
    Node *ptr1 = new Node(); 
    Node *temp = *head_ref;  
    ptr1->data = data;  
    ptr1->next = *head_ref;
    if (*head_ref != NULL)  
    {  
        while (temp->next != *head_ref)  
            temp = temp->next;  
        temp->next = ptr1;  
    }  
    else
        ptr1->next = ptr1;
  
    *head_ref = ptr1;  
}  
 

Node* removeAlternateNodes(Node* head) {
	if (head == NULL)
		return NULL;
	Node* ptr = head;
	while (true) {
		ptr->next = ptr->next->next;
		ptr = ptr->next;
		if (ptr == head || ptr->next == head)
			break;
	}
	return head;
}

void printList(Node* head) 
{ 
    Node* temp = head; 
    if (head != NULL) { 
        do { 
            cout << temp->data << " "; 
            temp = temp->next; 
        } while (temp != head); 
    }
    cout << endl;
} 

int main() 
{
    Node* head = NULL; 

    push(&head, 61); 
    push(&head, 12); 
    push(&head, 56); 
    push(&head, 2); 
    push(&head, 11); 
    push(&head, 57); 
    push(&head, 13);
    printList(head);
    cout << "\nList after deletion : " << endl; 
    Node* result = removeAlternateNodes(head);
    printList(result); 
  
    return 0; 
} 