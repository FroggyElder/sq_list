#ifndef  _SQ_LIST_H_
#define  _SQ_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int SQ_ELEM_TYPE;

struct sq_list {
    SQ_ELEM_TYPE* data;
    int len;
    int tail;
};

struct sq_list* SqNewList (int len);

bool SqDestory (struct sq_list** ll);

bool SqInsertTail (struct sq_list* ll, SQ_ELEM_TYPE val);

bool SqInsertAt (struct sq_list* ll, SQ_ELEM_TYPE val, int pos);

int SqIndex (struct sq_list* ll,SQ_ELEM_TYPE val);

bool SqDeleteByVal (struct sq_list* ll,SQ_ELEM_TYPE val);

bool SqDeleteByIndex (struct sq_list* ll,int index);

bool SqPrint (struct sq_list* ll);

#endif  //_SQ_LIST_H_