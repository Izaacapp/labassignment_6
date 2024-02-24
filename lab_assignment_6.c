#include <stdio.h>
#include <stdlib.h>

// Function prototype declarations
int search(int numbers[], int low, int high, int value);
void printArray(int numbers[], int size);

// Binary search function
int search(int numbers[], int low, int high, int value) {
    if (high < low) {
        return -1; // Base case: value not found
    }

    int mid = low + (high - low) / 2; // Calculate middle index

    if (numbers[mid] == value) {
        return mid; // Value found at mid
    } else if (numbers[mid] > value) {
        return search(numbers, low, mid - 1, value); // Search in the left half
    } else {
        return search(numbers, mid + 1, high, value); // Search in the right half
    }
}

// Function to print the array
void printArray(int numbers[], int size) {
    printf("Number array: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

// Main function
int main(void) {
    int numInputs, countOfNums, value, index;
    FILE* inFile = fopen("input.txt", "r");

    if (inFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(inFile, "%d\n", &numInputs);

    while (numInputs-- > 0) {
        fscanf(inFile, "%d\n", &countOfNums);
        int* numArray = (int*)malloc(countOfNums * sizeof(int));
        if (numArray == NULL) {
            printf("Memory allocation failed.\n");
            fclose(inFile);
            return 1;
        }

        float average = 0;
        for (int i = 0; i < countOfNums; i++) {
            fscanf(inFile, "%d", &value);
            numArray[i] = value;
            average += value;
        }

        printArray(numArray, countOfNums);
        average /= countOfNums;
        index = search(numArray, 0, countOfNums - 1, (int)average);
        if (index >= 0) {
            printf("Item %d exists in the number array at index %d!\n", (int)average, index);
        } else {
            printf("Item %d does not exist in the number array!\n", (int)average);
        }

        free(numArray);
    }

    fclose(inFile);
    return 0;
}
