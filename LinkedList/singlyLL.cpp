#include<iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

node* createLL(int data);
void print(node *list);
node* add(int data, node *head);

int main() {
    node *head = NULL;

    head = createLL(5);
    add(7, head);
    add(6, head);
    add(4, head);

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
        return head;
    }

    //Traverse to last node
    while(head->next != NULL) {
        head = head -> next;
    }
    head->next = newData;
    return originalHead;
}