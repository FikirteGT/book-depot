#include <iostream>
#include <iomanip>

using namespace std;
enum switch1{InsertBook=1, ViewBook, FindBook, ModifyBook};
enum switch2{Fiction=1, Nonfiction};

class Book{
	public:
		  string FicBooks[100][5];
		  string NonFicBooks[100][5];
		 // string title,author,language;
		 //  int ibsn,quantity;
		   int ficBookCount = 0;
		   int nonFicBookCount = 0;
};
class RegisterBook : public Book{
  public:
		  void RegFicBooks(int num){
		   // this->num= numR;
		  	for(int i=0; i<num; i++){
		  	 cout<<"BOOK "<<i+1<<endl;
			 cout<<"    1.Title: ";
		     getline(cin, FicBooks[ficBookCount][0]);			    
		  	 cout<<"    2.Author: ";
		  	 getline(cin, FicBooks[ficBookCount][1]);
		  	///NOT DONE
		     cout<<"    3.ISBN: ";
		  	 getline(cin, FicBooks[ficBookCount][2]);
		     cout<<"    4.Language: ";
		  	 getline(cin, FicBooks[ficBookCount][3]);
		     cout<<"    5.Quantity: ";
		  	 getline(cin, FicBooks[ficBookCount][4]);
			 ficBookCount++;
			  }
		  }
		  void RegNonFicBooks(int num){
		  	for(int i=0; i<num; i++){
		  	cout<<"BOOK "<<i+1<<endl;	
		    cout<<"    1.Title: ";
		     getline(cin, NonFicBooks[nonFicBookCount][0]);
		  	cout<<"    2.Author: ";
		  	 getline(cin, NonFicBooks[nonFicBookCount][1]);
			cout<<"    3.ISBN ";///NOT DONE
		  	 getline(cin, NonFicBooks[nonFicBookCount][2]);
		    cout<<"    4.Language: ";
		  	 getline(cin, NonFicBooks[nonFicBookCount][3]);
		    cout<<"    5.Quantity: ";
		  	 getline(cin, NonFicBooks[nonFicBookCount][4]);
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
};
int main(){

switch1 choose;
switch2 choosegenra;
RegisterBook b1;
int num1,num2;
string again;
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
      choose = static_cast<switch1>(tempoChoose);
switch(choose){
    case InsertBook:
      cout<<"what is the genra of the book/s?\n"
	        <<"  1.Fiction Genra\n"
	        <<"  2.Non-Fiction Genra\n";
	   int tempoGenra;
	    cin>>tempoGenra;
	       choosegenra = static_cast<switch2>(tempoGenra);	     
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
      break;
    case FindBook:
      break;
    case ModifyBook:
      break;
    default:
       cout<<"invalid input";

}
do{
    cout<<"\n Do you want to do it again?(Yes/No) ";
    cin>>again;

   }while(!(again=="yes"||again=="no"));
}while(again=="yes");
cout<<"Thank you ;)";
//return 0;
}