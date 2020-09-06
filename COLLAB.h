#ifndef COLLAB_H_INCLUDED
#define COLLAB_H_INCLUDED

#include "TUBES.h"
#include "anak.h"

void insertfirstC(List &L, adrC p, adrP q);
void insertlastC (List &L, adrC p, adrP q);
adrC findelmC (List L, string x, adrP &p);
void deletefirstC (List &L, adrC &p, adrP q);
void deleteLastC (List &L, adrC &p, adrP q);
void deleteemp (List &L, adrC &p);
void convertdurasi (List);
int convertseconds(int sum);



#endif // COLLAB_H_INCLUDED
