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
 * \file Generator.cpp
 * \author Leandro Resende Mattioli
 * \date Feb 27, 2018
 */

#include "Generator.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

namespace fs = boost::filesystem;
using std::__cxx11::string;
using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::map;

Generator::Generator() {
    const char* markersTable[][2] = {
        {"h", "///"},
        {"c", "///"},
        {"hpp", "///"},
        {"cpp", "///"},
        {"cc", "///"},
        {"cs", "///"},
        {"java", "///"},
        {"d", "///"},
        {"py", "##"},
        {"sh", "##"},
        {"lsp", ";;;"},
        {"lisp", ";;;"},
        {0, 0}
    };
    for(int i = 0; markersTable[i][0]; i++) {
        const string extension = markersTable[i][0];
        const string marker = markersTable[i][1];
        markersByExtension.insert(std::make_pair(extension, marker));
    }
}

const string Generator::getMarkerByFilename(const string& filename) {
    string extension = fs::extension(filename);
    if (markersByExtension.count(extension))
        return markersByExtension[extension];
    return "///"; //fallback
}

void Generator::process(istream& in, ostream& out,
        const string& marker) {
    string line;
    cout.flush();
    while (std::getline(in, line)) {
        if (in.bad()) {
            throw new std::exception();
        }
        boost::trim_left(line);
        if (boost::starts_with(line, marker)) {
            boost::replace_first(line, marker, "");
            out << line << endl;
        }
    }
    out.flush();
}

int Generator::process(const string& fileIn, const string& fileOut,
        const string& marker) {
    //Defining marker
    string finalMarker;
    if (marker.empty())
        finalMarker = getMarkerByFilename(fileIn);
    else
        finalMarker = marker;

    //Creating streams
    ifstream in(fileIn);
    if (!in) {
        cerr << "error: cannot open file " << fileIn << endl;
        return 2;
    }

    ofstream outf;
    if (!fileOut.empty()) {
        outf = ofstream(fileOut);
        if (!outf) {
            cerr << "error: cannot create output file " << fileOut << endl;
            return 2;
        }
    }
    ostream& out = fileOut.empty() ? cout : outf;

    //Extracting documentation
    process(in, out, finalMarker);
    return 0;
}

int Generator::processDir(const string& dirIn, const string& dirOut,
        const string& extension, const string& marker) {
    // list dir
    // get marker
    // call process(fileIn, fileOut, marker)
    return 0;
}


