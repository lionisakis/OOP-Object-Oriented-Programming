Author: Lionis Emmanouil Georgios (Akis)

**There is a problem with Valgrind that sometimes does not work properly (it does not use "free" at space that its itself creates). It is not a problem with my code but it is a problem with the library Valgrind itself. It does not occur in all the computers but with those that have an old version of Valgrind. The issue that Valgrind itself told is at https://www.valgrind.org/docs/manual/faq.html#faq.reports  in the 4.1 section.**

### Summery of the program:
  This program tries to make a school environment. The programm moves the students and the teachers from out of the school into the classes that they belong to. Later, it works the school for N hours with a number (Fatige) that the user gives.
  
### Explanation of the files:
  I have 3 folders: main, include, modules.
  In the main folder, I have my main code and a file of txt with numerous names of people ( for the students and the teachers).
  In the include folder, I have my definition of the Class.
  In my modules folder, I have my functions that are needed for Each Class.
  
### How to compile  the programm:
  You run with the makefile you just type `$ make run` and it is working.
  If you want to change the Arguments that the user pashes then you just have to go to the file Makefile and edit it.
  There is a line that writes `ARGS= Cclass Lj Ls Lt N < name.txt` 
  The Cclass:a number in which it says how many students can be hold in a class (in my main, the number of the students, that are being created, is based on this number)
  Lj: a number which says the fatige of each junior student per hour 
  Ls: a number which says the fatige of each senior student per hour
  Lt: a number which says the fatige of each teacher per hour
  N:  a number which says the hours the school operates.
  (the <names.txt is not necessary but then the program will ask you for names)

### Description of the main :
  In the main at first, I create the School and the students and the teachers. The number of students is based on the first argument (Cclass). I create the students from the Class Senior or Junior depending which type is the student. The number of teachers is based on how many classes there are. Then I choose if I select to move a Student or a Teacher. If I move a Student, then I move him throught the rooms (schoolyard,Stair,Floor,Corridor,Class). If I move a Teacher, then I just move him to the Class he belongs. I do this until all the students and teachers have entered their classes. After that I operate the School for the N hours that the user gives me. Later I delete all the Students and the Teachers.

### Description of the Classes:
  The classes are the following:
  Person, Student, Senior, Junior, Teacher, Room, School, Yard (schoolyard), Stair, Floor, Corridor, TheClass

  #### Person:
The class Person represents a Person with a name, a class and a fatige. He has a constructor and a deconstructor for  "creating" and "deleting" the Person. The Person has also the basic get functions for the Name, the class he belongs to, if the Person has entered or not the class and the number of the fatige. The person has also a set function to set the person that has entered the room and to set the fatige with a number. Also, it has the print functions such as the print(), which prints the data of the Person, the printName(), which prints the Name and the Fatige, the printEnter() and printExit(), which prints if the student has entered or exited a room. 
  
  #### Student: 
  The class Student represents a student and is a subclass of the class Person. He has a constructor and a deconstructor for  "creating" and "deleting" the student.
  
  #### Senior:
  The class Senior represents a senior and is a subclass of the class Student. He has a constructor and a deconstructor for  "creating" the senior.
  
  #### Junior:
  The class Junior represents a junior and is a subclass of the class Student. He has a constructor and a deconstructor for  "creating" the junior.

  #### Teacher:
  The class Teacher represents a teacher and is a subclass of the class Person. He has a constructor and a deconstructor for  "creating" and "deleting" the teacher.
  
  #### Room:
  The class Room has a vector of Students. It has a constructor and a deconstructor for  "creating" and "deleting" the room. It has a function enter(), which inserts a Student to the vector. If it is Null, then we want to remove the last Student of the vector (I did that because I could not have a function exit. I did not want the Class TheClass to inherit it so when I want to remove a Student then I enter Null), print(), which prints all the Students, getStudent(), which returns a Student with an index.

  #### School:
  The class School represents a School complex. It has a constructor and a deconstructor for "creating" and "deleting" the school. In the constructor, the school complex classes are being constructed (yard, stairs, floors, corridors, classes). How many floors there are, are being defined at the school.cpp file. In the deconstructor, the school complex classes are also being deconstructed. There are get functions so the programmer can get each schoolroom alone (for the yard, stairs, floors, corridors, classes). Also, there is a function in which a student enters the school by calling the function enter from the Yard. Also, it has the function operate for N hours which operates every class for N hours. Finally, the school has the ability to print all of the school complex (prints the yard, stairs, floors, corridors, classes).

  #### Yard (schoolyard):
  The class Yard represents a schoolyard and is a subclass of the class Room. It has a constructor and a deconstructor for "creating" and "deleting" the yard. The functions of this class are: to put a student into the yard (in the main I do not use this function but the schoolEnters function), which enters the student to the vector of Students of the super-class Room and prints if a Student has entered the Yard, to remove a student from the yard by entering a Null Student to the super-class Room (that way it pops the last Student) and to print, which prints "Schoolyard" and then calls print from the print from the super-class Room.

  #### Stair:
  The class Stair represents a stair and is a subclass of the class Room. It has a constructor and a deconstructor for "creating" and "deleting" the stair. The functions of this class are: to put a student into the stair, which enters the student to the vector of Students of the super-class Room and prints if a Student has entered the Stair, to remove a student from the stair by entering a Null Student to the super-class Room (that way it pops the last Student) and to print, which prints "Stair" and then calls print from the print from the super-class Room.

  #### Floor:
  The class Floor represents a floor complex. It has a constructor and a deconstructor for "creating" and "deleting" the floor. In the constructor, the corridor and the classes of the floor are being constructed. In the deconstructor, the corridor and the classes of the floor are also being deconstructed. There are get functions so the programmer can get each class and the corridor. Finally, the class has the function to print all of its components (classes, corridor).

  #### Corridor:
  The class Corridor represents a corridor and is a subclass of the class Room. It has a constructor and a deconstructor for "creating" and "deleting" the corridor. The functions of this class are: to put a student into the corridor, which enters the student to the vector of Students of the super-class Room and prints if a Student has entered the Corridor, to remove a student from the Corridor by entering a Null Student to the super-class Room (that way it pops the last Student) and to print, which prints "Corridor" and then calls print from the print from the super-class Room.

  #### TheClass:
  The class TheClass represents the classes of a school and is a subclass of the class Room. It has a constructor and a deconstructor for "creating" and "deleting" the classes. The functions of this class are: to get the floor number and the class number, to set who is the teacher, to put a student into the class by using the super-class, to operate for N hours the class and to print the students and the teacher that are in the classes.
