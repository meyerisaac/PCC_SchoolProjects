//File Name: Assign10Ch6Proj8.cpp
//Author: Isaac Meyer
//Email: imeyer@go.pasadena.edu
//Assignment: Assignment 10 Chapter 6 Project 8
//Description: Create a program that is able to take a file and number the lines in a corresponding output file
//Last Date Changed: 11/04/2022

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

bool isIfStream(ifstream& stream);
//Checks if a stream was able to be opened successfully
//I:Takes in the call by reference stream
//O:Returns true or false accordingly

bool isOfStream(ofstream& stream);
//Checks if a stream was able to be opened successfully
//I:Takes in the call by reference stream
//O:Returns true or false accordingly

void transcribeFile();
//Transcribes the file accordingly to the output file
//I:No inputs
//O:No outputs, just copies and edits the output onto an output file

int main()
{
    char ans = 'y';

    //Repeat if user wants
    while(tolower(ans) == 'y')
    {
        //All we need is this one processing function
        transcribeFile();

        //Prompt user to repeat program
        cout << "Do you want to rerun the program? Y for yes / N for no:\n";
        cin >> ans;
    }
    return 0;
}

bool isIfStream(ifstream& stream)
{
    //Check for error in opening stream
    if(stream.fail())
    {
        cout << "Error Opening An Input Stream!\n";
        exit(1);
    }
}

bool isOfStream(ofstream& stream)
{
    //Check for error in opening stream
    if(stream.fail())
    {
        cout << "Error Opening An Output Stream!\n";
        exit(1);
    }
}

void transcribeFile()
{
    //File stream validations all done here
    ifstream inStream("Answers.txt");
    isIfStream(inStream);
    ofstream outStream("OutputFile.txt");
    isOfStream(outStream);

    //Declaration and initialization of variables we'll be using
    char next;
    string line;
    int count = 1;

    while(!inStream.eof())
    {
        //Set the width for the numbers
        outStream << setw(2) << count << ' ';

        //Loop until we get all the lines till the end of the file
        if(inStream >> next && next != '\n')
        {
            inStream.putback(next);
            getline(inStream, line);
            outStream << line << endl;
        }
        else
        {
            //If something went wrong and nothing is read correctly, eject
            cout << "Error With transcribeFile() loop!\n";
            exit(1);
        }

        //Update the counter
        count++;
    }
}

