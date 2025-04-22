// lc 3162 

#include <stdio.h>

int numberOfPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k){
    int pairs = 0;
    int n1, n2, den;
    for (int i = 0; i < nums1Size; i++) {
        n1 = nums1[i];
        for (int j = 0; j < nums2Size; j++) {
            n2 = nums2[j];
            den = n2 * k;
            if (den == 0) continue;
            if (n1 % den == 0) {
                printf("Found pair! [%d, %d]\n", n1, n2);
                pairs++;
            }
        }
    }
    return pairs;
}

int main(){
    int arr1[5] = {1, 2, 3, 4, 5};
    int len1 = sizeof(arr1) / sizeof(int);
    for (int i = 0; i < len1; i++){
        arr1[i] = arr1[i] * 10;
    }

    int arr2[7] = {2, 4, 6, 8, 10, 12, 14};
    int len2 = sizeof(arr2) / sizeof(int);
    int k = 2;
    int res;

    res = numberOfPairs(arr1, len1, arr2, len2, k); 

    printf("Number of pairs = %d\n", res);
    return 0;
}

