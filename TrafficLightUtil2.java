import javax.swing.*;
import java.awt.*;
import java.awt.geom.Ellipse2D;

public class TrafficLightUtil2 extends JComponent
{
    public void paintComponent(Graphics g)
    {
        //Recover Graphics2D
        Graphics2D g2 = (Graphics2D) g;

        Rectangle trafficFrame = new Rectangle(175, 100, 150, 400);

        g2.setColor(Color.BLACK);
        g2.fill(trafficFrame);

        Ellipse2D.Double light = new Ellipse2D.Double(200, 125, 100, 100);
        Color color = new Color(124, 0, 0);

        g2.setColor(color);
        g2.fill(light);

        light.setFrame(200, 250, 100,100);

        g2.setColor(Color.YELLOW);
        g2.fill(light);

        light.setFrame(200, 375, 100, 100);
        color = new Color(0, 126, 0);

        g2.setColor(color);
        g2.fill(light);
    }
}