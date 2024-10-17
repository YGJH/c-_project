#include<stdlib.h>
#include<stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {  // Changed < to >
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int search(int arr[], int tar, int l, int r) {
    if (l >= r) {
        return (arr[l] == tar) ? l : -1;
    }
    int mid = (l + r) >> 1;
    if (arr[mid] > tar) {
        return search(arr, tar, l, mid);
    }
    else {
        return search(arr, tar, mid + 1, r);
    }
}

int main() {
    int tar;
    scanf("%d", &tar);
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    
    printf("%d\n", search(arr, tar, 0, n - 1));
    return 0;
}