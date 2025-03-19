#include <stdio.h>

// Function to sort the array using Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary Search function
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;  // Element found

        if (arr[mid] < target)
            left = mid + 1;  // Search in right half
        else
            right = mid - 1; // Search in left half
    }
    return -1; // Element not found
}

int main() {
    int n, target;
    
    // Taking input for array size
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Taking input for array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Sorting the array before searching
    bubbleSort(arr, n);
    
    // Display sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Taking input for the element to search
    printf("Enter element to search: ");
    scanf("%d", &target);
    
    // Applying Binary Search
    int result = binarySearch(arr, 0, n - 1, target);
    
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");
    
    return 0;
}


//2nd type 
#include <stdio.h>

// Function for binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at mid
        if (arr[mid] == target)
            return mid;

        // If target is smaller, ignore the right half
        if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1; // Ignore the left half
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {2, 3, 4, 10, 15, 20, 30}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int result = binarySearch(arr, 0, size - 1, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
