#include <iostream>
#include <vector>
#include <ctime>   
#include <cstdlib>  


template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Bubble Sort
template <typename T>
void bubbleSort(std::vector<T> &arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n-1; ++i) {
        swapped = false;
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Selection Sort
template <typename T>
void selectionSort(std::vector<T> &arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; ++i) {
        int minIndex = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Insertion Sort
template <typename T>
void insertionSort(std::vector<T> &arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Merge Sort
template <typename T>
void merge(std::vector<T> &arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<T> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

template <typename T>
void mergeSortHelper(std::vector<T> &arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSortHelper(arr, left, middle);
        mergeSortHelper(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

template <typename T>
void mergeSort(std::vector<T> &arr) {
    mergeSortHelper(arr, 0, arr.size() - 1);
}

// Quick Sort
template <typename T>
int partition(std::vector<T> &arr, int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quickSortHelper(std::vector<T> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

template <typename T>
void quickSort(std::vector<T> &arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}

// Heap Sort
template <typename T>
void heapify(std::vector<T> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template <typename T>
void heapSort(std::vector<T> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to print the array
template <typename T>
void printArray(const std::vector<T> &arr) {
    for (const auto &elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<int> arr(10);
    for (auto &elem : arr) {
        elem = std::rand() % 100; 
    }

    std::cout << "Original Array: ";
    printArray(arr);

    // Sort using different algorithms
    bubbleSort(arr);
    std::cout << "Bubble Sort: ";
    printArray(arr);

    selectionSort(arr);
    std::cout << "Selection Sort: ";
    printArray(arr);

    insertionSort(arr);
    std::cout << "Insertion Sort: ";
    printArray(arr);

    mergeSort(arr);
    std::cout << "Merge Sort: ";
    printArray(arr);

    quickSort(arr);
    std::cout << "Quick Sort: ";
    printArray(arr);

    heapSort(arr);
    std::cout << "Heap Sort: ";
    printArray(arr);

    return 0;
}
