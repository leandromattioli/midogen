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

#include <catch.hpp>
#include <String.h>


TEST_CASE("prefix and suffix tests", "[String startswith,endswith]") {
    String testString("abcde");

    REQUIRE(testString.startswith("abc"));
    REQUIRE_FALSE(testString.startswith("abd"));
    REQUIRE(testString.endswith("cde"));
    REQUIRE_FALSE(testString.endswith("bcd"));
}


TEST_CASE("replace tests", "[String::replace]") {
    String testString("I'm going to Mars");

    SECTION("substring found and replaced and original not changed") {
        String result = testString.replace("going", "leaving");
        REQUIRE(result == "I'm leaving to Mars"); //replaced
        REQUIRE(testString == "I'm going to Mars");
    }
    
    SECTION("substring not found") {
        String result = testString.replace("nonsense", "ghost");
        REQUIRE(result == "I'm going to Mars"); //not found
    }
}

TEST_CASE("stripping (trimming)", "[String strip,lstrip,rstrip") {
    String testString("  -- Title --  ");
    
    SECTION("left strip") {
        REQUIRE(testString.lstrip(" ") == "-- Title --  ");
        REQUIRE(testString.lstrip(" -") == "Title --  ");
        REQUIRE(testString.lstrip(" -a") == "Title --  ");
        REQUIRE(testString.lstrip("!") == testString);
    }
    
    SECTION("right strip") {
        REQUIRE(testString.rstrip(" ") == "  -- Title --");
        REQUIRE(testString.rstrip(" -") == "  -- Title");
        REQUIRE(testString.rstrip(" -a") == "  -- Title");
        REQUIRE(testString.rstrip("!") == testString);
    }
    
    SECTION("strip") {
        REQUIRE(testString.strip(" ") == "-- Title --");
        REQUIRE(testString.strip(" -") == "Title");
        REQUIRE(testString.strip(" -a") == "Title");
        REQUIRE(testString.strip("!") == testString);
    }
}
