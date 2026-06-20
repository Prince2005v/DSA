#include <iostream>
#include <vector>
using namespace std;

void mergeSortedArrays(vector<int> &arr1, vector<int> &arr2, vector<int> &merged) {
    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};
    vector<int> merged;

    mergeSortedArrays(arr1, arr2, merged);

    cout << "Merged array: ";
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

