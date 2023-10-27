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
    for(i = 0; i < n; i = i + 1) {
        arr[i] = i * i;
    }
}

void arrsum(int n, int arr[], int *sump) {
    int i;
    for(i = 0; i < n; i = i + 1) {
        *sump = *sump + arr[i]; 
    }
}