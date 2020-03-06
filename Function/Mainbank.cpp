#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include<time.h>
#include "Admin/AdminLogin.cpp"
#include "User/UserLogin.cpp"

void mainbank(){
    int select;
    system("cls");
    printf("\n\t\t------------------------------------------\n");
    printf("\n\t\t\tWELLCOME TO ACCOUNT BANKING\n");
    printf("\n\t\t------------------------------------------\n");
    printf("Who are you ?\n");
    printf("select:\n");
    printf("\t(1)Login Admin\n");
    printf("\t(2)Login User\n");
    printf("\t(3)Exit\n");

    printf("select: "); // เลือก 1 คือ  admin เลือก 2 user
    scanf("%d", &select);
    switch (select){
        case 1:
            loginAdmin();
            break;
        case 2:
            loginUsers();
            break;
        case 3:
            return ;
            break;
        default:
            mainbank();
    }
}
