
extern void Selections();
extern char iduserLogin[10];
void showAcc(){
    system("cls");
    char filnameAccount[40] = "Function\\User\\File\\Account\\userAccount";
    strcat(filnameAccount,iduserLogin); strcat(filnameAccount, ".txt");
    char date[5];
    float deposit = 0,withdraw = 0,Left = 0;
    float getwithdraw;
    FILE *fr = fopen(filnameAccount, "r");
    if(fr == NULL){
        printf("---------------------------------------\n");
        printf("\n\n\tNot found!!!\n\n");
        printf("---------------------------------------\n");
    } else{
        printf("\t-------------------------------------------------------------------------------\n");
        printf("%10sDate\t%19sDeposit%15sWithdraw%12sLeft\n"," "," "," ","");
        printf("\t-------------------------------------------------------------------------------\n");
        int i = 0;
        while (fscanf(fr, "%s %f %f %f", date, &deposit, &withdraw, &Left) != EOF) {
            if(i != 0){
                printf("\n\t%s\t\t%10.2f\t\t%6.2f\t\t%10.2f\n", date, deposit, withdraw, Left);
            }
            i++;
        }
    }
    fclose(fr);


    Selections();
}
