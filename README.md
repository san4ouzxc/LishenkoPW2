# Lishenko Practice Work 2
## Завдання 1
### для 64-бітної системи:

Встановлюємо початковий час, який буде близкий до верхньої границі time_t у 64-бітній архітектурі

При переповненні time_t на 64-бітній архітектурі (де максимальне значення для time_t складає 9223372036854775807), коли цей лічильник досягає свого максимального значення, він "переповнюється" і починає відлік з мінімального значення для 64-бітного типу — -9223372036854775808.

![image](https://github.com/user-attachments/assets/edbe8dbd-72f4-450b-aaab-65769bb5422b)


### для 32-бітної:

використовуємо додатковий флаг -m32 для компіляції у 32-бітній архітектурі 

![image](https://github.com/user-attachments/assets/315c6693-e5c3-4e02-96c9-0a42a1c28b60)

Сегменти виконуваного файлу для 64-бітної архітектури використовують більше пам'яті:


![image](https://github.com/user-attachments/assets/e500cae5-fdda-46a8-a692-1efbedc239bc)




### Завдання 2
1

![image](https://github.com/user-attachments/assets/b79a73d3-c1b4-40e9-9f2b-d09387655df1)


2

![image](https://github.com/user-attachments/assets/1ed00021-dc4e-4ab3-b0b6-d677c95bbec0)

3

![image](https://github.com/user-attachments/assets/1fcaf4a4-1ca4-4496-ae2f-55da3f5eb0ee)

![image](https://github.com/user-attachments/assets/6f55984a-f5cd-44db-a3bf-d0d774bc91d2)

Локальні масиви не зберігаються в BSS чи data сегментах, оскільки вони використовують стек, який не зберігається у виконуваному файлі. Тому дані для таких масивів не зберігаються в самому виконуваному файлі (вони існують тільки в момент виконання програми).

4 

![image](https://github.com/user-attachments/assets/8a1fbddc-bca7-48ea-8c42-2585bc1e3308)



5

![image](https://github.com/user-attachments/assets/ef4a1c4d-249d-4873-89f8-0714f7d54191)

для налагодження: не зминюэться
для оптимизации: зменшуется розмир файлу

### 3)

![image](https://github.com/user-attachments/assets/20e46877-7f49-4ed8-b565-39ce7fc64bcd)

![image](https://github.com/user-attachments/assets/4937d78e-00f0-4bd1-aeb4-0164eb19fa11)

![image](https://github.com/user-attachments/assets/5ac4db54-aea7-4b6c-9ed9-bdbed38724c0)

### 4)

GDB:

![image](https://github.com/user-attachments/assets/2f328d34-b5cb-434e-9b2e-7480e4278ec5)

запустил процес и подключился через gdb –quiet attach <PID> и сделал backtrace как и указано в задании

### 5)
Вершина стека не може повністю замінити лічильник команд, оскільки стек зберігає тільки адреси повернення, але не вказує на поточну інструкцію в програмі.
В цьому приклады ми використовуэмо вершину стеку замисть IP для реализации програмы.

### 6)

![image](https://github.com/user-attachments/assets/1d13b1d8-9aba-4004-b54d-8c54a94ec730)
