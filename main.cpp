// Main function of the C++ program.

#include <bits/stdc++.h>

/**
 * @brief Given the name of a file, read the file and convert it into an outer vector
 *        composed of inner vectors for each line, and in each a double for each number
 *        on the line.
 * 
 * @param file_name String of the name of file being converted
 * @return Vector of double vectors, each line being a vector and each number a double
 */
std::vector<std::vector<double>> file_to_vector(std::string file_name) {
    // Initializing a vector to hold all raw data
    std::vector<std::vector<double>> rawData;
    
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
 * @param v Vector of double vectors (all the lines in the file)
 * @return Double of HW's contribution to the final grade
 */
double hw_contribution(std::vector<std::vector<double>> v) {
    // Initialize double vectors to differentiate and hold values related to HW
    std::vector<double> potential_scores = v[2];
    std::vector<double> raw_scores = v[3];
    std::vector<double> on_time = v[4];
    std::vector<double> late = v[5];

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

    // If any homeworks were late, remove the late penalty from the lowest one
    if(!late.empty()) {
        // Find lowest late HW
        double min = raw_scores[late[0]]/potential_scores[late[0]];
        int replaced = late[0] - 1;
        for(double d: late) {
            double current = raw_scores[d]/potential_scores[d];
            if(current < min) {
                min = current;
                replaced = (int)d - 1;
            }
        }
        // Replace lowest late HW
        hw_averages[replaced] += 0.5*(raw_scores[replaced]/potential_scores[replaced]);
    }
    // Calculation contribution to final grade
    double contribution = (100 * average(hw_averages)) * 0.12;

    // // Test
    // std::cout << 100 * average(hw_averages) << std::endl;
    // std::cout << contribution << std::endl;
    return contribution;
}

int main()
{
    std::vector<std::vector<double>> rawData = file_to_vector("examplefromdranthony.txt");
    double perusall = perusall_contribution(rawData[0]);
    double hw = hw_contribution(rawData);
    return 0;
}