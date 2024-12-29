grep -o 'mul([0-9][0-9]*,[0-9][0-9]*)' 3a.txt | sed -e 's/[^0-9]/ /g' | awk ' { print $1*$2; } ' | awk ' { s += $1; }
END { print s; } '

