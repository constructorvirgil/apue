#!/bin/bash

rm -rf file_hole file_nohole

gcc file_hole.c -o file_hole.out
gcc file_nohole.c -o file_nohole.out

./file_hole.out
./file_nohole.out

ls -ls file_hole.out file_nohole.out