#include "user.h"

T_user *user[MAX_USER];
int u_count = 0;
int available_user() //유저를 추가할 공간이 남아 있는가?
{
    int i;
    for (i = 0; i < MAX_USER; i++)
    {
        if (user[i] == NULL)
            return 1;
    }
    return 0;
}

T_user *u_search_by_name(char *n)   //
{
    int i;
    for (i = 0; i < MAX_USER; i++)
    {
        if (user[i] && strcmp(user[i]->name, n) == 0)
            return user[i];
    }
    return NULL;
}
T_user *u_search_by_name_index(char *n)   //
{
    int i;
    for (i = 0; i < MAX_USER; i++)
    {
        if (user[i] && strcmp(user[i]->name, n) == 0)
            return i;
    }
    return NULL;
}
void u_create(char *n, int a, int g) //유저 정보 입력&저장
{
    int index = u_first_available();
    user[index] = (T_user *)malloc(sizeof(T_user));
    T_user *p = user[index];
    strcpy(p->name, n);
    p->age = a;
    p->gender = g;
    u_count++;
}
void u_editer(char *n, int a, int g)
{
    int index = u_search_by_name_index(n);
    user[index] = (T_user *)malloc(sizeof(T_user));
    T_user *p = user[index];
    strcpy(p->name, n);
    p->age = a;
    p->gender = g;
}
void u_delete(T_user *p){
    int i,index;
    for (i=0;i<MAX_USER; i++)
    {
        if(user[i] == p){
            index = 1;
            break;
        }
    }
    free(p);
    user[index] = NULL;
    u_count --;
}
int U_count()
{
    return u_count;
}
int u_first_available()   // 추가할 수 있는 가장 빠른 포인터 배열의 인덱스 찾기
{ 
    int i;
    for (i = 0; i < MAX_USER; i++)
    {
        if (user[i] == NULL)
            return i;
    }
    return -1;
}

char *u_getname(T_user *p)
{
    return p->name;
}
int *u_getage(T_user *p)
{
    int i = p->age;
    return i;
}
char *u_getgender(T_user *p)
{
    if(p->gender == 1) return "man";
    else if(p->gender == 2) return "woman";
    return "noting";
}
void u_get_all(T_user *a[]){
    int i,c =0;
    for (i =0;i<MAX_USER; i++){
        if(user[i]){
            a[c] = user[i];
            c++;
        }
    }
}
