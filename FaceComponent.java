import javax.swing.*;
import java.awt.*;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;

public class FaceComponent extends JComponent
{
    public void paintComponent(Graphics g)
    {
        //Recover Graphics2D g2
        Graphics2D g2 = (Graphics2D) g;

        //The Head
        Ellipse2D.Double Circle = new Ellipse2D.Double(100, 150, 200,200);
        g2.draw(Circle);

        //2 Eyes
        Circle = new Ellipse2D.Double(140, 200, 20, 20);
        g2.draw(Circle);
        Circle = new Ellipse2D.Double(240, 200, 20, 20);
        g2.draw(Circle);

        //Mouth
        Line2D.Double line = new Line2D.Double(140, 300, 260, 300);
        g2.draw(line);
    }
}