/*Sample Output:
 *  1 Hacking is not like anything portrayed in the movies because it is not
 2 generally done in a terminal in a matter of seconds.
 3 The best way to seek for advice about Computer science is trhough school
 4 couneslor, CS professors, and students in CS department.
 5 The easiest to learn is Javascript.
 6 Python or Javascript are two really good languages to learn first since
 7 they're both relatively easy and in demand.
 8 You don't memorize the syntax, you will get used to the language that you
 9 are currently learning.
10 Computer Science is a good major for entrepreneurs because it allowed for
11 new ideas to be made.
12 Base on my understanding in both language so far, in term of app
13 delevopment, Java is more recommended since it is the foundation of
14 Android development and is easy to use.
15 1~2 hours is approriate for a day.
16 C is the procedural programming language that does not support class, and
17 objects, but C++ is the combination of both procedural and objects
18 oriented porgramming language.
19 According to Github, Javascript is the most widely used language.
20 Companies are looking for someone who is well rounded. Good communication
21 skills are a must.
22 According to PYPL's ranking, the three most popular programming languages
23 are: Python, Java, Javascript.
24 You can get internship information in the career center.
25 Cal Tech.
26 The ++ in C++ means to increment by one, to indicate that the language is
27 one step above C, adding object-oriented features.
28 Artificial Intelligence and Quantum Computing have the most promising
29 future in terms of research opportunities as of now.
30 The average base salary for computer science majors is found to be around
31 $59,000 with a low range of $42,000 and a high range of $130,000,
32 graduates have found an average pay increase of 10%.
33 Base on the current stiuition, it is going to be a cometitive work field
34 because many people choose to be a compuuter science major and many of
35 them go to graduate schools.
36 HTML is not a programming language.
37 The more math, the better, but if you want to set a target goal, you
38 should at least have a good understanding of calculus and linear algebra.
39 Caltech or MIT would not be too bad.
40 CS is competitive because the classes are more difficult and alot of
41 students want to major in CS.
42 Mostly even knowing alot of languge, if not able to solve a problem,
43 there is no point. So I would be skill with one languge and able to
44 understand and able to solve problem with a languge I familar with is more
45 preferable.
46 In my opinion, knowing one programming language is better to study
47 because there are many programming languages that have similar content.
48 The computer science more focuses on software, but the computer science
49 engineering is more about the hardware.
50 Depends on what you want to speacialize in computer science, but it
51 usually require a lot of math.
52 The computer science field is intensive but not as intensive as one may
53 think. It requires a lot of self preservation and disiciple.
54 C++ may have a reputation for its steep learning curve, but learning it
55 first means you'll be able to take on other languages easily later on.
56 The three most common languages used in software development are C++,
57 Java, and Python depending on what field you choose.
58 The interview consists of a bunch of smaller interviews. Each one with a
59 different member of the team asking you to solve coding questions.
60 A degree in CIS is a Bachelor of Arts(BA), where as CSE and CS is a
61 Bachelor of Science(BS). The major requirements between the 3 are genrally
62 the same. THe non-major requirements are different. CIS requires less math
63 courses, as the others do. For major requirements, CSE has more Electrical
64 Engineering courses, to add a little focus of hardware, where as CS is
65 pure programming, all software.
66 Automation will change the type of work computer science majors do.
67 Instead of, say building websites, they will be customizing the pre-built
68 website or automating the building of websites. So the future job
69 prospects for computer science students look promising.
70 It is not generally necessarily an inherent need for a VPN, just like how
71 we use a anti-virus scanner to prevent and get rid of viruses, we use a
72 VPN to have peace of mind when using the internet because it encrypts your
73 data traffic from being traced by others.
74 Usually students are very busy to study this major and people should only
75 consider double major if and only if they have a lot of free time after
76 study computer science.
77 Binary language.
78 There are a variety of potential career paths, such as web, ios, android
79 and game development, as well as cybersecurity, information technology,
80 and database administration.
81 Software developer, web developer, anything that would require a lot of
82 time on coding.
83 The learning curve isn't too hard but the introduction courses cause
84 students to dropout.
85 From some serach, there are alot of flied that can be realted to the
86 degree such as Computer system analyst, Network System Administrator,
87 Database Administrator, Computer System Engineer, Software Quality
88 Assurance Engineer, Computer User Support Specialist and more.
89 OOP pays more attention to data security, and,  in OOP, the data member
90 of the class can be accessed through the member functions of the class.
91 The most filed related to computer are requiring computer sience.
92 There are many resources related to artificial intelligence in online,
93 you can even look at the youtube.
94 Have people in your team vote for an idea or come to a compromize.
95 Best languages for Machine Learning are: Python, Java, R, Javascript,
96 Scala.
97 Creating and constantly updating a Github is very helpful to show
98 dedication
99 Coding interviews are between 3-7 hours long,
100 Yes, as they are generally written in the same style. C++ can actually
101 run C code, but not vice versa. C focuses on a sequence of steps or
102 procedures to solve a problem. C++ puts more focus on objects and classes
103 to find a solution, C does not have object and classes.
104 Scala is currently the highest paid programming language with the average
105 salary between $125K to $143K
106 CS will try develop, and CIS will try to utilize that development.
107 Theoretical appoaches more complex focusing on abstract mathematical
108 concepts while practical is more about coding and general programmming.
109 It bases on the the school, some offer the double major or master. Mostly
110 from my research, the closet major is electrical engineering, physic
111 major, or any major that related to nano technology.
112 In my case, I am interested in artificial intelligence
113 C/C++ are corestone software programming language that are continue to be
114 used widely in engineering field.
115 Computer Engineering is a "combination" of Electrical Engineering and
116 Computer Science. While Computer Science deals more with software,
117 Computer Engineering is more hands on with the hardware aspect.
118 You can read books meant specially for coding interviews like: "Cracking
119 the coding interview" by Laakman and do coding practice on websites like
120 hackerrank.com.
121 Mainly the physics classes.
122 Use command line to compile .cpp file to .exe.
123 To find the information about what you are studying, you have to figure
124 out exactly what happens in your program to find the error in there.
125 The most important part of computer science is being creative, so
126 thinking, and discussing with other pepole are important.
127 Both are popular choices as a first language. Python is great for Machine
128 Learning, while Javascript is widely used in building websites. What you
129 choose to learn depends on your area of interest.
130 Linear Algebra, Calculus for undergraduate students and Optimization,
131 Probability and Simulation for post graduate students are some of the
132 subjects that can be helpful to computer science students in the long run.
133 stackoverflow.com,hackerrank.com,quora.com,https://www.geeksforgeeks.org/
134 ,https://www.w3schools.com/ are some of the websits that computer science
135 students can use.
 */