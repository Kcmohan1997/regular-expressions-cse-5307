// Sivakumar, Namrata

// 2019-02-21

using System;
using System.IO;
using System.Text.RegularExpressions;

public class hmwk_03
{
  static public void processToken( string token ) {
    
    string fp=@"[0-9]+\)\([0-9]+";
  	string str=@"\|[A-Z0-9]*\+";
  	string integer=@"\#[0-9r-wR-W]+";

  	Match floatt=Regex.Match(token,fp);
  	Match strring=Regex.Match(token,str);
  	Match integerr=Regex.Match(token,integer);
	if(floatt.Success)
  	{
  	 	Console.WriteLine(">"+token+"< matches FP");
  	}
  	else if(strring.Success)
  	{
  		Console.WriteLine(">"+token+"< matches STR");
  	}
  	else if(integerr.Success)
  	{
  		Console.WriteLine(">"+token+"< matches INT");
  	}
  	else
  	{
  		Console.WriteLine(">"+token+"< does not match");
  	}
  }

  static public void Main( string[] args )
  {
    Console.WriteLine( "processing tokens from " + args[ 0 ] + " ..." );

    foreach ( string line in File.ReadAllLines( args[ 0 ] ) ) {
      foreach ( string token in line.Split( (char []) null, StringSplitOptions.RemoveEmptyEntries ) ) {
        processToken( token );
      }
    }
  }
}
