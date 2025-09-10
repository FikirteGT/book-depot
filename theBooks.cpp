#include <iostream>
#include <iomanip>

using namespace std;
enum switch1{InsertBook=1, ViewBook, FindBook, ModifyBook};
int main(){

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