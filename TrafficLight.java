//File Name: TrafficLight.java
//Authors: Isaac Meyer & James Donckels
//Assignment: Lab 2 Chapter 2 Program 15
//Description: Traffic Light Graphics
//Last Date Changed: 01/26/2023

//Import classes
import javax.swing.*;
import java.util.Scanner;

public class TrafficLight
{
    public static void main(String[] args) throws InterruptedException {
        //Create the 3 frames
        JFrame frame1 = new JFrame();
        frame1.setSize(500, 600);
        frame1.setTitle("Traffic Lights: An Exploration");
        frame1.setDefaultCloseOperation(frame1.EXIT_ON_CLOSE);

        TrafficLightUtil light = new TrafficLightUtil();
        TrafficLightUtil2 light2 = new TrafficLightUtil2();
        TrafficLightUtil3 light3 = new TrafficLightUtil3();


        System.out.println("How many times would you like the lights to flash: ");

        Scanner scanner = new Scanner(System.in);
        int input = scanner.nextInt();

        for(int i = 0; i < input; i++)
        {
            frame1.add(light3);
            frame1.setVisible(true);
            Thread.sleep(1000);

            frame1.remove(light3);
            frame1.add(light2);
            frame1.setVisible(true);
            Thread.sleep(1000);

            frame1.remove(light2);
            frame1.add(light);
            frame1.setVisible(true);
            frame1.remove(light);
            Thread.sleep(1000);
            frame1.setVisible(false);
        }
    }
}