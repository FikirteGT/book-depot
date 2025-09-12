#include <iostream>
#include <iomanip>

using namespace std;
enum switch1{InsertBook=1, ViewBook, FindBook, ModifyBook};
int main(){
string title,language,author;
int quantity, isbn, num1;
switch1 choose;
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
      cout<<"How many books do you want to enter? ";
	       	        cin>>num1;
	       for(int i=0; i<num1; i++){
		  	 cout<<"BOOK "<<i+1<<endl;
			   cout<<"    1.Title: ";
		     cin>> title;			    
		  	 cout<<"    2.Author: ";
		  	 cin>>author;
		     cout<<"    3.ISBN: ";
		  	 cin>>isbn;
		     cout<<"    4.Language: ";
		  	 cin>>language;
		     cout<<"    5.Quantity: ";
		     cin>> quantity;
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