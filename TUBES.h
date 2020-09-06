#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include "anak.h"
#include <iostream>
using namespace std;

#define Nil NULL
#define first(L) (L).first
#define child(p) p->child
#define next(p) (p)->next
#define info(p) (p)->info

typedef struct Dept infotypeP;

typedef struct elmP *adrP;

struct Dept
{
    int nemployee;
    float progressdept;
    string depthead;
    string idDept;
    string namedept;
};

struct elmP
{
    infotypeP info;
    adrP next;
    adrC child;
};

struct List
{
    adrP first;
};

void createList(List &L);
adrP alokasiP (infotypeP x);
void insertFirstP (List &L, adrP p);
void insertLastP (List &L, adrP p);
adrP findelmP (List L, string x);
void deleteFirst (List &L, adrP p);
void deleteLast (List &L, adrP &p);
void deletedept (List &L, adrP &q);
void printinfo (List L);
void counttarget (List &L);
void deptprogress (List &L, adrP p);
void bestdeptprogress (List L);
void bestproductiveemp (List L, adrP p);
void employeeproductivity (List &L, adrP p);
void bestdeptprogress (List L);


#endif // TUBES_H_INCLUDED
