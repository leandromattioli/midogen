/*
 * Copyright 2018 Leandro Resende Mattioli.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * \file midogen.cpp
 * \author Leandro Resende Mattioli
 * \date Feb 27, 2008
 **/

#include <cstdlib>
#include <iostream>
#include <String.h>
#include <Generator.h>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

using std::cerr;
using std::cout;
using std::endl;
using std::string;

void usage(po::options_description& desc) {
    cout << R"(Usage: midogen [OPTION]... [FILE]
  or: midogen --batch [OPTION]...
Extract documentation wrapped in special comments in FILE
In batch mode operation, extracts documentation from files in a directory
)";
    cout << desc << endl;
    cout << R"(
Exit status:
 0 if OK,
 1 if invalid usage,
 2 if file or directory not found.

Report bugs to: <https://github.com/leandromattioli/midogen/issues>
Midogen home page: <https://github.com/leandromattioli/midogen>
)";
}

void version() {
    cout << R"(midogen 0.4
Copyright (C) 2018 Leandro Resende Mattioli
License Apache 2.0: <http://www.apache.org/licenses/LICENSE-2.0>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
)";
}

void error() {
    cerr << "error: incorrect usage!" << endl;
}

string getMarker(po::variables_map& varmap) {
    string marker = "";
    if (varmap.count("marker")) {
        marker = varmap["marker"].as<string>();
    }
    return marker;
}

int processSingleFile(po::variables_map& varmap) {
    string file = varmap["file"].as<string>();
    Generator generator;
    generator.process(file, "", getMarker(varmap));
}

int processDir(po::variables_map& varmap) {
    string dirIn = varmap["in-dir"].as<string>();
    string dirOut = varmap["out-dir"].as<string>();
    string extension = varmap["extension"].as<string>();
    Generator generator;
    generator.processDir(dirIn, dirOut, extension, getMarker(varmap));
}

int main(int argc, char** argv) {
    po::options_description general("General options");
    general.add_options()
            ("batch,b", "enables batch mode and batch-specific options")
            ("marker,m", po::value<string>(), 
                "line comment used as documentation marker")
            ("help,h", "display this help and exit")
            ("version,v", "output version information and exit")
            ;

    po::options_description hidden_options("Hidden options");
    hidden_options.add_options()
            ("file", po::value<string>(), "input file");
            
    po::options_description batch_options("Batch mode options");
    batch_options.add_options()
            ("in-dir,i", po::value<string>(), 
                "directory containing sources (required)")
            ("out-dir,o", po::value<string>(), 
                "directory to output documentation (required)")
            ("extension,e", po::value<string>(), 
                "output files extension (required)")
            ;

    po::options_description all_options("All Options");
    all_options.add(general).add(batch_options).add(hidden_options);
    
    po::options_description visible_options("Options");
    visible_options.add(general).add(batch_options);

    po::positional_options_description pos;
    pos.add("file", 1);

    po::variables_map varmap;
    po::store(po::command_line_parser(argc, argv).
            options(all_options).positional(pos).run(), varmap);
    po::notify(varmap);
    
    cout << varmap.count("file") << endl;

    //Help
    if (varmap.count("help")) {
        usage(visible_options);
        return 0;
    }
    //Version
    if (varmap.count("version")) {
        version();
        return 0;
    }
    //Single mode operation
    if (varmap.count("file") && !varmap.count("batch") &&
            !varmap.count("in-dir") && !varmap.count("extension")) {
        return processSingleFile(varmap);
    }
    //Batch mode
    if (!varmap.count("file") && varmap.count("batch") &&
            varmap.count("in-dir") && varmap.count("extension")) {
        return processDir(varmap);
    }
    //Invalid mode
    error();
    usage(visible_options);
    return 1;
}

