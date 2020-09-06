#ifndef ANAK_H_INCLUDED
#define ANAK_H_INCLUDED

#include "TUBES.h"
#include <iostream>
using namespace std;

#define Nil NULL
#define nextC(q) (q)->nextC
#define prev(q) (q)->prev
#define infoC(q) (q)->infoC

typedef struct karyawan infotypeC;
typedef struct elmC *adrC;

struct jam
{
    int HH;
    int MM;
    int DD;
};

struct karyawan
{
    string nama;
    string npwp;
    string jabatan;
    float durasi;
    int progress;
    float productivity;
    jam masuk;
    jam pulang;
};

struct elmC
{
    infotypeC infoC;
    adrC nextC;
    adrC prev;
};

adrC alokasiC (infotypeC x);

#endif // ANAK_H_INCLUDED
