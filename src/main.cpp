#include <iostream>
#include "..\test\Q2\test_q1.h"
#include "..\include\LinearTable\LinkedList.h"
#include "..\include\SString\SString.h"
void test_LinkList(){
   LinkList<int> s;
   s.List_TailInsert(1);
   s.List_TailInsert(2);
   s.List_TailInsert(3);
   s.List_TailInsert(4);
   s.delete_Node(1);
   s.PrintLinkList();
   s.Insert_Node(1,2);
   s.PrintLinkList();
}
int main() {
   //test_Q2();
   //test_LinkList();
   std::string s="abcd";
   std::string t="dd";
   std::cout<<Index(s,t);
   return 0;
}