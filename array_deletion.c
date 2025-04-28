#include <stdio.h>

void delete_from_array() {
    int arr[50], size, i, pos;

    printf("Enter the size of array: ");
    scanf("%d", &size);

    printf("Enter elements in the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elements in the array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Deleting element
    printf("From which position do you want to delete data? ");
    scanf("%d", &pos);

    // Shifting elements
    for (i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;

    // Array after deleting element
    printf("Array after deleting element: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    delete_from_array();
    return 0;
}
