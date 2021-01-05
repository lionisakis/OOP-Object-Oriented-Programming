package schoolComplex;

import java.util.Vector;
import java.util.Random; 
import People.Student;

public class Room {
    
    private int max;
    private String name;
    private int floor;
    private int number;
    private Vector<Student> students;
    private Random rand;
    public Room(int size,String nameRoom,int floorRoom,int numberRoom){
        students =new Vector<Student>(size); 
        name=nameRoom;
        number=numberRoom;
        max=size;
        floor=floorRoom;
        rand = new Random(); 
    }
    public void enter(Student student,boolean way){
        if (max==students.size()){
            return;
        }
        students.add(student);
        String studentName=student.getName();
        if(name=="Corridor"&&way){
            System.out.println(studentName+" enters Floor with number:"+floor+"!");   
        }
        if (name=="Schoolyard"&&way){
            System.out.println(studentName+" enters School!");   
        }
        if (floor<0)
            System.out.println(studentName+" enters "+name+"!");
        else{
            if (number<0){
                System.out.println(studentName+" enters "+name+" with floor "+Integer.toString(floor)+"!");
            }
            else{
                System.out.println(studentName+" enters "+name+" with floor "+Integer.toString(floor)+" with number "+Integer.toString(number)+"!");
            }
        }
    }
    public int getStudentSize(){
        return students.size();
    }
    public Student exit(Student student,boolean way){
        int i;
        for (i=0;i<students.size();i++)
            if(student==students.get(i))
                break;
        if (i==students.size())
            return null;
        students.remove(i);
        String studentName=student.getName();
        if (floor<0)
            System.out.println(studentName+" exits "+name+"!");
        else{
            if (number<0){
                System.out.println(studentName+" exits "+name+" with floor "+Integer.toString(floor)+"!");
            }
            else{
                System.out.println(studentName+" exits "+name+" with floor "+Integer.toString(floor)+" with number "+Integer.toString(number)+"!");
            }
        }
        if(name=="Corridor"&&!way){
            System.out.println(student.getName()+" exits floor with number:"+ Integer.toString(i));
        }
        if (name=="Schoolyard"&&!way){
            System.out.println(studentName+" exits School!");   
        }
        return student;
        
    }
    public Student exit(){
        if (0==students.size()){
            return null;
        }
        
        int number =rand.nextInt(students.size()); 
        Student student=students.get(number);
        students.remove(number);
        String studentName=student.getName();
        if (floor<0)
            System.out.println(studentName+" exits "+name+"!");
        else{
            if (number<0){
                System.out.println(studentName+" exits "+name+" with floor "+Integer.toString(floor)+"!");
            }
            else{
                System.out.println(studentName+" exits "+name+" with floor "+Integer.toString(floor)+" with number "+Integer.toString(number)+"!");
            }
        }
        return student;
    }

    public void print(){
        if (floor<0)
            System.out.println(name+": ");
        else{
            if (number<0){
                System.out.println(name+" with floor "+Integer.toString(floor)+" :");
            }
            else{
                System.out.println(name+" with floor "+Integer.toString(floor)+" with number "+Integer.toString(number)+" :");
            }
        }
        System.out.println("Student(s):");
        for (int i=0;i<students.size();i++){
            students.get(i).printName();
        }
    }
    public Student getStudent(int index){
        if (index<0 || index >students.size()-1)
            return null;
        return students.get(index);
    }
}
