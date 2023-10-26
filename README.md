## Exercise 7.1

The lexer is succesfully generated with the command:
`./fslex.exe --unicode CLex.fsl`

The parser is also generated, with the command:
`./fsyacc.exe --module CPar CPar.fsy`

`dotnet fsi -r FsLexYacc.Runtime.dll Absyn.fs CPar.fs CLex.fs Parse.fs Interp.fs ParseAndRun.fs`

This is the syntax tree based on the abstract syntax created from running `fromFile "ex1.c"`.

![[ast.png]]

**declarations** - blue
**statements** - red
**expressions** - green
**types** - yellow
**strings/numbers** - grey
**others** - white

Output from running some other examples:
```fsharp
> run (fromFile "ex2.c") [];;  
-1 -1 1 -999 1 227 12 12 14 114 2 1 1 val it: Interp.store =
  map
    [(0, 2); (1, 12); (2, 14); (3, -999); (4, -999); (5, -999); (6, -999);
     (7, -999); (8, -999); ...]

> run (fromFile "ex4.c") [10];;
1 1 2 6 24 120 720 5040 40320 362880 val it: Interp.store =
  map
    [(0, 1); (1, 1); (2, 2); (3, 6); (4, 24); (5, 120); (6, 720); (7, 5040);
     (8, 40320); ...]

> run (fromFile "ex9.c") [5];;
120 val it: Interp.store =
  map
    [(0, 5); (1, 120); (2, 5); (3, 1); (4, 24); (5, 4); (6, 4); (7, 6); (8, 3);
     ...]
```

## Exercise 7.2
(i)
`microc/sum.c`
```c
// All of the code in this file is new

void main(int n) {
    int sump;
    sump = 0;
    int arr[4];
    arr[0] = 7;
    arr[1] = 13;
    arr[2] = 9;
    arr[3] = 8;
    arrsum(n, arr, &sump);
    print sump;
}

void arrsum(int n, int arr[], int *sump) {
    int i;
    i = 0;
    while(i < n) {
        *sump = *sump + arr[i];
        i = i + 1;
    }
}
```
This behaves as intended as long as you give an argument less than 5...

Results from running:
```fsharp
> run (fromFile "sum.c") [2];;     
20 val it: Interp.store =
  map
    [(0, 2); (1, 20); (2, 7); (3, 13); (4, 9); (5, 8); (6, 2); (7, 2); (8, 2);
     ...]

> run (fromFile "sum.c") [1];;
7 val it: Interp.store =
  map
    [(0, 1); (1, 7); (2, 7); (3, 13); (4, 9); (5, 8); (6, 2); (7, 1); (8, 2);
     ...]

> run (fromFile "sum.c") [3];;
29 val it: Interp.store =
  map
    [(0, 3); (1, 29); (2, 7); (3, 13); (4, 9); (5, 8); (6, 2); (7, 3); (8, 2);
     ...]

> run (fromFile "sum.c") [4];;
37 val it: Interp.store =
  map
    [(0, 4); (1, 37); (2, 7); (3, 13); (4, 9); (5, 8); (6, 2); (7, 4); (8, 2);
     ...]

> run (fromFile "sum.c") [0];;
0 val it: Interp.store =
  map
    [(0, 0); (1, 0); (2, 7); (3, 13); (4, 9); (5, 8); (6, 2); (7, 0); (8, 2);
     ...]

> run (fromFile "sum.c") [5];; // It reads from beyond the array
39 val it: Interp.store =
  map
    [(0, 5); (1, 39); (2, 7); (3, 13); (4, 9); (5, 8); (6, 2); (7, 5); (8, 2);
     ...]

> run (fromFile "sum.c") [6];; // It reads from beyond the array
45 val it: Interp.store =
  map
    [(0, 6); (1, 45); (2, 7); (3, 13); (4, 9); (5, 8); (6, 2); (7, 6); (8, 2);
     ...]


```

(ii)
