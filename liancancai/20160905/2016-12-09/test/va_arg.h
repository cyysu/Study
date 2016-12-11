

#ifndef _VAARG_H
#define _VAARG_H


typedef char *va_list;

/*
 * Storage alignment properties
 */
#define  _AUPBND                (sizeof (int) - 1)
#define  _ADNBND                (sizeof (int) - 1)

/*
 * Variable argument list macro definitions
 */
#define _bnd(X, bnd)            (((sizeof (X)) + (bnd)) & (~(bnd)))
#define va_arg(ap, T)           (*(T *)(((ap) += (_bnd (T, _AUPBND))) - (_bnd (T,_ADNBND))))
#define va_end(ap)              (void) 0
#define va_start(ap, A)         (void) ((ap) = (((char *) &(A)) + (_bnd (A,_AUPBND))))
//va_list  ap ;                 char *ap ; 
//va_start(ap , a);				(void)((ap)=(((char *)&(a))+((sizeof(int)+3)&(~3))))


#endif  //_AUPBND

