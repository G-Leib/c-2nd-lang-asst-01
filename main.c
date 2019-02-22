#include <stdio.h>

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

    return 0;
}

