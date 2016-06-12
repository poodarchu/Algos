package me.poodar.bpt.db;

import java.util.Arrays;
import java.util.HashMap;

/**
 * Created by poodar on 6/13/16.
 */
public class BPTree {
    Node root = null;
    int nodeKeys[] = new int[3];

    HashMap<Integer, Course> map = new HashMap<Integer, Course>();

    public void insert(int key, String couse_name, String teacher, int numStu) {
        Course cs = new Course();
        cs.setCourse_id(key);
        cs.setCourse_name(couse_name);
        cs.setTeacher(teacher);
        cs.setNumStu(numStu);

        map.put(key, cs);

        if (root == null) {
            Node newNode = new Node();
            newNode.getKeys()[0] = key;
            newNode.increament();
            root = newNode;
        } else {
            Node traversal = root;
            moveToLevel(traversal, key);
        }
    }

    private void moveToLevel(Node traversal, int key) {
        boolean looped = false;
        nodeKeys = Arrays.copyOf(traversal.getKeys(), 3);
        int numberOfComparisions = traversal.getCounter();

        for (int i = 0; i < numberOfComparisions; i++) {
            if (key < nodeKeys[i]) {
                if(traversal.getFirst() == null) {
                    if (numberOfComparisions != 3) {
                        insertIntoPosition(numberOfComparisions, key, i);
                        traversal.setKeys(nodeKeys);
                        traversal.increament();
                    } else  {
                        split(traversal, key);
                    }
                } else  {
                    moveDown(traversal, i, key);
                }
                looped = true;
                break;
            }
        }
        if (traversal.getFirst() == null && looped == false) {
            if (numberOfComparisions != 3) {
                nodeKeys[numberOfComparisions] = key;
                traversal.increament();
                traversal.setKeys(nodeKeys);
            } else {
                split(traversal, key);
            }
        } else if (traversal.getFirst() != null && looped == false) {
            moveDown(traversal, 3, key);
        }
    }

