#include <stdio.h>
#include "account.h"
#include "book.h"
account *AdminPath;
int check=1;
int CusLog(account *Path){
	int Option=0;
	int book_ID;
	do{
	printf("________________________\n");
	printf("Welcome to the Virtual Library System\n");
	printf("Please choose the operation:\n");
	printf("1.Borrow books\n");
	printf("2.Return books\n");
	printf("3.Search for books\n");
	printf("4.Display all books\n");
	printf("5. Log out\n");
	printf("________________________\n" );
	check=scanf("%d",&Option);
	while (check!=1)
	{
		printf("Detected Invalid Input, Please Try Again\n");
		fflush(stdin);
		check=scanf("%d",&Option);
	}
	switch(Option){
		case 1:
//			printf("This is a test for head %d",head->id);
		
    	printf("Please enter the ID of books that you want to borrow.\n");
    	check=scanf("%d",&book_ID);
    	if(check==0){
    		printf("Incompatible input type!");
    		break;
		}
    	if(book_ID<1001||final->id<book_ID){
    		printf("Detected Invalid Input\n");
    		break;
    	}
    	BorrowBooks(Path,book_ID);
    	break;
		case 2:
		printf("Please enter the ID of books that you want to return\n");
		check=scanf("%d",&book_ID);
		if(check==0){
    		printf("Incompatible input type!");
    		break;
		}
		if(book_ID<1001||final->id<book_ID){
    		printf("This book does not exsist in the system\n");
    		break;
    	}
    	ReturnBooks(Path,book_ID);
    	break;


		case 3:
		SearchEngine();
		break;

		case 4:
		DisplayAllBooks();
		break;
		case 5:
		printf("The account has logged out\n");
		break;
		default:
		printf("Invalid input, Please try again.\n");
		break;
	}

	}while(Option!=5);

	return Option;
}
int AdminOperation(){
	int Option1=0;
	Book AddingBook;
	Book DeletingBook;
	do{
	printf("________________________\n");
	printf("Operate to adjust the Virtual Library System:\n");
	printf("1.Add books to the System\n");
	printf("2.Remove books from the System\n");
	printf("3.Search for books\n");
	printf("4.Display All books\n");
	printf("5.Log out\n");
	printf("________________________\n");
	check=scanf("%d",&Option1);
	if (check!=1)
	{
		printf("Detected Invalid Input, Please Try Again\n");
		continue;
	}
	switch(Option1){
		case 1:
		printf("Please input the title,author,year,copies\n");
		check=scanf("%s%s%d%d",AddingBook.title,AddingBook.authors,&(AddingBook.year),&(AddingBook.copies));//How to handle wrong value?
//		if(check==0){
//			printf("The information of the books are incompatible!");
//			break;
//		}
		add_book(AddingBook);
		break;
		case 2:
		printf("Please input the information of the book you want to delete.\n");
		check=scanf("%d",&(DeletingBook.id));
		if(check==0){
			printf("Incmopatible input type!\n");
			break;
		}
		if(DeletingBook.id<1001||final->id<DeletingBook.id){
    		printf("This book does not exist in the system\n");
    		break;
    	}
		int JudgeCheck=JudgeForReturn(DeletingBook.id);
		if(JudgeCheck==1){
			printf("This book has already been borrowed,operation for deleting denied!\n");
			break;
		}
		
//		printf("Test1\n"); 
		remove_book(DeletingBook);
		break;
		case 3:
		SearchEngine();
		case 4:
		DisplayAllBooks();
		break;
		case 5:
		printf("Admin has successfully loged out!\n");
		break;
		default:
		printf("Please input a valid value!\n");
	}
//	return 0;


	}while(Option1!=5);

	return Option1;
}
 // int UserView(){
 // 	int Option2;
 // 	for(;Option2<=0||Option2>3;){
 // 	printf("________________________\n");
 // 	printf("Please choose the operation:\n");
 // 	printf("1:Borrow books from the Library\n");
 // 	printf("2:Return books\n");
 // 	printf("3:Log out\n");
 // 	printf("________________________\n");
 // 	scanf("%d",&Option2);
 // 	if (Option2<=0||Option2>3)
	// {
	// 	printf("Invalid input, Please try again.\n");
	// }
 // 	}
 // 	return Option2;

 // }
 static void main_menu() {

	int choice =5 ; //exit
	

	do {
		printf("\nPlease enter next action:\n1) Register an account\n2) Login\n3) Search for books\n4) Display all books\n5) Quit\nOption:");
		check=scanf("%d",&choice);
		while(check==0)
	{
		printf("Detected Invalid Input, Please Try Again\n");
		fflush(stdin);
		check=scanf("%d",&choice);
		
	}
//		char * answer = ask_question(" ");
//		choice = atoi(answer);
//		free(answer);

		switch (choice) {
			case 1:
				Register();
				break;
			case 2:
				AdminPath=LogIn();
				if(AdminPath==NULL){
						AdminOperation();} //Return NULL is admin
				if(AdminPath!=NULL&&AdminPath!=h){
					CusLog(AdminPath);
				}
				if(AdminPath==h) printf("No such account! \n");

				break;
			case 3:
				SearchEngine();
				break;
			case 4:
				DisplayAllBooks();
				break;
			
			case 5:
				printf("goodbye\n");
				break;
			default:
				printf("Sorry, that doesn't seem to be an option\n");
		}

	} while (choice != 5);
}
int main(){
	FILE *BOOK,*SAVE;
	BOOK=fopen("BookData.txt","r");
	LoadUserData();
	load_books(BOOK);
	main_menu();
	SAVE=fopen("BookData.txt","w");
	store_books(SAVE);
	SaveAccount();
	
	
}
