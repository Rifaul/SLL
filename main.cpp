#include <iostream>
#include "list.h"

using namespace std;

int main(){
    list L1, L2, L3, L4;
    address P;
    infotype x;
    string merge;

    cout<<"This is the personal training program for Single Linked List"<<endl;
    cout<<"There will be multiple procedure that are connected to SLL"<<endl<<endl;

    cout<<"Enter the element of List 1 (end it with 0)"<<endl;
    createList(L1);
    cin>>x;
    while (x != 0){
        createNewElmt(P, x);
        insertLast(L1, P);
        cin>>x;
    }
    cout<<"List L1 elements: "<<endl;
    showList(L1);
    sortList(L1);
    cout<<"List L1, after sorting: "<<endl;
    showList(L1);
    cout<<endl;

    cout<<"Enter the element of List 2 (end it with 0)"<<endl;
    createList(L2);
    cin>>x;
    while (x != 0){
        createNewElmt(P, x);
        insertLast(L2, P);
        cin>>x;
    }
    cout<<"List L2 elements: "<<endl;
    showList(L2);
    sortList(L2);
    cout<<"List L2, after sorting: "<<endl;
    showList(L2);
    cout<<endl;

    cout<<"What type of Merging would you like to do? (A/B/C/D) / 'done' "<<endl;
    cin>>merge;
    while (merge != "done"){
        if (merge == "A"){
            mergeListA(L1, L2, L4);
        } else if (merge == "B"){
            mergeListB(L1, L2, L4);
        } else if (merge == "C"){
            mergeListC(L1, L2, L4);
        } else if (merge == "D"){
            mergeListD(L1, L2, L4);
        }
        cout<<"The result of type "<<merge<<" merging is: "<<endl;
        showList(L4);
        cout<<endl;
        cout<<"What type of Merging would you like to do? (A/B/C/D) / 'done' "<<endl;
        cin>>merge;
    }
    cout<<endl;

    concat(L1, L2, L3);
    cout<<"The result of the concatination of List 1 and List 2 is: "<<endl;
    showList(L3);
    cout<<endl;

    return 0;
}
