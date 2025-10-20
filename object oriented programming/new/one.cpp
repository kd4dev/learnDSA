// Java doesn't have destructors, just finalize() (deprecated). So ignore destructor part.
class Student {
    String name;
    int age;

    // Constructor
    Student(String n, int a) {
        name = n;
        age = a;
    }

    void display() {
        System.out.println(name + " is " + age + " years old.");
    }

    public static void main(String[] args) {
        Student s = new Student("Kedar", 20);
        s.display();
    }
}
