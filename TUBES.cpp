#include <iostream>
#include "TUBES.h"
#include "anak.h"
#include "COLLAB.h"
#include <string>
using namespace std;

void createList(List &L)
{
    first(L) = NULL;
}

adrP alokasiP(infotypeP x)
{
    adrP p;
    p = new elmP;
    info(p).depthead = x.depthead;
    info(p).nemployee = x.nemployee;
    info(p).idDept = x.idDept;
    info(p).namedept = x.namedept;
    next(p) = NULL;
    child(p) = NULL;

    return p;
}

adrC alokasiC (infotypeC x)
{
    adrC p;
    p = new elmC;
    infoC(p).nama = x.nama;
    infoC(p).npwp = x.npwp;
    infoC(p).jabatan = x.jabatan;
    infoC(p).masuk = x.masuk;
    infoC(p).pulang = x.pulang;
    //infoC(p).progress = x.progress;
    nextC(p) = NULL;
    prev(p) = NULL;

    return p;
}

void insertFirstP(List &L, adrP p)
{
    if (first(L) == NULL)
    {
        first(L) = p;
    }
    else
    {
        next(p) = first(L);
        first(L) = p;
    }
}

void insertfirstC (List &L, adrC p, adrP q)
{
    if (child(q) == NULL)
    {
        child(q) = p;
        //prev(p) = q;
    }
    else
    {
        nextC(p) = child(q);
        prev(nextC(p)) = p;
        child(q) = p;
        //prev(p) = q;
    }
}

void insertLastP(List &L, adrP p)
{
    adrP q;
    if (first(L) == NULL)
    {
        first(L) = p;
    }
    else
    {
        q = first(L);
        while(next(q) != NULL)
        {
            q = next(q);
        };
        next(q) = p;
        next(p) = NULL;
    }
}

void insertlastC (List &L, adrC p, adrP q)
{
    adrC s;
    if (child(q) == NULL)
    {
        child(q) = p;
        //prev(p) = q;
    }
    else
    {
        s = child(q);
        while (nextC(s) != NULL)
        {
            s = nextC(s);
        }
        nextC(s) = p;
        prev(p) = s;
        nextC(p) = NULL;
    }
}

adrP findelmP(List L, string x)
{
    adrP p;
    p = first(L);
    while ((info(p).idDept != x) && (p != NULL))
    {
        p = next(p);
    }
    if (info(p).idDept == x)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}

adrC findelmC (List L, string x, adrP &p)
{
    adrC q;
    p = first(L);
    while ((p != NULL) && (infoC(q).npwp != x))
    {
        q = child(p);
        while ((q != NULL) && (infoC(q).npwp != x))
        {
            q = nextC(q);
        }
        p = next(p);
    }
    if (x == infoC(q).npwp)
    {
        return q;
    }
    else
    {
        return NULL;
    }
}

void deletefirstC(List &L, adrC &p, adrP q)
{
    if (child(q) == NULL)
    {
        cout << "KOSONG";
    }
    else
    {
        p = child(q);
        child(q) = nextC(p);
        //prev(nextC(p)) = q;
        nextC(p) = NULL;
        prev(p) = NULL;
    }
}

void deletelastC (List &L, adrC &p, adrP q)
{
    if (child(q) == NULL)
    {
        cout << "KOSONG";
    }
    else
    {
        adrC s;
        s = child(q);
        while ((nextC(nextC(s)) != NULL))
        {
            s = nextC(s);
        }
        p = nextC(s);
        nextC(s) = NULL;
        prev(p) = NULL;
    }
}

void deleteLast(List &L, adrP &p)
{
    adrP q;
    if (first(L) == NULL)
    {
        cout << "KOSONG BOS" << endl;
    }
    else
    {
        q = first(L);
        while (next(next(q)) != NULL)
        {
            q = next(q);
        }
        p = next(q);
        next(q) = NULL;
    }
}

void printinfo(List L)
{
    adrP p;
    adrC q;
    if (first(L) != NULL)
    {
        p = first(L);
        while (p != NULL)
        {
            cout << "Nama Departemen : " << info(p).namedept << endl;
            cout << "ID Departemen : " << info(p).idDept << endl;
            cout << "Kepala Departemen : " << info(p).depthead << endl;
            cout << "Jumlah Anggota : " << info(p).nemployee << endl;
            q = child(p);
            while (q != NULL)
            {
                cout << "Nama Karyawan : " << infoC(q).nama << endl;
                cout << "NPWP : " << infoC(q).npwp << endl;
                q = nextC(q);
            }
            p = next(p);
        }
    }
    else
    {
        cout << "KOSONG BOS" << endl;
    }
}

