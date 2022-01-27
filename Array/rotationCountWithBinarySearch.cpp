/*Find the rotation count in sorted rotated array with 
Binary search O(log n) instead of linear search O(n)
*/
#include<stdio.h>

int binarySearch(int ar[], int l, int r) {
    // printf("%d %d\n", l, r);
    int mid = (l+r)/2;
    if (ar[l] < ar[mid] && ar[mid] < ar[r]) {
        return 0;
    } else if (r-l == 1) {
        return r;
    }


    if(ar[l] > ar[mid]) {
        return binarySearch(ar, l, mid);
    } else {
        return binarySearch(ar, mid, r);
    }
}

int main () {
    int ar[] = {6,7,8,9,1,2,3,4,5};
    int size = sizeof(ar)/sizeof(ar[0]);

    printf("Rotation count with Binary Search is %d\n", size - binarySearch(ar, 0, size-1));
    return 0;
}