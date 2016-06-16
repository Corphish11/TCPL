#!/bin/bash

echo "struct key"
echo "keytab[] = {"

for i in $(cat key.txt) ; do
	echo -e "\t{\"$i\", 0},"
done

echo "};"

