/// для 32-бітної системи
#include <stdio.h>
#include <time.h>
#include <unistd.h>  

void check_time_t_overflow() {
    time_t current_time = time(NULL);

    printf("Поточний час: %ld\n", current_time);
}

int main() {
    time_t mock_time = 2147483644;  

    printf("Початковий час (epoch): %ld\n", mock_time);

    for (int i = 0; i < 5; i++) {
        mock_time++; 
        printf("Час через %d секунд: %ld\n", i + 1, mock_time);
        sleep(1);  
    }

    return 0;
}

/// для 64-бітної системи

/* #include <stdio.h>
#include <time.h>
#include <unistd.h>  

void check_time_t_overflow() {
    time_t current_time = time(NULL);

    printf("Поточний час: %ld\n", current_time);
}

int main() {
    time_t mock_time = 9223372036854775804;  

    printf("Початковий час (epoch): %ld\n", mock_time);

    for (int i = 0; i < 5; i++) {
        mock_time++; 
        printf("Час через %d секунд: %ld\n", i + 1, mock_time);
        sleep(1);  
    }

    return 0;
} */

