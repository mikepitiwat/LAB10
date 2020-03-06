extern void Selection();
extern void showUser();

void deleteUser(){
    char fileOld[40] = "Function\\Admin\\File\\userList.txt";
    char fileNew[40] = "Function\\Admin\\File\\new.txt";
    char name[20],getID[10],ID[10],pass[10];
    char strID[10];
    int check = 0;
    FILE *fold;
    FILE *fnew;
    fold = fopen(fileOld, "r");

    system("cls");
    showUser();
    printf("\nDelete!!\n\n");

    if(fold == NULL){
        printf("----------------------------\n");
        printf("\n\n\tNot found!!!\n\n");
        printf("----------------------------\n");
    }else{
        printf("Choose the (ID) you want to delete : ");
        scanf("%s", strID);
        fnew = fopen(fileNew, "a");
        while (fscanf(fold, "%s %s %s", getID, name, pass) != EOF) {
            if(strcmp(strID,getID) == 0){
                strcpy(ID, getID);
                check = 1;
            }else{
                fprintf(fnew, "%s %s %s\n", getID, name, pass);
            }
        }
        printf("----------------------------\n");
        if (check == 1){
            printf("\n\n\tDelete success!!!\n\n");
        }else{
            printf("\n\n\tDelete Fail!!!\n\n");
        }
        printf("----------------------------\n");
        fclose(fold);
        fclose(fnew);

        char fileinfo[40] = "Function\\User\\File\\Info\\userInfo";
        char fileaccount[40] = "Function\\User\\File\\Account\\userAccount";
        char nameID[10];
        sprintf(nameID,"%d",atoi(ID));
        strcat(fileinfo, nameID);strcat(fileinfo,".txt");
        remove(fileinfo);
        strcat(fileaccount, nameID);strcat(fileaccount,".txt");
        remove(fileaccount);
        remove(fileOld);
        rename("Function\\Admin\\File\\new.txt","Function\\Admin\\File\\userList.txt");
    }
    fclose(fold);
    Selection();
}
