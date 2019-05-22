# Sivakumar, Namrata
# nxs8168
# 2019-02-21
#--------------------------------------------------
import re
import sys

#--------------------------------------------------
def processToken( token ) :

   if re.compile("\|[A-Z0-9]*\+").fullmatch(token) != None:
       print(">",token,"< matches STR", sep='')

   elif re.compile("\#[0-9r-wR-W]+").fullmatch(token) !=None:
       print(">",token,"< matches INT", sep='')

   elif re.compile("[0-9]+\)\([0-9]+").fullmatch(token) !=None:
       print(">",token,"< matches FP", sep='')

   else:
       print(">",token,"< does not match", sep='')

#--------------------------------------------------
def main() :
  fName = sys.argv[ 1 ]
  print( 'processing tokens from ' + fName + ' ...' )

  with open( fName, 'r' ) as fp :
    lines = fp.read().replace( '\r', '' ).split( '\n' )

  for line in lines :
    for token in line.split() :
      processToken( token )

#--------------------------------------------------
if ( __name__ == '__main__' ) :
  main()

#--------------------------------------------------
