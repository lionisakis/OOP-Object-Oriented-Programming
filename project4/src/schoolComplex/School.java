package schoolComplex;

import java.util.Vector;
import People.Student;
public class School {

    private Vector<Floor> floors;
    private Stair stair;
    private Yard yard; 

    public School(int maxStudentClass){
        floors = new Vector<Floor>(3);
        for (int i=0;i<3;i++)
            floors.add(new Floor(i,maxStudentClass));
        stair=new Stair();
        yard= new Yard();
    }
    
    public Yard getYard() {
        return yard;
    }
    public Stair getStair(){
        return stair;
    }
    public Floor getFloor(int index){
        return floors.get(index);
    }
    public Corridor getCorridor(int index){
        return floors.get(index).getCorridor();
    }
    public TheClass getClass(int index, int number){
        return floors.get(index).getClass(number);
    } 

    public void print() {
        System.out.print("SchoolComplex:");
        yard.print();
        stair.print();
        for(int i=0;i<3;i++){
            floors.get(i).print();
        } 
    }

    public void enter(Student student,Boolean way){
        yard.enter(student,way);
    }
    
    public void empty(){
        for (int i=0;i<3;i++){
            for(int j=0;j<6;j++){
                Student student=floors.get(i).getClass(j).exit();
                while(student!=null){
                    floors.get(i).getCorridor().enter(student,false);
                    floors.get(i).getCorridor().exit(student,false);
                    stair.enter(student,false);
                    stair.exit(student,false);
                    yard.enter(student,false);
                    yard.exit(student,false);                    
                    student=floors.get(i).getClass(j).exit();
		}
                floors.get(i).getClass(j).exitTeacher();
            }
        }
    }

    public void operate(int hours){
        for (int i=0;i<3;i++)
            floors.get(i).operate(hours);
    }
}
