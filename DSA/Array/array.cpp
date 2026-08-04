#include <iostream>
#include <climits>
using namespace std;

int* create(int& size);
void insertAtBeginning(int*& arr, int& size);
void insertAtPosition(int*& arr, int& size);
void insertAtEnd(int*& arr, int& size);
void display(int arr[], int size);
void change(int arr[], int size);
void displayOne(int arr[], int size);
void search(int arr[], int size);
void delAtPos(int arr[], int& size);
void delAtBeginning(int arr[], int& size);
void delAtEnd(int arr[], int& size);
void delByValue(int*& arr, int& size);
void maxValue(int arr[], int size);
void minValue(int arr[], int size);
void maxNthValue(int arr[], int size);
void minNthValue(int arr[], int size);
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void mergeSort(int arr[], int size);
void mergeHelper(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quickSort(int arr[], int size);
void quickHelper(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void radixSort(int arr[], int size);
// Radix, Heap -min/max, bucket, counting, Binary Search

int main() {
    int size = 0;
    int choice;
    int* arr = create(size);
    while (1) {
        cout << "----MENU----" << endl << endl;
        cout << "1. Display All" << endl;
        cout << "2. Display One" << endl;
        cout << "3. Change a value" << endl;
        cout << "4. Search a value" << endl;
        cout << "5. Delete by Value" << endl;
        cout << "6. Insertion at Begining" << endl;
        cout << "7. Insertion at Position" << endl;
        cout << "8. Insertion at End" << endl;
        cout << "9. Delete at Beginning" << endl;
        cout << "10. Delete at Postion" << endl;
        cout << "11. Delete at End" << endl;
        cout << "12. Maximum Value" << endl;
        cout << "13. Minimum Value" << endl;
        cout << "14. Maximum Value at nth position" << endl;
        cout << "15. Minimum Value at nth position" << endl;
        cout << "16. Bubble Sort" << endl;
        cout << "17. Selection Sort" << endl;
        cout << "18. Insertion Sort" << endl;
        cout << "19. Merge Sort" << endl;
        cout << "20. Quick Sort" << endl;

        cout << "0. Exit" << endl << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
        case 1: display(arr, size); break;
        case 2: displayOne(arr, size); break;
        case 3: change(arr, size); break;
        case 4: search(arr, size); break;
        case 5: delByValue(arr, size); break;
        case 6: insertAtBeginning(arr, size); break;
        case 7: insertAtPosition(arr, size); break;
        case 8: insertAtEnd(arr, size); break;
        case 9: delAtBeginning(arr, size); break;
        case 10: delAtPos(arr, size); break;
        case 11: delAtEnd(arr, size); break;
        case 12: maxValue(arr, size); break;
        case 13: minValue(arr, size); break;
        case 14: maxNthValue(arr, size); break;
        case 15: minNthValue(arr, size); break;
        case 16: bubbleSort(arr, size); break;
        case 17: selectionSort(arr, size); break;
        case 18: insertionSort(arr, size); break;
        case 19: mergeSort(arr, size); break;
        case 20: quickSort(arr, size); break;

        case 0:
            delete[] arr; exit(0);
        }
        cout << endl;
    }
    return 0;
}

//  ---------------------------------- ---------------CREATE------------------- ----------------------------------

int* create(int& size) {
    cout << "Enter size for the array : ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter value at " << i << " : ";
        cin >> arr[i];
    }

    return arr;
}

//  ---------------------------------- ---------------DISPLAY------------------- ----------------------------------

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void displayOne(int arr[], int size) {
    int pos;
    cout << "Enter a position to search : ";
    cin >> pos;

    if (pos >= 0 && pos < size) {
        cout << "The value at position " << pos << " is : " << arr[pos] << endl;
    }
    else {
        cout << "No such value found" << endl;
    }
}

//  ---------------------------------- ---------------SEARCH-CHANGE------------------- ----------------------------------

void change(int arr[], int size) {
    if (size == 0) cout << "Array is empty" << endl; return;

    int pos;
    cout << "Enter a position to change : ";
    cin >> pos;

    if (pos >= 0 && pos < size) {
        cout << "Enter a value to change : ";
        cin >> arr[pos];
    }
    else {
        cout << "No value found" << endl;
    }
}

