 #include <stdio.h>
 #include "account.h"
 #include<stdlib.h>
 account *LoadUserData(){
  FILE *fp;
//  char buff[255];
//	int StuId;
//  char StuName[20]={'\0'},Account[20]={'\0'},Password[20]={'0'};
//  int BookStorage01,BookStorage02,BookStorage03;
  
   account *p,*last;
   CreateNode(h);
   last=h;
   fp = fopen("UserData.txt","r");
   for(;!feof(fp);){
    CreateNode(p);
//    printf("012");
   	fscanf(fp,"%d%s%s%s%d%d%d",&(p->StudentId),p->StudentName,p->AccountId,p->Password,&(p->book1),&(p->book2),&(p->book3));
//   	printf("001"); 
	p->BorrowedNum=0;
      if(p->book1 !=0)
        p->BorrowedNum++;
//        printf("Borrowed book is Y %d \n",p->BorrowedNum);
      if(p->book2 !=0)
        p->BorrowedNum++;
//        printf("Borrowed book is S %d \n",p->BorrowedNum);
      if(p->book3 !=0)
        p->BorrowedNum++;
    //test part
//    printf("%d \t%s \t%s \t%s \t%d \t%d \t%d\n",p->StudentId,p->StudentName,p->AccountId, p->Password,p->book1,p->book2,p->book3);
//    printf("\n \n THIS IS STUDENT ID %d",p->StudentId);
    // printf("Borrowed book is %d",p->BorrowedNum);
	last->next=p;
    last=p;
   }

   last->next=NULL;
   
   fclose(fp);
	return h;
 }
 // TESTED
 account *LogIn(){
  account *s=h->next;
//  printf("This is the fucking error,%s",s->AccountId);
  char AccountTest[50];
  char PasswordTest[50];
  char *ExitJudge = "exit";
  printf("Welcome to the Virtual Library System,Please log in\n");
  scanf("%s",&AccountTest);
  while(s){
    if(strcmp(AccountTest,"admin")==0){
      printf("Welcome admin, Please enter your password!\n");
      scanf("%s",&PasswordTest);
      if(strcmp(PasswordTest,"admin")==0){
        printf("You have logged in as administrator!\n");
        return NULL;
      }
    }
  	// printf("\n \n 11112312313");
    if(strcmp(s->AccountId,AccountTest)==0){
      printf("Welcome %s ,Please enter your Password!\n", s->StudentName);
      scanf("%s",&PasswordTest);
      for(;strcmp(s->Password,PasswordTest)!=0&&strcmp(PasswordTest,ExitJudge)!=0;){
        printf("Wrong password! Please try again!! /n Type 'exit' to go back to the login menu.");
        scanf("%s",&PasswordTest); 
        }
      if(strcmp(PasswordTest,s->Password)==0){
        printf("You have successfully accessed.\n");
        return s;
        }
      // if(strcmp(PasswordTest,ExitJudge)==0){
      //   break;
      // }
    }
    s=s->next;
  }
  printf("No such account! \n");
  return h;

 }
 int Register(){
  unsigned int TestStuID;
  account *RegisPointer=h->next;
  account *NewAccount;
  int RegisterCheck;
//  CreateNode(NewAccount);
  // printf("This is a test about %d %s",RegisPointer->StudentId,RegisPointer->StudentName); 
  char TestAccount[50],TestName[50],TestPassword[50];
  printf("Please confirm your Student ID\n");
  RegisterCheck=scanf("%d",&TestStuID);
  while(RegisterCheck==0){
		printf("Detected Invalid Input, Please Try Again\n");
		fflush(stdin);
		RegisterCheck=scanf("%d",&RegisterCheck);
  }
  for(;RegisPointer->next!=NULL;){
//	while(RegisPointer){
	if(RegisPointer->StudentId!=TestStuID){
//		printf("LING YI GE XUN HUAN!");
		RegisPointer=RegisPointer->next;}
  if(RegisPointer->next==NULL){ //ADDED after test;
    if(RegisPointer->StudentId==TestStuID){
      printf("This Student ID has already registered.\n");
      return 1;
  }
	}
//  	printf("JIN XUN HUAN LA!"); 
    if(RegisPointer->StudentId==TestStuID){
      printf("This Student ID has already registered.\n");
      return 1;
//      printf("XUN HUAN LI DE ZHI ! %d",RegisPointer->StudentId);
    }
  }


//  last=NewAccount;
//  printf("\n \n 2");
//  NewAccount->next=NULL;
//  printf("\n \n 3");
  
  printf("Please confirm your name\n");
  RegisterCheck=scanf("%s",TestName);
  while(TestName==0){
  	Printf("Your name must be string type!");
  	fflush(stdin);
	RegisterCheck=scanf("%d",&RegisterCheck);	
  }
  for(RegisPointer=h->next;RegisPointer->next!=NULL;){
//	RegisPointer=h->next;
//	while(RegisPointer){
    if(strcmp(TestName,RegisPointer->StudentName)!=0){RegisPointer=RegisPointer->next;}
    if(strcmp(TestName,RegisPointer->StudentName)==0){
      printf("Idendical Name discovered, Please check your information and type again\n");
      scanf("%s",TestName);
      RegisPointer=h->next;
    }

  }
  strcpy(NewAccount->StudentName,TestName);
  printf("Welcome %s ,Please create your account \n",NewAccount->StudentName);
  scanf("%s",TestAccount);
  RegisPointer=h->next;
  
  for(;RegisPointer->next!=NULL;)
//	while(RegisPointer)
  {
//  	printf("JIN XUN HUAN LA!!");
    if(strcmp(TestAccount,RegisPointer->AccountId)!=0){
      	RegisPointer=RegisPointer->next;
   		 
}
//	while(RegisPointer){
    if(strcmp(TestAccount,RegisPointer->AccountId)==0){
    	printf("This account has already been registered, please choose a new one!\n");
      	scanf("%s",TestAccount);
      	RegisPointer=h->next;
    }
  }
  strcpy(NewAccount->AccountId,TestAccount);
  printf("Your personal account has been created successfully, please set your own password!\n");
  scanf("%s",NewAccount->Password);
	RegisPointer->next=NewAccount;
  NewAccount->next=NULL;
  NewAccount->StudentId=TestStuID;
  NewAccount->book1=0;
  NewAccount->book2=0;
  NewAccount->book3=0;
  NewAccount->BorrowedNum=0;
  printf("Congratulations! you can log in and use the Library now!\n");
//	printf("%d \t%s \t%s \t%s \t%d \t%d \t%d\n",NewAccount->StudentId,NewAccount->StudentName,NewAccount->AccountId, NewAccount->Password,NewAccount->book1,NewAccount->book2,NewAccount->book3);
  return 0;

 }
