#include <iostream>
#include <algorithm>

int getIndexOfMinElementFromArray(const int pInt[], int size);

using namespace std;

int main() {
    int k;
    cin >> k;
    int arr[k];
    for (int i = 0; i < k; ++i) {
        cin >> arr[i];
    }

    int minVotesNeededForWin = 0;
    int minGroupWinsNeeded = (k / 2) + 1;
    //find |minGroupWinsNeeded| groups with the lowest number of participants

    int allVotesForEachGroup[minGroupWinsNeeded];
    for (int i = 0; i < minGroupWinsNeeded; ++i) {
        int minElementIndex = getIndexOfMinElementFromArray(arr, k);
        allVotesForEachGroup[i] = arr[minElementIndex];
        arr[minElementIndex] = INT32_MAX;
    }
    for (int i = 0; i < minGroupWinsNeeded; ++i) {
        minVotesNeededForWin += (allVotesForEachGroup[i] / 2) + 1;
    }
    return minVotesNeededForWin;
}

int getIndexOfMinElementFromArray(const int pInt[], int size) {
    int indexMin = 0;
    for (int i = 0; i < size; ++i) {
        if (pInt[i] < pInt[indexMin]) indexMin = i;
    }
    return indexMin;
}
