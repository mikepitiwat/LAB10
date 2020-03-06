#include "AdminList.cpp"
extern void mainbank();

void loginAdmin(){
    char user[20];
    char  pass[10];
    int n = -1;
    system("cls");
    getchar();
    // input username
    printf("\nloginAdmin\n\n");
    printf("\tUsername: ");
    gets(user);
    // input password
    printf("\tPassword: ");
    do {
        n++;
        pass[n] = getch();
        if(pass[n] != 13)
            printf("*");
    } while (pass[n] != 13);
    pass[n] = '\0';
    printf("\n");

    // check input
    if (strcmp(user, "root") == 0 && strcmp(pass, "1234") == 0) { // ถ้าชื่อ และ รหัสผ่าน admin ถูกต้อง
        system("cls");
        adminList();
    }else{              // ถ้าชื่อ หรืิ รหัสผ่าน ไม่ถูกต้อง
        int select;
        printf("\n---------------------------------------------\n");
        printf("!!!The username or password is incorrect.\n");
        printf("select:\n");
        printf("\t(1)Try again | (2) back Home\n");
        printf("\n---------------------------------------------\n");
        printf("select: ");
        scanf("%d", &select);
        if(select == 2) {
            mainbank();
        }else{
            loginAdmin();
        }
    }
}
