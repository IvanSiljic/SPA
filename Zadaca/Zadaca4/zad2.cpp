#include "iostream"
#include <vector>

using namespace std;

void radixSort(vector<int> &list) {
    
}

int main() {
    vector<int> list = {1, 2, 5, 2, 7, 3, 8, 1};

    radixSort(list);

    for (int i = 0; i < list.size(); i++) {
        cout << list.at(i) << " ";
    }
    cout << endl;

    return 0;
}