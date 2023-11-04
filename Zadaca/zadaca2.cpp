//
// Created by isiljic on 10/22/23.
//

#include <iostream>
using namespace std;

void merge(int A[], int l, int m, int n) {
    int start = m + 1;

    if (A[m] <= A[start]) {
        return;
    }

    while (l <= m && start <= n) {
        if (A[l] <= A[start]) {
            l++;
            continue;
        }

        int value = A[start];
        int index = start;

        while (index != l) {
            A[index] = A[index - 1];
            index--;
        }
        A[l] = value;

        l++;
        m++;
        start++;
    }
}

void mergeSort(int A[], int l, int n) {
    if (l == n) {
        return;
    }

    int m = l + (n - l)/2;

    mergeSort(A, l, m);
    mergeSort(A, m+1, n);

    merge(A, l, m, n);
}



int main() {
    int array[5] = {1,2,3,4,5};

    mergeSort(array, 0, 5);

    cout << array[0] << ", " << array[1] << ", " << array[2] << ", " << array[3] << ", " << array[4] << ", " << endl;
}
