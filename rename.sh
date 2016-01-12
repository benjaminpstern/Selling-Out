#!/bin/bash
echo "Starting rename"
index=0
words=(`cat randomWords.txt | cut -d',' -f1`)
echo $words
for file in `ls data`
do
    name=${words[index]}
    ((index++))
    echo "Renaming ${file} to ${name}"
    mv data/${file} data/${name}
done
