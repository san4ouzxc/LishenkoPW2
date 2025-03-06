#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    
    current_time = time(NULL);
    printf("Поточний час (epoch): %ld\n", current_time);

    #if defined(__x86_64__) || defined(__aarch64__)
        // 64-бітна архітектура
        printf("Для 64-бітної архітектури time_t не переповниться на людському рівні.\n");
    #else
        // 32-бітна архітектура
        time_t max_32bit_time = 2147483647;  // Максимум для 32-бітної архітектури
        printf("Максимальний час для 32-бітної архітектури: %ld секунд\n", max_32bit_time);
        printf("Це відбудеться 19 січня 2038 року.\n");
    #endif

    return 0;
}