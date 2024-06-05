#include "sq_list.h"

struct sq_list* SqNewList (int len) {
    struct sq_list* new_ll = (struct sq_list*)malloc(sizeof(struct sq_list));
    if (new_ll==NULL) {
        perror ("malloc");
        return NULL;
    }
    new_ll->data = (SQ_ELEM_TYPE*)malloc(sizeof(SQ_ELEM_TYPE)*len);
    if (new_ll->data==NULL) {
        perror ("malloc");
        goto init_error;
    }

    //put the tail and length in
    new_ll->tail = 0;
    new_ll->len = len;

    //if all is good
    return new_ll;

init_error:
    free(new_ll);
    return NULL;
}

bool SqDestory (struct sq_list** ll) {  //we are using pointer to struct pointer here
    if (*ll == NULL) return true;

    (*ll)->tail=0;
    free((*ll)->data);
    free(*ll);

    *ll = NULL; //so we can set it to NULL
    return true;
}

bool SqInsertTail (struct sq_list* ll, SQ_ELEM_TYPE val) {
    if (ll->tail>ll->len||ll==NULL) return false;
    ll->data[ll->tail++]=val;
    return true;
}

bool SqInsertAt (struct sq_list* ll, SQ_ELEM_TYPE val, int pos) {
    if (pos<0||pos>ll->len-1||ll==NULL) return false;

    if (pos==ll->tail) {
        ll->data[ll->tail++]=val;
        return true;
    }

    for (int i=ll->tail-1;i>=pos;--i)
        ll->data[i+1] = ll->data[i];

    ll->data[pos] = val;
}

int SqIndex (struct sq_list* ll, SQ_ELEM_TYPE val) {
    if (ll==NULL) return -1;

    for (int i=0;i<ll->tail;i++)
        if (ll->data[i]==val) return i;

    return -1;
}

bool SqDeleteByVal (struct sq_list* ll,SQ_ELEM_TYPE val) {
    if (ll==NULL) return false;

    for (int i=0;i<ll->tail;i++)
        if(ll->data[i]==val) {
            SqDeleteByIndex(ll,i);
            return true;
        }

    return false;
}

bool SqDeleteByIndex (struct sq_list* ll,int index) {
    if (ll==NULL) return false;
    for (int i=index;i<ll->tail-1;i++)
        ll->data[i] = ll->data[i+1];
    --ll->tail;
    return true;
}

bool SqPrint (struct sq_list* ll) {
    for (int i=0;i<ll->tail;i++)
        printf("%d ",ll->data[i]);
    printf("\n");
}


int main () {
    struct sq_list* list0 = SqNewList(32);
    for (SQ_ELEM_TYPE i=0;i<=5;i++) {
        SqInsertTail(list0,i);
    }

    SqInsertAt(list0,114514,3);

    SqPrint(list0);

    SqIndex(list0,114514);

    SqDeleteByVal(list0,3);

    SqPrint(list0);

    SqDestory(&list0);
}