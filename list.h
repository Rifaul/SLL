#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define info(P) P->info
using namespace std;
typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct list {
    address first, last;
};

void createList(list &L);
bool isEmpty(list L);
void createNewElmt(address &P, infotype X);
address findElement(list L, infotype X);
void insertFirst(list &L, address P);
void insertLast(list &L, address P);
void insertAfter(list &L, address Prec, address P);
void deleteFirst(list &L, address &P);
void deleteLast(list &L, address &P);
void deleteAfter(list &L, address Prec, address &P);
void showList(list L);
void sortList(list &L);
void concat(list L1, list L2, list &L3);
void mergeListA(list L1, list L2, list &L3);
void mergeListB(list L1, list L2, list &L3);
void mergeListC(list L1, list L2, list &L3);
void mergeListD(list L1, list L2, list &L3);

#endif // LIST_H_INCLUDED
