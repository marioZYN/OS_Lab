#!/bin/sh
awk -v F="$1" '{ if(NR==FNR) {name[$1]=$1;first[$1]=$2;second[$1]=$3;third[$1]=$4;total[$1]=$2+$3+$4;}
else { name2[$1]=$1;first2[$1]=$2;second2[$1]=$3;third2[$1]=$4;total2[$1]=$2+$3+$4;
 for (key in name) {
if (key==$1) 
{temp=0;
sum1=first[$1]+second[$1]+third[$1];
sum2=$2+$3+$4;
if(sum1>sum2) sum=sum2;
else  sum=sum1;
print name[$1],first[$1],second[$1],third[$1],sum,"BEST";both[$1]=$1;
print name[$1],first[$1],second[$1],third[$1],sum,"BEST" >> F}

} 
}}
 END{
 	for (key in name){
	bool=0;
	for(i in both){
		if(key==i)
			bool=1;}
	if(bool==0){
		print name[key],first[key],second[key],third[key],total[key],"One";
		print name[key],first[key],second[key],third[key],total[key],"One" >> F;
	}
	}
	for (key in name2){
	bool=0;
	for(i in both){
		if(key==i)
			bool=1;}
	if(bool==0){
		print name2[key],first2[key],second2[key],third2[key],total2[key],"One";
		print name2[key],first2[key],second2[key],third2[key],total2[key],"One" >> F;
	}
	}
 }' FileA.txt FileB.txt
