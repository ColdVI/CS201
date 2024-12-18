//
// Created by user on 18.11.2024.
//

#ifndef CS201_HW2_SEARCH_H
#define CS201_HW2_SEARCH_H


class Search {
public:
    static int binarySearch(int* arr, int n, int value);
    static int itLinSearch(int* arr, int n, int value);
    static int recLinSearch(int* arr, int n, int value);
    static int jumpSearch(int* arr, int n, int value);
    static int randomSearch(int* arr, int n, int value);
    static void quickSort(int arr[], int low, int high);
    static int partition(int arr[], int low, int high);

private:
    static void swap(int &i, int& k);
};


#endif //CS201_HW2_SEARCH_H
