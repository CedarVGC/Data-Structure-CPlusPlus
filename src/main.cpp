#include <iostream>
#include "..\test\Q2\test_q1.h"
#include "../include/LinearTable/LinkedList.h"
int main() {
   //test_Q2();
   LinkList<int> s;
   s.List_HeadInsert(1);
   s.List_HeadInsert(2);
   s.PrintLinkList();
   return 0;
}