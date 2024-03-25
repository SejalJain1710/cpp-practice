#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
    int data; 
    Node* next; 
}; 

Node* create_Node(int data) 
{ 
    Node* temp = new Node(); 
    temp->data = data; 
    temp->next = NULL; 
    return temp; 
} 

void print(Node* head) 
{ 
  
    Node* temp = head; 
    while (temp != NULL) { 
        cout << temp->data << " "; 
        temp = temp->next; 
    } 
    cout << endl; 
} 

Node* addOne(Node* head) {
    Node* last = NULL; 
    Node* cur = head;
    while (cur->next != NULL) { 
  
        if (cur->data != 9) { 
            last = cur; 
        } 
        cur = cur->next; 
    } 

    if (cur->data != 9) { 
        cur->data++; 
        return head; 
    }
    if (last == NULL) { 
        last = new Node(); 
        last->data = 0; 
        last->next = head; 
        head = last; 
    }

    last->data++; 
    last = last->next; 
  
    while (last != NULL) { 
        last->data = 0; 
        last = last->next; 
    } 
  
    return head; 
} 

int main() 
{ 
    Node* head = create_Node(9); 
    head->next = create_Node(9); 
    head->next->next = create_Node(9); 
    head->next->next->next = create_Node(9); 
  
    cout << "Original list is : "; 
    print(head);
  
    head = addOne(head); 
  
    cout << "Resultant list is : "; 
    print(head); 
  
    return 0; 
} 