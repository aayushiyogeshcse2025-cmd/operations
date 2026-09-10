#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void display(int arr[], int size);
void insert(int arr[], int *size, int element, int position);
void deleteElement(int arr[], int *size, int position);

int main() {
    int arr[MAX];
    int size = 0;
    int choice, element, position, i;

    printf("Enter the initial number of elements (Max %d): ", MAX);
    scanf("%d", &size);

    if (size > MAX || size < 0) {
        printf("Invalid size! Setting initial size to 0.\n");
        size = 0;
    } else if (size > 0) {
        printf("Enter %d elements:\n", size);
        for (i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
    }

    while (1) {
        printf("\n--- ARRAY OPERATIONS MENU ---\n");
        printf("1. Insert an Element\n");
        printf("2. Delete an Element\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position (0 to %d): ", size);
                scanf("%d", &position);
                insert(arr, &size, element, position);
                break;

            case 2:
                if (size == 0) {
                    printf("Error: Array is empty! Nothing to delete.\n");
                } else {
                    printf("Enter the position to delete (0 to %d): ", size - 1);
                    scanf("%d", &position);
                    deleteElement(arr, &size, position);
                }
                break;

            case 3:
                display(arr, size);
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please choose a number between 1 and 4.\n");
        }
    }

    return 0;
}

void display(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insert(int arr[], int *size, int element, int position) {
    
    if (*size >= MAX) {
        printf("Error: Array is full! Cannot insert more elements.\n");
        return;
    }
  
    if (position < 0 || position > *size) {
        printf("Error: Invalid position! Position must be between 0 and %d.\n", *size);
        return;
    }

    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    
    (*size)++;
    printf("Success: Element %d inserted successfully at position %d.\n", element, position);
}


void deleteElement(int arr[], int *size, int position) {

    if (position < 0 || position >= *size) {
        printf("Error: Invalid position! Position must be between 0 and %d.\n", *size - 1);
        return;
    }

    int removedValue = arr[position];

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size);
    printf("Success: Element %d deleted successfully from position %d.\n", removedValue, position);
}
