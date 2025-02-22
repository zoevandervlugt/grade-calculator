// Main function of the C++ program.

#include <bits/stdc++.h>

int main()
{
    // Open example text file
    std::fstream file;
    file.open("examplefromdranthony.txt");  // In codeboard this needs to be Root/examplefromdranthony.txt
        
    if(file.is_open()) {
        // String variable to store and read data
        std::string dataString;
    
        // Read file and print until completely read
        while(getline(file, dataString))
        std::cout << dataString << std::endl;
        
        // Close the file
        file.close();
        return 1;
    } else {
        std::cout << strerror(errno) << std::endl;
        return -1;
    }
}