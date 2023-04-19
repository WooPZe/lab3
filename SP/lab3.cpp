#include<iostream>
#include<ctime>
using namespace std;
int main()
{
  srand(time(0));
  const int n = 11;
  char array[n];
  cout<<"Сенерированный массив:\n";
  for (int i = 0; i < n; i++)
  {
    array[i] = rand() % 26 + 97;
    cout << array[i] <<" ";
  }
  cout << endl;
  char *ptr_array = &array[0];
  char *end_array = &array[n-1];
  __asm__(
  "xor %%rax, %%rax" "\n\t"
  "xor %%rbx, %%rbx" "\n\t"
  "mov %[ptr_array], %%rsi" "\n\t"
  "mov %[end_array], %%rdi" "\n\t"
  "jmp strt" "\n\t"
  "doing:" "\n\t"
  "mov (%%rsi), %%al" "\n\t"
  "mov (%%rdi), %%bl" "\n\t"
  "xor %%al, %%bl" "\n\t"
  "xor %%bl, %%al" "\n\t"
  "xor %%al, %%bl" "\n\t"
  "mov %%al, (%%rsi)" "\n\t"
  "mov %%bl, (%%rdi)" "\n\t"
  "inc %%rsi" "\n\t"
  "dec %%rdi" "\n\t"
  "strt:" "\n\t"
  "cmp %%rsi, %%rdi" "\n\t"
  "jg doing" "\n\t"
  :
  :[ptr_array] "m" (ptr_array),[end_array]  "m"  (end_array)
  :  "%rax"  ,  "%rbx");
  cout<<"Инвертированный массив:\n";
  for (int i = 0; i < n; i++)
  {
    cout << array[i] <<" ";
  }
  cout << "\n";
  return 0;}

