extern void Selection();

void showUser(){
    system("cls");
    char id[10],name[20],pass[10];
    char filename[40] = "Function\\Admin\\File\\userList.txt";
    FILE *fr;
    fr = fopen(filename, "r");
    printf("\n---------- Show user table -------------\n\n");
    if(fr == NULL){
        printf("\t--------------------\n");
        printf("\tAcc.ID\tuser\tpass\n");
        printf("\t--------------------\n");
        printf("\tNOT found\n");
    }else{
        printf("\t--------------------\n");
        printf("\tAcc.ID\tuser\tpass\n");
        printf("\t--------------------\n");
        while (fscanf(fr, "%s %s %s", id, name, pass) != EOF) {
            printf("\t%s\t%-s\t%-s\n", id, name, pass);
        }
    }
    printf("\t--------------------\n");
    fclose(fr);
}

void see(){
    system("cls");
    showUser();
    Selection();
}
