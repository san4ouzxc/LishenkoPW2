#include <stdio.h>
#include <stdlib.h>
#define MSG "In function %20s; &localvar = %p\n"

void call_function(void (*func)(void)) {
    void *return_address;
    __asm__("mov %%rbx, %0" : "=r"(return_address));  
    printf("Returning to address: %p\n", return_address);
    func();  
}

static void bar_is_now_closed(void) {
    int localvar = 5;
    printf(MSG, __FUNCTION__, &localvar);
    printf("\n Now blocking on pause()...\n");
    pause();  
}

static void bar(void) {
    int localvar = 5;
    printf(MSG, __FUNCTION__, &localvar);
    call_function(bar_is_now_closed);  
}

static void foo(void) {
    int localvar = 5;
    printf(MSG, __FUNCTION__, &localvar);
    call_function(bar);  
}

int main(int argc, char **argv) {
    int localvar = 5;
    printf(MSG, __FUNCTION__, &localvar);
    call_function(foo);  
    exit(EXIT_SUCCESS);
}