void search(int arr[], int size) {
    if (size == 0) cout << "Array is empty" << endl; return;

    int key;
    cout << "Enter a value to search : ";
    cin >> key;
    bool val = false;
    int pos = 0;

    for (int i = 0; i < size; i++) {
        if (key == arr[i]) {
            val = true;
            pos = i;
            break;
        }
    }
    cout << (val ? "Position found at : " + to_string(pos) : "Not found") << endl;
}

//  ---------------------------------- ---------------INSERTION------------------- ----------------------------------

void insertAtBeginning(int*& arr, int& size) {
    int val;
    cout << "Enter value to be inserted : ";
    cin >> val;

    int* newarr = new int[size + 1];
    newarr[0] = val;

    for (int i = 0; i < size; i++) {
        newarr[i + 1] = arr[i];
    }

    delete[] arr;

    arr = newarr;
    size++;
}

void insertAtPosition(int*& arr, int& size) {
    int pos, val;
    cout << "Enter a postion to insert : ";
    cin >> pos;
    if (pos == 0) {
        insertAtBeginning(arr, size);
    }
    else if (pos == size) {
        insertAtEnd(arr, size);
    }
    else if (pos > 0 && pos < size) {
        cout << "Enter value to be inserted : ";
        cin >> val;
        int* newarr = new int[size + 1];

        for (int i = 0; i < pos; i++) {
            newarr[i] = arr[i];
        }
        newarr[pos] = val;
        for (int i = pos; i < size; i++) {
            newarr[i + 1] = arr[i];
        }

        delete[] arr;

        arr = newarr;
        size++;
    }
    else {
        cout << "Invalid Position";
    }
}

void insertAtEnd(int*& arr, int& size) {
    int val;
    cout << "Enter value to be inserted : ";
    cin >> val;
    int* newarr = new int[size + 1];

    for (int i = 0; i < size; i++) {
        newarr[i] = arr[i];
    }

    newarr[size] = val;
    delete[] arr;

    arr = newarr;
    size++;
}

//  ---------------------------------- ---------------DELETE------------------- ----------------------------------

