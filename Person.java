public class Person
{
    String name;
    String address;
    String phoneNumber;

    public Person()
    {
        name = "";
        address = "";
        phoneNumber = "";
    }

    public Person(String personName, String personAddress, String personPhoneNumber)
    {
        name = personName;
        address = personAddress;
        phoneNumber = personPhoneNumber;
    }

    public String getName()
    {
        return name;
    }

    public String getAddress()
    {
        return address;
    }

    public String getPhoneNumber()
    {
        return phoneNumber;
    }

    public void setName(String newName)
    {
        name = newName;
    }

    public void setAddress(String newAddress)
    {
        address = newAddress;
    }

    public void setPhoneNumber(String newPhoneNumber)
    {
        phoneNumber = newPhoneNumber;
    }

    @Override
    public String toString()
    {
        return "Name = " + name + ", Address = " + address + ", Phone Number = " + phoneNumber;
    }
}
