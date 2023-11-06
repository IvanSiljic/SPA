#include <vector>
#include "iostream"

using namespace std;
using listType = int;

int findMax(vector<listType> &list, int n) {
    if (n <= 0 || n >= list.size() - 1)
        return -1;

    listType max = list.at(n);

    if (max > list.at(n-1) && max > list.at(n+1))
        return n;

    if (max < list.at(n+1)) {
        return findMax(list, n + n/2 + 1);
    } else {
        return findMax(list, n - n/2 - 1);
    }
}

int main() {
    vector<listType> list{1, 2, 3, 4, 5, 4, 3, 2, 1};
    int maxIndex = findMax(list, (int)list.size()/2);

    if (maxIndex != -1) {
        cout << "Found maximum element at: " << maxIndex << ". index which is: " << list.at(maxIndex) << endl;
    } else {
        cout << "List is not unimodal";
    }

    return 0;
}