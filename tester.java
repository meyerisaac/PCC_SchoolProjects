public class tester
{
    public static void main(String[] args)
    {
        String name = "Isaac";
        String address = "321 Lala Avenue, Cotton Village, CA";
        String phoneNumber = "2316452837";

        String ID = "bc78264";
        int yearsTeaching = 2;

        Person Isaac = new Person(name, address, phoneNumber);
        Faculty Cassie = new Faculty(name, address, phoneNumber, ID, yearsTeaching);

        System.out.println("The Person's String form is " + Isaac.toString());
        System.out.println("The Faculty's String form is " + Cassie.toString());
    }
}

/*Sample Run:
The Person's String form is Name = Isaac, Address = 321 Lala Avenue, Cotton Village, CA, Phone Number = 2316452837
The Faculty's String form is Name = Isaac, Address = 321 Lala Avenue, Cotton Village, CA, Phone Number = 2316452837, ID = bc78264, yearsTeaching = 2

Process finished with exit code 0
 */