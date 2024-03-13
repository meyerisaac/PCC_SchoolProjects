import javax.swing.*;

public class ColorNameViewer
{
    public static void main(String[] args)
    {
        JFrame frame = new JFrame();
        frame.setSize(400, 500);
        frame.setTitle("Colors: An Exploration");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        ColorNameComponent word = new ColorNameComponent();
        frame.add(word);

        frame.setVisible(true);

        System.out.println("Hello world!");
    }
}