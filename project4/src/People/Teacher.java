package People;

public class Teacher extends Person{
    public Teacher(String name,int classFloor,int classNumber,int tiredness){
        super(name,classFloor,classNumber,tiredness);
        System.out.println("A new teacher is being created");
        print();
    }
}
