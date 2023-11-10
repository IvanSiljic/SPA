#include "iostream"
#include "vector"

using namespace std;

void radixHelp(vector<int> &list, int d, int max) {
    if (max / d == 0)
        return;

    vector<vector<int>> cList{10};

    for (auto n : list)
        cList.at((n/d)%10).push_back(n);

    list.clear();
    for (auto i : cList) {
        for (auto j : i)
            list.push_back(j);
    }

    radixHelp(list, d*10, max);
}

void radixSort(vector<int> &list) {
    int max = list.at(0);

    for (int i = 1; i < list.size(); i++) {
        if (max < list.at(i))
            max = list.at(i);
    }

    radixHelp(list, 10, max);
}

int main() {
    vector<int> list = {100, 299, 512, 226, 73, 365, 84, 155};

    radixSort(list);

    for (auto n : list) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}