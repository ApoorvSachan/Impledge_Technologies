# Word Composition Problem

//Code is written in C++
#Steps to execute the code ->
1. Download or copy Word_Composition.cpp , input_01.txt and input_02.txt files into desktop and place them in the same directory.
2. Compile the cpp file using command prompt or any code editor like VisualStudio Code.
3. Now run the compiled file to get results in the file named output.txt which will be created in the same directory.

#Overview of Program ->
Search the coumpounded word of maximum length from the list of words given in input file.

Data Structures Used -> Trie , Queue
Use of trie data structure to store all the words of file in a trie tree and efficiently search if prefix or suffix of a particular word is present in the list of words stored in trie.
Firstly insert all the words in the trie data structure.
Traverse through the list of words in input file and for each word->
  1. Search for all the prefixes of that word in trie tree.
  2. Store the suffix of prefixes present in trie in queue along with the word like pair{word,suffix} as prefix is already present in input file and we have to check for suffix.
Now the elements from the front of queue are popped one by one and if the suffix is present in trie tree then the current word is compounded word else if suffix is not present then all the possible prefixes of current suffix are searched from trie and the word along with new suffix is stored in queue.
Elements from the queue are used to find the possible compounded words till the queue becomes empty. 
In this way longest and second longest compounded word are computed from all possible compounded words found with help of trie and queue data structure.

The basic idea used to check compounded word is generating the compounded word from concatenating prefixes present in the input file.
The suffixes are stored in queue alongside inserting words in trie from input file top to bottom as input file contains word sorted in lexographical order so the prefix of the current word will always be present before it while travering from top to bottom.
In the program user defined data structure of trie is created and inbuilt queue data structure is used from Standard Template Library of C++.

Longest Compounded Word, Second Longest Compounded Word and Time taken to process the input file are stored in file named output.txt . 



