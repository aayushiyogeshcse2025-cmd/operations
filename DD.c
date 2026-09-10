#include <stdio.h>

int main() {
    int arr[100], pos, c, n;

    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (c = 0; c < n; c++) {
        scanf("%d", &arr[c]);
    }

    printf("Enter the position where you wish to delete element (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos >= 1 && pos <= n) {
        for (c = pos - 1; c < n - 1; c++) {
            arr[c] = arr[c + 1];
        }

        printf("Resultant array:\n");
        for (c = 0; c < n - 1; c++) {
            printf("%d\n", arr[c]);
        }
    } else {
        printf("Deletion not possible. Invalid position.\n");
    }

    return 0;
}
