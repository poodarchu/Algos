package me.poodar.bpt.db;

import java.util.Scanner;

/**
 * Created by poodar on 6/13/16.
 */
public class Test {
    public static void main(String[] args) {
        BPTree a = new BPTree();
        Scanner scanner = new Scanner(System.in);
        System.out.println("Please enter a course name into the Course table using sql example below");
        System.out.println("INSERT INTO Course VALUES(101,\"Database\",\"Tang\",49)");
        System.out.println("SELECT * FROM Course");
        System.out.println("SELECT * FROM Course WHERE course_id=101");
        System.out.println("SELECT * FROM Course WHERE course_id>101");
        System.out.println("DELETE * FROM Course WHERE course_id=101");
        System.out.println("Enter \"exit\" to exit program");

        while (true){
            String table = scanner.nextLine();
            if (table.equals("exit")) {
                System.out.println("Bye!");
                break;
            }

            if (table.length() < 4) {
                System.out.println("Please input valid query");
                continue;
            }

            String which = table.substring(0, 6);
            if (which.equals("SELECT")) {
                if (table.length() > 28) {
                    if (table.substring(36, 37).equals("=")) {
                        String checkQuery = table.substring(0, 37);
                        if (checkQuery.equals("SELECT * FROM Course WHERE course_id=")) {
                            String values = table.substring(37);
                            int id = Integer.parseInt(values);
                            a.LookUp(id);
                        } else {
                            System.out.println("Please enter valid query!");
                            continue;
                        }
                    } else {
                        String checkQuery = table.substring(0, 37);
                        if (checkQuery.equals("SELECT * FROM Course WHERE course_id>")) {
                            String values = table.substring(37);
                            int id = Integer.parseInt(values);
                            a.Range(id);
                        } else  {
                            System.out.println("Please enter valid query!");
                            continue;
                        }
                    }
                } else if (table.length() > 18) {
                    String checkQuery=table.substring(0,20);
                    if(checkQuery.equals("SELECT * FROM Course")){
                        String tableName=table.substring(14);
                        if(tableName.equals("Course")){
                            a.display();
                        }
                    }else{
                        System.out.println("Please enter valid query");
                        continue;
                    }
                }else{
                    System.out.println("Please enter valid query");
                    continue;
                }
            }else if(which.equals("INSERT")){
                String checkQuery=table.substring(0,25);
                String values=table.substring(25);
                String noBrace= values.replaceAll("\\p{P}"," ");
                String split[]=noBrace.split(" ");
                String course_id = null,course_name = null,teacher = null,numStu = null;

                for(int i=0;i<split.length;i++){
                    if(i==1){
                        course_id=split[1];
                    }else if(i==2){
                        course_name=split[2];
                    }else if(i==3){
                        teacher=split[3];
                    }else if(i==4){
                        numStu=split[4];
                    }
                }
                int ID=Integer.parseInt(course_id);
                int NUM=Integer.parseInt(numStu);

                if("INSERT INTO Course VALUES".equals(checkQuery)){

                    if(isAlpha(course_name) &&  isAlpha(teacher)){
                        a.insert(ID,course_name,teacher,NUM);
                        System.out.println("Successfully Entered to database");
                    }else{
                        System.out.println("CourseName AND Teacher HAVE CONSTRAINT OF STRING");
                    }
                }else{
                    System.out.println("Please enter a valid query!");
                }
            }else if(which.equals("DELETE")){
                String checkQuery=table.substring(0,30);
                if(checkQuery.equals("DELETE * FROM Course WHERE ID=")){
                    String values=table.substring(30);
                    int id=Integer.parseInt(values);
                    a.Delete(id);

                }else{
                    System.out.println("Please enter valid query!");
                    continue;
                }
            }
        }

    }
    public static boolean isAlpha(String name) {
        return name.matches("[a-zA-Z]+");
    }
}
