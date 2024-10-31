//
//  main.cpp
//  bubble_sort
//
//  Created by Saloxiddin Sayfuddinov on 15/10/24.
//

#include <iostream>
#include <vector>


using namespace std;

void bubble_sort(vector<int> & a, int n) {
    int tmp;
    int t_f = 0;
    int i_f = 0;
    int changes = 0;
    for (int k=n-1; k>=0; k--) {
        t_f++;
        for (int i = 0; i<=k-1; i++) {
            i_f++;
            if (a[i]>a[i+1]) {
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1]=tmp;
                changes++;
            }
        }
    }
    cout<< "bubble_sort: \n"<< endl;
    
    cout<< "solishtirish: " << t_f * i_f<< endl;
    cout<< "changes: " << changes << endl;
    
    cout<< "result: ";
    for (int i = 0; i<n; i++) {
        cout<< a[i] << " ";
    }
    cout<< "\n" <<endl;
};

int count_func(int count) {
    return count++;
}

void merge(vector<int> & arr, int left, int right, int mid, int &count) {
    int n1 = mid - left + 1; // chap
    int n2 = right - mid; // o'ng
    
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);
    
    // left
    for(int i = 0; i<n1; i++) {
        leftArr[i] = arr[left+i];
    }
    
    // o'ng
    for(int j = 0; j<n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    // 2ta massivni birlashtirish
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    
    // qolgan elementlarni qo'shish
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
    count++;
    
};

void mergeSort(vector<int> & arr, int left, int right, int &count) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid, count); // chap yarim
        mergeSort(arr, mid + 1, right, count); // o'ng yarim
        
        merge(arr, left, right, mid, count); // birlashtirish
    }
};

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    auto arrSize = arr.size();
    
    int count = 0;

    bubble_sort(arr, arrSize);
    
    mergeSort(arr, 0, arrSize - 1, count);
    
    cout<< "merge_sort: \n"<<endl;
    cout << "count: " << count_func(count) << endl;
    
    cout<<"Saralangan massiv: ";
    for (int i: arr) {
        cout<< i << " ";
    }
    cout<<endl;
    
    return 0;
}
