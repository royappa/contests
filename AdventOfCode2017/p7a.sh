awk ' { print $1 } ' 7.ain |  while read x; do y=`grep '>.*'$x'.*$' 7.ain`; if [ -z "$y" ]; then echo $x; fi; done
