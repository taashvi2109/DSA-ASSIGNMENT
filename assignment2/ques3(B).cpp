#include <iostream>
using namespace std;
int findMissing(int arr[], int n) {
    int start= 0, end = n - 2;
    while (start<=end) {
        int mid = (start+ end) / 2;
        if (arr[mid] == mid + 1) {
            start = mid + 1;
            end = mid - 1;
        }
    }
    return start + 1;
}
int main() {
    int arr[] = {1, 2, 3, 5, 6, 7};
    int n = 7;
    cout << "Missing number is " << findMissing(arr, n) << endl;
    return 0;
}
