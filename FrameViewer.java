import java.awt.*;
import javax.swing.*;

public class FrameViewer
{
    public static void main(String[] args)
    {
        JFrame frame = new JFrame();
        frame.setSize(400, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Color paleGreen = new Color(153, 255, 153);

        JLabel label = new JLabel("Hello, Isaac!");
        label.setOpaque(true);
        label.setBackground(paleGreen);
        frame.add(label);

        ImageIcon me = new ImageIcon("Selfie.jpg");
        JLabel selfie = new JLabel(me);
        selfie.setOpaque(true);
        //frame.add(selfie);

        frame.setVisible(true);
    }
}