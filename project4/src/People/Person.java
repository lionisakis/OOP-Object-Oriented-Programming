package People;

public class Person {
    private String name;
    private int floorNumber;
    private int classNumber;
    private Boolean inside;
    private int fatige;
    private int tiredness;
    
    public Person(String namePerson,int floorNumberPerson,int classNumberPerson,int tirednessFactor){
        name=namePerson;
        floorNumber=floorNumberPerson;
        classNumber=classNumberPerson;
        tiredness=tirednessFactor;
        inside=false;
        fatige=0;
    }

    public String getName(){
        return name;
    }
    public int getClassFloor(){
        return floorNumber;
    }
    public int getClassNumber(){
        return classNumber;
    }
    public int getFatige(){
        return fatige;
    }
    public Boolean getInside(){
        return inside;
    }
    public void setFatige(int newFatige){
        fatige=newFatige;
    }
    public void addFatige(int newFatige){
        fatige+=newFatige;
    }
    public void setInside(Boolean newInside){
        inside=newInside;
    }

    public void print(){
        System.out.println("Name: "+name);
        System.out.println("Class Number: "+Integer.toString(classNumber)+" Floor: "+Integer.toString(floorNumber));
        System.out.println("Fatige: "+Integer.toString(fatige));
        System.out.println("Inside: "+Boolean.toString(inside));
    }  

    public void printName(){
        System.out.println("Name: "+name);
        System.out.println("Fatige: "+Integer.toString(fatige));
    }

    public void operate(int hours){
        addFatige(hours*tiredness);
    }
}
