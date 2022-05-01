//
// Created by 17412 on 2022/4/18.
//
#include <vector>
using namespace std;
#ifndef MYDATASTRUCT_SORT_H
#define MYDATASTRUCT_SORT_H

//bubble sort
    void BubbleSort(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n-1; i++){
            int exchange = false;
            for(int j = n-1; j > i; j--){
                if(a[j] < a[j-1]){
                    int t = a[j];a[j] = a[j-1];a[j-1]=t;
                    exchange = true;
                }
            }
            if (exchange == false) return;
        }
    }

    //插入排序
    vector<int> InsertSort(vector<int>& a) {
        auto n = a.size();
        int temp , j;
        if(n <= 1) return a;
        for (int i = 1; i < n; i++) {
            if(a[i] < a[i-1]) {
                temp = a[i];j = i-1;
                do{
                    a[j+1] = a[j];j--;
                }while(a[j] > temp&&j>=0);
                a[j] = temp;
            }
        }
        return a;
    }

    //折半插入排序
    void BinaryInsertSort(vector<int>& a) {
        auto n = a.size();
        int left , right,temp, mid;
        if(n <= 1) return;
        for (int i = 1; i < n; i++) {
            left = 0;right = i; temp = a[i];
            while( left <= right) {
                mid = (left + right)/2;
                if(temp >= mid) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            for(int k = i; k > right; k--) {
                a[k] = a[k-1];
            }
            a[right] = temp;
        }
    }

    //希尔排序
    void ShellSort(vector<int>& a) {
        int d,i,j,n = a.size();
        for (d = n/2; d >= 1; d = d/2) {
            for ( i = d; i < n; i++) {
                if (a[i] < a[i-d]) {
                    int temp = a[i];
                    for (j = i-d; j >= 0&&a[j]>a[j+d]; j-=d)
                        a[j+d] = a[j];
                    a[j+d] = temp;
                }
            }
        }
    }
    //快排
    int GetPriovt(vector<int>& a,int low, int high) {
        int temp = a[low];
        while (low < high) {
            while ( low < high&&temp<=a[high]) high--;
            a[low] = a[high];
            while ( low < high&& temp>=a[high]) low++;
            a[high] = a[low];
        }
        a[low] = temp;
        return low;
    }

    void QuickSort(vector<int>& a, int low, int high) {
        if (low < high) {
            int p = GetPriovt(a,low,high);
            QuickSort(a,low,p-1);
            QuickSort(a,p+1,high);
        }
    }

    //堆排序   堆排序以A[1]开始  原因在完全二叉树中当前节点i的左右子女分别为 2*i 和 2*i+1  因此根节点不能以A[0]作为第一个节点
    void HeapAdjust(vector<int>& a,int k, int len) {
        int temp = a[k];
        for (int i=2*k;i <= len; i = i*2) {
            if(i < len&& a[i]<a[i+1]) i++;
            if (temp>a[i]) break;
            else {
                a[k] = a[i];
                k = i;
            }
        }
        a[k] = temp;
    }

    void BuildMaxHeap (vector<int>& a, int len) {
        for (int i = len/2; i>0;i--) {
            HeapAdjust(a, i,len);
        }
    }

    void HeapSort (vector<int>& a, int len) {
        BuildMaxHeap(a, len);
        for (int i = len; i >=1; i--) {
            int t = a[1];
            a[1] = a[i];
            a[i] = t;
            HeapAdjust(a, 1, i-1);
        }
    }
    //归并排序
    void Merge(vector<int>& a, int low,int mid, int high) {
        vector<int> b;
        int i,j;
        for (int k=low; k<=high;k++) {
            b[k] = a[k];
        }
        int k;
        for (i = low,j = mid+1,k=i;i<=mid&&j<=high;k++) {
            if(b[j] < b[i]) {
                a[k] = b[j];
                j++;
            } else {
                a[k] = b[i];
                i++;
            }
        }
        while(j<=high) a[k++] = b[j++];
        while(i<=mid) a[k++] = b[i++];
    }

    void MergeSort (vector<int>& a, int low, int high) {
        if (low<high) {
            int mid = (low+high)/2;
            MergeSort(a,low,mid);
            MergeSort(a,mid+1,high);
            Merge(a,low,mid,high);
        }=
    }




#endif //MYDATASTRUCT_SORT_H






























