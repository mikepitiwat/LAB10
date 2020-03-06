extern void Selection();
extern void showUser();

void selecEdit(char name[], char pass[]) {
    int select;
    char editname[20];
    char editpass[30];
    showUser();
    printf("--------------------------\n");
    printf("\t(1)Edit username\n");
    printf("\t(2)Edit password\n");
    printf("\t(3)Edit username and password\n");
    printf("--------------------------\n");
    scanf("\tselect: ");
    scanf("%d", &select);
    switch (select) {
        case 1:
            printf("Edit username to: ");
            scanf("%s", editname);
            strcpy(name, editname);
            break;
        case 2:
            printf("Edit password to: ");
            scanf("%s", editpass);
            strcpy(pass, editpass);
            break;
        case 3:
            printf("Edit username to: ");
            scanf("%s", editname);
            strcpy(name, editname);
            printf("Edit password to: ");
            scanf("%s", editpass);
            strcpy(name, editname);
            strcpy(pass, editpass);
            break;
        default:
            selecEdit(name,pass);
    }
}

void editUser(){
    char fileOld[40] = "Function\\Admin\\File\\userList.txt";
    char fileNew[40] = "Function\\Admin\\File\\new.txt";
    char name[20],ID[10],pass[10];
    char strID[10];
    int check = 0;
    FILE *fold;
    FILE *fnew;
    fold = fopen(fileOld, "r");

    system("cls");
    showUser();
    printf("\nEdit!!\n\n");

    if(fold == NULL){
        printf("----------------------------\n");
        printf("\n\n\tNot found!!!\n\n");
        printf("----------------------------\n");
    }else{
        printf("Choose the (ID) you want to edit : ");
        scanf("%s", strID);
        fnew = fopen(fileNew, "a+");
        while (fscanf(fold, "%s %s %s", ID, name, pass) != EOF) {
            if(strcmp(strID,ID) == 0){
                selecEdit(name, pass);
                fprintf(fnew, "%s %s %s\n", ID, name, pass);
                check = 1;
            }else{
                fprintf(fnew, "%s %s %s\n", ID, name, pass);
            }
        }
        printf("----------------------------\n");
        if (check == 1){
            printf("\n\n\tEdit success!!!\n\n");
        }else{
            printf("\n\n\tEdit Fail!!!\n\n");
        }
        printf("----------------------------\n");
        fclose(fold);
        fclose(fnew);
        remove(fileOld);
        rename("Function\\Admin\\File\\new.txt","Function\\Admin\\File\\userList.txt");
    }
    fclose(fold);
    Selection();
}
