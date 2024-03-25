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

node* merge(node* head1, node* head2) {
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    if (head1->data < head2->data) {
        head1->next = merge(head1->next, head2);
        return head1;
    }
    else {
        head2->next = merge(head1, head2->next);
        return head2;
    }
}

void print(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node* head1 = NULL;
    node* head2 = NULL;
    insertAtHead(head1, 9);
    insertAtHead(head1, 8);
    insertAtHead(head1, 5);
    insertAtHead(head1, 4);
    insertAtHead(head1, 2);
    print(head1);
    insertAtHead(head2, 15);
    insertAtHead(head2, 14);
    insertAtHead(head2, 13);
    insertAtHead(head2, 7);
    insertAtHead(head2, 3);
    print(head2);
    node* result = merge(head1, head2);
    print(result);
    return 0;
}
