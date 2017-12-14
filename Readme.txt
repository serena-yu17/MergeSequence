This program takes a commandline argument of file path, and merges FASTA files.

For instance, suppose we have a file:

C:\seq.fasta

>01  5
aaaaaaaaaaaaaaaaaaaaaaaa

>02  5
gggggggggggggggggggggggg

>03  5
aaaaaaaaaggggggggggggggg

>04  5
aaagggggggcccccccttttttt

>a1  10
aaaaaaaaaaaaaaaaaaaaaaaa

>a2  10
gggggggggggggggggggggggg

>a3  10
aaaaaccccccccgggggggggggg

>a4  10
aaaaaggggcccccccccttttttt

and run MergeSequence C:\seq.fasta

It will generate:

seq_processed.fasta

>02	15
gggggggggggggggggggggggg

>01	15
aaaaaaaaaaaaaaaaaaaaaaaa

>03	5
aaaaaaaaaggggggggggggggg

>a3	10
aaaaaccccccccgggggggggggg

>04	5
aaagggggggcccccccttttttt
