 #include <stdio.h>
 #include "book.h"
//struct BookNode
//{
//	struct _book books;
//	struct BookNode *next;
//};
Book *q,*final;
 int store_books(FILE *file){
 	FILE *Store; 
 	Book *PointerForSave = head->next;
 	Store=fopen(file,"w");
  for(;PointerForSave->next!=NULL;){
    fprintf(file, "%d %s %s %d %d\n",PointerForSave->id,PointerForSave->title,PointerForSave->authors,PointerForSave->year,PointerForSave->copies);
    PointerForSave=PointerForSave->next;
  }
  if(PointerForSave->next=NULL){
    fprintf(file, "%d %s %s %d %d\n",PointerForSave->id,PointerForSave->title,PointerForSave->authors,PointerForSave->year,PointerForSave->copies);

  }
  printf("All books have been saveed successfully\n");
	fclose(Store);
  return 0;


 };
  int load_books(FILE *file){
  FILE *fp;
  
  CreateJunction(head);
  final=head;
  fp =fopen("BookData.txt","r");
//  printf(fp);
  for(;!feof(fp);){
//  	printf("JIN XUN HUAN LA!");
  	CreateJunction(q);
//  	printf("Bug1");
  	fscanf(fp,"%d%s%s%d%d",&(q->id),q->title,q->authors,&(q->year),&(q->copies));
//  	printf("BUG 2");
  	printf("Book information PRINTING :%d %s %s %d %d\n",q->id,q->title,q->authors,q->year,q->copies);
  	final->next=q;
  	final=q;
  }
  final->next=NULL;
//  printf("This is final Test %s",final->title);
  fclose(fp);
  return 0;
  };
  int add_book(Book book){
//  	CreateJunction(&book);
  	static int TestUse;
  	Book *AddTest=head->next;
  	for(;AddTest->next!=NULL;){
  		TestUse=0;
  		printf("try!!\n");
  		// printf("DATA %d%dNUMBER ID %d\n",book.id,AddTest->id,TestUse);
  		if(strcmp(book.title,AddTest->title)==0) TestUse++;
  		// printf("DATA %s%sNUMBER TITLE %d\n",book.title,AddTest->title,TestUse);
  		if(strcmp(book.authors,AddTest->authors)==0) TestUse++;
  		// printf("DATA %s%sNUMBER AUTHOR %d\n",book.authors,AddTest->authors,TestUse);
  		if(book.year==AddTest->year) TestUse++;
  		// printf("DATA %d%dNUMBER YEAR %d\n",book.year,AddTest->year,TestUse);
//  		if(book.copies==AddTest->copies) TestUse++;
  		if(TestUse==3){
  			printf("there has been an identical book in the library.\n");
  			printf("The system automatically adds the number of the books to the original ones.\n");
  			AddTest->copies= AddTest->copies+book.copies;
  			break;
  		}
  		printf("NUMBER %d\n",TestUse);
  		AddTest=AddTest->next;
  		if(TestUse>0&&TestUse<3){
  			printf("Identical information to the exsisting storaged books, please confirm the information!\n");
  			scanf("%s%s%d%d",book.title,book.authors,&(book.year),&(book.copies));
  			AddTest=head->next;
  		}


  	}
  	if(AddTest->next==NULL){
  		TestUse=0;
//  		printf("try!!\n");
//  		printf("DATA %d%dNUMBER ID %d\n",book.id,AddTest->id,TestUse);
  		if(strcmp(book.title,AddTest->title)==0) TestUse++;
//  		printf("DATA %s%sNUMBER TITLE %d\n",book.title,AddTest->title,TestUse);
  		if(strcmp(book.authors,AddTest->authors)==0) TestUse++;
//  		printf("DATA %s%sNUMBER AUTHOR %d\n",book.authors,AddTest->authors,TestUse);
  		if(book.year==AddTest->year) TestUse++;
//  		printf("DATA %d%dNUMBER YEAR %d\n",book.year,AddTest->year,TestUse);
//  		if(book.copies==AddTest->copies) TestUse++;
  		if(TestUse==3){
  			printf("there has been an identical book in the library.\n");
  			printf("The system automatically adds the number of the books to the original ones.\n");
  			AddTest->copies= AddTest->copies+book.copies;
  			return 0;
  		}
  		printf("NUMBER %d\n",TestUse);
  		AddTest=AddTest->next;
  		if(TestUse>0&&TestUse<3){
  			printf("Identical information to the exsisting storaged books, please confirm the information!\n");
  			scanf("%s%s%d%d",book.title,book.authors,&(book.year),&(book.copies));
  			AddTest=head->next;
  		}
  		
	  }
  	if(TestUse=0){
  		AddTest->next=&book;
  		book.next=NULL;
      book.id=AddTest->id+1;
  		printf("New book has been added successfully");
  		return 0;
	  }


  };
  int remove_book(Book book){
//  	CreateJunction(&book);
  	Book *RemoveTest=head->next;
  	for(;RemoveTest->next!=NULL;){
  		if(book.id==RemoveTest->id&&strcmp(book.title,RemoveTest->title)==0&&strcmp(book.authors,RemoveTest->authors)==0&& book.year==RemoveTest->year){
  			free((void*)RemoveTest);
  			printf("This book has been removed successfully\n");
  			return 0;
  		}
  		RemoveTest=RemoveTest->next;
  	}
  	printf("Operation of Remove failed because of no such book found\n");
  	return 1;

  };
  BookArray find_book_by_title (const char *title){
  	Book *findT=head->next;
//  	Book *Array[10];
  	BookArray PreResult;
  	char *Check;
  	int Count=0;
  	printf("ID   ");
    printf("Title          ");
    printf("Authors        ");
    printf("Year ");
    printf("copies \n");
  	for(;findT->next!=NULL;){
//  		printf("JINXUNHUANLA1\n");
  		Check=strstr(findT->title,title);
  		if (Check!=NULL)
  		{
//  			printf("JIN PAN DUAN LA!\n");
  			printf("%-5d",findT->id);
    		printf("%-15s",findT->title);
    		printf("%-15s",findT->authors);
    		printf("%-5d",findT->year);
    		printf("%-5d\n",findT->copies);
  			
//  			printf("The book you looking for has been searched successfully\n");
//  			Array[Count]=findT;
//  			printf("Subset of requirment consists %s\n",Array[Count]->title);
//  			Count++;

  		}
  		findT=findT->next;

  	}
  	if(findT->next==NULL){
  		Check=strstr(findT->title,title);
  		if(Check!=NULL){
  			printf("%-5d",findT->id);
    		printf("%-15s",findT->title);
    		printf("%-15s",findT->authors);
    		printf("%-5d",findT->year);
    		printf("%-5d\n",findT->copies);
//  			printf("The book you looking for has been searched successfully\n");
//  			Array[Count]=findT;
//  			Count++;
//  			printf("Subset of requirment consists %s",findT->title);
  			
		  }'/;L>K
		  '';/'/;'/;/;'/'/;L>K
		  ;'MNHJ>OL<K?P
		  lk;'lk/;'''?'?'/;>L
		  '/'/;'/;/;;/;/;'//;'/;>LK
		  MJO<P{I}>LK?:"'/;'/;'/;'>LK
		  MNHJO<IP{BG}';/';'/;/;/;'/;L'/;/;;/;'/;LL>
		  K{PO}<JJ{PO'/:L
		  >'?::>L
		  KOP{<}PO}<K{PO}<JIMPOJ<}K{POJ<}K{POJ<J<PO'/;L
		  >''/;>L
		  MJO<IKP{}>LK?:"MNHJO<P{
		  '/;;>L'/;'//;''/;'''/;>L
		  K{PO<>L
		  '/;'//'/;/;'/;''/;L?:">L
		  KMJO<IP{}>L
		  KP{'/;/;'''/;L>>
		  K>'//;'/;'/;'/;'/;;>L
		  ;/';'/;/;'/;'>LK>>LK
		  L>>LL>L>K
		  
		  K
		  KL>L>L>'/;'/;'/;>L
		  '/;'/;>L
		  K>L
		  KKK'//';/;'>L
		  KP{O<J}IM>L
		  >L
		  K{K>/;'/;>L
		  >L
		  '/;>L
		  KP{O<}PO<J>L
		  >>L
		  '/;'/;'/;'/;LL>>L
		  K
		  K
		  L>
		  K>'/;/;L'/;'/;>LK'/;'/;''/;'/;'/;>LK
		  P{O<J}JK
		  K
		  '/;L>>L'/;>LK
		  >L
		  K'/;'/;;'/;/;''/;'/;/;'/;'/;'/;;'/;'/;LLLL>L>K
		  JO<P{POJ<MI}K
		  K
		  L>K
		  P{OO>LK
		  >>K
		  OP{K'
	  }
//  	PreResult.ArrayID= Array;
  	PreResult.length=Count;
  	PreResult.array=findT;
  	printf("Check\n");
//  	DisplaySearchedResult(Array[0],Count);
//  	printf("THe length is %d\n",PreResult.length);

  	return PreResult;


  	
  };
  BookArray find_book_by_author (const char *author){
  	Book *findA=head->next;
  	Book *ArrayForA[10];
  	BookArray PreForA;
  	char *CheckForA;
  	int Count=0;
  	printf("ID   ");
    printf("Title          ");
    printf("Authors        ");
    printf("Year ");
    printf("copies \n");
  	for(;findA->next!=NULL;){
  		CheckForA=strstr(findA->authors,author);
  		if(CheckForA!=NULL){
  			printf("%-5d",findA->id);
    		printf("%-15s",findA->title);
    		printf("%-15s",findA->authors);
    		printf("%-5d",findA->year);
    		printf("%-5d\n",findA->copies);
//  			ArrayForA[Count]=findA;
//  			Count++;
  		}
  		findA=findA->next;
  	}
  	if(findA->next==NULL){
  		CheckForA=strstr(findA->authors,author);
  		if(CheckForA!=NULL){
  			printf("%-5d",findA->id);
    		printf("%-15s",findA->title);
    		printf("%-15s",findA->authors);
    		printf("%-5d",findA->year);
    		printf("%-5d\n",findA->copies);
//  			ArrayForA[Count]=findA;
//  			Count++;
  		}
	  }
  	PreForA.array=findA;
  	PreForA.length=Count;
  	return PreForA;
  	
  };
  BookArray find_book_by_year (unsigned int year){
  	Book *findY=head->next;
  	Book *ArrayForY[10];
  	BookArray PreForY;
  	// char *CheckForY;
  	int Count=0;
  	printf("ID   ");
    printf("Title          ");
    printf("Authors        ");
    printf("Year ");
    printf("copies \n");
  	for(;findY->next!=NULL;){
  		if(findY->year==year){
  			printf("%-5d",findY->id);
    		printf("%-15s",findY->title);
    		printf("%-15s",findY->authors);
    		printf("%-5d",findY->year);
    		printf("%-5d\n",findY->copies);
//  			ArrayForY[Count]=findY;
//  			Count++;  			
  		}
  		findY=findY->next;
  	}
  	if(findY->next==NULL){
  		if(findY->year==year){
  			printf("%-5d",findY->id);
    		printf("%-15s",findY->title);
    		printf("%-15s",findY->authors);
    		printf("%-5d",findY->year);
    		printf("%-5d\n",findY->copies);
//  			ArrayForY[Count]=findY;
//  			Count++;  			
  		}
  		
	  }
	  
  	PreForY.array=findY;
  	PreForY.length=Count;
  	return PreForY;

  };
  void DisplayAllBooks(Book *head){
  Book *PointerForDisplay=head->next;
	printf("ID   ");
	printf("Title          ");
    printf("Authors        ");
    printf("Year ");
    printf("copies \n") ;
  while(PointerForDisplay)
  {
    
    printf("%-5d",PointerForDisplay->id);
    printf("%-15s",PointerForDisplay->title);
    printf("%-15s",PointerForDisplay->authors);
    printf("%-5d",PointerForDisplay->year);
    printf("%-5d\n",PointerForDisplay->copies);
    PointerForDisplay=PointerForDisplay->next;
  }
  }
//  void DisplaySearchedResult(Book *condition[],int length){
//  	int ConditionCount=0;
//    for(;ConditionCount<length;){
//    
//    printf("%-5d",Array[ConditionCount]->id);
//    printf("%-15s",(Array[ConditionCount])->title);
//    printf("%-15s",(Array[ConditionCount])->authors);
//    printf("%-5d",(Array[ConditionCount])->year);
//    printf("%-5d\n",(Array[ConditionCount])->copies);
//    ConditionCount++;
//  }
//}


void SearchEngine(){
  int SearchValue,SearchYear;
    char SearchCondition[50];
    BookArray condition;
    printf("Please choose an option\n");
    printf("1.Find books by title\n");
    printf("2.Find books by authors\n");
    printf("3.Find books by year\n");
    printf("4.Return to previous menu\n");
    scanf("%d",&SearchValue);
    switch(SearchValue){
      case 1:
      printf("Please input the key word!\n");
      scanf("%s",SearchCondition);
      find_book_by_title(SearchCondition);
//      DisplaySearchedResult(condition);
      break;
      case 2:
      printf("Please input the authors' name!\n");
      scanf("%s",SearchCondition);
      find_book_by_author(SearchCondition);
//      DisplaySearchedResult(condition);
      break;
      case 3:
      printf("Please input the year that books are published!\n");
      scanf("%d",&SearchYear);
      find_book_by_year(SearchYear);
//      DisplaySearchedResult(condition);
      case 4:
      printf("Back to the previous menu\n");
      break;
      default:
      printf("Please input a valid value\n");
    }while(SearchValue!=4);

}
  
  // int main(){
  // 	load_books("BookData.txt");
//  	Book Increase1;
//  	struct _Book In1={4,"MeiTing","Wangbadang",1998,8};
//  	struct _Book In2={1002,"PoJieSeng","LiJinqi",2020,5};
//  	struct _Book In3={1480,"PoJieSeng","LiJinqi",2019,4};
////  	Increase.authors='WangBadan',Increase.copies=5,Increase.id=4,Increase.title='MeiTingShuoGuo',Increase.year=1998;
//  	add_book(In1);
//  	printf("add 1 succeed");
//  	add_book(In2);
//  	printf("Add 2 succeed");
//  	add_book(In3);
//	printf("Final succeed");
//	find_book_by_title("e");
  	
// }