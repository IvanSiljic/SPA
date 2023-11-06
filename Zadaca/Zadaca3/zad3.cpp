#include "iostream"
#include "vector"

using namespace std;
using listType = int;

int binarySearch(vector<listType> &list, listType n) {
    int l = 0;
    int r = (int)list.size() - 1;

    while (l <= r) {
        int pos = l + (r - l)/2;
        if (list.at(pos) == n)
            return pos;

        if (list.at(pos) > n) {
            r = pos - 1;
        } else {
            l = pos + 1;
        }
    }

    return -1;
}

int main() {
    vector<listType> list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    listType n;

    cin >> n;

    while (n != -1) {
        cout << "Found " << n << " on: " << binarySearch(list, n) << ". index" << endl;
        cin >> n;
    }

    return 0;
}