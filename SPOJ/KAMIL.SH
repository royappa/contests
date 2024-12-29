while read word
do
        echo "echo `echo $word | sed -e 's/T/{K,T}/g' -e 's/D/{G,D}/g' -e 's/L/{R,L}/g' -e 's/F/{R,F}/g'`" | bash | wc -w | tr -d ' '
done
