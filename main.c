#include <stdio.h>

void pass_value(int arg) {
    // subtract 5 from a value
    // this function should not change the passed argument
    arg -= 5;
}

void pass_pointer(int *arg) {
    // subtract 3 from a value
    // this function should change a passed argument
    *arg -= 3;
}

int return_new(int arg) {
    // add 10 to am argument and return the new value
    return arg + 10;
}

void print_arr(int arr) {
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < arr_size; i++) {
        printf("%d   ", arr[i]);
    };
}

int main() {
    // part 1-i
    int num = 10;
    printf("%d\n", num);
    int *p = &num;
    *p = 9;
    printf("%d\n", num);

    // part 1-ii
    pass_value(num);
    pass_pointer(&num);

    // Output should be subtracted by 5 if the first method works and 3 if the second one works
    // If only the pass_value works the final will be 4,
    // if only pass_pointer works final will be 6
    // if both work, final will be 1
    printf("%d\n", num);

    // part 1-iii
    num = return_new(num);
    printf("%d\n", num);

    // part 2-ii
    int integer_array[] = {3, 1, 5, 6, 78, 9, 234, 12, 2, 8746, 23, 8};
    int arr_size = sizeof(integer_array)/sizeof(integer_array[0]);
    printf("There are %d elements in the array.", arr_size);

    // part 2-iii
    int iarray[10];

    // zero out iarray[]
    for (int i = 0; i < 10; i++) {
        iarray[i] = 0;
    };
    print_arr(iarray);

    iarray[5] = 6;
    print_arr(iarray);

    int *jarr = iarray;
    jarr[5] = jarr[5]+1;
    print_arr(iarray);

    return 0;
}

