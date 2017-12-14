This program takes a commandline argument of text files, and merges them based on sequence.

Usage: 

MergeSequence [filename1] [filename2] ...

///////////////////

For instance, suppose we have such files:

///////////////////

C:\seq1.fasta

>01  5
aaaaaaaaaaaaaaaaaaaaaaaa

>02  5
gggggggggggggggggggggggg

>03  5
aaaaaaaaaggggggggggggggg

>04  5
aaagggggggcccccccttttttt

///////////////////

C:\seq2.fasta

>a1  10
aaaaaaaaaaaaaaaaaaaaaaaa

>a2  10
gggggggggggggggggggggggg

>a3  10
aaaaaccccccccgggggggggggg

>a4  10
aaaaaggggcccccccccttttttt

///////////////////


Commandline:
MergeSequence C:\seq1.fasta C:\seq2.fasta 



It will generate:

///////////////////

seq1_processed.fasta


>02	15
gggggggggggggggggggggggg

>01	15
aaaaaaaaaaaaaaaaaaaaaaaa

>a4	10
aaaaaggggcccccccccttttttt

>03	5
aaaaaaaaaggggggggggggggg

>a3	10
aaaaaccccccccgggggggggggg

>04	5
aaagggggggcccccccttttttt

///////////////////


The executable is compiled for Windows. 

If you want to use it on other systems, please compile it yourself using 

g++ -c stdafx.h -o stdafx.h.gch
g++ std=c++11 MergeSequence.cpp
