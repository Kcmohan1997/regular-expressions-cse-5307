# regular-expressions-cse-5307, Implemented in Python 3.7, Java, C#, C++ and C.

  * The input file will have multiple proposed tokens on each
    line.  There also might be lines with no proposed tokens
    and / or just or extra whitespace.

  * The proposed tokens will be separated by whitespace, which is
    to be ignored.

  * Your program will consider successive tokens from the input
    file and classify them as 'FP', 'STR', 'INT', or
    'does not match'.

  * An FP is one or more decimal digits, followed by a right
    parenthesis, followed by a left parenthesis, followed by
    one or more decimal digits.

  * A STR is a vertical bar (|) followed by zero or more uppercase
    letters and decimal digits followed by a plus sign (+).

  * An INT is a octothorpe sign (#) followed by one or more
    decimal digits or letters R through W.  The letters may be
    uppercase or lowercase.  (That is, r through w are allowed.)
    
    Examples:

  000)(000  is a legal FP.
  1)(1      is a legal FP.
  )000      is not a legal FP.
  000(      is not a legal FP.
  1.1       is not a legal FP.

  |+        is a legal STR.
  |1+       is a legal STR.
  |HITHERE+ is a legal STR.
  |a+       is not a legal STR.
  "abc"     is not a legal STR.
  A+        is not a legal STR.
  |A        is not a legal STR.

  #rSt      is a legal INT.
  #0        is a legal INT.
  #r0       is a legal INT.
  #W        is a legal INT.
  123       is not a legal INT.
  rSt       is not a legel INT.
