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
 * \file Path.cpp
 * \author Leandro Resende Mattioli
 * \date Feb 27, 2018
 */

#include <sys/stat.h>
#include <string>
#include "Path.h"

bool Path::isFile(std::string path) {
	struct stat s;
	if( stat(path.c_str(), &s) == 0 )
		return s.st_mode & S_IFREG;
	return false;
}

bool Path::isDir(std::string path) {
    std::string pathcopy;
    struct stat s;
    int result;
    int last;

    //Removing trailing PATHSEP, if existent
    pathcopy = path;
    last = pathcopy.length() - 1;
    if (pathcopy[last] == '/')
        pathcopy[last] = '\0';

    //Checking for dir existence
    result = stat(pathcopy.c_str(), &s);

    if (result == 0)
        return s.st_mode & S_IFDIR;
    return false;
}
