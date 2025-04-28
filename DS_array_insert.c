#include<stdio.h>

void insert()
{
    int arr[50], size, i, pos, num;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter elements in the array:\n");
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Elements in the array: ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter data you want to insert: ");
    scanf("%d", &num);

    printf("Enter position: ");
    scanf("%d", &pos);

    for(i = size - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    
    arr[pos - 1] = num;
    size++;

    printf("Elements in the array after insertion: ");
    for(i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{
    insert();
}