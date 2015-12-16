#!/bin/bash
case $1 in
-h) 
echo "
–h | --help: prints a help message with the command sintax;
–l | --longest: the script must replace each word in the input file with the longest translation possible for that word;
–s | --shortest: the script must replace each word in the input file with the shortest translation possible for that word;
–n Num: the script must replace each word in the input file with the translation at position Num in the vocabulary for each word;
–v | --verbose: for each word such that a translation is not available the original word is written together with a warning message for each word which is not translated (the default behavior is not to print anything in place of the word if a translation is not available);";;
-l)
while read line
do
awk -v Var="$line" -v File="$4" 'BEGIN {RS="#"}{if(Var==$1){
					max=$2;for(i=2;i<=NF;i++){
							if(length(max)<length($i)) max=$i} print max >> File  }}' $2 
done < $3 ;;
-s)
while read line
do
awk -v Var="$line" -v File="$4" 'BEGIN {RS="#"}{if(Var==$1){
					min=$2;for(i=2;i<=NF;i++){
							if(length(min)>length($i)) min=$i} print min >> File}}' $2 
done < $3 ;;
-n)
while read line
do
awk -v Var="$line" -v NUM="$2" -v File="$5" 'BEGIN {RS="#"}{if(Var==$1) print $NUM >> File}' $3
done < $4 ;;
-v)
while read line
do
awk -v Var="$line" -v File="$4" 'BEGIN {RS="#";bool="f"}{if(Var==$1){ bool="t"}} END{if(bool=="f") printf("Translation of \"%s\" not exist!\n",Var)>>File}' $2
done < $3 ;;
*)
while read line
do
awk -v Var="$line" -v File="$4" 'BEGIN {RS="#"}{if(Var==$1) print $0 >> File}' $2
done < $3 ;;
esac



#awk 'BEGIN {RS="#"}{if($1=="hello") print $3}' $1




