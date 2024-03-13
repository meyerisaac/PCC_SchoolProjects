import javax.swing.*;
import java.awt.*;

public class CarViewer
{
    public static void main(String[] args)
    {
        JFrame frame = new JFrame();
        Color first = Color.RED;
        Color second = Color.BLUE;

        frame.setSize(300, 400);
        frame.setTitle("Two cars");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        CarComponent component = new CarComponent();
        component.getColors(first, second);
        frame.add(component);

        frame.setVisible(true);
    }
}