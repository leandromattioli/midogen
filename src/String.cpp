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
 * \file String.cpp
 * \author Leandro Resende Mattioli
 * \date Feb 27, 2018
 */

#include "String.h"
#include <string>

using std::string;

#include <iostream> //debug

bool String::startswith(const string& prefix) {
    return prefix.length() <= this->length()
            && equal(prefix.begin(), prefix.end(), this->begin());
}

bool String::endswith(const string& suffix) {
    return suffix.length() <= this->length()
            && equal(suffix.rbegin(), suffix.rend(), this->rbegin());
}

String String::trim(const string& chars) {

}

String String::ltrim(const string& chars) {
    String s(*this);
}

String String::rtrim(const string& chars) {
    //String s(*this);
    //s.erase(s.find_last_not_of(t) + 1);
    //return s;
}

String String::replace(const string& oldValue, const string& newValue) {
    String copyString;
    copyString.assign(*this);
    size_t pos = this->find(oldValue);
    if(pos != string::npos) {
        copyString.replace(pos, oldValue.length(), newValue);
    }
    return copyString;
}

