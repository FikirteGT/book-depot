#include <iostream>
#include <iomanip>

using namespace std;
enum switch1{InsertBook=1, ViewBook, FindBook, ModifyBook};
enum switch2{Fiction=1, Nonfiction};
int main(){

string title1,title2,language1,language2, author1,author2;
int quantity1,quantity2, isbn1,isbn2, num1,num2;
switch1 choose;
switch2 choosegenra;
char symbol[100];

fill(symbol, symbol + 100, '*');
for(char asterisk : symbol){
 	cout<<asterisk;
}
 
cout<<endl<<setw(60)<<"welcome to book store management\n";

for(char asterisk : symbol){
	cout<<asterisk;
}

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
      choosegenra =static_cast<switch2>(tempoGenra);
      switch(choosegenra){
        case Fiction:
	       	       	cout<<"How many books do you want to enter? ";
	       	        cin>>num1;
	       for(int i=0; i<num1; i++){
		  	  cout<<"BOOK "<<i+1<<endl;
			    cout<<"    1.Title: ";
		      cin>> title1;			    
		  	  cout<<"    2.Author: ";
		  	  cin>>author1;
		      cout<<"    3.ISBN: ";
		  	  cin>>isbn1;
		      cout<<"    4.Language: ";
		  	  cin>>language1;
		      cout<<"    5.Quantity: ";
		      cin>> quantity1;
         }
	       	       break;

	      case Nonfiction:
	       	        cout<<"How many books do you want to enter? ";
	       	        cin>>num2;
	        for(int i=0; i<num1; i++){
		  	   cout<<"BOOK "<<i+1<<endl;
			     cout<<"    1.Title: ";
		       cin>> title2;			    
		  	   cout<<"    2.Author: ";
		  	   cin>>author2;
		       cout<<"    3.ISBN: ";
		  	   cin>>isbn2;
		       cout<<"    4.Language: ";
		  	   cin>>language2;
		       cout<<"    5.Quantity: ";
		       cin>> quantity2;
                break;
          }
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
//return 0;
}