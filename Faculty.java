import javax.xml.stream.FactoryConfigurationError;
import java.lang.annotation.Inherited;

public class Faculty extends Person
{
    private String ID;
    private int yearsTeaching;

    public Faculty()
    {
        super();
        ID = "";
        yearsTeaching = 0;
    }

    public Faculty(String personName, String personAddress, String personPhoneNumber, String facultyID, int facultyYearsTeaching)
    {
        super(personName, personAddress, personPhoneNumber);
        ID = facultyID;
        yearsTeaching = facultyYearsTeaching;
    }

    public String getID()
    {
        return ID;
    }

    public int getYearsTeaching()
    {
        return yearsTeaching;
    }

    public void setID(String newID)
    {
        ID = newID;
    }

    public void setYearsTeaching(int newYearsTeaching)
    {
        yearsTeaching = newYearsTeaching;
    }

    @Override
    public String toString()
    {
        return super.toString() + ", ID = " + ID + ", yearsTeaching = " + yearsTeaching;
    }
}
