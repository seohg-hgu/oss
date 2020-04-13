#include "user.h"
#include "vote.h"

void create_user();
void create_vote();
void read_user();
void read_vote();
void editer_user();
void editer_vote();
void delete_user();
void delete_vote();
void list_user();
void list_vote();
//////
void start_vote(); //투표 시작

int main(void)
{
    while (1)
    {
        int menu;
        printf("\nMenu : User(1) vote(2) Start Vote(3) exit(0)\n");
        scanf("%d", &menu);
        printf("\n");
        if (menu == 1) // User
        {
            while (1)
            {
                printf("\nMenu_User : Create New User(1) Read User(2) Editer User(3) Delete User(4) List User(5) Exit(0)\n");
                scanf("%d", &menu);
                printf("\n");
                if (menu == 1) //Create New User
                {
                    create_user();
                }
                else if (menu == 2) //Read User
                {
                    read_user();
                }
                else if (menu == 3) //Editer User
                {
                    editer_user();
                }
                else if (menu == 4)
                { //Delete User
                    delete_user();
                }
                else if (menu == 5)
                { //List user
                    list_user();
                }
                else if (menu == 0) //exit
                    break;
            }
        }
        else if (menu == 2) //Vote
        {
            while (1)
            {
                printf("\nMenu_Vote : Create New Vote(1) Read Vote(2) Editer Vote(3) Delete Vote(4) List Vote(5) exit(0)\n");
                scanf("%d", &menu);
                printf("\n");
                if (menu == 1) //Create new vote
                {
                    create_vote();
                }
                else if (menu == 2) //Read vote
                {
                    read_vote();
                }
                else if (menu == 3) //Editer Vote
                {
                    editer_vote();
                }
                else if (menu == 4)
                { //Delte Vote
                    delete_vote();
                }
                else if (menu == 5)
                { //List vote
                    list_vote();
                }
                else if (menu == 0) //exit
                    break;
            }
        }
        else if (menu == 3) //Start
        {
            start_vote();
            //1. 1개라도 만들어진 투표 주제가 있는 확인     //list_vote에서 모두다 NULL 일 경우 0 -> break;
            //2. 유저 이름 입력 받기                   // 만들어져 있는 user인지 확인, 이미 투표한 user인지 확인
            //3. 투표 주제들 list 나열하기
            //4. 투표 주제 선택하기
            //5. 투표하기
            //6. 현재 투표된 선택지 현황 전체 정리해서 보여주기     // 각 선택지에 투표된 수만 print한다.(익명) //나중에 실명 모드도 만들기
        }
        else if (menu == 0) //exit
            break;
    }
}

