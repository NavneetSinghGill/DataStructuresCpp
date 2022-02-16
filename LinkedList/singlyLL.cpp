#include<iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

node* createLL(int data);
void print(node *list);
node* add(int data, node *head);
void deleteLast(node **head);

int main() {
    node *head = NULL;

    head = createLL(5);
    // add(7, head);
    // add(6, head);
    // add(4, head);
    print(head);
    deleteLast(&head);
    head = createLL(99);
    print(head);

    return 0;
}

void print(node *list) {
    node *traversalPointer = list;

    while(traversalPointer != NULL) {
        cout << traversalPointer->data;
        if(traversalPointer->next != NULL) {
            cout << " -> ";
        }

        traversalPointer = traversalPointer->next;
    }
    cout << endl;
}

node* createLL(int data) {
    return add(data, NULL);
}

node* add(int data, node *head) {
    node *originalHead = head;
    //Create node to be added
    struct node *newData = (node*)malloc(sizeof(node));
    newData->data = data;
    newData->next = NULL;

    //head is NULL only when linked list is empty
    if(head == NULL) {
        head = newData;
        cout << "Add " << data << " to newly created singly linked list" << endl;
        return head;
    }

    //Traverse to last node
    while(head->next != NULL) {
        head = head -> next;
    }
    head->next = newData;
    cout << "Add " << data << " to singly linked list" << endl;
    return originalHead;
}

//Used double pointer to set head to NULL when no elements are present
void deleteLast(node **head) {
    if(*head != NULL) {
        node* prev = NULL;
        while((*head) -> next != NULL) {
            prev = *head;
            *head = (*head) -> next;
        }
        if(prev != NULL) {
            prev->next = NULL;
        }
        if(*head != NULL) {
            cout << "Delete " << (*head)->data << " from end of singly linked list" << endl;
            free(*head);
            *head = NULL;
        }
    }
}