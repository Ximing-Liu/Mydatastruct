#include <iostream>
#include "sort.h"


int main() {
    vector<int> a = {1,3,4,5,6,3,4,5};
    int n = a.size();
    //ShellSort(a);
//    int l = 0, h = a.size()-1;
//    QuickSort(a,l,h);
    HeapSort(a, n-1);
    for(int i : a) {
        cout << i << endl;
    }
    return 0;
}
