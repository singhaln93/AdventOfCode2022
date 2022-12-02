# Copyright © 2022  Neeraj Singhal
# All rights reserved

# Find packages- dependent or 3rd party libraries
if(NOT TARGET Catch2)
    find_package(Catch2 REQUIRED)
    message(STATUS "    catch2: v2.13.9-1 - found")
endif()

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
    message(STATUS "    spdlog: v1.11.0-1 - found")
endif()

if(NOT TARGET nlohmann_json)
    find_package(nlohmann_json 3.2.0 REQUIRED)
    message(STATUS "    nlohmann-json: v3.11.2-1 - found")
endif()