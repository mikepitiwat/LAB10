
extern void Selections();
extern char iduserLogin[10];

void udatemoneyinfo(float Left){
    char fileOld[40] = "Function\\User\\File\\Info\\userInfo";;
    strcat(fileOld, iduserLogin); strcat(fileOld, ".txt");
    char fileNew[40] = "Function\\User\\File\\Info\\new.txt";
    char AccountID[10],firstname[20],lastname[20],phoneNumber[15],type[10];
    float money;

    FILE *fold;
    FILE *fnew;
    fold = fopen(fileOld, "r");
    if(fold == NULL){
        printf("---------------------------------------\n");
        printf("\n\n\tNot found!!!\n\n");
        printf("---------------------------------------\n");
    } else{
        fscanf(fold, "%s %s %s %s %s %f", AccountID, firstname, lastname, phoneNumber, type, &money);
        fnew = fopen(fileNew, "a");
        money = Left;
        fprintf(fnew,"%05s %s %s %s %s %.2f", AccountID, firstname, lastname, phoneNumber, type, money);
        fclose(fold);
        fclose(fnew);
        remove(fileOld);
        rename(fileNew, fileOld);
    }
}

void Time(char Date[]){
    char date[20]="";

    time_t timer;
    struct tm* tm_info;
    char day[3];
    char month[3];
    char year[5];

    time(&timer);
    tm_info = localtime(&timer);
    strftime(day, 3, "%d", tm_info);
    strftime(month, 3, "%m", tm_info);
    strftime(year, 5, "%Y", tm_info);

    strcat(date, day);strcat(date,"/");
    strcat(date, month);strcat(date,"/");
    strcat(date, year);
    strcpy(Date, date);
}

void withdraw(){
    system("cls");
    printf("\n\tWithdraw\n\n");
    char date[20]="";
    char filnameAccount[40] = "Function\\User\\File\\Account\\userAccount";
    strcat(filnameAccount,iduserLogin); strcat(filnameAccount, ".txt");
    float deposit = 0,withdraw = 0,Left = 0;
    float getwithdraw;
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
        printf("\nEnter withdraw: ");
        scanf("%f", &getwithdraw);
        withdraw = getwithdraw;
        if(Left - getwithdraw < 0){
            printf("---------------------------------------\n");
            printf("\n\n\tNot enough money!!!\n\n");
            printf("---------------------------------------\n");
        }else{
            Left -= getwithdraw;
            char filnameAccount[40] = "Function\\User\\File\\Account\\userAccount";
            strcat(filnameAccount,iduserLogin); strcat(filnameAccount, ".txt");
            FILE *fw = fopen(filnameAccount, "a+");
            deposit = 0;
            Time(date);
            fprintf(fw, "%s %.2f %.2f %.2f\n", date, deposit, withdraw, Left);
            printf("\n---------------------------------\n");
            printf("!! All money : %.2f\n" ,Left);
            printf("\n---------------------------------\n");
            udatemoneyinfo(Left);
            fclose(fw);
        }
    }
    fclose(fr);
    Selections();
}
