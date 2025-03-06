/// 1
#include <stdio.h>

int main() {
   printf("Hello, World!\n");
   return 0;
}

/// 2
#include <stdio.h>

int arr[1000];  

int main() {
    printf("Hello, World!\n");
    return 0;
}

/// 3
#include <stdio.h>

int arr[1000] = {1}; 

int main() {
   printf("Hello, World!\n");
   return 0;
}

/// 4
#include <stdio.h>

void func() {
    int local_arr[1000] = {1};  
}

int main() {
    printf("Hello, World!\n");
    func();
    return 0;
}
