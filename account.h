 // #ifndef ACCOUNT_MANAGEMENT 
 // #define ACCOUNT_MANAGEMENT
 #include <stdio.h>
 #include<stdlib.h>
typedef struct UserInfo
 {
 	unsigned int StudentId;
 	char StudentName[50];
 	char AccountId[50];
 	char Password[50];
    int BorrowedNum;
 	// unsigned int LimitedNum;
 	int book1;
 	int book2;
 	int book3;
 	struct UserInfo *next;

 }account;
 account *h;
 account *AdminPath;
 struct UserInfo *p,*last;
 struct UserInfo *NewAccount;
 #define CreateNode(p) p=(account*)malloc(sizeof(account));

 account *LoadUserData();
 // int ReadAccountInfo();
 account *LogIn();
 // int LogOut(unsigned int UserChoice);
 int Register();
 int SaveAccount();
 int BorrowBooks(account *User,int book_ID);
void ReturnBooks(account *Lend,int book_ID);
 

