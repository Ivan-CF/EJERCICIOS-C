#include <stdio.h>
 
int main ()
{
 
    int tabla;
   
    int i;
   
    printf("escribe un numero");
    scanf("d", &tabla);
    
    getchar ();
    
    for(i=1; i<=10; i++)
    {
      printf("\n %d * %d = %d", tabla, i, tabla * i);
    
    }
   
    getchar();
    
    return 0;
}