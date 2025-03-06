#include <stdio.h>
#include <stdlib.h>

int global_var = 42;

void func() {
    int local_var = 10;
    int large_array[10000];  
    printf("The address of large_array (stack) is %p\n", &large_array);
    printf("The address of local_var (stack) is %p\n", &local_var);
}

int main() {
    int i;
    char *heap_var = (char *)malloc(1000 * sizeof(char));

    printf("The stack top is near %p\n", &i);
    printf("The address of global_var (data) is %p\n", &global_var);
    printf("The address of heap_var (heap) is %p\n", heap_var);

    func();

    free(heap_var);

    return 0;
}
