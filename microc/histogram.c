// All of the code in this file is new

void main() {
    // ex1();
    ex2();
}

void ex1() {
    int max;
    int n;
    max = 5;
    n = 5;
    int freq[6];
    int ns[5];
    ns[0] = 2;
    ns[1] = 5; 
    ns[2] = 0; 
    ns[3] = 5; 
    ns[4] = 1;
    histogram(n, ns, max, freq);
    int i;
    i = 0;
    while(i < max + 1) {
        print freq[i];
        i = i + 1;
    }
}

void ex2() {
    int max;
    int n;
    max = 5;
    n = 11;
    int freq[6];
    int ns[11];
    ns[0] = 0;
    ns[1] = 1; 
    ns[2] = 1; 
    ns[3] = 2; 
    ns[4] = 3;
    ns[5] = 5;
    ns[6] = 3; 
    ns[7] = 2; 
    ns[8] = 1; 
    ns[9] = 1;
    ns[10] = 0;
    histogram(n, ns, max, freq);
    int i;
    i = 0;
    while(i < max + 1) {
        print freq[i];
        i = i + 1;
    }
}

void histogram(int n, int ns[], int max, int freq[]) {
    int i;
    i = 0;
    while(i < max + 1) {
        freq[i] = 0;
        i = i + 1;
    }
    i = 0;
    while(i < n) {
        int x;
        x = ns[i];
        freq[x] = freq[x] + 1;
        i = i + 1;
    }
}