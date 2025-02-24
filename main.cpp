// Main function of the C++ program.

#include <bits/stdc++.h>

// Initializing a vector to hold all raw data
std::vector<std::vector<double>> rawData;

/**
 * @brief Given the name of a file, read the file and convert it into an outer vector
 *        composed of inner vectors for each line, and in each a double for each number
 *        on the line.
 * 
 * @param file_name String of the name of file being converted
 * @return Vector of double vectors, each line being a vector and each number a double
 */
std::vector<std::vector<double>> file_to_vector(std::string file_name) {
    
    // Open example text file
    std::ifstream file(file_name);  // In codeboard this needs to be Root/examplefromdranthony.txt
        
    if(file.is_open()) {
        // Initialize string to store current line
        std::string currentLine;

        // Read through each line of file
        while(getline(file, currentLine)) {
            // Initialize a vector to hold current category of data
            std::vector<double> currentDataCategory;

            // Initialize a string to hold current value on line
            std::string currentStr;

            // Loop through entire line, and add each individual number as a double to the vector
            for(int i = 0; i < currentLine.length(); i++) {
                char c = currentLine[i];
                if(c == ' ') {
                    double currentVal = std::stod(currentStr);
                    currentDataCategory.push_back(currentVal);
                    currentStr = "";
                } else if(i == currentLine.length() - 1) {
                    currentStr = currentStr + c;
                    double currentVal = std::stod(currentStr);
                    currentDataCategory.push_back(currentVal);
                } else {
                    currentStr = currentStr + c;
                }
            }
            // Add the current vector of numbers to the overall raw data vector
            rawData.push_back(currentDataCategory);
        }
        // // test vector contents
        // for (std::vector<double> current: rawData) {
        //     for (int i = 0; i < current.size(); i++){
        //         std::cout << current[i] << " ";
        //     }
        //     std::cout << "end vector" << std::endl;
        // }
        
        // Close the file
        file.close();
        return rawData;

    // Give an error message if the file isn't opening
    } else {
        std::cout << strerror(errno) << std::endl;
        return {{-1}};
    }
}

/**
 * @brief Given a raw Perusall score, return how many points the 
 *        score contributes to the class's final score.
 * 
 * @param v Double vector containing the file's raw Perusall score
 * @return Double of Perusall's contribution to the final grade
 */
double perusall_contribution(std::vector<double> v) {
    // Initialize doubles to hold raw Perusall score and to hold contribution
    double value = v[0];
    double contribution;

    // Check what range Perusall score falls into and determine contribution
    if(2.5 <= value <= 3) {
        contribution = 4;
    } else if(2 <= value < 2.5){
        contribution = 3;
    } else if(1.5 <= value < 2){
        contribution = 2;
    } else if(1 <= value < 1.5) {
        contribution = 1;
    } else if(0 <= value < 1) {
        contribution = 0;
    // If score isn't in the range, display an error message
    } else {
        std::cout << "Invalid Peruall Input (Check line 1 of file)" << std::endl;
        contribution = -1;
    }
    // // Test
    // std::cout << contribution << std::endl;
    return contribution;
}

/**
 * @brief Given a vector of doubles, calculate and return the average.
 * 
 * @param v Double vector
 * @return Average of all doubles in v
 */
double average(std::vector<double> v) {
    double sum;
    for(double d: v) {
        sum += d;
    }
    return sum/v.size();
}

/**
 * @brief Take the homework-related vectors of the file's vector of double vectors,
 *        calculate how homework contributes to the final grade considering on-time
 *        bonuses, late penalties, and the dropping of one late penalty.
 * 
 * @return Double of HW's contribution to the final grade
 */
