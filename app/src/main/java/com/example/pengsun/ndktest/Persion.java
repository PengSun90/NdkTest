package com.example.pengsun.ndktest;

public class Persion {

    public int age;

    public float tall;

    public String name;

    public Persion(int age, float tall, String name) {
        this.age = age;
        this.tall = tall;
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public float getTall() {
        return tall;
    }

    public void setTall(float tall) {
        this.tall = tall;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Persion{" +
                "age=" + age +
                ", tall=" + tall +
                ", name='" + name + '\'' +
                '}';
    }
}
