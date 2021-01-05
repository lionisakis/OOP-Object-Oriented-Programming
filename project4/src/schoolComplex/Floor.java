package schoolComplex;

import java.util.Vector;

public class Floor {
        
    private int floor;
    private Vector<TheClass> classes;
    private Corridor corridor;
    
    public Floor(int floorNumber,int sizeClass){
        classes = new Vector<TheClass>(6);
        for (int i=0;i<6;i++)
            classes.add(new TheClass(floorNumber,i,sizeClass));
        corridor= new Corridor(floorNumber);
        floor=floorNumber;
    }    
    public TheClass getClass(int index){
        return classes.get(index);
    }
    public Corridor getCorridor(){
        return corridor;
    }
    
    public void print(){
        System.out.println("Floor (number:"+Integer.toString(floor)+")");
        for (int i=0;i<6;i++)
            classes.get(i).print();
        corridor.print();
    }
    public void operate(int hours){
        for (int i=0;i<6;i++)
            classes.get(i).operate(hours);
    }
}

