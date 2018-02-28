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
 * \file String.h
 * \author Leandro Resende Mattioli
 * \date Feb 27, 2018
 */

#ifndef STRING_H
#define STRING_H

#include <string>

class String : public std::string {
public:
    using std::string::string;
    using std::string::replace;
    bool startswith(const std::string& prefix);
    bool endswith(const std::string& suffix);
    String replace(const std::string& oldValue, const std::string& newValue);
    String lstrip(const std::string& chars);
    String rstrip(const std::string& chars);
    String strip(const std::string& chars);
    /*String(const String& orig);
    virtual ~String();*/
};

#endif /* STRING_H */

