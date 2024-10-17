#include <stdio.h>

void mergeSort(int arr[], int left, int right);
void quickSort(int arr[], int low, int high);
void merge(int arr[], int left, int mid, int right);
int partition(int arr[], int low, int high);
void printArray(int arr[], int size);

int main() {
    int choice, n, i;
    int arr[100];

    do {
        printf("\nMenu:\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting program.\n");
            break;
        }

        printf("Enter the number of elements in the array: ");
        scanf("%d", &n);
        
        printf("Enter the elements of the array:\n");
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        switch (choice) {
            case 1:
                mergeSort(arr, 0, n - 1);
                printf("Array sorted using Merge Sort: \n");
                break;
            case 2:
                quickSort(arr, 0, n - 1);
                printf("Array sorted using Quick Sort: \n");
                break;
            default:
                printf("Invalid choice! Please enter 1, 2, or 3.\n");
        }

        printArray(arr, n);

    } while (choice != 3);

    return 0;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);
    int temp;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}