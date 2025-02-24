# Algorithms Grade Calculator

## Overview

This program is designed to read a file containing raw grade data and calculate the final grade based on various components such as Perusall readings, homework, projects, and exams. It applies specific grading policies, including late penalties and replacement rules for exams, to determine the final course score.

## Features

Reads a structured input file and parses data into a vector of vectors.

Calculates individual contributions from:

Perusall Readings (scaled contribution based on score ranges)

Homework (accounts for lateness, bonuses, and dropping the lowest late penalty)

Projects (applies late penalties of 20 points per day late)

Exams (allows final exam score to replace the lowest prior exam score if beneficial)

Computes the final course grade based on weighted contributions.

## File Format

The input file must be structured as follows:
```
Line 1: Perusall score

Line 2: Participation score

Line 3: Homework potential scores

Line 4: Homework raw scores

Line 5: Homework submitted on time

Line 6: Homework submitted late

Line 7: Project grades

Line 8: Days late for projects

Line 9: Textbook Exam 1 score

Line 10: C++ Exam score

Line 11: Textbook Exam 2 score

Line 12: Final Exam score
```

## How to Use

Compile the program using a C++ compiler:

```
g++ -o grade_calculator grade_calculator.cpp
```

Run the program:

```
./grade_calculator
```

When prompted, enter the filename of the data file:

Enter a file name:
example.txt

The program will output the calculated contributions and final grade.

## Example Output

Enter a file name:
example.txt

File Name: example.txt
Perusall Readings: 4.0
Homework Contribution: 11.5
Project Contribution: 9.6
Exam Replacement: Textbook Exam 1
Final Course Grade: 89.2

## Dependencies

C++ Standard Library

## Notes

Ensure the input file is formatted correctly, as incorrect values may result in errors or inaccurate grade calculations.

The program currently uses std::ifstream for file reading. Ensure the file path is correctly specified.

## Future Improvements

Add more robust error handling for file parsing.

Provide support for different grading policies via configuration files.

Implement a graphical user interface for ease of use.

## Author

Created by Zoe Van Der Vlugt

## Sources
https://www.geeksforgeeks.org/how-to-read-from-a-file-in-cpp/
https://en.cppreference.com/w/cpp/container/vector
https://www.geeksforgeeks.org/vector-of-vectors-in-c-stl-with-examples/
https://www.geeksforgeeks.org/copy-file-to-vector-in-cpp-stl/
https://www.geeksforgeeks.org/std-find-in-cpp/
https://www.geeksforgeeks.org/input-in-cpp/
https://www.geeksforgeeks.org/how-to-use-cin-fail-method-in-cpp/
https://www.geeksforgeeks.org/iterators-c-stl/

