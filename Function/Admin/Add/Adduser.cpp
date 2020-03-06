extern void adminList();
extern void mainbank();
extern void Selection();
typedef struct{
    int ID;
    int PASS;
    char NAME[20];
}FileInfo;
FileInfo info;
int id = 0;
char name[20],pass[10];
int checkname = 1;

void input(){
    system("cls");
    printf("\nRegister user\n");
    printf("\tEnter Username: ");
    scanf("%s", name);
    printf("\tEnter Password: ");
    scanf("%s", pass);
}

void addUser(){
    system("cls");
    char fileUserlist[40] = "Function\\Admin\\File\\userList.txt";
    FILE *fw;
    FILE *fr;

    //Register user----------------------------------------------------------------------------------------
    input();
    fr = fopen(fileUserlist, "r");
    fw = fopen(fileUserlist, "a+");
    if(fr == NULL){
        id = 1;
        fprintf(fw, "%05d %s %s\n",id, name, pass);
    }else{
        do{
            checkname = 1;
            while (fscanf(fr,"%d %s %d", &info.ID, info.NAME, &info.PASS) != EOF){
                if(strcmp(name,info.NAME) == 0) {
                    printf("---------------------------------------\n");
                    printf("This name(%s) is already used.!!!\n", name);
                    printf("Can press any key to do it again\n");
                    printf("---------------------------------------\n");
                    getchar();getchar();
                    input();
                    checkname = 0;
                    break;
                }
            }
        }while (checkname != 1);
        if(info.ID == 0){
            fw = fopen(fileUserlist, "w");
        }
        id = info.ID + 1;
        fprintf(fw, "%05d %s %s\n", id, name, pass);
    }
    fclose(fr);
    fclose(fw);

    system("cls");
    printf("---------------------------------\n");
    printf("success!!!\n");
    printf("\tYour username is %s\n", name);
    printf("\tYour password is %s\n", pass);
    printf("---------------------------------\n");
    printf("Press any key to fill in information........");
    getchar();getchar();

    //Account info----------------------------------------------------------------------------------------
    char firstname[20];
    char lastname[20];
    char phoneNumber[15],depositType[10];
    int DepositType;
    float money = 0;

    system("cls");
    printf("\nAccount info\n");
    printf("\tEnter firstname: ");
    scanf("%s",firstname);
    printf("\tEnter lastname  : ");
    scanf("%s", lastname);
    printf("\tEnter phoneNumber(10): ");
    scanf("%s",phoneNumber);
    printf("\tselect Deposit type\n");
    do{
        printf("\t\t(1)fixed\n");
        printf("\t\t(2)saving\n");
        printf("\tselect: ");
        scanf("%d",&DepositType);
    }while (DepositType != 1 && DepositType != 2);
    if(DepositType == 1)
        strcpy(depositType, "fixed");
    else if(DepositType == 2)
        strcpy(depositType, "saving");
    printf("Enter mony : ");

    FILE *fw2;
    char strID[10];
    char fileuserInfo[40]= "Function\\User\\File\\Info\\userInfo";
    sprintf(strID, "%d", id);
    strcat(fileuserInfo, strID);
    strcat(fileuserInfo,".txt");
    fw2 = fopen(fileuserInfo, "w");
    fprintf(fw2, "%05s %s %s %s %s %.2f", strID, firstname, lastname, phoneNumber, depositType, money);
    fclose(fw2);

    FILE *fw3;
    char fileuserAccount[40]= "Function\\User\\File\\Account\\userAccount";
    strcat(fileuserAccount, strID);
    strcat(fileuserAccount,".txt");
    fw3 = fopen(fileuserAccount, "w");
    fprintf(fw3, "%s %.2f %.2f %.2f\n", "NULL", 0, 0, 0);
    fclose(fw3);

    system("cls");
    printf("success!!!\n");
    printf("---------------------------------------\n");
    printf("\tAccount number\t: %05d\n", id);
    printf("\tfirstname\t: %s\n", firstname);
    printf("\tlastname\t: %s\n", lastname);
    printf("\tphone Number\t: %s\n", phoneNumber);
    printf("\tDeposit Type\t: %s\n", depositType);
    printf("\tAmount of money\t: %.2f\n", money);
    printf("---------------------------------------\n");
    printf("---------------------------------------\n");
    printf("\tYour username is %s\n", name);
    printf("\tYour password is %s\n", pass);
    printf("---------------------------------------\n");


    Selection();
}
