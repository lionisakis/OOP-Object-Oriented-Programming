Author: Lionis Emmanouil Georgios (Akis)

In this project there were some restrictions. Those were that I could not use libriaries of c++ such us vector,array,list. The only libriary I was alowed was the string labriary. And I was not allowed to use Inheritance.

Summery of the program:
  This program tries to make a school environment and then tries to move the students from out of the school into the classes that they belong to if the teacher of its class has not gone into the class.
  
Explanation of the files:
   I have 3 folders: main, include, modules.
   In the main folder, I have my main code and a file of txt with numerous names for people ( for the students and the teachers).
   In the include folder, I have my definition of the Class.
   In my modules folder, I have my functions that are needed for Each Class.
  
How to compile  the programm:
    first you have to go to the main folder by typing $ cd main
    then you have to run the following command  $ g++ main.cpp ../modules/corridor.cpp ../modules/floor.cpp  ../modules/school.cpp ../modules/stair.cpp ../modules/student.cpp ../modules/teacher.cpp ../modules/theClass.cpp ../modules/yard.cpp 
    The final step is to run the executable program with the following arguments: $ /a.out  Cclass  Cyard  Cstair Ccorr
    Cclass: a number in which it says how many students can be hold in a class (in my main, the number of the students, that are being created, is based on this number)
    Cyard:  a number in which it says how many students can be hold in a yard
    Cstair: a number in which it says how many students can be hold in the stairs
    Ccorr:  a number in which it says how many students can be hold in the corridors

Description of the main :
    In the main, at first, I create the School and the students and the teachers. The number of students is based on the first argument (Cclass). The number of teachers is based on how many classes there are. There are numerous ways to move a student. I used the wave system. The wave system is that in each room the number of random students that can be entered is based on how much room is available. For example, if the yard has room for 10 people then 10 random students that have not been in the School complex enter the yard (and so they enter the school complex). The wave first moves students at first from the corridor->classes then stairs->corridor then yard->stairs and last out of school->yard. The teachers move to their Classes automatically and they don't have to go through all that process. This process goes on until either all students or teachers have entered their classes. Which group (teachers, students) moves is based on Chance (the chance for a teacher to move is small so that the students can go to their classes). 
    

Description of the Classes:
    The classes are the following:
    Student, Teacher, School, yard (schoolyard), stairs, floors, corridors, Classes

    Student: 
    The class Student represents a student with a name and a class. He has a constructor and a deconstructor for  "creating" and "deleting" the student. The student has also the basic get functions for the Name, the Where the student is, The class he belongs, and if the student has entered or not the class. The student has also a set function to set where the student is. 
    
    Teacher:
    The class Teacher represents a teacher with a name and a class. He has a constructor and a deconstructor for "creating" and "deleting" the teacher. The teacher has also the basic get functions for the Name, The class in which he belongs. The teacher has also a set function to set the teacher that has entered the Class.
    
    School:
    The class School represents a School complex. He has a constructor and a deconstructor for "creating" and "deleting" the school. In the constructor, the school complex classes is being constructed (yard, stairs, floors, corridors, classes).In the deconstructor, the school complex classes is also being deconstructed. There are get functions so the programmer can get each schoolroom alone (for the yard, stairs, floors, corridors, classes). Also, there is a function in which a student enters the school (by seeing if the yard has room for a student or not. If there is room then the students enter the yard automatically). Finally, the school has the ability to print all of the school complex (prints the yard, stairs, floors, corridors, classes).
    
    yard (schoolyard):
    The class yard represents a schoolyard. It has a constructor and a deconstructor for "creating" and "deleting" the yard. The functions of this class are to: put a student into the yard (in the main I do not use this function but the schoolEnters function), remove a student from the yard, print the students that are in the yard, return if there is room in the yard.
    
    stair:
    The class stair represents the stairs. It has a constructor and a deconstructor for "creating" and "deleting" the stairs. The functions of this class are to: put a student into the stairs, remove a student from the stairs, print the students that are in the stairs, return if there is room in the stairs.
    
    floor:
    The class floor represents a floor complex. It has a constructor and a deconstructor for "creating" and "deleting" the floor. In the constructor, the corridor and the classes of a floor are being constructed. In the deconstructor, the corridor and the classes of the floor are also being deconstructed. There are get functions so the programmer can get each class and the corridor. Finally, the class has the function to print all of its components (classes, corridor).
    
    corridor:
    The class corridor represents corridors. It has a constructor and a deconstructor for "creating" and "deleting" the corridor. The functions of this class are to: put a student into the corridors, remove a student from the corridors, print the students that are in the corridors, return if there is room in the corridors.
    
    class:
    The class class represents classes. It has a constructor and a deconstructor for "creating" and "deleting" the classes. The functions of this class are to: get the floor number and the class number, set who is the teacher, put a student into the class, check if a student is in the class or not, print the students and the teacher that are in the classes, print the floor and the number of the class, return if the teacher has entered or not and if there is room or not.    
    




