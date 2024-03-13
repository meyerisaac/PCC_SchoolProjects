import javax.swing.*;
import java.awt.*;

public class ColorNameComponent extends JComponent
{
    public void paintComponent(Graphics g)
    {
        Graphics2D g2 = (Graphics2D) g;

        String phrase;

        phrase = "This color is black";
        g2.setColor(Color.BLACK);
        g2.drawString(phrase, 140, 20);

        phrase = "This color is blue";
        g2.setColor(Color.BLUE);
        g2.drawString(phrase, 140, 30);

        phrase = "This color is cyan";
        g2.setColor(Color.CYAN);
        g2.drawString(phrase, 140, 40);

        phrase = "This color is gray";
        g2.setColor(Color.GRAY);
        g2.drawString(phrase, 140, 50);

        phrase = "This color is dark gray";
        g2.setColor(Color.DARK_GRAY);
        g2.drawString(phrase, 140, 60);

        phrase = "This color is light gray";
        g2.setColor(Color.LIGHT_GRAY);
        g2.drawString(phrase, 140, 70);

        phrase = "This color is green";
        g2.setColor(Color.GREEN);
        g2.drawString(phrase, 140, 80);

        phrase = "This color is magenta";
        g2.setColor(Color.MAGENTA);
        g2.drawString(phrase, 140, 90);

        phrase = "This color is orange";
        g2.setColor(Color.ORANGE);
        g2.drawString(phrase, 140, 100);

        phrase = "This color is pink";
        g2.setColor(Color.PINK);
        g2.drawString(phrase, 140, 110);

        phrase = "This color is red";
        g2.setColor(Color.RED);
        g2.drawString(phrase, 140, 120);

        phrase = "This color is yellow";
        g2.setColor(Color.YELLOW);
        g2.drawString(phrase, 140, 130);
    }
}
