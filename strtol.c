#include <stdio.h>
#include <stdlib.h>

int main () {
   char str[50] = "0001000000010000OK";
   char *ptr;
   long ret;

   ret = strtol(str, &ptr, 10);
   printf("The number(unsigned long integer) is %ld\n", ret);
   printf("String part is |%s|", ptr);

   return(0);
}
