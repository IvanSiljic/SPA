#include "iostream"
#include<vector>

using namespace std;

int canSplit(vector<int> &list, int k, long long sum) {
    long long cur = 0;
    int cnt = 1;

    for (int i = 0; i < list.size(); i++) {
        if (list.at(i) > sum)
            return false;
        if (cur + list.at(i) < sum)
            return true;
        // TODO finish this
    }

    return 0;
}

int main() {
    vector<int> list = {2, 4, 7, 3, 5};

    cout << maxSum(list, 5, 3);

    return 0;
}