void delAtBeginning(int arr[], int& size) {
    if (size == 0) cout << "Array is empty" << endl; return;
    
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

void delAtPos(int arr[], int& size) {
    if (size == 0) cout << "Array is empty" << endl; return;

    int pos;
    cout << "Enter a position to delete : ";
    cin >> pos;

    if (pos < 0 || pos >= size) {
        cout << "No such position to delete" << endl;
    }
    else {
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
}

void delAtEnd(int arr[], int& size) {
    if (size == 0) cout << "Array is empty" << endl; return;

    size--;
}

void delByValue(int*& arr, int& size) {
    if (size == 0) cout << "Array is empty" << endl; return;
    
    int val;
    cout << "Enter a value to delete : ";
    cin >> val;
    bool check = false;
    int pos = -1;

    for (int i = 0; i < size && check == false; i++) {
        if (arr[i] == val) {
            pos = i;
            check = true;
        }
    }

    if (!check) {
        cout << "Value not found" << endl;
        return;
    }

    int* newarr = new int[size - 1];
    for (int i = 0; i < pos; i++) {
        newarr[i] = arr[i];
    }
    for (int i = pos; i < size - 1; i++) {
        newarr[i] = arr[i + 1];
    }

    delete[] arr;
    arr = newarr;

    size--;
}

//  ---------------------------------- ---------------MIN-MAX------------------- ----------------------------------

void maxValue(int arr[], int size){
    int maximum = INT_MIN;
    for(int i = 0; i < size ; i++){
        if(arr[i] > maximum){
            maximum = arr[i];
        }
    }
    cout << "The maximum value of array is : " << maximum << endl;
}

void minValue(int arr[], int size){
    int minimum = INT_MAX;
    for(int i = 0; i < size ; i++){
        if(arr[i] < minimum){
            minimum = arr[i];
        }
    }
    cout << "The minimum value of array is : " << minimum << endl;
}


void maxNthValue(int arr[], int size){
    int pos;
    
    cout << "Enter the position of maximum : ";
    cin >> pos;

    int prevMax = INT_MAX;

    for(int i = 0 ; i < pos; i++){
        int currMax = INT_MIN;
        
        for(int j = 0; j < size; j++){
            if(arr[j] > currMax && arr[j] < prevMax){
                currMax = arr[j];
            }
        }
        prevMax = currMax;
    }
    
    cout << "The maxium value ar position " << pos << " is : " << prevMax;
}

void minNthValue(int arr[], int size){
    int pos;
    
    cout << "Enter the position of maximum : ";
    cin >> pos;

    int prevMin = INT_MIN;

    for(int i = 0; i < pos; i++){
        int currMin = INT_MAX;

        for(int j = 0 ; j < size; j++ ){
            if(arr[j] < currMin && arr[j] > prevMin){
                currMin = arr[j];
            }
        }
        prevMin = currMin;
    }

    cout << "The minimum value at position " << pos << " is : " <<prevMin;
}

//  ---------------------------------- ---------------SORTING------------------- ----------------------------------

// BUBBLE SORT

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size - 1 ; i++){
        bool swapped = false;

        for(int j = 0; j < size - i - 1; j++){
            
            if(arr[j] > arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;

                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

// SELECTION SORT

void selectionSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        int minIndex = i;

        for(int j = i + 1; j < size; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }

        if(minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// INSERTION SORT

void insertionSort(int arr[], int size){
    for(int i = 1; i <size; i++){
        int key = arr[i];
        int j = i-1;

        for(; j >= 0 && arr[j] > key; j--){
            arr[j+1] = arr[j];
        }

        arr[j+1] = key;
    }
}

// MERGE SORT

void mergeSort(int arr[], int size){
    int left = 0;
    int right = size - 1;
    mergeHelper(arr, left, right);
}

void mergeHelper(int arr[], int left, int right){
    if ( left >= right ) return;

    int mid = (left + right)/2;
    mergeHelper(arr, left, mid);
    mergeHelper(arr, mid+1, right);

    merge(arr, left, mid, right);

}   

void merge(int arr[], int left, int mid, int right){
    // Size of sub array
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Values to new array
    int *leftarr = new int[n1];
    int *rightarr = new int[n2];

    for(int i = 0; i < n1; i ++){
        leftarr[i] = arr[left + i];
    }

    for(int i = 0; i <n2; i++){
        rightarr[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0, k = left;

    //Comparing of values
    while( i < n1 && j < n2){
        if(leftarr[i] <= rightarr[j]){
            arr[k] = leftarr[i];
            i++;
        }else{
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }

    // Adding back extra values
    while(i < n1){
        arr[k] = leftarr[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = rightarr[j];
        j++;
        k++;
    }

    delete[] leftarr;
    delete[] rightarr;
}

// QUICK SORT

void quickSort(int arr[], int size){
    int low = 0; 
    int high = size-1;
    quickHelper(arr, low, high);   
}

void quickHelper(int arr[], int low, int high){
    if (low >= high) return;

    int index = partition(arr, low, high);
    quickHelper(arr, low, index -1);
    quickHelper(arr, index, high);
}

int partition(int arr[], int low, int high){
    int pivot = arr[(low+high)/2];
    int i = low, j = high;
    while(i <= j){
        while(arr[i] < pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if( i<=j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

// Radix Sort

void radixSort(int arr[], int size){
    int maximum = getMax(arr, size);

    for(int exp = 1; maximum/exp > 0; exp*=10){
        countingSort(arr, size, exp);
    }
}

void countingSort(int arr[], int size, int exp){
    int output[size];
    int count[10] = {0};

    for(int i = 0; i < size; i++){
        count[(arr[i]/exp) % 10]++;
    }

    for(int i = 1; i < 10; i++){
        count[i] += count[i+1];
    }

    for(int i = size - 1; i >= 0; i--){
        output[count[(arr[i]/exp) % 10]-1] = arr[i];
        count[(arr[i]/exp) % 10]--;
    }

    for(int i = 0; i < size; i++){
        arr[i] = output[i];
    }
}

int getMax(int arr[], int size){
    int maximum = arr[0];

    for(int i = 0; i < size; i++){
        if(arr[i] > maximum){
            maximum = arr[i];
        }
    }

    return maximum;
}