import javax.swing.*;

// File Name: HouseViewer.java
// Authors: James Donckels & Isaac Meyer
// Last Modified: Feb 7 2023
// Assignment: Chapter 3 Lab 4 Graphics E3.21
// Description: Program to draw multiple houses
public class HouseViewer
{
    public static void main(String[] args)
    {
        // set up frame
        JFrame frame = new JFrame();
        frame.setSize(500,500);
        frame.setTitle("House Viewer");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // construct house component so houses can be drawn
        HouseComponent testComponent = new HouseComponent();

        // add houses to frame
        frame.add(testComponent);

        frame.setVisible(true);

        System.out.println("\nEnd of program.");
    }
}