void create_user()
{
    char name[20];
    int age, gender;
    if (available_user() == 0)
    {
        printf("Sorry there is no space :(\n");
    }
    else
    {
        printf("Enter a new user's info.\n");
        printf("Name > ");
        scanf("%s", name);
        if (u_search_by_name(name))
        {
            printf("Duplicated %s !\n", name);
            return;
        }
        printf("age > ");
        scanf("%d", &age);
        printf("man(1) or woman(2) > ");
        scanf("%d", &gender);
        u_create(name, age, gender);
    }
}
void create_vote()
{
    char name[20];
    int amount;
    if (available_vote() == 0)
    {
        printf("Sorry there is no space :(\n");
    }
    else
    {
        printf("Enter a new vote's info.\n");
        printf("Name > ");
        scanf("%s", name);
        if (v_search_by_name(name))
        {
            printf("Duplicated %s !\n", name);
            return;
        }
        printf("몇개의 선택지를 만들겠습니까? > ");
        scanf("%d", &amount);
        v_create(name, amount);
    }
}
void read_user()
{
    //이름을 입력받으면 이름~도시까지 프린트해주고 끝낸다
    //단, 없는 이름일 경우 "No such member :(" 예외 처리를 해준다.
    char name[20];
    printf("Enter a user name > ");
    scanf("%s", name);
    if (u_search_by_name(name) != NULL)
    {
        T_user *p = u_search_by_name(name);
        printf("Name > %s\n", u_getname(p));
        printf("age > %d\n", u_getage(p));
        printf("gender > %s\n", u_getgender(p));
    }
    else
        printf("No such member :(\n");
}
void read_vote()
{
    //이름을 입력받으면 이름~도시까지 프린트해주고 끝낸다
    //단, 없는 이름일 경우 "No such member :(" 예외 처리를 해준다.
    char name[20];
    printf("Enter a vote name > ");
    scanf("%s", name);
    if (v_search_by_name(name) != NULL)
    {
        T_vote *p = v_search_by_name(name);
        printf("Name > %s\n", v_getname(p));
        printf("amount > %d\n", v_getamount(p));
        printf("choise >\n");
        for (int i = 0; i < p->amount; i++)
        {
            printf("%d. %s\n", i + 1, v_getchoice(p, i));
        }
    }
    else
        printf("No such member :(\n");
}
void editer_user()
{
    char name[20];
    int age, gender;
    printf("editer a user name > ");
    scanf("%s", name);
    if (u_search_by_name(name) != NULL)
    {
        printf("age > ");
        scanf("%d", &age);
        printf("man(1) or woman(2) > ");
        scanf("%d", &gender);
        u_editer(name, age, gender);
    }
    else
        printf("No such user :(\n");
}
void editer_vote()
{
    char name[20];
    int amount, menu;
    printf("Enter a vote name > ");
    scanf("%s", name);
    if (v_search_by_name(name) != NULL)
    {
        T_vote *p = v_search_by_name(name);

        while (1)
        {
            printf("Editer Vote Amount(1) Editer Vote Choice(2) Exit(0) : ");
            scanf("%d", &menu);
            if (menu == 1)
            {
                printf("선택지를 몇개로 만들겠습니까? > ");
                scanf("%d", &amount);
                v_editer(p, amount);
            }
            else if (menu == 2)
            {
                v_editer_choice(p);
            }
            else if (menu == 0)
                break;
        }
    }
    else
        printf("No such vote :(\n");
}
void delete_user()
{
    char name[20];
    printf("Enter a name > ");
    scanf("%s", name);
    if (u_search_by_name(name) != NULL)
    {
        T_user *p = u_search_by_name(name);
        u_delete(p);
        printf("User is deleted :)\n");
    }
    else
        printf("No such user :(\n");
}
void delete_vote()
{
    char name[20];
    printf("Enter a name > ");
    scanf("%s", name);
    if (v_search_by_name(name) != NULL)
    {
        T_vote *p = v_search_by_name(name);
        v_delete(p);
        printf("Vote is deleted :)\n");
    }
    else
        printf("No such vote :(\n");
}
void list_user()
{
    printf("All User.\n");
    int size = U_count();
    T_user *all_user[MAX_USER];
    u_get_all(all_user);
    for (int i = 0; i < size; i++)
    {
        T_user *p = all_user[i];
        printf("%d. %s / %d / %s\n", i + 1, u_getname(p), u_getage(p), u_getgender(p));
    }
}
void list_vote()
{
    printf("All Vote.\n");
    int size = V_count();
    T_user *all_vote[MAX_USER];
    v_get_all(all_vote);
    for (int i = 0; i < size; i++)
    {
        T_user *p = all_vote[i];
        printf("%d. %s / 선택지 %d개\n", i + 1, v_getname(p), v_getamount(p));
        for (int i = 0; i < v_getamount(p); i++)
        {
            printf("\t(%d) %s\n", i + 1, v_getchoice(p, i));
        }
    }
}
void start_vote()
{
    int size = V_count();
    char user_name[20];
    int choose;
    //5. 투표하기
    //6. 현재 투표된 선택지 현황 전체 정리해서 보여주기     // 각 선택지에 투표된 수만 print한다.(익명) //나중에 실명 모드도 만들기
    if (size == 0) //1개라도 만들어진 투표 주제가 있는지 확인
    {
        printf("Nothing to vote for :(\n");
    }
    else
    {
        char user_name[20];
        printf("Enter a user name > ");
        scanf("%s", user_name);
        if (u_search_by_name(user_name) == NULL)
        {
            printf("No such member :(\n");
        }
        else
        {
            printf(":) Hello %s Would you vote?\n",user_name);
            T_vote *all_vote[MAX_USER];
            v_get_all(all_vote);
            for (int i = 0; i < size; i++)
            {
                T_vote *p = all_vote[i];
                printf("%d. %s \n", i + 1, v_getname(p));
            }
            printf("0. Exit\n\n");
            printf("\nChoose Vote : ");
            scanf("%d", &choose);
            if (choose != 0)
            {

                T_vote *p = all_vote[choose];
                T_vote *p = v_search_by_name(v_getname(p));

                v_start(p, user_name);
                v_status(p);
            }
        }
    }
}
