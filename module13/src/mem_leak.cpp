// Пример утечки памяти в Си++
//

#include <iostream>
#include <string>

using namespace std;

void f(){
    int* ptr = new int[1000000000];
    // delete [] ptr; // освобождаем память за собой...
    // delete ptr; // неопределенное поведение
}

int main()
{
    int count = 0;
    while(1){
        cout << ++count << endl;
        f(); // каждый вызов этой функции выделяет миллиард интов на куче и забывает про них
    }
}

/* После выделения 35183 миллиардов int-ов ~ , на куче кончилось место (в виртуальной памяти).
...
35183
35184
terminate called after throwing an instance of 'std::bad_alloc'
  what():  std::bad_alloc
Aborted (core dumped)
*/
