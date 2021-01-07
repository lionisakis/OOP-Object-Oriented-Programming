

java Main

Author: Lionis Emmanouil Georgios (Akis)

### Summery of the program:
  This program tries to make a school environment. The programm moves the students and the teachers from out of the school into the classes that they belong to. Later, it works the school for N hours with a number (Fatige) that the user gives. At the end it exits all the students and the teachers from their classes out of the school complex.
  
### Explanation of the files:
  I have 3 folders: main, include, modules.
  In the main folder, I have my main code and a file of txt with numerous names of people ( for the students and the teachers).
  In the include folder, I have my definition of the Class.
  In my modules folder, I have my functions that are needed for Each Class.
  
### How to compile the programm:
  First you have to go to the correct folder by typing `cd src/`.
  Then you have to compile the project with the following command: `javac Main.java People/Junior.java People/Person.java People/Senior.java People/Student.java People/Teacher.java schoolComplex/Corridor.java schoolComplex/Floor.java schoolComplex/Room.java schoolComplex/School.java schoolComplex/Stair.java schoolComplex/TheClass.java schoolComplex/Yard.java`
  At last, you have an executable programm and have to run it by using the following command: `java Main Cclass Lj Ls Lt N`
  The Cclass:a number in which it says how many students can be held in a class (in my main, where the number of the students that are being created, is based on this number)
  Lj: a number which says the fatige of each junior student per hour 
  Ls: a number which says the fatige of each senior student per hour
  Lt: a number which says the fatige of each teacher per hour
  N:  a number which says the hours the school operates.
  (the <names.txt is not necessary but then the program will ask you for names)

### Description of the main :
  In the main at first, I create the School and the students and the teachers. The number of students is based on the first argument (Cclass). I create the students from the Class Senior or Junior depending which type is the student. The number of teachers is based on how many classes there are. Then I choose if I select to move a Student or a Teacher. If I move a Student, then I move him throught all the rooms (schoolyard,Stair,Floor,Corridor,Class). If I move a Teacher, then I just move him to the Class he belongs. I do this until all the students and teachers have entered their classes. After that I operate the School for the N hours that the user gives me. Then i call the function exit so all the students and the teachers leave the school complex. Later I delete all the Students and the Teachers.

### Description of the Classes:
  The classes are the following:
  Person, Student, Senior, Junior, Teacher, Room, School, Yard (schoolyard), Stair, Floor, Corridor, TheClass

  #### Person:
The class Person represents a Person with a name, a class and a fatige. He has a constructor for  "creating" the Person. The Person has also the basic get functions for the Name, the class he belongs to, if the Person has entered or not the class and the number of the fatige. The person has also a set function to set the person that has entered the room and to set the fatige with a number. Also, it has the print functions such as the print(), which prints the data of the Person, the printName(), which prints the Name and the Fatige, the printEnter() and printExit(), which prints if the student has entered or exited a room. 
  
  #### Student: 
  The class Student represents a student and is a subclass of the class Person. He has a constructor for  "creating" the student.
  
  #### Senior:
  The class Senior represents a senior and is a subclass of the class Student. He has a constructor for  "creating" the senior.
  
  #### Junior:
  The class Junior represents a junior and is a subclass of the class Student. He has a constructor for  "creating" the junior.

  #### Teacher:
  The class Teacher represents a teacher and is a subclass of the class Person. He has a constructor for  "creating" the teacher.
  
  #### Room:
  The class Room has a vector of Students. It has a constructor for  "creating" the room. It has a function enter(), which inserts a Student to the vector, exit(), which removes a Student from the vector of the Student, print(), which prints all the Students, getStudent(), which returns a Student with an index. Also it has an exit function which removes a student from the vector.

  #### School:
  The class School represents a School complex. It has a constructor for "creating"  the school. In the constructor, the school complex classes are being constructed (yard, stairs, floors, corridors, classes). There are get functions so the programmer can get each schoolroom alone (for the yard, stairs, floors, corridors, classes). Also, there is a function in which a student enters the school by calling the function enter from the Yard. Also, it has the function operate for N hours which operates every class for N hours. It has a function empty, which removes all students and teachers from the class all the way out of the school. The students pass through all the school complex. Finally, the school has the ability to print all of the school complex (prints the yard, stairs, floors, corridors, classes). 

  #### Yard (schoolyard):
  The class Yard represents a schoolyard and is a subclass of the class Room. It has a constructor for "creating" the yard. It inherits all the functions from the class Room that it needs.

  #### Stair:
  The class Stair represents a stair and is a subclass of the class Room. It has a constructor for "creating" the stair. It inherits all the functions from the class Room that it needs.

  #### Floor:
  The class Floor represents a floor complex. It has a constructor for "creating" the floor. In the constructor, the corridor and the classes of a floor are being constructed. In the deconstructor, the corridor and the classes of the floor are also being deconstructed. There are get functions so the programmer can get each class and the corridor. Finally, the class has the function to print all of its components (classes, corridor).

  #### Corridor:
  The class Corridor represents a corridor and is a subclass of the class Room. It has a constructor for "creating" the corridor. It inherits all the functions from the class Room that it needs.

  #### TheClass:
  The class TheClass represents the classes of a school and is a subclass of the class Room. It has a constructor for "creating"  the classes. The functions of this class are: to get the floor number and the class number, to set who is the teacher, to put a student into the class by using the super-class, to operate for N hours the class and to print the students and the teacher that are in the classes. Also it has a function exit, which overides the function exit of the super-class and exits either a student or a teacher.
