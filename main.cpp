// Main function of the C++ program.

#include <bits/stdc++.h>

std::vector<double> contributions = {4, 3, 12, 12, 8, 4, 11, 6, 18};
std::vector<double> averages;

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
    } else {
        std::cout << strerror(errno) << std::endl;
        return {{-1}};
    }
}

double perusall_contribution(std::vector<double> v) {
    double value = v[0];
    double contribution;
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
    } else {
        std::cout << "Invalid Peruall Input (Check line 1 of file)" << std::endl;
        contribution = -1;
    }
    // // test
    // std::cout << contribution << std::endl;
    return contribution;
}


double average(std::vector<double> v) {
    double sum;
    for(double d: v) {
        sum += d;
    }
    return sum/v.size();
}

double hw_contribution(std::vector<std::vector<double>> v) {
    std::vector<double> potential_scores = v[2];
    std::vector<double> raw_scores = v[3];
    std::vector<double> on_time = v[4];
    std::vector<double> late = v[5];

    std::vector<double> averages;
    for(int i = 0; i < 6; i++) {
        double avg = 100*(raw_scores[i]/potential_scores[i]);
        if(count(on_time.begin(), on_time.end(), i + 1)){
            avg += 5;
        } if(count(late.begin(), late.end(), i + 1)){
            avg -= 50;
        }
        averages.push_back(avg);
    }
    // Need to add excluding late penalty from lowest late hw
    std::cout << average(averages) << std::endl;
    return average(averages);
}

int main()
{
    std::vector<std::vector<double>> rawData = file_to_vector("examplefromdranthony.txt");
    double perusall = perusall_contribution(rawData[0]);
    double hw = hw_contribution(rawData);
    return 0;
}