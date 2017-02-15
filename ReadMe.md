All code in this folder was built, compiled and run successfully using cmake on ubuntu 16.04 - check CMakeLists.txt for further information.

Running The Program:
In its current state, the main.cpp will simply run the test cases I used to create the results displayed in the research document.
If you would like to run the code simply to test if the methods work, and now how fast they work then you will need to comment out some code,
and uncomment some other code. There are other comments in the code that will tell you where test cases begin and end, and where code that can be used
to test functions that may not have been used in the test cases begins.

This code solves the problem as follows: You need to maintain some similar trees, but with their own member variables in each node. This offers a solution,
as it allows you to derive classes from the base class Tree_template in a way that gives them all the functions of a BST, while requiring that you only 
write two functions and an enum in the derived class.

Instructions:
(These instructions are based off linux, more specifcally Ubuntu 16.04, which is what I used. They should work with any linux distribution with the proper
version of cmake. Quotation marks denote a bash terminal command. Do not type the quotation marks in the terminal).

1.Open a terminal to the Tree folder. 

2.Type "mkdir build" to create a folder called build

3.Type "cd build" to change your directory  to the build folder.

4.Type "cmake .." which will set you up to build the program and run it.

5.Type "make" to compile the program. *Run this command after making ANY changes to the code*

6.Type "./project5" to run the program.

Assuming no complications with different versions of cmake or not having the right version of c++, this should compile and run the program without any errors.

If you are using an IDE such as visual studio or codeblocks to run this, these general steps may help, googling might be better, as I do not usually use
these on existing code files.

1.Create a new project

2.Import all the code files (none of the .txt files, only .cpp and .hpp are necessary)

3.The code should be good to build and run.


for codeblocks you can consult this link: http://wiki.codeblocks.org/index.php/Creating_a_new_project 
It has a section called Adding a pre-existing file that can help. 

If using visual studio you can consult this link: https://msdn.microsoft.com/en-us/library/754c3hy7.aspx

If you are having any issues, contact me at nts23@zips.uakron.edu