#include <stdio.h>
#include <stdlib.h>

#define MSG "У функції %20s; &localvar = %p\n"

void *get_stack_address() {
    int *localvar = (int *) malloc(sizeof(int));  
    *localvar = 5;  
    return (void *) localvar;
}

void *get_heap_address() {
    char *ptr = (char *) malloc(1);
    void *address = (void *) ptr;
    free(ptr);
    return address;
}

void *get_code_address() {
    return (void *) get_code_address;
}

int main(int argc, char **argv) {
    void *stack_addr = get_stack_address();
    printf("Адреса стеку: %p\n", stack_addr);

    void *heap_addr = get_heap_address();
    printf("Адреса змінної в кучі: %p\n", heap_addr);

    void *code_addr = get_code_address();
    printf("Адреса коду: %p\n", code_addr);

    if ((stack_addr != heap_addr) && (heap_addr != code_addr) && (stack_addr != code_addr)) {
        printf("\nASLR, ймовірно, працює: сегменти розміщені випадковим чином.\n");
    } else {
        printf("\nASLR, ймовірно, не ввімкнено або немає випадковості в розміщенні сегментів.\n");
    }

    free(stack_addr);

    return 0;
}
