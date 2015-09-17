/*
Auteur Matthieu Caron
Utilisé comme un entrainement pour récupérer les variables esp et ebp
*/

#include <stdio.h>

/*
int print_ebp_esp( void ) {
   int ebp, esp;
   asm( "mov %%ebp, %0 \n\t"
        "mov %%esp, %1"
        : "=r"(ebp),
          "=r"(esp) ); 
   printf("ebp = %d et esp = %d \n", ebp, esp) ;
   return 0 ;
}
*/

int g (void) {
   int ebp, esp;
   asm( "mov %%ebp, %0 \n\t"
        "mov %%esp, %1"
        : "=r"(ebp),
          "=r"(esp) ); 
   printf("Dans g() ebp = %d et esp = %d \n", ebp, esp) ;
   return 0;
}

int f(void) {
   int ebp, esp;
   asm( "mov %%ebp, %0 \n\t"
        "mov %%esp, %1"
        : "=r"(ebp),
          "=r"(esp) ); 
   printf("Dans f() ebp = %d et esp = %d \n", ebp, esp) ;
   g();
}

int recursif(int cpt) {
   int ebp, esp;
   if(cpt != 0) {
      asm( "mov %%ebp, %0 \n\t"
           "mov %%esp, %1"
           : "=r"(ebp),
             "=r"(esp) );
      printf("cpt = %d ebp = %d et esp = %d \n", cpt, ebp, esp) ;
      recursif(cpt-1);
   } else {
      return 0 ;
   }  
}

int main(int argc, char *argv[]){
   recursif(5) ;
   f() ;
   return 0;
}
