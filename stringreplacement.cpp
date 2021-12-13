#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>

using namespace std;

int main() {

  string search , replace, str, pathtofile, nameoffile;
  int index;

  cout<< "Write down the path to file you want to edit (beginning with /home/.....), and separately name of the file: \n";
  cin>>pathtofile>>nameoffile;

  cout <<"Word to delete: ";
  cin>> search;
  
  cout <<"Word to replace with: ";
  cin>> replace;
  
 
  fstream filein;
  filein.open((pathtofile+nameoffile).c_str(), fstream::in | fstream::out);
  ofstream fileout;
  fileout.open("../c++/temp.txt");

while(getline(filein, str)){

  while ((index=str.find(search))!= string::npos){

      str.replace(index, search.length(), replace );
     
  }
  fileout << str<< endl;
}
 
filein.close();
fileout.close();

remove((pathtofile+nameoffile).c_str());
rename("../c++/temp.txt", (pathtofile+nameoffile).c_str());

cout<< "Done!\n";

}