int SaveAccount(){
	FILE *fp= NULL;
  account *t=h->next;
  fp=fopen("UserData.txt","w+");
  for(t=h->next;t->next!=NULL;){
//  	printf("JIN XUN HUAN LA!");
    fprintf(fp,"%d %s %s %s %d %d %d\n",t->StudentId,t->StudentName,t->AccountId,t->Password,t->book1,t->book2,t->book3);
    t=t->next;
  }
  if(t->next==NULL){
//  	printf("BU CHONG!");
  	fprintf(fp,"%d %s %s %s %d %d %d",t->StudentId,t->StudentName,t->AccountId,t->Password,t->book1,t->book2,t->book3);
  }
  printf("The account has been saved successfully!\n");
  fclose(fp);
  return 0;


	
}
  int BorrowBooks(account *User,int book_ID){
//  	printf("check for wether the values consist%d%s\n%d%d%d",User->StudentId,User->StudentName,User->book1,User->book2,User->book3);
    if(User->BorrowedNum!=3&&User->book1!=book_ID&&User->book2!=book_ID&&User->book3!=book_ID){
      if(User->book1==0) {
	  User->book1=book_ID;
		printf("You have successfully borrowed the book!~!~\n");
		return 0;
	  }
      if(User->book1!=0&&User->book2==0) {
      	User->book2=book_ID;
      	printf("You have successfully borrowed the book!~!~\n");
      	return 0;
	  }
      if(User->book1!=0&&User->book2!=0&&User->book3==0) {
      	User->book3=book_ID;
      	printf("You have successfully borrowed the book!~!~\n");
      	return 0;
	  }
      
    }
    printf("You have borrowed this book or you have reached the maximum number of borrowed books\n");
    return 1;
  }
  
  void ReturnBooks(account *User,int book_ID){
//    q=head->next;
    if(User->book1!=book_ID&&User->book2!=book_ID&&User->book3!=book_ID){
      printf("NO such book found in the account\n");
      return;
    }
    if(User->book1==book_ID) {User->book1=0;}
    if(User->book2==book_ID) User->book2=0;
    if(User->book3==book_ID) User->book3=0;
    printf("you have successfully returned the book\n");
//      while(q){
//        if(q->id==book_ID)
//        {
//          q->copies++;
//          printf("The book has been returned successfully\n");
//          break;
//        }
//        q=q->next;
//      }
    }
	int JudgeForReturn(int BOOKID){
		account *JudgePointer=h->next;
		while(JudgePointer){
			if(JudgePointer->book1==BOOKID||JudgePointer->book2==BOOKID||JudgePointer->book3==BOOKID){
				return 1;
			}
			JudgePointer=JudgePointer->next;
		}
		return 0;
	}
    
