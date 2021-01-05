import schoolComplex.School;
import java.util.Random; 
import java.util.Vector;
import java.util.Scanner;

import People.Junior;
import People.Senior;
import People.Student;
import People.Teacher;
public class Main {
    public static void main(String[] args) {
        
        // if (args.length!=5){
        //     System.out.println("Not the right arguments.");
        //     System.out.println("Arguments needed:");
        //     System.out.println("./file Cclass Lj Ls Lt N");
        //     return ;
        // }
            
        // int poepleInClass=Integer.parseInt(args[0]);
        // int fatigeJ=Integer.parseInt(args[1]);
        // int fatigeS=Integer.parseInt(args[2]);
        // int fatigeT=Integer.parseInt(args[3]);
        // int hours=Integer.parseInt(args[4]); 
        int poepleInClass=Integer.parseInt("1");
        int fatigeJ=Integer.parseInt("5");
        int fatigeS=Integer.parseInt("10");
        int fatigeT=Integer.parseInt("15");
        int hours=Integer.parseInt("20"); 
        School school= new School(poepleInClass);
        System.out.println("");
        Scanner Scann = new Scanner(System.in);
        Vector<Student> students=new Vector<Student>(3*6*poepleInClass);
    
        for (int i=0;i<3;i++)
            for(int j=0;j<6;j++)
                for(int k=0;k<poepleInClass;k++){
                    String name = Scann.nextLine();
                    if(j<3)
                        students.add(new Junior(name,i,j,fatigeJ));
                    else
                        students.add(new Senior(name,i,j,fatigeS));
                }
    
        
        System.out.println();
    
        Vector<Teacher> teachers=new Vector<Teacher>(3*6);
    
        for (int i=0;i<3;i++)
            for(int j=0;j<6;j++){
                String name = Scann.nextLine();
                teachers.add(new Teacher(name,i,j,fatigeT));
            }
    
        System.out.println();
    
        Random random=new Random();
    
        while(true){
            int i;
            for(i=0;i<students.size();i++){
                if(!students.get(i).getInside())
                    break;
            }
            if(i>=students.size()){
                int j=-1;
                for(j=0;j<teachers.size();j++){
                    if(!teachers.get(j).getInside())
                        break;
                }
                if(j>=teachers.size()){
                    break;
                }
            }
            
            int which= random.nextInt(poepleInClass+1);            
            if(which<poepleInClass){
    
                int whichStudent=random.nextInt(students.size());
                
                Student student =students.get(whichStudent);

                if(student.getInside())
                    continue;
    
                school.enter(student,true);
                student=school.getYard().exit();
                school.getStair().enter(student,true);
                student=school.getStair().exit();
                
                int floor;
                int number;
                floor=student.getClassFloor();
                number=student.getClassNumber();
                school.getCorridor(floor).enter(student,true);
                student=school.getCorridor(floor).exit();
                school.getClass(floor,number).enter(student,true);
                
                
            }
            else{
                int whichTeacher=random.nextInt(teachers.size());
                
                Teacher teacher = teachers.get(whichTeacher);
                
                if(teacher.getInside())
                    continue;
                
                int floor;
                int number;
                floor=teacher.getClassFloor();
                number=teacher.getClassNumber();
                school.getClass(floor,number).enter(teacher);
                
            }
        }
    
        // System.out.println("");
        // school.operate(hours);
        // school.print(); 
        System.out.println("");
        school.empty();
        // System.out.println("");
        // school.print();

        // System.out.println("");
    
    }
}
