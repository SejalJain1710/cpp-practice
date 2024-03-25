#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node (int d) {
        data = d;
        next = NULL;
    }
};

void insertAtHead(node* &head, int data) {
    node* n = new node(data);
    n -> next = head;
    head = n;
}

void print(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int kthNodeFromLast(node* head, int k) {
    node *fast = head;
    node *slow = head;
    while (k--)
        fast = fast->next;
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}

int main() {
    node* head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 7);
    insertAtHead(head, 9);
    print(head);
    cout << kthNodeFromLast(head, 2) << endl;
    return 0;
}
