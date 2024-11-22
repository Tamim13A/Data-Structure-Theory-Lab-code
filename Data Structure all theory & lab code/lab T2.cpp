Q2) insert Abdullah after Tamim
--------------------------------

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int address;
    Node* next;
};

void printList(Node* head) {
    for (Node* temp = head; temp; temp = temp->next)
        cout << temp->name << " (" << temp->address << ") -> ";
    cout << "NULL" << endl;
}

void insertAfter(Node* head, const string& target, const string& newNode, int newAddress) {
    while (head) {
        if (head->name == target) {
            head->next = new Node{newNode, newAddress, head->next};
            return;
        }
        head = head->next;
    }
    cout << "Node with name '" << target << "' not found!" << endl;
}

int main() {
    Node* head = new Node{"Mehedi", 1, new Node{"Israfil", 2, new Node{"Tamim", 3, new Node{"Faruk", 4, nullptr}}}};

    cout << "Single Linked List before insertion: " << endl;
    printList(head);

    insertAfter(head, "Tamim", "Abdullah", 5);

    cout << "\nSingle Linked List after insertion: " << endl;
    printList(head);

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

Q3) delete the name tamim from the linked list based ont he scenario.
-------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    int address;
    Node* next;
};

void printList(Node* head) {
    while (head) {
        cout << head->name << " (" << head->address << ") -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void deleteNodeByName(Node*& head, const string& nameToDelete) {
    Node** current = &head;
    while (*current) {
        if ((*current)->name == nameToDelete) {
            Node* temp = *current;
            *current = (*current)->next;
            delete temp;
            return;
        }
        current = &((*current)->next);
    }
    cout << "Node with name '" << nameToDelete << "' not found!" << endl;
}

int main() {
    Node* head = new Node{"Mehedi", 1, new Node{"Israfil", 2, new Node{"Tamim", 3, new Node{"Abdullah", 5, new Node{"Faruk", 4, nullptr}}}}};

    cout << "Single Linked List before deletion: " << endl;
    printList(head);

    deleteNodeByName(head, "Tamim");

    cout << "\nSingle Linked List after deletion: " << endl;
    printList(head);

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}


Q4)Display the name in reverse order.
---------------------------------------
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node(string n) : name(n), next(nullptr) {}
};

void display(Node* head, bool reverse = false) {
    if (!reverse) {
        for (Node* temp = head; temp; temp = temp->next)
            cout << temp->name << " -> ";
    } else {
        stack<string> s;
        for (Node* temp = head; temp; temp = temp->next)
            s.push(temp->name);
        while (!s.empty()) {
            cout << s.top() << " -> ";
            s.pop();
        }
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node("Mehedi");
    head->next = new Node("Israfil");
    head->next->next = new Node("Abdullah");
    head->next->next->next = new Node("Faruk");

    cout << "Main linked list: ";
    display(head);

    cout << "\nAfter Reversing the list: ";
    display(head, true);

    return 0;
}

