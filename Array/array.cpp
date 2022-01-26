#include<stdio.h>
void rotateLeft(int ar[], int d, int n) {
    int store;
    while(d-- && n > 1) {
        store = ar[0];
        for( int i = 1; i < n; i++ ) {
            ar[i-1] = ar[i];
        }
        ar[n-1] = store;
    }
}

void print(int ar[], int n) {
    for( int i = 1; i < n; i++ ) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

int main () {
    int ar[] = {1,2,3,4,5,6,7,8};
    int size = sizeof(ar)/sizeof(ar[0]);

    rotateLeft(ar,2,size);
    print(ar, size);
    return 0;
}