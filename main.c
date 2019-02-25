#include <stdio.h>
#include <stdlib.h>

struct class_record {
    char name[10];
    char class[7];
    float num_grade;
};

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

void print_arr(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d: %d   ", i, arr[i]);
    }
    printf("\n");
}

void print_rec(struct class_record student) {
    printf("Name: %s\nClass: %s\nGrade: %.2f\n", student.name, student.class, student.num_grade);
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
    printf("There are %d elements in the array.\n", arr_size);

    // part 2-iii
    int iarray[10];

    // zero out iarray[]
    for (int i = 0; i < 10; i++) {
        iarray[i] = 0;
    };
    int isize = sizeof(iarray)/sizeof(iarray[0]);
    print_arr(iarray, isize);

    iarray[5] = 6;
    print_arr(iarray, isize);

    int *jarr = iarray;
    jarr[5] = jarr[5]+1;
    print_arr(iarray, isize);

    struct class_record jim = {"Jim", "CS2400", 98.6};
    struct class_record *point = &jim;

    printf("%s\n", point->name);
    printf("%s\n", (*point).class);

    print_rec(jim);

    typedef struct {
        char owner[10];
        char make[10];
        char model[10];
        float miles;
        int year;
    } car_t;

    car_t greg = {"Greg", "Toyota", "Camry", 164879.3, 2000};

    printf("%s's %d %s %s has %.1f miles on it.\n", greg.owner, greg.year, greg.make, greg.model, greg.miles);

    // Part 6
    //explicit allocation of an integer on the heap
    int *array_size = (int *) malloc(sizeof(int));
    int size = 8;

    // check if the allocation was successful
    // if it was, the pointer will be non-NULL
    if (array_size == NULL) {
        printf("ERROR: Memory allocation failed!\n");
        return 1;
    } else {
        *array_size = 7;
    }

    // explicit allocation of an integer array on the heap
    int *int_array = (int *) malloc(*array_size * sizeof(int));

    // check if the allocation was successful
    // if it was, the pointer will be non-NULL
    if (int_array == NULL) {
        printf("ERROR: Memory allocation failed!\n");
        return 0;
    } else {
        for (int i = 0; i < *array_size; i ++) {
            int_array[i] = i * *array_size;
            printf("Array element %d holds %d\n", i, int_array[i]);
        }
    }

    // free the allocated memory:
    // dynamically allocated memory
    // has to be released explicitly
    free(array_size);
    array_size = NULL; // this is good practice in case
    // the pointer might get reused

    free(int_array);
    int_array == NULL;

    // 6-iii
    double ***cube_arr;

    // allocate 1st dimension
    cube_arr = (double ***) malloc(sizeof(double**) * 1000);

    // allocate 2nd dimension
    for (int i=0; i<1000; i++) {
        cube_arr[i] = (double**) malloc(sizeof(double*) * 1000);
    }

    // allocate 3rd dimension
    for (int i=0; i<1000; i++) {
        for(int j=0;j<1000;j++){
            cube_arr[i][j] = (double*) malloc(sizeof(double)*1000);
        }
    }

    // use of cube_arr
    // blah blah blah

    // free 3rd dim
    for (int i=0; i<1000; i++) {
        for(int j=0;j<1000;j++){
            free(cube_arr[i][j]);
            cube_arr[i][j]=NULL;
        }
    }

    // free 2nd dim
    for (int i=0; i<1000; i++) {
        free(cube_arr[i]);
        cube_arr[i]=NULL
    }

    // free 1st dim
    free(cube_arr);
    cube_arr=NULL;

    return 0;
}

