# Algorithms-Grade-Calculator

## Input File Description
A valid data file will have the format as described in the bullet points, in order, with precisely
that content per line of the file. Values are separated by whitespace; it need not be a single
space. If it says values will only be within a range, a student cannot earn more than 100%
on that category; otherwise, it should be assumed to be possible.
- The Perusall reading score, an average reported by Perusall. Values will only be in [0, 3].
- A participation score. Values will only be in [0, 100].
- The points possible on each of 6 homework assignments, in order.
- The points a student earns (independent of on-time bonus or late penalty) on each of 6
homework assignments, in order.
- The numbers of the homework assignments, from 1 to 6 in order, on which the student
earned the on-time bonus.
- The numbers of the homework assignments, from 1 to 6 in order, which the student
submitted late.
- Grades for 4 programming projects.
- The number of days late for each of the 4 programming projects, in order. These values
will only be nonnegative integers.
- The grade on the Evaluation of Algorithms in an App, out of 100. Values will only be
in [0, 100].
- The number of questions answered correctly on the prerequisite assessment; use the
information from the class feedback about how that translates into a grade..
- The grade on the Textbook Exam 1, out of 100.
- The grade on the C++ Exam, out of 100.
- The grade on the Textbook Exam 2, out of 100.
- The points earned on the whiteboard coding interview, out of a maximum of 12, with
the contribution to the course grade determined by the fraction of points earned. Values
will only be in [0, 12].
- The grade on the Final Exam, out of 100.
- The total points earned from Extra Credit Opportunities falling in the Bonus category
on the syllabus.

## Expected Output
For a given data file, you will report the file’s name, the amount that each component listed
in the syllabus contributes to the final grade, what (if anything) had its grade replaced by the
grade on the final exam (either None, or the name of the component replaced), and the final
grade. Match the formatting below, as it would be for allZeroes.txt. If you use additional
print statements in testing, comment them out prior to submission.
```
File: allZeroes.txt
Perusall Readings: 0.0000
Classroom Participation: 0.0000
Homework Assignments: 0.0000
C++ Projects: 0.0000
Evaluation of Algorithms in an App: 0.0000
Prerequisite Assessment: 0.0000
Textbook Exam 1: 0.0000
C++ Exam: 0.0000
Textbook Exam 2: 0.0000
Whiteboard Coding Interview: 0.0000
Final Exam: 0.0000
Final Exam Grade Replaced: None
Bonus: 0.0000
Final Grade: 0.0000
```

## Additional Instructions
- Vectors are commonly used in C++, providing some of the advantages that you may have
seen in CS1 with ArrayLists. Use vectors instead of arrays whenever possible.
- Intermediate calculations should be as exact as possible. When printing grades (both the
final grade, and the requested subcomponents) display 4 decimal places. You may find
std::setprecision()3 and std::fixed4 helpful. For example, if the (provided) file called
allZeroes.txt represents someone earning all zeroes (e.g. before any graded assignments
have been completed), the final grade for that should be shown as 0.0000.
- Your submission is expected to handle any input file that meets the specifications, even if
it seems contrived and unlikely to arise from a real student. You do not have to have any
particular behavior for input files that do not meet the specifications.
- Your submission is expected to handle any input file that meets the specifications, even if
it seems contrived and unlikely to arise from a real student. You do not have to have any
particular behavior for input files that do not meet the specifications.
- You are welcome and
encouraged to use a calculator or spreadsheet to check the correctness of your answers. You
should expect to earn very little credit if your submission does not correctly calculate and
print grades for valid data files; close but different is not correct.

## Sources
https://www.geeksforgeeks.org/how-to-read-from-a-file-in-cpp/
https://en.cppreference.com/w/cpp/container/vector
https://www.geeksforgeeks.org/vector-of-vectors-in-c-stl-with-examples/
https://www.geeksforgeeks.org/copy-file-to-vector-in-cpp-stl/
