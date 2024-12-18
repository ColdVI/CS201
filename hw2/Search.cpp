#include <bits/stdc++.h>


#include "Search.h"
 int Search::binarySearch( int* arr, int n, int value ){
    int low = 0, high = n - 1;
    while ( low <= high ) {
        int mid = (low + high) / 2;
        if ( arr[ mid ] < value )
            low = mid + 1;
        else if ( arr[ mid ] > value )
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}
 int Search::itLinSearch(int *arr, int n, int value) {
    for ( int i = 0; i < n; i++)
        if ( arr[i] == value )
            return i;
    return -1;
}

 int Search::randomSearch(int *arr, int n, int value) {

        /* srand(time(0));
         for (int attempts = 0; attempts < 5*n; attempts++) {
             int randomIndex = rand() % n;
             if (arr[randomIndex] == value) return randomIndex;
         }
         return -1; */

     bool* indexes = new bool[n]();


     srand((time(NULL)));

     for (int i = 0; i < n; ++i) {

         int random;
         do {
             random = rand() % n;
         } while (indexes[random]);

         indexes[random] = true;

         if (arr[random] == value) {
             delete[] indexes;
             return random;
         }
     }


     delete[] indexes;
     return -1;


}

int Search::jumpSearch(int *arr, int n, int value) {
    int blockSize = sqrt(n);
    int start = 0;
    int nextBlock = sqrt(n);

    while (start < n && arr[start] < value) {
        if(start+blockSize < n){
            nextBlock = start+blockSize;
        }
        else {
            nextBlock = n;
        }
        if (arr[nextBlock - 1] >= value) {
            break;
        }
        start = nextBlock;
    }
    for (int i = start; i < nextBlock; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}


int Search::recLinSearch(int *arr, int n, int value) {

    if(n == 0){
        return -1;
    }
    if(arr[0] == value){
        return 0;
    }
    int index = recLinSearch(arr + 1, n - 1, value);
    if (index == -1) {
        return -1;
    }
    return index + 1;




}

void Search::quickSort(int *arr, int low, int high) {
    if(low<high)
    {


        int piv=partition(arr,low,high);


        quickSort(arr,low,piv-1);
        quickSort(arr,piv+1,high);
    }

}

int Search::partition(int *arr, int low, int high) {
    int i=(low-1);
    int pivot=arr[high];
    for(int j=low;j<=high;j++)
    {

        if(arr[j]<pivot)
        {

            i++;
            swap(arr[i],arr[j]);
        }

    }
    swap(arr[i+1],arr[high]);

    return (i+1);
}

void Search::swap(int &i, int &k) {

        int temp = i;
        i = k;
        k = temp;

}