void deletefirst(List &L, adrP p)
{
    if (first(L) == NULL)
    {
        cout << "KOSONG BOS" << endl;
    }
    else
    {
        p = first(L);
        first(L) = next(p);
        next(p) = NULL;
    }
}

void counttarget(List &L)
{
    adrC p;
    adrP q;
    string no;

    cout << "Masukan Nomor NPWP anda : ";
    cin >> no;

    p = findelmC(L, no, q);

    if (p == NULL)
    {
        cout << "Data tidak ditemukan..." << endl;
    }
    else
    {
        cout << "Masukan progress hari ini : ";
        cin >> infoC(p).progress;
        cout << "Masukan lama kerja hari ini : ";
        cin >> infoC(p).durasi;
    }
}

void deptprogress(List &L, adrP p)
{
    float pro;
    int i;
    p = first(L);
    while (p != NULL)
    {
        adrC q;
        q = child(p);
        while (q != NULL)
        {
            pro = pro + infoC(q).progress;
            i++;
            q = nextC(q);
        }
        info(p).progressdept = pro / i;
        cout << info(p).namedept << " : " << info(p).progressdept << endl;
        p = next(p);
    }
}

void bestdeptprogress (List L)
{
    adrP p, q;
    float temp;

    p = next(first(L));
    temp = info(first(L)).progressdept;
    while (p != NULL)
    {
        if (temp < info(p).progressdept)
        {
            temp = info(p).progressdept;
            q = p;
        }
        p = next(p);
    }
    cout << "Departemen Progress terbaik : " << info(q).namedept;
}

void employeeproductivity (List &L, adrP p)
{
    adrC q;

    q = child(p);
    while (q != NULL)
    {
        infoC(q).productivity = infoC(q).progress / infoC(q).durasi;
        q = nextC(q);
    }
}

void bestproductiveemp (List L, adrP p)
{
    adrC q;
    string nama, npwp;

    q = child(p);
    float temp = infoC(q).productivity;
    q = nextC(q);

    while (q != NULL)
    {
        if (temp < infoC(q).productivity)
        {
            temp = infoC(q).productivity;
            nama = infoC(q).nama;
            npwp = infoC(q).npwp;
        }
        q = nextC(q);
    }
    cout << " Karyawan Paling Produktif : " << nama << " NPWP : " << infoC(q).npwp << endl;
    cout << "Dengan produktivitas sebesar : " << temp;
}

void deletedept (List &L, adrP &q)
{
    string dept;
    cout << " WARNING DELETE A DEPERTMENT WILL CAUSE AN ENTIRE DEPARTMENT ASSETS GONE" << endl;
    cout << "Which Department ? : ";
    cin >> dept;

    q = findelmP(L, dept);
    if (q == first(L))
    {
        first(L) = next(q);
        next(q) = NULL;
    }
    else if (next(q) == NULL)
    {
        deleteLast(L, q);
    }
    else
    {
        adrP p = first(L);
        while (next(p) != q)
        {
            p = next(p);
        }
        next(p) = next(q);
        next(q) = NULL;
    }
}

void deleteemp(List &L, adrC &p)
{
    adrP q;
    string id;
    cout << "Input the Employee ID : ";
    cin >> id;

    p = findelmC(L, id, q);
    if (prev(p) == NULL)
    {
        deletefirstC(L, p, q);
    }
    else if (nextC(p) == NULL)
    {
        deletelastC(L, p, q);
    }
    else
    {
        adrC s = prev(p);
        nextC(s) = nextC(p);
        prev(nextC(p)) = prev(p);
        nextC(p) = NULL;
        prev(p) = NULL;
    }
}

int convertseconds (int sum)
{
    jam out;
}

void convertdurasi (List L)
{
    adrP p;
    string cari;
    cout << "Input the ID of Employee : ";
    cin >> cari;
    adrC q = findelmC(L, cari, p);
    if (q == NULL)
    {
        cout << "System cannot find the specified ID";
    }
    else
    {
        int tot1 = infoC(q).masuk.HH*3600 + infoC(q).masuk.MM*60 + infoC(q).masuk.DD;
        int tot2 = infoC(q).pulang.HH*3600 + infoC(q).pulang.MM*60 + infoC(q).pulang.DD;
        int tot = tot2 - tot1;
        cout << "Man Hour : " << tot << " Seconds";
    }
}



