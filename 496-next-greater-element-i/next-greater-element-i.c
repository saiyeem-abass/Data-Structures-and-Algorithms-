#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
    int stack[1000];
    int top = -1;

    // Map for storing next greater element
    int map[10001];

    // Initialize map with -1
    for (int i = 0; i < 10001; i++) {
        map[i] = -1;
    }

    // Process nums2 using stack
    for (int i = 0; i < nums2Size; i++) {
        while (top != -1 && nums2[i] > stack[top]) {
            map[stack[top]] = nums2[i];
            top--;
        }
        stack[++top] = nums2[i];
    }

    // Allocate result array
    int* result = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;

    // Fill result
    for (int i = 0; i < nums1Size; i++) {
        result[i] = map[nums1[i]];
    }

    return result;
}