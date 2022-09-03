#include <stdio.h>
clasts IntList {

    typedef struct intlist {
        int data;
        struct intlist * nextint;
    } iList_t;
    iList_t * start_of_list; 
    iList_t * end_of_list;
    public:
    IntList (int a) {
       start_of_list = new iList_t;
       start_of_list->data = a;
       start_of_list->nextint = NULL;
       end_of_list = start_of_list;
    }
    ~IntList() {
        iList_t * tmp = start_of_list;
        iList_t * tmp1;

        while (tmp != NULL) {
            tmp1 = tmp->nextint;
            delete(tmp);
            tmp = tmp1;
        }
    }
    int AddToEnd(int a) {
        end_of_list->nextint = new iList_t;
        end_of_list->nextint->data = a;
        end_of_list->nextint->nextint = NULL;
        end_of_list = end_of_list->nextint;
        return(0);
    }
    void PrintList() {
        ilist_t * tmp = start_of_list;
        while (tmp != NULL)
            printf("%d",tmp->data);
            tmp = tmp->nextint;
        }
        printf("\n");
        return;
    }


};



class newclass : public IntClass {

