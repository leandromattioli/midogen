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
 * \file Generator.h
 * \author Leandro Resende Mattioli
 * \date Feb 27, 2018
 */

#ifndef GENERATOR_H
#define GENERATOR_H

#include <map>
#include <string>
#include <iostream>

using std::istream;
using std::ostream;
using std::__cxx11::string;
using std::cin;
using std::cout;

class Generator {
private:
    std::map<const std::string, const std::string> markersByExtension;
public:
    Generator();
    const string getMarkerByFilename(const string& filename);
    void process(const istream& in = cin, const ostream& out = cout, 
                 const string& marker = "///");
    int process(const string& fileIn, const string& fileOut = "", 
                 const string& marker = "");
    int processDir(const string& dirIn, const string& dirOut = "", 
                    const string& extension = ".txt", const string& marker= "");
};

#endif /* GENERATOR_H */

