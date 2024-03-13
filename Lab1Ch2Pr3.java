import java.awt.Rectangle;
import javax.swing.JComponent;

public class Lab1Ch2Pr3 extends JComponent{
    public static void main(String[] args)
    {
        int xOne = 100, yOne = 100, length = 200, height = 200;
        Rectangle box = new Rectangle(xOne, yOne, length, height);
        System.out.println("The location of the square's x and y value is");
        System.out.println(box.getLocation());
        System.out.println("The width and height are:");
        System.out.println(box.getSize());
        box.grow(-(length / 4) ,-(height / 4));
        System.out.println("The location of the square's x and y value is");
        System.out.println(box.getLocation());
        System.out.println("The width and height are:");
        System.out.println(box.getSize());

        System.out.println("Bye world!");
    }

}

/*Sample Run:
The location of the square's x and y value is
java.awt.Point[x=100,y=100]
The width and height are:
java.awt.Dimension[width=200,height=200]
The location of the square's x and y value is
java.awt.Point[x=150,y=150]
The width and height are:
java.awt.Dimension[width=100,height=100]
Bye world!
 */