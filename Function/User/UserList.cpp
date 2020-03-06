#include "ShowInfo/showInfo.cpp"
#include "EditInfo/editInfo.cpp"
#include "ShowAcc/showAcc.cpp"
#include "Deposit/deposit.cpp"
#include "Withdraw/withdraw.cpp"
extern void mainbank();

extern char nameuserLogin[20];

void usersList(){
    int select;
    system("cls");
    printf("\nWellcome to %s\n",nameuserLogin);
    printf("Do you want to....\n");
    printf("-------------------------------------\n");
    printf("select :\n");
    printf("\t(1)Show information.\n");
    printf("\t(2)Edit information.\n");
    printf("\t(3)Show accout.\n");
    printf("\t(4)(deposit).\n");
    printf("\t(5)(withdraw).\n");
    printf("\t(6)Log out.\n");
    printf("-------------------------------------\n");
    printf("select : ");
    scanf("%d", &select);
    switch (select){
        case 1:
            showinfo();
            break;
        case 2:
            editInfo();
            break;
        case 3:
            showAcc();
            break;
        case 4:
            deposit();
            break;
        case 5:
            withdraw();
            break;
        case 6:
            mainbank();
            break;
        default:
            usersList();
    }
}

void Selections() {
    int select;
    printf("---------------------------------------\n");
    printf("(1) back menu\n");
    printf("(2) Log out\n");
    printf("---------------------------------------\n");
    printf("select: ");
    scanf("%d", &select);
    switch (select) {
        case 1:
            usersList();
            break;
        case 2:
            mainbank();
            break;
        default:
            system("cls");
            Selections();
    }
}
