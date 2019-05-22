// Sivakumar, Namrata

// 2019-02-21

import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.util.Arrays;

public class hmwk_03 {
  public static void processToken( String token )
  {
	  Pattern pattern1 = Pattern.compile("[|][[A-Z][0-9]]*[+]");
	  Pattern pattern2 = Pattern.compile("[0-9]+[)][(][0-9]+");
	  Pattern pattern3 = Pattern.compile("[#][[0-9][r-w][R-W]]+");
  
	  Matcher s = pattern1.matcher(token);
	  Matcher f = pattern2.matcher(token);
	  Matcher i = pattern3.matcher(token);
	  
	  if(s.matches()) {
		  System.out.println(">"+ token +"< matches STR");
	  }
	  else if(f.matches()) {
		  System.out.println(">"+ token +"< matches FP");
	  }
	  else if(i.matches()) {
		  System.out.println(">"+ token +"< matches INT");
		  
	  }
	  else
	  {
		  System.out.println(">"+ token +"< does not match");
		  
	  }
  }

  public static void main( String[] args )
  {
    System.out.println( "processing tokens from " + args[ 0 ] + " ..." );

    try {
      Files.lines( Paths.get( args[ 0 ] ) ).filter(line -> line.length() > 0).forEachOrdered(
        line -> Arrays.stream( line.split( "\\s+" )  )
            .forEachOrdered( token -> processToken( token ) ) );
    } catch ( java.io.IOException e ) {
      e.printStackTrace();
    }
  }
}
