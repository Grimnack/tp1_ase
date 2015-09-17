/* 
Auteur Matthieu Caron
Fichier try.c
*/
typedef int (func_t) (int); // une fonction qui retourne un int a partir d'un int

struct ctx_s {
   void * ctx_ebp ;
   void * ctx_esp ;
   int magic ;
} ;

/* 
La fonction try sauvegarde un contexte puis appelle la fonction passée en paramètre
param : *pctx le pointeur vers le contexte
        f la fonction
        et arg l'argument qui va être donné a f
*/

int try(struct ctx_s *pctx, func_t *f,int arg){
   static void* ebp ;
   static void* esp ;
   asm( "mov %%ebp, %0 \n\t mov %%esp, %1"
        : "=r" (ebp),
          "=r" (esp)) ;
   pctx->ctx_ebp = ebp ;
   pctx->ctx_esp = esp ;
   pctx->magic = 0xB00B5666 ;
   return f(arg);
}
