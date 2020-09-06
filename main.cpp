#include <iostream>
#include "COLLAB.h"
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main()
{
    List L;
    infotypeP x;
    infotypeC y;
    adrP q;
    adrC p;
    createList(L);
    int menu;
    while (menu != 0)
    {
        system("cls");
        cout << " - - - - - - - - - - - - - - - - - - - " << endl;
        cout << "   ORGANIZATIONAL PRODUCTIVITY V 1.0   " << endl;
        cout << " - - - - - - - - - - - - - - - -  - - -" << endl;
        cout << "" << endl;
        cout << "1. Add Department " << endl;
        cout << "2. Add New Employee " << endl;
        cout << "3. Add Progress for Employee " << endl;
        cout << "4. Delete a Department " << endl;
        cout << "5. Delete an Employee " << endl;
        cout << "6. Best Department " << endl;
        cout << "7. Best Employee " << endl;
        cout << "8. Look for All Employee " << endl;
        cout << "0. Exit from The App "<< endl;
        cout << "\n\nChoose Menu: ";
        cin >> menu;

        if (menu == 1)
        {
            system("cls");
            cout << "Input Department Name : " ;
            cin >> x.namedept;
            cout << "Input the Head of Department's Name : " ;
            cin >> x.depthead;
            cout << "Input Department Signature : " ;
            cin >> x.idDept;
            cout << "Input The Number of Employee : " ;
            cin >> x.nemployee;
            insertFirstP(L, alokasiP(x));
            cout << " Enter To Continue";
            getch();
        }
        else if (menu == 2)
        {
            system("cls");
            string namadept;
            cout << "Input Name : " ;
            cin >> y.nama;
            cout << "Input Employee ID (NPWP) : " ;
            cin >> y.npwp;
            cout << "Input Arrival Time (HH, MM, DD) : " ;
            cin >> y.masuk.HH; cin >> y.masuk.MM; cin >> y.masuk.DD;
            cout << "Input Finish Time (HH, MM, DD) : " ;
            cin >> y.pulang.HH; cin >> y.pulang.MM; cin >> y.pulang.DD;
            cout << "Input Your Department : ";
            cin >> namadept;
            q = findelmP(L, namadept);
            p = alokasiC(y);
            insertfirstC(L, p, q);
            cout << "Enter to Continue";
            getch();
        }
        else if (menu == 3)
        {
            system("cls");
            counttarget(L);
            getch();
        }
        else if (menu == 4)
        {
            system("cls");
            deletedept(L, q);
            getch();
        }
        else if (menu == 5)
        {
            system("cls");
            deleteemp(L, p);
            getch();
        }
        else if (menu == 6)
        {
            system("cls");
            deptprogress(L, q);
            bestdeptprogress(L);
            getch();
        }
        else if (menu == 7)
        {
            system("cls");
            string ndept;
            cout << " Which Department : ";
            cin >> ndept;
            employeeproductivity(L, findelmP(L, ndept));
            bestproductiveemp(L, findelmP(L, ndept));
            getch();
        }
        else if (menu == 8)
        {
            system("cls");
            printinfo(L);
            getch();
        }
    }
    return 0;
}
