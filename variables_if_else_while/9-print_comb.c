#include <stdio.h>

/**
 * main - prints all possible combinations of single-digit numbers.
 *
 * My function: loop
 *
 * Return: Always 0 (Success)
 */
int main (void){
for( int a=0;a<10;a++);
putchar(a ,", ");
putchar(48 + a);
if (a < 9){
putchar(44);
putchar(32);
}
}
putchar('\n');
return (0);
}

