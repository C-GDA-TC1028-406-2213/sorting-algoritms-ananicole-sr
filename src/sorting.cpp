#include "sorting.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

namespace SortingAlgorithms {

void swap(int &uno, int &dos){
    int var = uno;
    uno = dos;
    dos = var;
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < (n - 1); i++){
            for(int j = 0; j < (n - 1); j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
}

void selectionSort(int arr[], int n) {
       for(int i = 0; i < n; i++){
           int grande = 0;
           for(int j = 0; j < n - i ; j++){
               if(arr[j] > arr[grande]){
                   grande = j;
               }
           }
           swap(arr[grande],arr[(n-1)-i]);
       }
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n ; i++){
           int m = i;
           int valor = arr[i];
           
           while(valor < arr[m-1] && m > 0){
               arr[m]= arr[m-1];
               m--;
           }
           arr[m] = valor;
       }
}

void merge(int arr[], int left, int mid, int right) {
    int arrayfinal[right-left+1];
       int p1 = left;
       int p2 = mid+1;
       
       for(int idx = 0; idx <= right; idx++){
           if(p1 <= mid && p2 <= right){
               if(arr[p1] < arr[p2]){
                   arrayfinal[idx] = arr[p1];
                   p1++;
               } else{
                   arrayfinal[idx] = arr[p2];
                   p2++;
               }
           } else {
               while(p1 <= mid){
                   arrayfinal[idx++] = arr[p1];
                   p1++;
               }
               while(p2 <= right){
                   arrayfinal[idx++] = arr[p2];
                   p2++;
               }
           }
       }
       for(int t = 0; t < (right-left+1); t++){
           arr[left+t] = arrayfinal[t];
       }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;

      int mid = (left+right)/2;
      mergeSort(arr,left,mid);
      mergeSort(arr,(mid+1), right);
      merge(arr,left,mid,right);
}

int partition(int arr[], int low, int high) {
    int pivote = arr[low];
       int i = low;
       int j = high + 1;
       while(i < j){
           do {
            i++;
           } while (i <= high && arr[i] < pivote);
           do {
               j--;
           } while (j >= low && arr[j] > pivote);


           if(i < j){
               swap(arr[i], arr[j]);
           }
       }
       swap(arr[low], arr[j]);
       return j;
}

void quickSort(int arr[], int low, int high) {
    if(low >= high) return;

    int par = partition(arr, low, high); 
    quickSort(arr, low, par - 1);
    quickSort(arr, par + 1, high);
}

void heapify(int arr[], int n, int i) {
    
}

void heapSort(int arr[], int n) {
    
}

void printArray(int arr[], int n) {
    if (n == 0) {
        std::cout << "[]" << std::endl;
        return;
    }
    
    std::cout << "[";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void SortingTimer::start() {
    start_time = std::chrono::high_resolution_clock::now();
}

void SortingTimer::stop() {
    end_time = std::chrono::high_resolution_clock::now();
}

double SortingTimer::getElapsedMilliseconds() const {
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    return duration.count() / 1000.0;
}

std::string SortingTimer::getElapsedTime() const {
    double ms = getElapsedMilliseconds();
    std::stringstream ss;
    
    if (ms < 1.0) {
        ss << std::fixed << std::setprecision(3) << (ms * 1000) << " microseconds";
    } else if (ms < 1000.0) {
        ss << std::fixed << std::setprecision(3) << ms << " ms";
    } else {
        ss << std::fixed << std::setprecision(3) << (ms / 1000.0) << " seconds";
    }
    
    return ss.str();
}

std::vector<int> generateRandomArray(int size, int minVal, int maxVal) {
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minVal, maxVal);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    
    return arr;
}

std::vector<int> generateSortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
    return arr;
}

std::vector<int> generateReverseSortedArray(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
    }
    return arr;
}

std::vector<int> generateNearlySortedArray(int size, int swaps) {
    std::vector<int> arr = generateSortedArray(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, size - 1);
    
    for (int i = 0; i < swaps && i < size/2; i++) {
        int idx1 = dis(gen);
        int idx2 = dis(gen);
        std::swap(arr[idx1], arr[idx2]);
    }
    
    return arr;
}

}
