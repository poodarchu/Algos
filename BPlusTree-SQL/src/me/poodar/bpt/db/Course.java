package me.poodar.bpt.db;

/**
 * Created by poodar on 6/13/16.
 */
public class Course {
    private int course_id;
    private String course_name;
    private String teacher;
    private int numStu;

    public int getCourse_id() {
        return course_id;
    }

    public void setCourse_id(int id) {
        this.course_id = id;
    }

    public String getCourse_name() {
        return course_name;
    }

    public void setCourse_name(String name) {
        this.course_name = name;
    }

    public String getTeacher() {
        return teacher;
    }

    public void setTeacher(String teacher) {
        this.teacher = teacher;
    }

    public int getNumStu() {
        return numStu;
    }

    public void setNumStu(int num) {
        this.numStu = num;
    }
}
