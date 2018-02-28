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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    String teste = "   ABC   ";
    String prefix = "   A";
    String suffix = "C   ";
    std::cout << teste.startswith(prefix) << teste.endswith(suffix) << std::endl;
    teste.replace(String("ABC"), String("DEF"));
    std::cout << teste << std::endl;
    return 0;
}

