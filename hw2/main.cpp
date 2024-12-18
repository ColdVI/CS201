#include <iostream>
#include "Search.h"
#include <chrono>
#include <cmath>
void search(int arr[], int n){
    std::chrono::time_point< std::chrono::system_clock > startTime;
    std::chrono::duration< double, std::milli > elapsedTime;
    int index;
    int nearFirst = arr[0];
    int nearMiddle = arr[n / 2];
    int nearLast = arr[n - 1];
    int noKey = 100 * n; // A value guaranteed not to exist

    int loopcounter{1};

    //--------------------------nearFirst-nearMiddle-NearLast respectively--------------------------------------------------//

    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::jumpSearch(arr, n, nearFirst);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "JUMP SEARCH with nearFirst took " << elapsedTime.count() << " milliseconds." << std::endl;


    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::jumpSearch(arr, n, nearMiddle);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "JUMP SEARCH with nearMiddle took " << elapsedTime.count() << " milliseconds." << std::endl;


    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::jumpSearch(arr, n, nearLast);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "JUMP SEARCH with nearLast took " << elapsedTime.count() << " milliseconds." << std::endl;


    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::jumpSearch(arr, n, noKey);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "JUMP SEARCH with noKey took " << elapsedTime.count() << " milliseconds. \n" << std::endl;

    //-------------------------


    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++) {
        index = Search::itLinSearch(arr, n, nearFirst);
    }
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Iterative LinearSearch with nearFirst took " << elapsedTime.count() << " milliseconds."
              << std::endl;


    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::itLinSearch(arr, n, nearMiddle);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Iterative LinearSearch with nearMiddle took " << elapsedTime.count() << " milliseconds."
              << std::endl;


    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::itLinSearch(arr, n, nearLast);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Iterative LinearSearch with NearLast took " << elapsedTime.count() << " milliseconds."
              << std::endl;
    ;

    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::itLinSearch(arr, n, noKey);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Iterative LinearSearch with noKey took " << elapsedTime.count() << " milliseconds.\n"
              << std::endl;


    //----------------------------

    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::recLinSearch(arr, n, nearFirst);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Recursive LinearSearch with nearFirst took " << elapsedTime.count() << " milliseconds."
              << std::endl;

    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::recLinSearch(arr, n, nearMiddle);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Recursive LinearSearch with nearMiddle took " << elapsedTime.count() << " milliseconds."
              << std::endl;

    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::recLinSearch(arr, n, nearLast);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Recursive LinearSearch with NearLast took " << elapsedTime.count() << " milliseconds."
              << std::endl;

    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::recLinSearch(arr, n, noKey);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Recursive LinearSearch with noKey took " << elapsedTime.count() << " milliseconds.\n"
              << std::endl;

    //-----------------------------

    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::binarySearch(arr, n, nearFirst);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Binary Search with nearFirst took " << elapsedTime.count() << " milliseconds." << std::endl;

    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::binarySearch(arr, n, nearMiddle);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Binary Search with nearMiddle took " << elapsedTime.count() << " milliseconds." << std::endl;

    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::binarySearch(arr, n, nearLast);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Binary Search with nearLast took " << elapsedTime.count() << " milliseconds." << std::endl;

    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::binarySearch(arr, n, noKey);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Binary Search with noKey took " << elapsedTime.count() << " milliseconds.\n" << std::endl;

    //-------------------------------

    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::randomSearch(arr, n, nearFirst);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Random Search with nearFirst took " << elapsedTime.count() << " milliseconds." << std::endl;


    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::randomSearch(arr, n, nearMiddle);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Random Search with nearMiddle took " << elapsedTime.count() << " milliseconds." << std::endl;


    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::randomSearch(arr, n, nearLast);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Random Search with nearLast took " << elapsedTime.count() << " milliseconds." << std::endl;


    startTime = std::chrono::system_clock::now();
    for(int i = 0; i <100 ; i++)
    index = Search::randomSearch(arr, n, noKey);
    elapsedTime = std::chrono::system_clock::now() - startTime;
    std::cout << "Random Search with noKey took " << elapsedTime.count() << " milliseconds." << std::endl;


    //-----------------------------------------------------------------------------
}
int *generate_sorted_random_array(int size) {
    int* arr = new int[size];
    srand(time(NULL));
    for(int i = 0; i < size; i++){
    if(size < 10000)
        arr[i] = rand() % (10*size);

    else
        arr[i] = rand() % (2*size);
    }
    Search::quickSort(arr,0,size-1);
    return  arr;

}
void printArray(int arr[],int  size){
    for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << std::endl;
    }
    std::cout << "\n";
}


int main() {

    /*
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                  34, 55, 89, 144, 233, 377, 610,1000,2000,3000,4000,12311,12333,12567,21567,26512 };
    int x = 12333;
    int n = 20;
    int index;
    index = Search::jumpSearch(arr,n,x);
    std::cout << index << std::endl;

    index = Search::recLinSearch(arr,n,x);
    std::cout << index << std::endl;

    index = Search::itLinSearch(arr,n,x);
    std::cout << index << std::endl;

    index = Search::binarySearch(arr,n,x);
    std::cout << index << std::endl;

    index = Search::randomSearch(arr,n,x);
    std::cout << index << std::endl;
     */
    int array[] = {10, 25,100, 500,1500, 3000, 5000, 10000, 15000, 30000 };





        for (int size : array) {
            std::cout << "\n Search methods on array of size " << size << " :\n";

            int *arr = generate_sorted_random_array(size);


            search(arr, size);

            // Clean up memory
            delete[] arr;
//------------------------------ARR WITH SIZE 10--------------------------------------



    }
    return 0;


}
