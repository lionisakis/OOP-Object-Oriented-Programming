Author: Lionis Emmanouil Georgios (Akis)

**There is a problem with Valgrind that sometimes does not work properly (it does not use "free" at space that its itself creates). It is not a problem with my code but it is a problem with the library Valgrind itself. It does not occur in all the computers but with those that have an old version of Valgrind. The issue that Valgrind itself told is at https://www.valgrind.org/docs/manual/faq.html#faq.reports  in the 4.1 section.**

### Summary of the program: 

  This program tries to make pairs of Students that are in a kindergarten by trying to make pairs of the opposite sex. Also, those students can create a mess and the program has to change their pairs.
  
### Explanation of the files: 
   I have 3 folders: main, include, modules.
   In the main folder, I have my main code and a file of txt with numerous names for people ( for the students).
   In the include folder, I have my definition of the Class.
   In my modules folder, I have my functions that are needed for Each Class.

### How to compile  the programm:
   First you have to go to the main folder by typing `$ cd main`
   then you have to run the following command  `$ g++ main.cpp ../modules/kindergarden.cpp ../modules/pair.cpp ../modules/student.cpp    `
   The final step is to run the executable program with the following arguments: `$ /a.out  K L Tquiet Tmessy < names.txt`
   
   K: a number in which it says how many classes there are (in my main, the number of the students, that are being created, is based on this number(k) * the define number of each student in a class)
   L:  a number that shows how many random students create a mess.
   Tquiet: a threshold in which the class was quiet ( this thershold is multiplyed by the number of the students that fit in a class)
   Tmessy:  a threshold in which the class was messy ( this thershold is multiplyed by the number of the students that fit in a class)
   (the <names.txt is not necessary but then the program will ask you for names)

### Description of the main :
   In the main, at first, I create the kindergarten and the students. The number of students is based on the defined number of students in each class * the number of classes that have been created. At first, I create the pairs and then I print them. Finally, I say how many students have made a mess and print the new sequence.
   
### Description of the Classes: 
   The classes are the following:
   Student, Pair, Kindergarden

  #### Student: 
   The class Student represents a student with a name and a class. The student has only a constructor for initializing his name and class as the destructor is not needed. The student has the basic get functions for the Name, the Sex and if he is Messy or not. The student also has a set function to set if he is Messy or not. Finally, there is the function to print the student's data. 
    
  #### Pair: 
   The class Pair represents Pairs with 1 or 2 Students. The Pair has only a constructor for initializing his Students as the destructor is not needed. The Pair has the basic get functions for getting the first Student and the second Student. Also, the pair has the function that can change his Students and one that prints them. Finally, it has the ability to see if the Pair is messy. The Pair is messy if there are 2 Students and both of them are messy.
    
  #### Kindergarden: 
   The class Kindergarden represents a Kindergarden. It has a constructor and a deconstructor for initializing how many classes there are, the pairs, and the threshold and to deconstruct them. There are many many helpful functions that are being used in the public functions of the class. Those will be described later on. The public functions of the class are the following:
        
   Put a Student in the Class.
  
   Create a Sequence for each Class. At first, the program sees if there is a previous pair that has room for a student to go in. If there is, check if the sex is different for the last student then put him in that pair and change it. If it is not, then do not change it. Then the students from the beginning to the end -1 use the helpful function putStudentInSequence. The putStudentInSequence function finds and creates the pair with the 2 appropriate Student. The 2nd student is found by the other helpful function findStudent which returns a student with the opposite sex or returns Null. If there is then it moves him to the next position of the 1st student (which will be his pair) in the array students. If there is not any previous Pair then put the 2 Students in a new Pair and in the Sequence. If it is not then check how to place them. Every student has to have in front of them the opposite sex. For example, a male student has to have a female student and the opposite.   
        
   There is the createMess function. The createMess function finds random students and makes them naughty. Then it calls the changeNaughtyStudents.
        
   The changeNaughtyStudents function puts in an array of naughty students all the naughty ones. Then it is printed. After that, if in the pair there is only one naughty student then it uses the helpful function replaceStudent which finds a random student that is different from the naughty one but with the same sex. Then that function uses another helpful function changePairs which changes the Pairs. Now we go to the first function(changeNaughtyStudents) and if the pair is naughty then we check if the following pair is also naughty (or with the help of a flag we see if there was a previous naughty pair). If there is then we scatter the students in the next Class. If there is not then we scatter the students in random classes.
   
   Finally, there is the print function that prints the sequence and if a class was quiet, normal or there was a mess.

