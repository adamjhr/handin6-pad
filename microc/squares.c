// All of the code in this file is new

void main(int n) {
    int arr[20];
    int sump;
    sump = 0;
    squares(n, arr);
    arrsum(n, arr, &sump);
    print sump;
}

void squares(int n, int arr[]) {
    int i;
    i = 0;
    while(i < n) {
        arr[i] = i * i;
        i = i + 1;
    }
}

void arrsum(int n, int arr[], int *sump) {
    int i;
    i = 0;
    while(i < n) {
        *sump = *sump + arr[i]; 
        i = i + 1;
    }
}