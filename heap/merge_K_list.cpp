#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Min heap comparator
struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;   // min heap
    }
};

// Merge K Lists function
Node* mergeKLists(vector<Node*>& lists) {

    priority_queue<Node*, vector<Node*>, compare> pq;

    // Push all heads into heap
    for (Node* head : lists) {
        if (head != NULL) {
            pq.push(head);
        }
    }

    Node* dummy = new Node(0);
    Node* tail = dummy;

    // Process heap
    while (!pq.empty()) {
        Node* temp = pq.top();
        pq.pop();

        tail->next = temp;
        tail = tail->next;

        if (temp->next != NULL) {
            pq.push(temp->next);
        }
    }

    return dummy->next;
}

// Print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // List 1: 1 -> 4 -> 5
    Node* l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(5);

    // List 2: 1 -> 3 -> 4
    Node* l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);

    // List 3: 2 -> 6
    Node* l3 = new Node(2);
    l3->next = new Node(6);

    vector<Node*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    Node* result = mergeKLists(lists);

    cout << "Merged List: ";
    printList(result);

    return 0;
}