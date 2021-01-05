Author: Lionis Emmanouil Georgios (Akis)

**There is a problem with Valgrind that sometimes does not work properly (it does not use "free" at space that its itself creates). It is not a problem with my code but it is a problem with the library Valgrind itself. It does not occur in all the computers but with those that have an old version of Valgrind. The issue that Valgrind itself told is at https://www.valgrind.org/docs/manual/faq.html#faq.reports  in the 4.1 section.**

### Summery of the program:
  This program tries to make a school environment and then moves the students and the teachers from out of the school into the classes that they belong to and works the school for N hours with same Fatige that the users gives.
  
### Explanation of the files:
  I have 3 folders: main, include, modules.
  In the main folder, I have my main code and a file of txt with numerous names for people ( for the students and the teachers).
  In the include folder, I have my definition of the Class.
  In my modules folder, I have my functions that are needed for Each Class.
  
### How to compile  the programm:
  You ru with the makefile you just type `$ make run` and it is working.
  If you want to change the Arguments that the user pashes then you just have to go to the file Makefile and edit it.
  There is a line that writes `ARGS= Cclass Lj Ls Lt N < name.txt` 
  The Cclass:a number in which it says how many students can be hold in a class (in my main, the number of the students, that are being created, is based on this number)
  Lj: a number which says the fatige of each junior student per hour 
  Ls: a number which says the fatige of each junior student per hour
  Lt: a number which says the fatige of each junior student per hour
  N:  a number which says the hours of the school operates.
  (the <names.txt is not necessary but then the program will ask you for names)

### Description of the main :
  In the main, at first, I create the School and the students and the teachers. The number of students is based on the first argument (Cclass). I create the students from the Class Senior or Junior depending which type student is. The number of teachers is based on how many classes there are. Then I choose if I choose to move a Student or a Teacher. If I move a Student then I move him from all the rooms (schoolyard,Stair,Floor,Corridor,Class). If I move a Teacher then I just move him to the Class he belongs. I do this until all the students and teacheres have enter their classes. After that I operate the School for the N hours that the user gives me. Later I delete all the Students and the Teachers.

### Description of the Classes:
  The classes are the following:
  Person, Student, Senior, Junior, Teacher, Room, School, Yard (schoolyard), Stair, Floor, Corridor, theClass

  #### Person:
The class Person represents a Person with a name and a class and a fatige. He has a constructor and a deconstructor for  "creating" and "deleting" the Person. The Person has also the basic get functions for the Name, the class he belongs, if the Person has entered or not the class and the number of the fatige. The person has also a set function to set the person that has enterd the room and to set the fatige with a number. Also, it has the print functions such as the print(), which prints the data of the Person, the printName(), which prints the Name and the Fatige, the printEnter() and printExit(), which prints if the student has enterd or exited a room. 
  
  #### Student: 
  The class Student represents a student and is a subclass of the class Person. He has a constructor and a deconstructor for  "creating" and "deleting" the student.
  
  #### Senior:
  The class Senior represents a senior and is a subclass of the class Student. He has a constructor and a deconstructor for  "creating" the senior.
  
  #### Junior:
  The class Junior represents a junior and is a subclass of the class Student. He has a constructor and a deconstructor for  "creating" the junior.

  #### Teacher:
  The class Teacher represents a student and is a subclass of the class Person. He has a constructor and a deconstructor for  "creating" and "deleting" the teacher.
  
  #### Room:
  The class Teacher Room with the a vector of Students. It has a constructor and a deconstructor for  "creating" and "deleting" the a room. It has a function enter(), which inserts a Student to the vector of the Students if it is Null then we want to remove the last Student of the Vector (I did that because I could not have a function exit because I did not want the Class TheClass to inherit it so when I want to remove a Student then I enter Null), exit(), which removes a Student from the vector of the Student, print(), which prints all the Students, getStudent(), which returns a Student with an index.

  #### School:
  The class School represents a School complex. He has a constructor and a deconstructor for "creating" and "deleting" the school. In the constructor, the school complex classes is being constructed (yard, stairs, floors, corridors, classes). How many floors are being defined at the school.cpp file.In the deconstructor, the school complex classes is also being deconstructed. There are get functions so the programmer can get each schoolroom alone (for the yard, stairs, floors, corridors, classes). Also, there is a function in which a student enters the school by calling the function enter from the Yard. Also, it has the function operate for N hours which operates every class for N hours. Finally, the school has the ability to print all of the school complex (prints the yard, stairs, floors, corridors, classes).

  #### Yard (schoolyard):
  The class Yard represents a schoolyard and is a subclass of the class Room. It has a constructor and a deconstructor for "creating" and "deleting" the yard. The functions of this class are to: put a student into the yard (in the main I do not use this function but the schoolEnters function) which enters the student to the vector of Students of the super class Room and prints that a Student has enterd the Yard, remove a student from the yard by entering a Null Student to the super class Room (that way it pop the last Student), print which prints "Schoolyard" and then calls print form the print from the super class Room.

  #### Stair:
  The class Stair represents a stair and is a subclass of the class Room. It has a constructor and a deconstructor for "creating" and "deleting" the stair. The functions of this class are to: put a student into the stair which enters the student to the vector of Students of the super class Room and prints that a Student has enterd the Stair, remove a student from the stair by entering a Null Student to the super class Room (that way it pop the last Student), print which prints "Stair" and then calls print form the print from the super class Room.

  #### Floor:
  The class Floor represents a floor complex. It has a constructor and a deconstructor for "creating" and "deleting" the floor. In the constructor, the corridor and the classes of a floor are being constructed. In the deconstructor, the corridor and the classes of the floor are also being deconstructed. There are get functions so the programmer can get each class and the corridor. Finally, the class has the function to print all of its components (classes, corridor).

  #### Corridor:
  The class Corridor represents a corridor and is a subclass of the class Room. It has a constructor and a deconstructor for "creating" and "deleting" the corridor. The functions of this class are to: put a student into the corridor which enters the student to the vector of Students of the super class Room and prints that a Student has enterd the Corridor, remove a student from the Corridor by entering a Null Student to the super class Room (that way it pop the last Student), print which prints "Corridor" and then calls print form the print from the super class Room.

  #### theClass:
  The class theClass represents classes and is a subclass of the class Room. It has a constructor and a deconstructor for "creating" and "deleting" the classes. The functions of this class are to: get the floor number and the class number, set who is the teacher, put a student into the class by using the super class, operate for N hours the class, print the students and the teacher that are in the classes.
