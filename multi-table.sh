#!/bin/sh
if [ $# -ne 2 ]
then 
  echo "Invalid input"
  exit 0
fi

if [ $1 -le 0 -o $2 -le 0 ]
then 
  echo "Input must be greater than 0"
  exit 0
fi

for i in $(seq 1 $1) 
do 
 for j in $(seq 1 $2)
 do 
        result=`expr $i \* $j`
	printf "$i*$j= %-4d" $result
 done
echo ""

done
exit 0

