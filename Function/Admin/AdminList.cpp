#include "Add/Adduser.cpp"
#include "See/showUser.cpp"
#include "Edit/editUser.cpp"
#include "Delete/deleteUser.cpp"
extern void mainbank();


void adminList(){
    int select;
    system("cls");
    printf("\nWellcome to Admin\n");
    printf("Do you want to....\n");
    printf("-------------------------------------\n");
    printf("select :\n");
    printf("\t(1)Add user information.\n");
    printf("\t(2)Delete user information.\n");
    printf("\t(3)Edit user information.\n");
    printf("\t(4)See a list of users.\n");
    printf("\t(5)Log out.\n");
    printf("-------------------------------------\n");
    printf("select : ");
    scanf("%d", &select);
    switch (select){
        case 1:
            addUser();
            break;
        case 2:
            deleteUser();
            break;
        case 3:
            editUser();
            break;
        case 4:
            see();
            break;
        case 5:
            mainbank();
            break;
        default:
            adminList();
    }
}

void Selection(){
    int select;
    printf("---------------------------------------\n");
    printf("(1) back menu\n");
    printf("(2) Log out\n");
    printf("---------------------------------------\n");
    printf("select: ");
    scanf("%d", &select);
    switch (select){
        case 1:
            adminList();
            break;
        case 2:
            mainbank();
            break;
        default:
            system("cls");
            Selection();
    }
}
