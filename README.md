# LishenkoPW2
1)
1. Напишіть програму для визначення моменту, коли time_t
закінчиться.Дослідіть, які зміни відбуваються в залежності від 32- та
64-бітної архітектури. Дослідіть сегменти виконуваного файлу.


#include <stdio.h>
#include <time.h>


int main() {
   time_t current_time;
  
   // Виведемо поточний час
   current_time = time(NULL);
   printf("Поточний час (epoch): %ld\n", current_time);


   // Визначимо максимальне значення time_t для 32-бітної та 64-бітної архітектури
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




для 64 бит
![image](https://github.com/user-attachments/assets/a971b05b-6659-4fa9-97ee-3b2a854ee1a0)

для 32 бит системи
![image](https://github.com/user-attachments/assets/dbc9c9bc-7d5e-4f81-9e0a-ef92d053e181)

lilpeep@avice:~/pw2 $ objdump -h 1.out

1.out:     file format elf64-x86-64-freebsd

Sections:
Idx Name          Size      VMA               LMA               File off  Algn
  0 .interp       00000015  0000000000400200  0000000000400200  00000200  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  1 .note.tag     00000048  0000000000400218  0000000000400218  00000218  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  2 .hash         00000038  0000000000400260  0000000000400260  00000260  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  3 .dynsym       000000d8  0000000000400298  0000000000400298  00000298  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  4 .dynstr       00000085  0000000000400370  0000000000400370  00000370  2**0
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  5 .gnu.version  00000012  00000000004003f6  00000000004003f6  000003f6  2**1
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  6 .gnu.version_r 00000030  0000000000400408  0000000000400408  00000408  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  7 .rela.dyn     00000030  0000000000400438  0000000000400438  00000438  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  8 .rela.plt     00000060  0000000000400468  0000000000400468  00000468  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
  9 .init         00000006  00000000004004c8  00000000004004c8  000004c8  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 10 .plt          00000050  00000000004004d0  00000000004004d0  000004d0  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 11 .text         00000120  0000000000400520  0000000000400520  00000520  2**4
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 12 .fini         00000006  0000000000400640  0000000000400640  00000640  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, CODE
 13 .rodata       000000a9  0000000000400648  0000000000400648  00000648  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 14 .eh_frame_hdr 00000024  00000000004006f4  00000000004006f4  000006f4  2**2
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 15 .eh_frame     00000084  0000000000400718  0000000000400718  00000718  2**3
                  CONTENTS, ALLOC, LOAD, READONLY, DATA
 16 .init_array   00000008  00000000004017a0  00000000004017a0  000007a0  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 17 .fini_array   00000008  00000000004017a8  00000000004017a8  000007a8  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 18 .dynamic      000001d0  00000000004017b0  00000000004017b0  000007b0  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 19 .got          00000010  0000000000401980  0000000000401980  00000980  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 20 .got.plt      00000038  0000000000401990  0000000000401990  00000990  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 21 .data         00000010  00000000004019c8  00000000004019c8  000009c8  2**3
                  CONTENTS, ALLOC, LOAD, DATA
 22 .bss          00000010  00000000004019d8  00000000004019d8  000009d8  2**3
                  ALLOC
 23 .comment      0000008e  0000000000000000  0000000000000000  000009d8  2**0
                  CONTENTS, READONLY
 24 .debug_aranges 000000b0  0000000000000000  0000000000000000  00000a66  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 25 .debug_info   0000032e  0000000000000000  0000000000000000  00000b16  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 26 .debug_abbrev 000000c1  0000000000000000  0000000000000000  00000e44  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 27 .debug_line   00000295  0000000000000000  0000000000000000  00000f05  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 28 .debug_str    000000de  0000000000000000  0000000000000000  0000119a  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS
 29 .debug_ranges 000000a0  0000000000000000  0000000000000000  00001278  2**0
                  CONTENTS, READONLY, DEBUGGING, OCTETS

2) 
Завдання 2.2.
Розгляньте сегменти у виконуваному файлі.
1. Скомпілюйте програму &quot;hello world&quot;, запустіть ls -l для
виконуваного файлу, щоб отримати його загальний розмір, і
запустіть size, щоб отримати розміри сегментів всередині нього.
2. Додайте оголошення глобального масиву із 1000 int,
перекомпілюйте й повторіть вимірювання. Зверніть увагу на
відмінності.
3. Тепер додайте початкове значення в оголошення масиву
(пам’ятайте, що C не змушує вас вказувати значення для кожного
елемента масиву в ініціалізаторі). Це перемістить масив із сегмента

BSS у сегмент даних. Повторіть вимірювання. Зверніть увагу на
різницю.
4. Тепер додайте оголошення великого масиву в локальну функцію.
Оголосіть другий великий локальний масив з ініціалізатором.
Повторіть вимірювання. Дані розташовуються всередині функцій,
залишаючись у виконуваному файлі? Яка різниця, якщо масив
ініціалізований чи ні?
5. Які зміни відбуваються з розмірами файлів і сегментів, якщо ви
компілюєте для налагодження? Для максимальної оптимізації?
Проаналізуйте результати, щоб переконатися, що:
● сегмент даних зберігається у виконуваному файлі;
● сегмент BSS не зберігається у виконуваному файлі (за винятком
примітки щодо його вимог до розміру часу виконання);
● текстовий сегмент більшою мірою піддається перевіркам
оптимізації;
● на розмір файлу a.out впливає компіляція для налагодження, але не
сегменти.


1)
#include <stdio.h>


int main() {
   printf("Hello, World!\n");
   return 0;
}
![image](https://github.com/user-attachments/assets/b79a73d3-c1b4-40e9-9f2b-d09387655df1)


2)

#include <stdio.h>

int arr[1000];  // Глобальний масив

int main() {
    printf("Hello, World!\n");
    return 0;
}



![image](https://github.com/user-attachments/assets/1ed00021-dc4e-4ab3-b0b6-d677c95bbec0)

3)

#include <stdio.h>


int arr[1000] = {1}; 


int main() {
   printf("Hello, World!\n");
   return 0;
}

![image](https://github.com/user-attachments/assets/1fcaf4a4-1ca4-4496-ae2f-55da3f5eb0ee)

4)
#include <stdio.h>


void func() {
   int local_arr[1000] = {0};  // Локальний масив, ініціалізований нулями
}


int main() {
   printf("Hello, World!\n");
   func();
   return 0;
}


![image](https://github.com/user-attachments/assets/6f55984a-f5cd-44db-a3bf-d0d774bc91d2)

Локальні масиви не зберігаються в BSS чи data сегментах, оскільки вони використовують стек, який не зберігається у виконуваному файлі. Тому дані для таких масивів не зберігаються в самому виконуваному файлі (вони існують тільки в момент виконання програми).

5)
![image](https://github.com/user-attachments/assets/ef4a1c4d-249d-4873-89f8-0714f7d54191)

для налагодження: не зминюэться
для оптимизации: зменшуется розмир файлу

3)

#include <stdio.h>


int main() {
   int i;
   printf("The stack top is near %p\n", &i);
   return 0;
}
![image](https://github.com/user-attachments/assets/20e46877-7f49-4ed8-b565-39ce7fc64bcd)

#include <stdio.h>
#include <stdlib.h>


int global_var = 42;  // глобальна змінна (сегмент даних)


void func() {
   int local_var = 10;  // локальна змінна (стек)
   printf("The address of local_var (stack) is %p\n", &local_var);
}


int main() {
   int i;
   char *heap_var = (char *)malloc(1000 * sizeof(char)); // змінна в купі


   // Виведення адреси змінних
   printf("The stack top is near %p\n", &i);
   printf("The address of global_var (data) is %p\n", &global_var);
   printf("The address of heap_var (heap) is %p\n", heap_var);


   // Викликаємо функцію для демонстрації стека
   func();


   // Очищаємо купу
   free(heap_var);
  
   return 0;
}




![image](https://github.com/user-attachments/assets/4937d78e-00f0-4bd1-aeb4-0164eb19fa11)

#include <stdio.h>
#include <stdlib.h>


int global_var = 42;


void func() {
   int local_var = 10;
   int large_array[10000];  // Великий локальний масив
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





![image](https://github.com/user-attachments/assets/5ac4db54-aea7-4b6c-9ed9-bdbed38724c0)

4)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#define MSG "In function %20s; &localvar = %p\n"
static void bar_is_now_closed(void) {
int localvar = 5;
printf(MSG, __FUNCTION__, &localvar);
printf("\n Now blocking on pause()...\n");
pause();
}
static void bar(void) {
int localvar = 5;
printf(MSG, __FUNCTION__, &localvar);
bar_is_now_closed();
}
static void foo(void) {
int localvar = 5;
printf(MSG, __FUNCTION__, &localvar);
bar();
}
int main(int argc, char **argv) {
int localvar = 5;
printf(MSG, __FUNCTION__, &localvar);
foo();
exit(EXIT_SUCCESS);
}




GDB:
![image](https://github.com/user-attachments/assets/2f328d34-b5cb-434e-9b2e-7480e4278ec5)

запустил процес и подключился через gdb –quiet attach <PID> и сделал backtrace как и указано в задании

5)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Добавить эту строку для использования pause()


#define MSG "In function %20s; &localvar = %p\n"


// Функция для имитации использования вершины стека
void call_function(void (*func)(void)) {
   // Манипуляции с вершиной стека
   void *return_address;
   __asm__("mov %%rbx, %0" : "=r"(return_address));  // Сохраняем текущий адрес возврата
   printf("Returning to address: %p\n", return_address);
   func();  // Вызов функции
}


// Функции, которые вызывают друг друга
static void bar_is_now_closed(void) {
   int localvar = 5;
   printf(MSG, __FUNCTION__, &localvar);
   printf("\n Now blocking on pause()...\n");
   pause();  // Приостановка выполнения
}


static void bar(void) {
   int localvar = 5;
   printf(MSG, __FUNCTION__, &localvar);
   call_function(bar_is_now_closed);  // Используем вершину стека для вызова функции
}


static void foo(void) {
   int localvar = 5;
   printf(MSG, __FUNCTION__, &localvar);
   call_function(bar);  // Используем вершину стека для вызова функции
}


int main(int argc, char **argv) {
   int localvar = 5;
   printf(MSG, __FUNCTION__, &localvar);
   call_function(foo);  // Используем вершину стека для вызова функции
   exit(EXIT_SUCCESS);
}



Вершина стека не може повністю замінити лічильник команд, оскільки стек зберігає тільки адреси повернення, але не вказує на поточну інструкцію в програмі.
В цьому приклады ми використовуэмо вершину стеку замисть IP для реализации програмы.

6)
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


![image](https://github.com/user-attachments/assets/1d13b1d8-9aba-4004-b54d-8c54a94ec730)












