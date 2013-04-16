
#!/bin/sh

BAK=bak

for f in ./*.csv
do
	iconv -f $1 -t $2 $f > $f$BAK;
    rm -f $f;
    mv $f$BAK $f;
done

exit 0
