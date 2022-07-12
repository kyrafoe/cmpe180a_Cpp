#include <fstream>
#include <iostream>
#include <getopt.h>

/*main program to copy an existing source file to one or multiple valid target files.
Valid target files don't exists before. If a target file already exists, a copy is not made.
Errors are indicated.*/


int main(int argc, char *argv[])
{
    int opt;

    // getopt_long returns -1, if all arguments are parsed
    // long_options struct: name of long option, required argument, flag (0/1), value
    while (1) 
    {
        int option_index = 0;
        static struct option long_options[] = {
            {"source",  required_argument, 0, 's' },
            {"target",  required_argument, 0, 't' },
        };

        opt = getopt_long(argc, argv, "s:t:",
                 long_options, &option_index);

        if (opt == -1)
            break;    


        switch (opt) 
        {
            case 's':
            {
                    // Check if source file exists
                    std::string sourceFile;
                    sourceFile = optarg;                  
                    
                    std::string line;
                    std::ifstream inputFile (sourceFile);  

                    if (inputFile.is_open()){}                                        
                    else{
                        std::cerr << "Source file doesn't exist. \n";
                        exit(1); // exit if not existent
                    }
                    break;
            }

            case 't':
            {
                    // Check if target file already exists
                    // Get target filename from optarg
                    std::string targetFile = optarg;
                    std::fstream outputFile;

                    // Open target file
                    outputFile.open(targetFile, std::ios_base::out | std::ios_base::in); 

                    if (outputFile.is_open())
                    {
                        std::cerr << "Target file "<< optarg 
                        <<" already exists! Provide a different target file name. \n";
                    } 
                    else //make actual copy, if source exists (program would exit if source does not exist) and if target file does not exist
                    {
                        outputFile.clear();

                        // Create the file, if not exist
                        outputFile.open(targetFile, std::ios_base::out);

                        // Get source file name
                        std::string sourceFile = argv[2];                                     
                        std::string line;
                        std::ifstream inputFile (sourceFile); 

                        // Get all lines from source file
                        while (std::getline (inputFile,line) )
                        {
                            // Write all lines in output file
                            outputFile << line << "\n";
                        }
                        inputFile.close(); 
                        outputFile.close();
                    }                   
                    break;
            }

            // Option character that is not in opstring returns ?
            case '?':
                break;
    
            default:
            {
                std::cerr << " Getopt returned unknown character code: " << opt << "\n"; 
            }
        }
    }

    // Check for unknown arguments, optind is index that is not an option
    // optind is initilaized to 1
    for (int i = optind; i < argc; i ++)
    {
        std::cerr << "Non-option argument provided: "
        << argv[i] << "\n";
    } 

    return 0;
}
