package basic02.demo012面向对象三大特性之封装;

public class UsePerson
{
    public static void main(String[] args)
    {
        Person person = new Person();
        person.setAge(10);
        person.name = "Alice";
        person.showPerson();
    }
}
