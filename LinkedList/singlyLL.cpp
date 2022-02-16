#include<iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

void print(node *list);
void add(int data, node **head);
void deleteLast(node **head);

int main() {
    node *head = NULL;

    add(5, &head);
    add(7, &head);
    add(6, &head);
    deleteLast(&head);
    add(9, &head);
    add(1, &head);
    deleteLast(&head);
    deleteLast(&head);
    deleteLast(&head);
    deleteLast(&head);

    return 0;
}

void print(node *list) {
    node *traversalHead = list;

    while(traversalHead != NULL) {
        cout << traversalHead->data;
        if(traversalHead->next != NULL) {
            cout << " -> ";
        }

        traversalHead = traversalHead->next;
    }
    if(list == NULL) {
        cout << "Nothing to print";
    }
    cout << endl;
}

void add(int data, node **head) {
    node *traversalHead = *head;
    //Create node to be added
    node *newData = (node*)malloc(sizeof(node));
    newData->data = data;
    newData->next = NULL;

    //head is NULL only when linked list is empty
    if(*head == NULL) {
        *head = newData;
        // cout << "Added " << data << ": ";
        print(*head);
        return;
    }

    //Traverse to last node
    while((traversalHead)->next != NULL) {
        traversalHead = traversalHead -> next;
    }
    traversalHead->next = newData;
    // cout << "Added " << data << ": ";
    print(*head);
}

//Used double pointer to set head to NULL when no elements are present
void deleteLast(node **head) {
    if(*head != NULL) {
        node *traversalHead = *head;
        node* prev = NULL;
        while(traversalHead -> next != NULL) {
            prev = traversalHead;
            traversalHead = traversalHead -> next;
        }
        if(prev != NULL) {
            prev->next = NULL;
        }
        if(traversalHead != NULL) {
            // cout << "Deleted " << traversalHead->data << ": ";

            //This condition satisfies when we delete the only element in the list
            if(*head == traversalHead) {
                *head = NULL;
            }
            free(traversalHead);

            print(*head);
        }
    }
}