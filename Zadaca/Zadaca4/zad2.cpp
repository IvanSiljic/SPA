#include "iostream"
#include <vector>

using namespace std;

void countingSort(vector<int> &list) {
    int max = list.at(0);

    for (int i = 1; i < list.size(); i++) {
        if (max < list.at(i))
            max = list.at(i);
    }

    vector<vector<int>> countList{max + 1};

    for (auto n : list)
        countList.at(n).push_back(n);

    list.clear();

    for (auto i : countList) {
        for (auto j : i)
            list.push_back(j);
    }
}

int main() {
    vector<int> list = {1, 2, 5, 2, 7, 3, 8, 1};

    countingSort(list);

    for (auto n : list) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}