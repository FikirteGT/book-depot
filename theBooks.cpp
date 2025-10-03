#include <iostream>
#include <iomanip>

using namespace std;
enum menu{InsertBook=1, ViewBook, FindBook, ModifyBook};
enum genre{Fiction=1, Nonfiction, allBooks};
enum aboutBook{title=1, author, isbn, language, quantity};

struct ToCheck{
  bool digitChecker(const string& input){
		for(int i=0; i<input.length(); i++){
		  	if(!isdigit(input[i])) return false;
		}
		return true;
	}
 void letterChecker( string& input){
    	for(int i=0; i<input.length(); i++){
    	  if(isupper(input[i])){
    		input[i] = tolower(input[i]);
		  }     
	    }
	}		
};
class Book{
	public:
		  string FicBooks[100][5];
		  string NonFicBooks[100][5];
		   int ficBookCount = 0;
		   int nonFicBookCount = 0;
};
class RegisterBook : public Book{
  public:
      ToCheck check;
		  void RegFicBooks(int num){
		   // this->num= numR;
		  	for(int i=0; i<num; i++){
		  	 cout<<"BOOK "<<i+1<<endl;
			 cout<<"    1.Title: ";
		     getline(cin, FicBooks[ficBookCount][0]);			    
         do{
			 cout<<"    2.Author: ";
		  	 getline(cin, FicBooks[ficBookCount][1]);
		   }while(check.digitChecker(FicBooks[ficBookCount][1]));
		  do{
             cout<<"    3.ISBN: ";
		  	 getline(cin, FicBooks[ficBookCount][2]);
		   }while(!check.digitChecker(FicBooks[ficBookCount][2]));
		  do{
		     cout<<"    4.Language: ";
		  	 getline(cin, FicBooks[ficBookCount][3]);
		  }while(check.digitChecker(FicBooks[ficBookCount][3]));
		 do{
             cout<<"    5.Quantity: ";
		     getline(cin, FicBooks[ficBookCount][4]);
		  }while(!check.digitChecker(FicBooks[ficBookCount][4]));
			 ficBookCount++;
			  }
		  }
		  void RegNonFicBooks(int num){
		  	for(int i=0; i<num; i++){
		  	cout<<"BOOK "<<i+1<<endl;	
		    cout<<"    1.Title: ";
		    getline(cin, NonFicBooks[nonFicBookCount][0]);
		  do{
             cout<<"    2.Author: ";
		  	 getline(cin, NonFicBooks[nonFicBookCount][1]);
		   }while(check.digitChecker(NonFicBooks[nonFicBookCount][1]));	
		  do{
             cout<<"    3.ISBN: ";
		  	 getline(cin, NonFicBooks[nonFicBookCount][2]);
		   }while(!check.digitChecker(NonFicBooks[nonFicBookCount][2]));
		  do{
		     cout<<"    4.Language: ";
		  	 getline(cin, NonFicBooks[nonFicBookCount][3]);
		   }while(check.digitChecker(NonFicBooks[nonFicBookCount][3]));
     	  do{
             cout<<"    5.Quantity: ";
		  	 getline(cin, NonFicBooks[nonFicBookCount][4]); 
		  }while(!check.digitChecker(NonFicBooks[nonFicBookCount][4]));
		   nonFicBookCount++;
			  }
		  }
};
class DisplayBook : public RegisterBook{
public:
		void DisFicBooks(){
		//	numR = numR + num;
		    cout<<setw(50)<<"Fiction Books\n";
			cout<<"Title"<<setw(30)<<"Author"<<setw(30)<<"IBSN"<<setw(20)<<"Language"<<setw(20)<<"Quantity"<<endl;
			for(int i=0; i<ficBookCount; i++){
				cout<<FicBooks[i][0]<<setw(30)<<FicBooks[i][1]<<setw(30)<<FicBooks[i][2]<<setw(20)<<FicBooks[i][3]<<setw(20)<<FicBooks[i][4]<<endl;
			}
		}
		void DisNonFicBooks(){
		    cout<<setw(60)<<"Non-Fiction Books\n";
			cout<<"Title"<<setw(30)<<"Author"<<setw(30)<<"IBSN"<<setw(20)<<"Language"<<setw(20)<<"Quantity"<<endl;
			for(int i=0; i<nonFicBookCount; i++){
				cout<<NonFicBooks[i][0]<<setw(30)<<NonFicBooks[i][1]<<setw(30)<<NonFicBooks[i][2]<<setw(20)<<NonFicBooks[i][3]<<setw(20)<<NonFicBooks[i][4]<<endl;
			}    	
		}
};
class SearchBook : public DisplayBook {
 public:

