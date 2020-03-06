extern void Selections();
extern void showInfo();
extern char iduserLogin[10];

void editInfo(){
    char fileOld[40] = "Function\\User\\File\\Info\\userInfo";;
    strcat(fileOld, iduserLogin); strcat(fileOld, ".txt");
    char fileNew[40] = "Function\\User\\File\\Info\\new.txt";

    char AccountID[10],firstname[20],lastname[20],phoneNumber[15],type[10];
    float money;
    char newfirstname[20],newlastname[20],newphoneNumber[15],newtype[10];

    FILE *fold;
    FILE *fnew;
    fold = fopen(fileOld, "r");

    system("cls");
    showInfo();
    printf("\nEdit!!\n\n");

    if(fold == NULL){
        printf("----------------------------\n");
        printf("\n\n\tNot found!!!\n\n");
        printf("----------------------------\n");
    }else {
        int Choose;
        printf("----------------------------\n");
        printf("\t(1)firstname\n");
        printf("\t(2)lastname\n");
        printf("\t(3)phone Number\n");
        printf("\t(4)type\n");
        printf("----------------------------\n");
        printf("Choose the you want to edit : ");
        scanf("%d", &Choose);
        fscanf(fold, "%s %s %s %s %s %f", AccountID, firstname, lastname, phoneNumber, type, &money);
        fnew = fopen(fileNew, "a");
        switch (Choose) {
            case 1:
                printf("\t\tEnter firstname: ");
                scanf("%s", newfirstname);
                strcpy(firstname, newfirstname);
                break;
            case 2:
                printf("\t\tEnter lastname: ");
                scanf("%s", newlastname);
                strcpy(lastname, newlastname);
                break;
            case 3:
                printf("\t\tphone Number: ");
                scanf("%s", newphoneNumber);
                strcpy(phoneNumber, newphoneNumber);
                break;
            case 4:
                printf("\t\t(1)fixed\n");
                printf("\t\t(2)saving\n");
                printf("\t\ttype: ");
                scanf("%s", newtype);
                if (newtype == "1") strcpy(type, "fixed");
                else strcpy(type, "saving");
                break;
            case 5:
                editInfo();
                break;
        }
        fprintf(fnew,"%05s %s %s %s %s %.2f", AccountID, firstname, lastname, phoneNumber, type, money);

        fclose(fold);
        fclose(fnew);
        remove(fileOld);
        rename(fileNew, fileOld);
        Selections();
    }
}
