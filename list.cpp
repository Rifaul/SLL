#include <iostream>
#include "list.h"
using namespace std;

void createList(list &L){
    first(L) = NULL;
    last(L) = NULL;
}

bool isEmpty(list L){
    return (first(L)==NULL) && (last(L)==NULL);
}

void createNewElmt(address &P, infotype X){
    P = new elmlist;
    info(P) = X;
    next(P) = NULL;

}

address findElement(list L, infotype X){
    bool found = false;
    address P = first(L);

    while (P != NULL && !found){
        found = (X == info(P));
        if (!found){
            P = next(P);
        }
    }
    if (found){
        return P;
    } else {
        return NULL;
    }
}

void insertFirst(list &L, address P){
    next(P) = first(L);
    first(L) = P;
    if (last(L) == NULL){
        last(L) = P;
    }
}

void insertLast(list &L, address P){
    if (isEmpty(L)) {
        insertFirst(L, P);
    } else {
        insertAfter(L, last(L), P);
    }
}

void insertAfter(list &L, address Prec, address P){
    next(P) = next(Prec);
    next(Prec) = P;
    if (Prec == last(L)){
        last(L) = P;
    }
}
void deleteFirst(list &L, address &P){
    P = first(L);
    first(L) = next(P);
    if (first(L) == NULL){
        last(L) = NULL;
    }
}
void deleteLast(list &L, address &P){
    if (first(L) == last(L)){
        deleteFirst(L, P);
    } else {
        address t = first(L);
        while (next(t) != last(L)){
            t = next(t);
        }
        deleteAfter(L, t, P);
    }
}

void deleteAfter(list &L, address Prec, address &P){
    P = next(Prec);
    next(Prec) = next(P);
    if (P == last(L)){
        last(L) = Prec;
    }
}

void showList(list L){
    address P = first(L);
    while (P != NULL){
        cout<<info(P)<<" ";
        P = next(P);
    }
    cout<<endl;
}

void sortList(list &L){
    address P = first(L);
    address Prec = NULL;
    infotype temp;

    if (isEmpty(L)){
        return;
    } else {
        while (P != NULL){
            Prec = next(P);
            while (Prec != NULL){
                if (info(P) > info(Prec)){
                    temp = info(P);
                    info(P) = info(Prec);
                    info(Prec) = temp;
                }
            Prec = next(Prec);
            }
        P = next(P);
        }
    }
}

void concat(list L1, list L2, list &L3){
    createList(L3);
    if (isEmpty(L1)){
        first(L3) = first(L2);
        last(L3) = last(L2);
    } else {
        first(L3) = first(L1);
        if (isEmpty(L2)){
            last(L3) = last(L1);
        } else {
            next(last(L1)) = first(L2);
            last(L3) = last(L2);
        }
    }
}

void mergeListA(list L1, list L2, list &L3){
    createList(L3);
    address newElmt, p1, p2;
    p1 = first(L1);
    p2 = first(L2);
    while (p1 != NULL && p2 != NULL){
        if (info(p1) <= info(p2)){
            createNewElmt(newElmt, info(p1));
            insertLast(L3, newElmt);
            p1 = next(p1);
        } else {
            createNewElmt(newElmt, info(p2));
            insertLast(L3, newElmt);
            p2 = next(p2);
        }
    }
    while (p1 != NULL){
        createNewElmt(newElmt, info(p1));
        insertLast(L3, newElmt);
        p1 = next(p1);
    }
    while (p2 != NULL){
        createNewElmt(newElmt, info(p2));
        insertLast(L3, newElmt);
        p2 = next(p2);
    }
}

void mergeListB(list L1, list L2, list &L3){
    createList(L3);
    address newElmt, p1, p2;
    p1 = first(L1);
    p2 = first(L2);
    while (p1 != NULL && p2 != NULL){
        if (info(p1) == info(p2)){
            p1 = next(p1);
        } else if (info(p1) < info(p2)){
            createNewElmt(newElmt, info(p1));
            insertLast(L3, newElmt);
            p1 = next(p1);
        } else {
            createNewElmt(newElmt, info(p2));
            insertLast(L3, newElmt);
            p2 = next(p2);
        }
    }
    while (p1 != NULL){
        createNewElmt(newElmt, info(p1));
        insertLast(L3, newElmt);
        p1 = next(p1);
    }
    while (p2 != NULL){
        createNewElmt(newElmt, info(p2));
        insertLast(L3, newElmt);
        p2 = next(p2);
    }
}

void mergeListC(list L1, list L2, list &L3){
    createList(L3);
    address newElmt, p1, p2;
    p1 = first(L1);
    p2 = first(L2);
    while (p1 != NULL && p2 != NULL){
        if (info(p1) == info(p2)){
            p1 = next(p1);
        } else if (info(p1) < info(p2)){
            createNewElmt(newElmt, info(p1));
            insertFirst(L3, newElmt);
            p1 = next(p1);
        } else {
            createNewElmt(newElmt, info(p2));
            insertFirst(L3, newElmt);
            p2 = next(p2);
        }
    }
    while (p1 != NULL){
        createNewElmt(newElmt, info(p1));
        insertFirst(L3, newElmt);
        p1 = next(p1);
    }
    while (p2 != NULL){
        createNewElmt(newElmt, info(p2));
        insertFirst(L3, newElmt);
        p2 = next(p2);
    }
}

void mergeListD(list L1, list L2, list &L3){
    createList(L3);
    address newElmt, p1, p2;
    p1 = first(L1);
    p2 = first(L2);
    while (p1 != NULL && p2 != NULL){
        if(info(p1) == info(p2)){
            createNewElmt(newElmt, info(p1));
            insertLast(L3, newElmt);
            p1 = next(p1);
        } else if (info(p1) < info(p2)){
            p1 = next(p1);
        } else {
            p2 = next(p2);
        }
    }
}