   void display(string find){

       // Search Fiction
       for(int i = 0; i < ficBookCount; i++){
           if(FicBooks[i][0] == find){
             cout<<"Title"<<setw(30)<<"Author"<<setw(30)<<"ISBN"
                          <<setw(20)<<"Language"<<setw(20)<<"Quantity"<<endl;
             cout<<FicBooks[i][0]<<setw(30)<<FicBooks[i][1]
                            <<setw(30)<<FicBooks[i][2]<<setw(20)<<FicBooks[i][3]
                            <<setw(20)<<FicBooks[i][4]<<endl;
               return;
           }
       }
	   // Search Non-Fiction
       for(int i = 0; i < nonFicBookCount; i++){
           if(NonFicBooks[i][0] == find){
                cout<<"Title"<<setw(30)<<"Author"<<setw(30)<<"ISBN"
                        <<setw(20)<<"Language"<<setw(20)<<"Quantity"<<endl;
                cout<<NonFicBooks[i][0]<<setw(30)<<NonFicBooks[i][1]
                        <<setw(30)<<NonFicBooks[i][2]<<setw(20)<<NonFicBooks[i][3]
                        <<setw(20)<<NonFicBooks[i][4]<<endl;
               return;
           }
       }
       cout << "sorry no such book";
   }
};
class UpdateBook : public SearchBook {
	public:
		string Newtitle,NewAuthor,NewLanguage,NewIsbn,NewQuantity; 

