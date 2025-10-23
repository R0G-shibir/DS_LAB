/*Traversing: carry out the following operations on a Linked List 
    a) Maximum Value 
    b) Minimum Value 
    c) Average Value 
    d) Total Value 
    e) Sin Value
*/

#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// Function to display Linked List
void display(Node* ptr) {
    cout << "\nLinked List: ";

    while (ptr != nullptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Find the max value in Linked List
int max_value(Node* ptr) {
    int max_value = ptr->data;

    while (ptr != nullptr) {
        if (max_value < ptr->data) {
            max_value = ptr->data;
        }
        ptr = ptr->next;
    }

    return max_value;
}

// Find the min value in Linked List
int min_value(Node* ptr) {
    int min_value = ptr->data;

    while (ptr != nullptr) {
        if (ptr->data < min_value) {
            min_value = ptr->data;
        }
        ptr = ptr->next;
    }

    return min_value;
}

// Find the total value of Linked List
int total_value(Node* ptr) {
    int sum = 0;

    while (ptr != nullptr) {
        sum += ptr->data;
        ptr = ptr->next;
    }

    return sum;
}

// Find the average value of Linked List
double average_value(Node* ptr) {
    int sum = 0;
    int size = 0;

    while (ptr != nullptr) {
        sum += ptr->data;
        size++;
        ptr = ptr->next;
    }

    double average = static_cast<double>(sum) / size;
    return average;
}

// Find the sine value 
void sine_value(Node* ptr) {
    cout << "Sine values of list elements:\n";
    while (ptr != nullptr) {
        cout << "sine(" << ptr->data << ") = " << sin(ptr->data) << endl;
        ptr = ptr->next;
    }
}

// Free the Linked List 
void free_list(Node* ptr) {
    while (ptr != nullptr) {
        Node* temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

int main() {
    cout << "Enter the size of Linked List: " << endl;
    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;
    
    while (n--) {
        int x;
        cin >> x;
        Node* newNode = new Node{x, nullptr};

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    display(head);

    cout << "Maximum value: " << max_value(head) << endl;
    cout << "Minimum value: " << min_value(head) << endl;
    cout << "Total value: " << total_value(head) << endl;
    cout << "Average value: " << average_value(head) << endl;
    
    sine_value(head);

    free_list(head);

}