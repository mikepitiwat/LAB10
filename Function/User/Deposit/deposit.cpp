
extern void Selections();
extern void udatemoneyinfo(float Left);
extern void Time(char Date[20]);
extern char iduserLogin[10];

void deposit(){
    system("cls");
    printf("\n\tDeposit\n\n");
    char date[20]="";
    char filnameAccount[40] = "Function\\User\\File\\Account\\userAccount";
    strcat(filnameAccount,iduserLogin); strcat(filnameAccount, ".txt");
    float deposit = 0,withdraw = 0,Left = 0;
    float getdeposit;
    FILE *fr = fopen(filnameAccount, "r");
    if(fr == NULL){
        printf("---------------------------------------\n");
        printf("\n\n\tNot found!!!\n\n");
        printf("---------------------------------------\n");
    } else{
        while (fscanf(fr, "%s %f %f %f", date, &deposit, &withdraw, &Left) != EOF) {
        }
        printf("\t-----------------------------------------------------------------------\n");
        printf("%10sDate\t%14sDeposit%10sWithdraw%12sLeft\n"," "," "," ","");
        printf("\t-----------------------------------------------------------------------\n");
        printf("\n\t%s\t%10.2f\t\t%.2f\t\t%.2f\n", date, deposit, withdraw, Left);
        printf("\nEnter deposit: ");
        scanf("%f", &getdeposit);
        deposit = getdeposit;
        Left += getdeposit;

        char filnameAccount[40] = "Function\\User\\File\\Account\\userAccount";
        strcat(filnameAccount,iduserLogin); strcat(filnameAccount, ".txt");
        FILE *fw = fopen(filnameAccount, "a+");
        withdraw = 0;
        Time(date);
        fprintf(fw, "%s %.2f %.2f %.2f\n", date, deposit, withdraw, Left);
        printf("\n---------------------------------\n");
        printf("!! All money : %.2f\n" ,Left);
        printf("\n---------------------------------\n");
        udatemoneyinfo(Left);
        fclose(fw);
    }

    fclose(fr);
    Selections();
}
