#include <stdio.h>

int numberOfItems = 5;
int numberArray[5];

void displayNumericArray(int passedArray[numberOfItems]) {
    int i = 0;
    printf("\nArray data: ");
    for (i = 0; i < numberOfItems; i++) {
        printf("%d", passedArray[i]);
        if (i < (numberOfItems - 1)) {
            printf(", ");
        }
    }
    i = 0;
}

int partition(int passedArray[], int startIndex, int endIndex) {
    int pivotValue = passedArray[endIndex];
    int i = startIndex - 1;
    int j = 0;
    int temp = 0;
    for (j = startIndex; j <= endIndex - 1; j++){
        if (passedArray[j] <= pivotValue){
            i++;
            temp = passedArray[i];
            passedArray[i] = passedArray[j];
            passedArray[j] = temp;
        }
    }
    temp = passedArray[i + 1];
    passedArray[i + 1] = passedArray[endIndex];
    passedArray[endIndex] = temp;
    return i + 1;
}

void quicksort(int passedArray[], int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        int partitionIndex = partition(passedArray, startIndex, endIndex);
        quicksort(passedArray, startIndex, partitionIndex - 1);
        quicksort(passedArray, partitionIndex + 1, endIndex);
    }
}

int main () {
    printf("*** Quicksort in C ***");
    printf("\n\n");
    printf("Enter %d items to populate the array to be sorted.\n", numberOfItems);
    int i = 0;
    for (i = 0; i < numberOfItems; i++) {
        printf("Value for index %d : ", i);
        scanf("%d", &numberArray[i]);
    }
    printf("\nBefore sorting:\n");
    displayNumericArray(numberArray);
    quicksort(numberArray, 0, numberOfItems - 1);
    printf("\nAfter sorting:\n");
    displayNumericArray(numberArray);
    printf("\n\n");

    return 0;
}