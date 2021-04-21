/*
 *  INSERTION-SORT(A)
 *      for j = 2 to A.length
 *          key = A[j]
 *          i = j - 1
 *          while i > 0 and A[i] < key
 *              A[i + 1] = A[i]
 *              i = i - 1
 *          A[i + 1] = key
*/

#include <stdio.h>
#include <stdint.h>

void print_array(int a[], int l)
{
    int i;

    for (i=0; i<l; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void insertion_sort(int a[], int l)
{
    int i, j, key;

    for (j = 1; j < l; j++) {
        key = a[j];
        i = j - 1;
        while ((i >= 0) && (a[i] < key)) {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
}

int main()
{
    int a[6] = {31,41,59,26,42,58};

    print_array(a, 6);

    insertion_sort(a, 6);

    print_array(a, 6);
}