		void edit(string target){ 
		  for(int i = 0; i < ficBookCount; i++){
           if(FicBooks[i][0] == target){
			cout<<"Title"<<setw(30)<<"Author"<<setw(30)<<"IBSN"<<setw(20)<<"Language"<<setw(20)<<"Quantity"<<endl;			    	
		 	        cout<<FicBooks[i][0]<<setw(30)<<FicBooks[i][1]<<setw(30)<<FicBooks[i][2]<<setw(20)<<FicBooks[i][3]<<setw(20)<<FicBooks[i][4]<<endl;
		 	        cout<<"which part do you to modify?\n"
	                    <<"1.Title\n2.Author\n3.IBSN\n4.Language\n5.Quantity\n";
		            int tempoEditable;
					cin>> tempoEditable;
					cin.ignore();
					aboutBook editable;
		            editable = static_cast<aboutBook> (tempoEditable);
		            switch(editable){
			          case title:
					    cout<<"New title: ";
			            getline(cin, Newtitle); 
						FicBooks[i][0] =  Newtitle;        
			            break;
			          case author:
			           do{
						cout<<"New author: ";
			          	getline(cin, NewAuthor);
			          	FicBooks[i][1] = NewAuthor;
					   }while(check.digitChecker(NewAuthor));
						break;
			          case isbn:
			           do{
						cout<<"New ISBN: ";
			          	getline(cin, NewIsbn);
			          	FicBooks[i][2] = NewIsbn;
					   }while(!check.digitChecker(NewIsbn));
			            break;
		              case language:
		               do{
					    cout<<"New Language: ";
			          	getline(cin, NewLanguage);
						FicBooks[i][3] = NewLanguage;
					   }while(check.digitChecker(NewLanguage));
						break;
		              case quantity:   
					   do{ 
						cout<<"New quantity: ";
			          	getline(cin, NewQuantity);	
						FicBooks[i][4] = NewQuantity;
     				   }while(!check.digitChecker(NewQuantity));
						break;
		      	      default:
				        cout<<"invalid choice";
		            }                        
		 	     	return;
				 }
			else if(NonFicBooks[i][0] == target){
			    	cout<<NonFicBooks[i][0]<<setw(30)<<NonFicBooks[i][1]<<setw(30)<<NonFicBooks[i][2]<<setw(20)<<NonFicBooks[i][3]<<setw(20)<<NonFicBooks[i][4]<<endl;
		 	     	cout<<"which part u wanna modify?\n"
	                    <<"1.Title\n2.Author\n3.IBSN\n4.Language\n5.Quantity\n";
		            int tempoEditable;
					cin>> tempoEditable;
					cin.ignore();
					aboutBook editable;
		            editable = static_cast<aboutBook> (tempoEditable);
		            switch(editable){
			          case title:
					    cout<<"New title: ";
			            getline(cin, Newtitle); 
						NonFicBooks[i][0] =  Newtitle;        
			            break;
			          case author:
			          do{ 
					    cout<<"New author: ";
			          	getline(cin, NewAuthor);
			          	NonFicBooks[i][1] = NewAuthor;
  					   }while(check.digitChecker(NewAuthor));
						break;
			          case isbn:
			            cout<<"New ISBN: ";
			          	getline(cin, NewIsbn);
			          	NonFicBooks[i][2] = NewIsbn;
			            break;
		              case language:
		              do{
						cout<<"New Language: ";
			          	getline(cin, NewLanguage);	
			          	NonFicBooks[i][3] = NewLanguage;
			           }while(check.digitChecker(NewLanguage));
						break;
		              case quantity:
		                cout<<"New quantity: ";
		                getline(cin, NewQuantity);
			          	NonFicBooks[i][4] = NewQuantity;
			            break;
			          
		      	      default:
				        cout<<"invalid choice";
		            }
					return;
				}
		    }
				cout<<"no such book";
		}    
};
int main(){

menu choose;
genre choosegenra;
UpdateBook b1;
int num1,num2,chooseShow;
string again, search;
ToCheck check;

char symbol[100];

fill(symbol, symbol + 100, '*');
for(char asterisk : symbol){
 	cout<<asterisk;
}
 
cout<<endl<<setw(60)<<"welcome to book store management\n";

for(char asterisk : symbol){
	cout<<asterisk;
}

do{
	
cout<<"\n1.Add new books"<<endl
    <<"2.Show all books"<<endl
    <<"3.Find a book"<<endl
    <<"4.Edit book detail"<<endl;
  int tempoChoose;
  cin>> tempoChoose;
      choose = static_cast<menu>(tempoChoose);
switch(choose){
    case InsertBook:
      cout<<"what is the genra of the book/s?\n"
	        <<"  1.Fiction Genra\n"
	        <<"  2.Non-Fiction Genra\n";
	   int tempoGenra;
	    cin>>tempoGenra;
	       choosegenra = static_cast<genre>(tempoGenra);	     
	       switch(choosegenra){
	       	 case Fiction:
	       	       	cout<<"How many books do you want to enter? ";
	       	        cin>>num1;
	       	        cin.ignore();
	       	        b1.RegFicBooks(num1);
	       	       break;
	       	 case Nonfiction:
	       	        cout<<"How many books do you want to enter? ";
	       	        cin>>num2;
	       	        cin.ignore();
	       	        b1.RegNonFicBooks(num2);
	       	       break;
		    }
	  break;
    case ViewBook:
		cout<<"which books you wanna see?\n"
		    <<"1. Fiction Books\n"
		    <<"2. Non Fiction Books\n"
			<<"3. All Available Books\n";
		int tempoShow;
		cin>>tempoShow;
		chooseShow = static_cast<genre> (tempoShow);
		cin.ignore();
		switch(chooseShow){
			case Fiction:
	            	b1.DisFicBooks();
	            	break;
	        case Nonfiction:
    	            b1.DisNonFicBooks();
	                break;
			case allBooks:
	        	    b1.DisFicBooks();
	        	    b1.DisNonFicBooks();
	        	    break;
	        default:
			       cout <<"invalid input";	    
		}
      break;
    case FindBook:
	    cout<<"Enter the title of the book you want to search: ";
		cin.ignore();
        getline(cin, search);
		b1.display(search);
      break;
    case ModifyBook:
	    cout<<"Enter the title of the book you want to modify: ";
		cin.ignore();
		getline(cin, search);
		b1.edit(search);
		cout<<"your editing has successfully finished";
		
      break;
    default:
       cout<<"invalid input";
}
do{
    cout<<"\n Do you want to do it again?(Yes/No) ";
    cin>>again;
    check.letterChecker(again);
   }while(!(again=="yes"||again=="no"));
}while(again == "yes");
cout<<"Thank you ;)";
return 0;
}