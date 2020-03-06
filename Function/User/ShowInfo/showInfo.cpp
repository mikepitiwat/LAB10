
extern char iduserLogin[10];
extern void Selections();
void showInfo(){
    system("cls");
    char AccountID[10],firstname[20],lastname[20],phoneNumber[15],type[10];
    float money;
    char filename[40] = "Function\\User\\File\\Info\\userInfo";
    strcat(filename, iduserLogin); strcat(filename, ".txt");
    FILE *fr;
    fr = fopen(filename, "r");
    printf("\n---------- Show user information -------------\n\n");
    if(fr == NULL){
        printf("\t--------------------\n");
        printf("\tNOT found\n");
        printf("\t--------------------\n");
    }else{
        printf("------------------------------------------------------------------\n");
        while (fscanf(fr, "%s %s %s %s %s %f",AccountID,firstname,lastname,phoneNumber,type,&money) != EOF) {
            printf("Account ID\t: %s\n", AccountID);
            printf("firstname\t: %s\n", firstname);
            printf("lastname\t: %s\n", lastname);
            printf("phone Number\t: %s\n", phoneNumber);
            printf("type\t\t: %s\n", type);
            printf("money\t\t: %.2f\n", money);
        }
        printf("------------------------------------------------------------------\n");
    }

    fclose(fr);
}

void showinfo(){
    system("cls");
    showInfo();
    Selections();
}
