// Main function of the C++ program.

#include <bits/stdc++.h>

void file_to_vector(std::string file_name) {
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
    } else {
        std::cout << strerror(errno) << std::endl;
    }
}

int main()
{
    file_to_vector("examplefromdranthony.txt");
    return 0;
}