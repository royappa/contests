#! /bin/sh

i=1
pref=bgvyzdsv
while true
do
x="$pref""$i"
foo=`echo -n $x | md5sum | awk '/^00000/ { print "YES";  } '`
if [ "$foo" = "YES" ]; then
exit
fi
i=`expr $i + 1`
echo $i
done
