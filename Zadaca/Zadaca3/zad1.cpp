#include "iostream"
#include "vector"

using namespace std;

// Vremenska kompleksnost quick sort algoritma u najgorem slučaju je O(n^2),
// ali prosječna vremenska kompleksnost je bliže nlog(n)

// Prostorna kompleksnost ovog algoritma je O(n) jer je implementiran in-place

void quickSort(vector<int> &list, int s, int e) {
    if (s >= e) {
        return;
    }

    int pIndex = s + (e - s) / 2;
    int pivot = list.at(pIndex);
    swap(list.at(s), list.at(pIndex));
    pIndex = s;

    for (int i = s + 1; i <= e; i++) {
        if (list.at(i) < pivot) {
            pIndex++;
            swap(list.at(pIndex), list.at(i));
        }
    }

    swap(list.at(s), list.at(pIndex));

    quickSort(list, s, pIndex - 1);
    quickSort(list, pIndex + 1, e);
}

int main() {
    vector<int> list;
    int n = 10;

    for (int i = 0; i < n; i++) {
        list.push_back(rand() % 100);
        cout << list[i] << ", ";
    }
    cout << endl;

    quickSort(list, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << list[i] << ", ";
    }
    cout << endl;

    return 0;
}