    public void split(Node traversal, int key) {
        int fourKeys[] = middleValue(key);
        if (traversal.parentNode == null) {
            System.out.println("Here");

            Node nodeParent = new Node();
            nodeParent.getKeys()[0] = fourKeys[1];
            nodeParent.increament();

            Node nodeLeft = new Node();
            nodeLeft.getKeys()[0] = fourKeys[0];
            nodeLeft.increament();

            Node nodeRight = new Node();
            nodeRight.setKeys(Arrays.copyOfRange(fourKeys, 1, 4));
            nodeRight.setCounter(3);

            nodeLeft.setFourth(nodeRight);
            nodeLeft.parentNode = nodeParent;
            nodeRight.parentNode = nodeParent;

            nodeParent.first = nodeLeft;
            nodeParent.second = nodeRight;
            root = nodeParent;
        } else {
            if (!traversal.parentNode.isFull()) {
                key = fourKeys[1];

                traversal = traversal.parentNode;
                boolean looped = false;

                nodeKeys=Arrays.copyOf(traversal.getKeys(),3);
                for(int i=0;i<traversal.getCounter();i++){
                    if(key<nodeKeys[i]){

                        insertIntoPosition(traversal.getCounter(), key, i);
                        traversal.setKeys(nodeKeys);
                        traversal.increament();
                        Node less=new Node();
                        less.parentNode=traversal;
                        less.increament();
                        less.getKeys()[0]=fourKeys[0];
                        Node more=new Node();
                        more.setKeys(Arrays.copyOfRange(fourKeys,1,4));
                        more.setCounter(3);
                        more.parentNode=traversal;
                        int index=-1;

                        for(int j=0;j<traversal.getCounter();j++){
                            if(key==traversal.getKeys()[j]){
                                index=j;
                                break;
                            }
                        }
                        if(index==0){
                            less.fourth=more;
                            traversal.first=less;
                            more.fourth=traversal.second;
                            traversal.second=more;
                        }else if(index==1){
                            traversal.first.fourth=less;
                            less.fourth=more;
                            more.fourth=traversal.second;
                            traversal.second=less;
                            traversal.third=more;
                        }
                        looped=true;
                        break;
                    }
                }
                if(looped==false){

                    nodeKeys[traversal.getCounter()]=key;
                    traversal.setKeys(nodeKeys);
                    traversal.increament();

                    if(traversal.getCounter()==2){
                        Node less=new Node();
                        less.getKeys()[0]=fourKeys[0];
                        less.increament();
                        Node more=new Node();
                        more.setKeys(Arrays.copyOfRange(fourKeys,1,4));
                        more.setCounter(3);
                        more.parentNode=traversal;
                        less.parentNode=traversal;
                        traversal.first.fourth=less;
                        traversal.second=less;
                        less.fourth=more;
                        traversal.third=more;
                    }else if(traversal.getCounter()==3){
                        Node less=new Node();
                        less.getKeys()[0]=fourKeys[0];
                        less.increament();
                        Node more=new Node();
                        more.setKeys(Arrays.copyOfRange(fourKeys,1,4));
                        more.setCounter(3);
                        traversal.second.fourth=less;
                        less.setFourth(more);
                        traversal.setThird(less);
                        traversal.setFourth(more);
                    }
                }
            }else if(traversal.parentNode.isFull()) {

            }
        }
    }
    public int[] middleValue(int key){
        int four[]=new int[4];
        four=Arrays.copyOf(nodeKeys,4);
        four[3]=key;
        Arrays.sort(four);
        return four;
    }
    private void insertIntoPosition(int numberOfComparisions, int key,int i) {
        int num=numberOfComparisions;
        for(int j=i;j<numberOfComparisions;j++){
            nodeKeys[num]=nodeKeys[num-1];
            num--;
        }
        nodeKeys[i]=key;
    }
    public void moveDown(Node traverse,int i,int key){
        if(i==0){
            traverse=traverse.getFirst();
        }else if(i==1){
            traverse=traverse.getSecond();
        }else if(i==2){
            traverse=traverse.getThird();
        }else if(i==3){
            int count=traverse.getCounter();
            if(count==1){
                traverse=traverse.getSecond();
            }else if(count==2){
                traverse=traverse.getThird();
//				System.out.println(traverse.getKeys()[0]+" "+traverse.getKeys()[1]+" "+traverse.getKeys()[2]);
            }else if(count==3){
                traverse=traverse.getFourth();
            }
        }
        moveToLevel(traverse, key);
    }
    public void LookUp(int value){
        Node node=root;
        boolean finding=false;
        for(int i=0;i<node.getCounter();i++){
            if(value<node.getKeys()[i]){
                if(i==0 && node.first!=null){
                    node=node.first;
                }else if(i==1 && node.second!=null){
                    node=node.second;
                }else if(i==2 && node.third!=null){
                    node=node.third;
                }
                finding=true;
                break;
            }else if(value==node.getKeys()[i]){
                if(i==0 && node.second!=null)
                    node=node.second;
                if(i==1 && node.third!=null)
                    node=node.third;
                if(i==2 && node.fourth!=null)
                    node=node.fourth;
                finding=true;
                break;
            }
        }
        if(finding==false){
            if(node.getCounter()==1 && node.second!=null){
                node=node.second;
            }
            else if(node.getCounter()==2 && node.third!=null){
                node=node.third;
            }
            else if(node.getCounter()==3 && node.fourth!=null){
                node=node.fourth;
            }
        }
        boolean found=false;
        for(int i=0;i<node.getCounter();i++){
            if(value==node.getKeys()[i] && node.getKeys()[i]!=-1){
                System.out.println("--------------------------------------");
                System.out.println("ID  |  COURSE   |   TEACHER  | STU_NUM");
                System.out.println("--------------------------------------");
                Course console=map.get(value);
                System.out.println(console.getCourse_id()+"  |  "+console.getCourse_name()+"      |    "+console.getTeacher()+" |  "+console.getNumStu());

                System.out.println("--------------------------------------");
                found=true;
            }
        }
        if(found==false){
            System.out.println("the number you entered doesn't exist");
        }
    }
    public void print(){

        Node node=root;
        while(node.first!=null){
            node=node.first;
        }
        for(int i=0;i<node.getCounter();i++){
            System.out.print(node.getKeys()[i]+" ");
        }
        System.out.print("->");
        while(node.fourth!=null){
            node=node.fourth;
            for(int i=0;i<node.getCounter();i++){
                System.out.print(node.getKeys()[i]+" ");
            }
            System.out.print("->");
        }
        System.out.println();
    }
    public void display(){
        System.out.println("--------------------------------------");
        System.out.println("ID  |  COURSE   |   TEACHER  | STU_NUM");
        System.out.println("--------------------------------------");
        Node node=root;
        while(node.first!=null){
            node=node.first;
        }
        for(int i=0;i<node.getCounter();i++){
            if(node.getKeys()[i]!=-1){
                Course console=map.get(node.getKeys()[i]);
                System.out.println(console.getCourse_id()+"  |  "+console.getCourse_name()+"      |    "+console.getTeacher()+" |  "+console.getNumStu());
                System.out.println("--------------------------------------");
            }
        }

        while(node.fourth!=null){
            node=node.fourth;
            for(int i=0;i<node.getCounter();i++){
                if(node.getKeys()[i]!=-1){
                    Course console=map.get(node.getKeys()[i]);
                    System.out.println(console.getCourse_id()+"  |  "+console.getCourse_name()+"      |    "+console.getTeacher()+" |  "+console.getNumStu());
                    System.out.println("--------------------------------------");
                }

            }
        }
    }

