#!/bin/sh

if [ $# -gt 0 ]; then
		gcc $1.c -o $1
		./$1
	
else
	echo "1つ以上の引数を渡してください"
fi
