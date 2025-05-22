#include <stdio.h>
#define SIZE 100

int main() {
    int arr[SIZE];
    int n, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n----- Menu -----\n");
        printf("1. Insert\n");
        printf("2. Update\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Sort\n");
        printf("6. Search\n");
        printf("7. Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int pos, val;
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);
                if (pos < 0 || pos > n || n >= SIZE) {
                    printf("Invalid position or array full.\n");
                } else {
                    printf("Enter value to insert: ");
                    scanf("%d", &val);
                    for (int i = n; i > pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = val;
                    n++;
                    printf("Value inserted successfully.\n");
                }
                break;
            }

            case 2: {
                int pos, val;
                printf("Enter position to update (0 to %d): ", n - 1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Invalid position.\n");
                } else {
                    printf("Enter new value: ");
                    scanf("%d", &val);
                    arr[pos] = val;
                    printf("Value updated successfully.\n");
                }
                break;
            }

            case 3: {
                int pos;
                printf("Enter position to delete (0 to %d): ", n - 1);
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Invalid position.\n");
                } else {
                    for (int i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Value deleted successfully.\n");
                }
                break;
            }

            case 4: {
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Array elements: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;
            }

            case 5: {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Array sorted successfully.\n");
                break;
            }

            case 6: {
                int val, found = 0;
                printf("Enter value to search: ");
                scanf("%d", &val);
                for (int i = 0; i < n; i++) {
                    if (arr[i] == val) {
                        printf("Value found at index %d\n", i);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Value not found in the array.\n");
                }
                break;
            }

            case 7:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 7);

    return 0;
}