    public void Range(int id){
        System.out.println("--------------------------------------");
        System.out.println("ID  |  COURSE   |   TEACHER  | STU_NUM");
        System.out.println("--------------------------------------");
        Node node=root;
        while(node.first!=null){
            node=node.first;
        }
        for(int i=0;i<node.getCounter();i++){
            if(id<=node.getKeys()[i] && node.getKeys()[i]!=-1){
                Course console=map.get(node.getKeys()[i]);
                System.out.println(console.getCourse_id()+"  |  "+console.getCourse_name()+"      |    "+console.getTeacher()+" |  "+console.getNumStu());
                System.out.println("--------------------------------------");
            }
        }
        while(node.fourth!=null){
            node=node.fourth;
            for(int i=0;i<node.getCounter();i++){
                if(id<=node.getKeys()[i] && node.getKeys()[i]!=-1){
                    Course console=map.get(node.getKeys()[i]);
                    System.out.println(console.getCourse_id()+"  |  "+console.getCourse_name()+"      |    "+console.getTeacher()+" |  "+console.getNumStu());
                    System.out.println("--------------------------------------");
                }
            }

        }

    }
    public void Delete(int value){
        Node node=root;
        boolean finding=false;
        for(int i=0;i<node.getCounter();i++){
            if(value<node.getKeys()[i]){
                if(i==0 && node.first!=null){
                    node=node.first;
                }else if(i==1 && node.second!=null){
                    node=node.second;
                }else if(i==2 && node.third!=null){
                    node=node.third;
                }
                finding=true;
                break;
            }else if(value==node.getKeys()[i]){
                if(i==0 && node.second!=null)
                    node=node.second;
                if(i==1 && node.third!=null)
                    node=node.third;
                if(i==2 && node.fourth!=null)
                    node=node.fourth;
                finding=true;
                break;
            }
        }
        if(finding==false){
            if(node.getCounter()==1 && node.second!=null){
                node=node.second;
            }
            else if(node.getCounter()==2 && node.third!=null){
                node=node.third;
            }
            else if(node.getCounter()==3 && node.fourth!=null){
                node=node.fourth;
            }
        }
        boolean found=false;
        for(int i=0;i<node.getCounter();i++){
            if(value==node.getKeys()[i]){
                node.getKeys()[i]=-1;
                System.out.println("the colum has been deleted");
                found=true;
            }
        }
        if(found==false){
            System.out.println("the number you entered doesn't exist");
        }
    }
}
