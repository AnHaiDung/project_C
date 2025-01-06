#include <stdio.h>
#include <string.h>

int numberUser=0;
struct Date{
    int day, month, year;
};
struct User {
    char userId[20];
    char name[20]; 
	int gender; 
    char phone[15];
    char email[30];
    char fullName[50];
    struct Date dateOfBirth;
    int status;
    float balance;
};

struct User users[100];

struct Admin{
	char account[20];
	char password[20];
};

struct Admin inforAdmin[1];

void logAdmin();
void addUser();
void showAllUsers();
void saveUser();
void loadUser();
void findUser();
void findId();
void status();
void arrangeUser();
void logUser(int i);
void showUser(int i);
void editUser(int i);
void depositMoney(int i);
void withdrawMoney(int i);
void changePassword(int i);
void loginUser();
void loginAdmin();
void transferMoney(int i);

//tai khoan: anhaidung2006
//mat khau: 06072006

int main() {
    loadUser();
    int choose;
    do {
        printf("***Bank Management System Using C***\n");
        printf("        CHOOSE YOUR ROLE\n");
        printf("   ===========================\n");
        printf("   [1] Quan ly.\n");
        printf("   [2] Nguoi dung.\n");
        printf("   [3] Thoat ung dung.\n");
        printf("   ===========================\n");
        printf("   Nhap lua chon: ");
        scanf("%d", &choose);
        getchar();
        switch (choose) {
            case 1:
            	loginAdmin();
                break;
            case 2:
            	loginUser();
                break;
            case 3:
                printf("========== Thank You =========\n");
                printf("========== See You Soon ======\n");
                printf("-------------------------------\n");
                break;
            default:
                printf("khong thuoc menu\n");
        }
    } while (choose!=3);
    return 0;
}
//
void logAdmin() {
    int chose;
    do {
        printf("***Bank Management System Using C***\n");
        printf("             MENU\n");
        printf("        =======================\n");
        printf("        [1] Them nguoi dung moi.\n");
        printf("        [2] Hien toan bo nguoi dung.\n");
        printf("        [3] Tim kiem thong tin nguoi dung theo ten.\n");
        printf("        [4] Tim kiem thong tin nguoi dung theo id.\n");
        printf("        [5] khoa (mo khoa) tai khoan.\n");
        printf("        [6] Sap xep theo ten.\n");
        printf("        [7] Thoat giao dien quan ly.\n");
        printf("        =======================\n");
        printf("        Nhap lua chon: ");
        scanf("%d", &chose);
        getchar();
        system("cls");
        switch (chose) {
            case 1:
                addUser();
                break;
            case 2:
                showAllUsers();
                break;
            case 3:
            	findUser();
                break;
            case 4:
         	    findId();
                break;
            case 5:
            	status();
                break;
            case 6:
            	arrangeUser();
                break;
            case 7:
                printf("Da thoat giao dien quan ly\n");
                break;
            default:
                printf("Khong thuoc menu\n");
        }
    } while (chose!=7);
}
//
void addUser(){
    if (numberUser>=100) {
        printf("Khong the them nguoi dung. Danh sach day.\n");
        return;
    }
    struct User newUser;
    printf("      *** Add a new user ***\n");
    do{
        do{
            printf("Nhap ID : ");
            fgets(newUser.userId, sizeof(newUser.userId), stdin);
            newUser.userId[strcspn(newUser.userId, "\n")] = '\0';
            if (strlen(newUser.userId)<10) {
                printf("Error: ID khong the be hon 10 ky tu\n");
            }
        }while(strlen(newUser.userId)<10);
        int check = 0;
        for(int i=0;i < numberUser;i++){
    	    if(strcmp(newUser.userId, users[i].userId) == 0){
    	       check=1;
    		   printf("Error: ID da ton tai\n");
    		   break;
		    }else{
		    	check=0;
			}
	    }
	    if(check == 0){
	    	break;
		}
    }while(1);
    //
    do{
    	do{
        printf("Nhap ten: ");
        fgets(newUser.name, sizeof(newUser.name), stdin);
        newUser.name[strcspn(newUser.name, "\n")] = '\0';
        if(strlen(newUser.name)==0){
        	printf("Ten nguoi dung khong duoc trong\n");
		}
		}while(strlen(newUser.name)==0);
        int check = 0;
        for(int i=0;i < numberUser;i++){
    	    if(strcmp(newUser.name, users[i].name) == 0){
    	       check=1;
    		   printf("Error: ten da ton tai\n");
    		   break;
		    }else{
		    	check=0;
			}
	    }
	    if(check == 0){
	    	break;
		}
    }while(1);
    //
    do{
        printf("Nhap email: ");
        fgets(newUser.email, sizeof(newUser.email), stdin);
        newUser.email[strcspn(newUser.email, "\n")] = '\0';
        if (strstr(newUser.email, "@gmail.com") == 0){
        printf("Error: Email phai co duoi @gmail.com\n");
        continue;
        }
        int check = 0;
        for(int i=0;i < numberUser;i++){
    	    if(strcmp(newUser.email, users[i].email) == 0){
    	       check=1;
    		   printf("Error: email da ton tai\n");
    		   break;
		    }else{
		    	check=0;
			}
	    }
	    if(check == 0){
	    	break;
		}
    }while(1);
    //
    do{
    	do{
        printf("Nhap so dien thoai: ");
        fgets(newUser.phone, sizeof(newUser.phone), stdin);
        newUser.phone[strcspn(newUser.phone, "\n")] = '\0';
        if (strlen(newUser.phone)<10) {
                printf("Error: sdt khong the be hon 10 so\n");
            }
        }while(strlen(newUser.phone)<10);
        int check = 0;
        for(int i=0;i < numberUser;i++){
    	    if(strcmp(newUser.phone, users[i].phone) == 0){
    	       check=1;
    		   printf("Error: sdt da ton tai\n");
    		   break;
		    }else{
		    	check=0;
			}
	    }
	    if(check == 0){
	    	break;
		}
    }while(1);
    //
        do{
           printf("Nhap ten day du: ");
           fgets(newUser.fullName, sizeof(newUser.fullName), stdin);
           newUser.fullName[strcspn(newUser.fullName, "\n")] = '\0';
           if(strlen(newUser.fullName)==0){
              printf("Ten khong duoc trong\n");
		   }
		}while(strlen(newUser.fullName)==0);
    //
    printf("Nhap ngay thang nam sinh: \n");
    printf("ngay: ");
    scanf("%d",&newUser.dateOfBirth.day);
    printf("thang: ");
    scanf("%d",&newUser.dateOfBirth.month);
    printf("nam: ");
    scanf("%d",&newUser.dateOfBirth.year);
    getchar();
    //
    printf("chon trang thai tai khoan (1:dong/0:mo) ");
    scanf("%d",&newUser.status);
    //
    users[numberUser] = newUser;
    numberUser++;
    printf("Them tai khoan thanh cong\n");
    saveUser();
    int exit;
    printf("an nut bat ki de quay lai menu ");
    scanf("%d",&exit);
    if(exit==1){
    	return;
	}
}
//
void showAllUsers(){
    if (numberUser == 0) {
        printf("Danh sach nguoi dung trong\n");
        return;
    }
    printf("|=============|===============|==================|================|============|\n");
    printf("|     ID      |      Name     |       email      |     Phone      |   Status   |\n");
    printf("|=============|===============|==================|================|============|\n");
    for (int i = 0; i < numberUser; i++) {
        printf("-----------------------------------------------------------------------------\n");
        printf("   %s    ", users[i].userId);
        printf("    %s   ", users[i].name);
        printf("   %s  ", users[i].email);
        printf("    %s    ", users[i].phone);
        if(users[i].status==1){
            	printf("  lock  \n");
			}
		if(users[i].status==0){
            	printf("   open  \n");
			}
        printf("-----------------------------------------------------------------------------\n");
    }
    int exit;
    printf("an nut bat ki de quay lai menu ");
    scanf("%d",&exit);
    if(exit==1){
    	return;
	}
}
//
void saveUser(){
    FILE *file;
    file = fopen("user.bin", "wb");
    fwrite(&users, sizeof(struct User), numberUser, file);
    fclose(file);
}
//
void loadUser(){
    FILE *file;
    file = fopen("user.bin", "rb");
    if (file == NULL) {
        printf("loi khong mo uoc file\n");
		return;
    }
    numberUser= fread(&users,sizeof(struct User),100,file);
    fclose(file);
}
//
  void findUser() {
    char text[50];
    printf("Nhap ten nguoi dung muon tim kiem: ");
    fgets(text, 50, stdin);
    text[strcspn(text, "\n")] = '\0'; 
    int count = 0; 
    for (int i = 0; i < numberUser; i++) {
        if (strstr(users[i].name, text) != NULL) { 
            if (count == 0) { 
                printf("|=============|===============|==================|================|============|\n");
                printf("|     ID      |      Name     |       Email      |     Phone      |    Status  |\n");
                printf("|=============|===============|==================|================|============|\n");
            }
            printf("---------------------------------------------------------------------------------\n");
            printf("    %s    ", users[i].userId);
            printf("    %s    ", users[i].name);
            printf("    %s    ", users[i].email);
            printf("   %s   ", users[i].phone);
            if(users[i].status==1){
            	printf("  lock  \n");
			}
			if(users[i].status==0){
            	printf("  open  \n");
			}
            printf("--------------------------------------------------------------------------------\n");
            count = 1;
        }
    }
    if (count == 0) {
        printf("Khong tim thay nguoi dung\n ");
    }
    int exit;
    printf("an 1 de quay lai menu ");
    scanf("%d",&exit);
    if(exit==1){
    	return;
	}
}
//
void findId(){
	char textid[50];
    printf("Nhap id nguoi dung muon tim kiem: ");
    fgets(textid, 50, stdin);
    textid[strcspn(textid, "\n")] = '\0';
    int count = 0;
    for (int i = 0; i < numberUser; i++) {
    	if (strcmp(textid, users[i].userId) == 0) {
    		printf("Id: %s\n",users[i].userId);
    		printf("ten tai khoan : %s\n",users[i].name);
    		printf("email: %s\n",users[i].email);
    		printf("ngay sinh: %d\n",users[i].dateOfBirth.day);
    		printf("thang sinh: %d\n",users[i].dateOfBirth.month);
    		printf("nam sinh: %d\n",users[i].dateOfBirth.year);
    		printf("ho ten day du : %s\n",users[i].fullName);
    		count = 1; 
		}
	}
    if (count == 0) {
        printf("Khong tim thay id nguoi dung\n ");
    }
    int exit;
    printf("an nut bat ki de quay lai menu  ");
    scanf("%d",&exit);
    if(exit==1){
    	return;
	}
}
//
void status(){
	char textid[50];
	int check;
    printf("Nhap id nguoi dung muon mo khoa(khoa): ");
    fgets(textid, 50, stdin);
    textid[strcspn(textid, "\n")] = '\0';
    printf("co xac nhan muon khoa(mo khoa) tai khoan(1:dong y/0:thoat): ");
    scanf("%d",&check);
    if(check==0){
    	return;
	}else{
    int count = 0;
    for (int i = 0; i < numberUser; i++) {
    	if (strcmp(textid, users[i].userId) == 0) {
    		if(users[i].status==1){
    			users[i].status=0;
            	printf("da mo khoa tai khoan\n");
            	count = 1; 
            	saveUser();
            	break;
			}
			if(users[i].status==0){
				users[i].status=1;
            	printf("da khoa tai khoan\n");
            	count = 1; 
            	saveUser();
            	break;
			}
		}
	}
    if (count == 0) {
        printf("Khong tim thay id nguoi dung\n ");
    }
    int exit;
    printf("an nut bat ki de quay lai menu  ");
    scanf("%d",&exit);
    if(exit==1){
    	return;
	}
   } 
}
//
void arrangeUser(){
	int choosecase6;
	printf("1. xap xep tang dan\n");
	printf("2. xap xep giam dan\n");
	scanf("%d",&choosecase6);
	if(choosecase6==1){
		for (int i = 0;i<numberUser-1;i++) {
            for (int j =i+1;j<numberUser;j++) {
                if (strcmp(users[i].name,users[j].name)>0) {
                    struct User temp=users[i];
                    users[i]=users[j];
                    users[j]=temp;
                }
            }
        }
        printf("Danh sach nguoi dung sau khi sap xep tang dan:\n");
        showAllUsers();
	}
	if(choosecase6==2){
		 for (int i=0;i<numberUser-1;i++) {
            for (int j =i+1;j<numberUser;j++) {
                if (strcmp(users[i].name, users[j].name)<0) {
                    struct User temp=users[i];
                    users[i]=users[j];
                    users[j]=temp;
                }
            }
        }
        printf("Danh sach nguoi dung sau khi sap xep giam dan:\n");
        showAllUsers();
	}
}
//
void logUser(int i) {
	if(users[i].status==1){
    		printf("tai khoan dang bi khoa\n");
    		return 0;
		}
    int chose;
    do {
        printf("***User Management System in C***\n");
        printf("             MENU\n");
        printf("        =======================\n");
        printf("        [1] Hien thi thong tin.\n");
        printf("        [2] Sua thong tin nguoi dung.\n");
        printf("        [3] Nap tien.\n");
        printf("        [4] Rut tien.\n");
        printf("        [5] Doi mat khau.\n");
        printf("        [6] Chuyen tien.\n");
        printf("        [7] Thoat giao dien quan ly nguoi dung.\n");
        printf("        =======================\n");
        printf("        Nhap lua chon: ");
        scanf("%d", &chose);
        getchar();
        system("cls");
        switch (chose) {
            case 1:
                showUser(i);
                break;
            case 2:
                editUser(i);
                break;
            case 3:
                depositMoney(i);
                break;
            case 4:
                withdrawMoney(i);
                break;
            case 5:
                changePassword(i);
                break;
            case 6:
            	transferMoney(i);
                break;
            case 7:
                printf("Da thoat giao dien quan ly nguoi dung\n");
                break;
            default:
                printf("Khong thuoc menu\n");
        }
    } while (chose != 7);
}
//
void showUser(int i) {
            printf("Thong tin nguoi dung:\n");
            printf("ID: %s\n", users[i].userId);
            printf("Ten: %s\n", users[i].name);
            printf("Email: %s\n", users[i].email);
            printf("So dien thoai: %s\n", users[i].phone);
            printf("Ngay sinh: %d/%d/%d\n", users[i].dateOfBirth.day, users[i].dateOfBirth.month, users[i].dateOfBirth.year);
            printf("Ho ten day du: %s\n", users[i].fullName);
    int exit;
    printf("an nut bat ki de quay lai menu  ");
    scanf("%d", &exit);
    if (exit == 1) {
        return;
    }
}
//
void editUser(int i) {
    printf("Sua thong tin nguoi dung:\n");
    do {
        printf("Nhap ten moi: ");
        fgets(users[i].name, sizeof(users[i].name), stdin);
        users[i].name[strcspn(users[i].name, "\n")] = '\0';
        if (strlen(users[i].name) == 0) {
            printf("Ten nguoi dung khong duoc trong\n");
        }
        int check = 0;
        for (int j = 0; j < numberUser; j++) {
            if (strcmp(users[i].name, users[j].name) == 0 && i != j) {
                check = 1;
                printf("Error: ten da ton tai\n");
                break;
            }
        }
        if (check == 0) {
            break;
        }
    } while (1);
    
    do {
        printf("Nhap email moi: ");
        fgets(users[i].email, sizeof(users[i].email), stdin);
        users[i].email[strcspn(users[i].email, "\n")] = '\0';
        if (strstr(users[i].email, "@gmail.com") == 0) {
            printf("Error: Email phai co duoi @gmail.com\n");
            continue;
        }
        int check = 0;
        for (int j = 0; j < numberUser; j++) {
            if (strcmp(users[i].email, users[j].email) == 0 && i != j) {
                check = 1;
                printf("Error: email da ton tai\n");
                break;
            }
        }
        if (check == 0) {
            break;
        }
    } while (1);
    do {
        printf("Nhap so dien thoai moi: ");
        fgets(users[i].phone, sizeof(users[i].phone), stdin);
        users[i].phone[strcspn(users[i].phone, "\n")] = '\0';
        if (strlen(users[i].phone) < 10) {
            printf("Error: sdt khong the be hon 10 so\n");
            continue;
        }
        int check = 0;
        for (int j = 0; j < numberUser; j++) {
            if (strcmp(users[i].phone, users[j].phone) == 0 && i != j) {
                check = 1;
                printf("Error: sdt da ton tai\n");
                break;
            }
        }
        if (check == 0) {
            break;
        }
    } while (1);
    do {
        printf("Nhap ho ten day du moi: ");
        fgets(users[i].fullName, sizeof(users[i].fullName), stdin);
        users[i].fullName[strcspn(users[i].fullName, "\n")] = '\0';
        if (strlen(users[i].fullName) == 0) {
            printf("Ten khong duoc trong\n");
        }
    } while (strlen(users[i].fullName) == 0);
    saveUser();
    printf("Cap nhat thong tin thanh cong.\n");
    int exit;
    printf("an nut bat ki de quay lai menu  ");
    scanf("%d", &exit);
    if (exit == 1) {
        return;
    }
}
//
void depositMoney(int i){
	float deposit;
	printf("nhap so tien muon nap: ");
	scanf("%f",&deposit);
	printf("da nap thanh cong %2.f\n",deposit);
	users[i].balance=users[i].balance+deposit;
	saveUser();
    int exit;
    printf("an nut bat ki de quay lai menu  ");
    scanf("%d", &exit);
    if (exit == 1) {
        return;
    }
}
//
void withdrawMoney(int i) {
	float withdraw;
	printf("nhap so tien muon rut: ");
	scanf("%f",&withdraw);
	if(users[i].balance >= withdraw){
		printf("da rut thanh cong %2.f\n",withdraw);
	    users[i].balance=users[i].balance-withdraw;
	    saveUser();
	}else{
		printf("tai khoan khong du tien\n");
	}
    int exit;
    printf("an nut bat ki de quay lai menu  ");
    scanf("%d", &exit);
    if (exit == 1) {
        return;
    }
}
//
void changePassword(int i) {
	char newPassword[20];
	do{
		printf("nhap mat khau cu: ");
		fgets(newPassword,20,stdin);
		newPassword[strcspn(newPassword, "\n")] = '\0';
		if(strcmp(newPassword,users[i].phone)==0){
			printf("nhap mat khau moi ");
			fgets(users[i].phone, sizeof(users[i].phone), stdin);
            users[i].phone[strcspn(users[i].phone, "\n")] = '\0';
            if (strlen(users[i].phone) < 10) {
                printf("Error: mat khau khong the be hon 10 so\n");
                continue;
            }
            printf("doi mat khau thanh cong\n");
            saveUser();
            break;
		}else{
			printf("sai mat khau\n");
		}
	}while(1);
    int exit;
    printf("an nut bat ki de quay lai menu  ");
    scanf("%d", &exit);
    if (exit == 1) {
        return;
    }
}
//
void transferMoney(int i){
	float transfer;
	char textid[50];
    printf("Nhap id nguoi dung muon chuyen tien: ");
    fgets(textid, 50, stdin);
    textid[strcspn(textid, "\n")] = '\0';
    int count = 0;
    for (int j = 0; j < numberUser; j++) {
    	if (strcmp(textid, users[j].userId) == 0) {
    		printf("nhap so tien muon chuyen: ");
    		scanf("%.2f",&transfer);
    		if(users[i].balance>transfer){
    			users[i].balance-transfer;
    		    users[j].balance+transfer;
    		    saveUser();
    		    printf("chuyen tien thanh cong\n");
			}else{
				printf("tai khoan khong du tien\n");
			}
    		count = 1; 
		}
	}
    if (count == 0) {
        printf("Khong tim thay id nguoi dung\n ");
    }
    int exit;
    printf("an nut bat ki de quay lai menu  ");
    scanf("%d",&exit);
    if(exit==1){
    	return;
	}
}
//
void loginUser(){
	char userAccount[20], userPassword[20];
	int i;
    int count=0;
    printf("     account: ");
    fgets(userAccount, sizeof(userAccount), stdin);
    userAccount[strcspn(userAccount, "\n")] = '\0';
    printf("     password: ");
    fgets(userPassword, sizeof(userPassword), stdin);
    userPassword[strcspn(userPassword, "\n")] = '\0';
    for( i=0; i<numberUser; i++){
        if(strcmp(userAccount, users[i].userId)==0&&strcmp(userPassword, users[i].phone)==0){	
		    count=1;
            logUser(i) ;
            break;
        }
    }
    if(count==0){
        printf("khong dung tai khoan hoac mat khau\n");
	}
}
//
void loginAdmin(){
	printf("***Bank Management System Using C***\n");
            	printf("               LOGIN\n");
            	printf("     =========================\n");
            	do{
            		printf("     account: ");
            	    fgets(inforAdmin[0].account,sizeof(inforAdmin[0].account),stdin);
            	    inforAdmin[0].account[strcspn(inforAdmin[0].account, "\n")] = '\0';
            	    if(strcmp(inforAdmin[0].account, "anhaidung")==0){
            	    	break;
					}else{
						printf("chua dung tai khoan\n");
					}
				}while(1);
				do{
            		printf("     password: ");
            	    fgets(inforAdmin[0].password,sizeof(inforAdmin[0].password),stdin);
            	    inforAdmin[0].password[strcspn(inforAdmin[0].password, "\n")] = '\0';
            	    if(strcmp(inforAdmin[0].password, "06072006")==0){
            	    	break;
					}else{
						printf("chua dung mat khau\n");
					}
				}while(1);
            	printf("     =========================\n");
                logAdmin();
}

