package People;

public class Student extends Person{
    public Student(String name,int classFloor,int classNumber,int tiredness){
        super(name,classFloor,classNumber,tiredness);
        System.out.println("A new student is being created");
        print();
    }
}