double hw_contribution() {
    // Initialize double vectors to differentiate and hold values related to HW
    std::vector<double> potential_scores = rawData[2];
    std::vector<double> raw_scores = rawData[3];
    std::vector<double> on_time = rawData[4];
    std::vector<double> late = rawData[5];

    // Initialize double vector to hold the 6 HW averages
    std::vector<double> hw_averages;

    // For each homework, calculate the average with its respective raw and 
    // potential score, add 5% if on time, and subtract 50% if late
    for(int i = 0; i < 6; i++) {
        double avg = raw_scores[i]/potential_scores[i];
        if(count(on_time.begin(), on_time.end(), i + 1)){
            avg = avg + 0.05*(raw_scores[i]/potential_scores[i]);
        } if(count(late.begin(), late.end(), i + 1)){
            avg = avg - 0.5*(raw_scores[i]/potential_scores[i]);
        }
        hw_averages.push_back(avg);
    }

    // If any homeworks were late, remove the late penalty from the greatest one
    if(!late.empty()) {
        // Find greatest late HW
        double max = raw_scores[late[0]]/potential_scores[late[0]];
        int replaced = late[0] - 1;
        for(double d: late) {
            double current = raw_scores[d]/potential_scores[d];
            if(current > max) {
                max = current;
                replaced = (int)d - 1;
            }
        }
        // Replace highest late HW
        hw_averages[replaced] += 0.5*(raw_scores[replaced]/potential_scores[replaced]);
    }
    // Calculation contribution to final grade
    double contribution = (100 * average(hw_averages)) * 0.12;

    // // Test
    // std::cout << 100 * average(hw_averages) << std::endl;
    // std::cout << contribution << std::endl;
    return contribution;
}

/**
 * @brief Given vectors of four project grades and the number of days late for each, calculate
 *        and return the contribution projects have to the final grade.
 * 
 * @param project_grades Four project grades(0-100) as double values
 * @param days_late Number of days late for each of the four projects, expressed as a non-negative int (in double form)
 * @return Double of projects' contribution to the final grade
 */
double project_contribution(std::vector<double> project_grades, std::vector<double> days_late) {
    // For each project, subtract 20 points for each day late
    for(int i = 0; i < 4; i++) {
        project_grades[i] -= 20*days_late[i];
    }
    // // Test
    // std::cout << average(project_grades) << std::endl;
    // std::cout << 0.12 * (average(project_grades)) << std::endl;
    return 0.12 * average(project_grades);
}

std::string exam_replacement() {
    double exam1 = rawData[10][0];
    double c_exam = rawData[11][0];
    double exam2 = rawData[12][0];
    double final = rawData[14][0];

    if(final > exam1 || final > c_exam || final > exam2) {
        if(exam1 <= c_exam && exam1 <= exam2) {
            rawData[10][0] = final;
            return "Textbook Exam 1";
        } else if(c_exam < exam1 && c_exam <= exam2) {
            rawData[11][0] = final;
            return "C++ Exam";
        } else {
            rawData[12][0] = final;
            return "Textbook Exam 2";
        }
    } else {
        return "None";
    }
}

int main()
{
    std::vector<std::vector<double>> rawData = file_to_vector("examplefromdranthony.txt");

    double perusall = perusall_contribution(rawData[0]);
    std::cout << "Perusall Readings: " << perusall << std::endl;

    double participation = 0.03 * rawData[1][0];
    std::cout << "Classroom Participation: " << participation << std::endl;

    double hw = hw_contribution();
    std::cout << "Homework Assignments: " << hw << std::endl;

    double project = project_contribution(rawData[6], rawData[7]);
    std::cout << "C++ Projects: " << project << std::endl;

    double paper = 0.08 * rawData[8][0];
    std::cout << "Evaluation of Algorithms in an App: " << paper << std::endl;

    double prereq = 0.04 * (100 * (rawData[9][0] / 10));
    std::cout << "Prerequisite Assessment: " << prereq << std::endl;

    std::string replaced_exam = exam_replacement();
    double exam1 = 0.11 * rawData[10][0];
    double c_exam = 0.11 * rawData[11][0];
    double exam2 = 0.11 * rawData[12][0];
    std::cout << "Textbook Exam 1: " << exam1 << std::endl;
    std::cout << "C++ Exam: " << c_exam << std::endl;
    std::cout << "Textbook Exam 2: " << exam2 << std::endl;

    double interview = 0.06 * (100 * (rawData[13][0] / 12));
    std::cout << "Whiteboard Coding Interview: " << interview << std::endl;

    double final_exam = 0.18 * rawData[14][0];
    std::cout << "Final Exam: " << final_exam << std::endl;

    std::cout << "Final Exam Grade Replaced: " << replaced_exam << std::endl;

    double bonus = rawData[15][0];
    std::cout << "Bonus: " << bonus << std::endl;

    double final_grade = perusall + participation + hw + project + paper + prereq + exam1 + c_exam + exam2 + final_exam + interview + bonus;
    std::cout << "Final Grade: " << final_grade << std::endl;

    return 0;
}