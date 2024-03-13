import javax.swing.*;

public class FaceViewer
{
    public static void main(String[] args)
    {
        //Create the JFrame object to draw/write components onto
        JFrame frame = new JFrame();
        frame.setSize(400, 500);
        frame.setTitle("Face: An Exploration");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Create our FaceComponent
        FaceComponent face = new FaceComponent();
        frame.add(face);

        //Make the fram visible to the user
        frame.setVisible(true);

        System.out.println("Hello world!");
    }
}