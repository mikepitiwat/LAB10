#include "UserList.cpp"
extern void mainbank();

char nameuserLogin[20];
char iduserLogin[10];

void loginUsers(){
    char fileUserslist[40]="Function\\Admin\\File\\userList.txt";
    char getID[10],getUsers[20],getPass[40];
    int checkLogin = 0;
    char user[20];
    char  pass[10];
    int n = -1;
    system("cls");
    getchar();
    // input username
    printf("\nloginUsers\n\n");
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
    FILE *fr;
    fr = fopen(fileUserslist, "r");
    if (fr == NULL) {
        printf("----------------------------\n");
        printf("\n\n\tNot found!!!\n\n");
        printf("----------------------------\n");
    }else{
        while (fscanf(fr, "%s %s %s", getID, getUsers, getPass) != EOF) {
            if(strcmp(user,getUsers) == 0 && strcmp(pass,getPass) == 0){
                int numID = atoi(getID);
                sprintf(iduserLogin, "%d", numID);
                strcpy(nameuserLogin, getUsers);
                checkLogin = 1;
            }
        }
    }
    if (checkLogin) {
        system("cls");
        usersList();
    }else{
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
            loginUsers();
        }
    }
}
