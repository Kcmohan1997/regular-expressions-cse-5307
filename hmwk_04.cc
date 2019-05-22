// Sivakumar, Namrata

// 2019-02-28

#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

void processToken( string token )
{
  regex s("[|]{1}[A-Z0-9]*[+]{1}");
  regex fp("[0-9]+[)]{1}[(]{1}[0-9]+");
  regex intt("[#]{1}[r-wR-W0-9]+");
  if(regex_match(token,s)){
cout<<">"<<token<<"<"<<" matches STR."<<endl;
  }
  
  else if(regex_match(token,fp)){
cout<<">"<<token<<"<"<<" matches FP."<<endl;
  }
else if(regex_match(token,intt)){
cout<<">"<<token<<"<"<<" matches INT."<<endl;
  }
  else{
    cout<<">"<<token<<"<"<<" does not match."<<endl;
  }
  //cout << ">" << token << "< is the proposed token.\n";
}

int main( int argc, char *argv[] )
{
  if ( argc > 1 ) {
    cout << "processing tokens from " << argv[ 1 ] << " ...\n";

    ifstream inputFile;
    string   token;

    inputFile.open( argv[ 1 ] );

    if ( inputFile.is_open() ) {
      while ( inputFile >> token ) {
        processToken( token );
      }
      inputFile.close();
    } else {
      cout << "unable to open " << argv[ 1 ] << "?\n";
    }
  } else {
    cout << "No input file specified.\n";
  }
}
