package schoolComplex;

import java.util.Random;

import People.Student;
import People.Teacher;
public class TheClass extends Room {
    private Teacher teacher;
    private int floor;
    private int number;
    private Random rand;
    public TheClass(int floorClass,int numberClass,int maxStudent) {
        super(maxStudent,"Class",floorClass,numberClass);
        floor=floorClass;
        number=numberClass;
        rand=new Random();
    }
    public int getClassFloor(){
        return floor;
    }
    public int getClassNumber(){
        return number;
    }
    @Override
    public void enter(Student student,boolean way){
        student.setInside(true);
        super.enter(student,way);
    }
    public void enter(Teacher newTeacher){
        teacher=newTeacher;
        teacher.setInside(true);
    }
    @Override
    public Student exit(){
        Student student=null;
        if (getStudentSize()==0){
            return null;
        }
        int index=rand.nextInt(getStudentSize());
        int i=0;
        while(i==index){
            student=getStudent(i);
            i++;
        }
        System.out.println(student.getName()+" starts exiting!");
        return super.exit(student,false);
    }
    public Teacher exitTeacher(){
        Teacher temp=teacher;
        teacher=null;
        return temp;
    }
    public void operate(int hours){
        if (teacher==null||getStudent(0)==null)
            return;
        int i=0;
        Student student;
        while((student=getStudent(i))!=null){
            student.operate(hours);
            i++;
        }
        teacher.operate(hours);
    }
    public void print(){
        super.print();
        if(teacher==null)
            return;
        System.out.print("Teacher: ");
        teacher.print();
    }
}
