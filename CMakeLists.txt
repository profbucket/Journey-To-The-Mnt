cmake_policy(SET CMP0048 NEW)
project(Lab08)
cmake_minimum_required(VERSION 3.10)
 
# Locate GTest
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_compile_options(-std=c++17)  

add_library (applibrary SHARED CharacterFactory.cpp combatEncounter.cpp Major.cpp CompEng.cpp CompSci.cpp
Cybersecurity.cpp JazzStudies.cpp Binarion.cpp Technomancer.cpp 
Generator.cpp Dataweaver.cpp party.cpp FinalBossStats.cpp FinalBossAbilities.cpp Profession.cpp )

add_executable(runTests tests.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread applibrary)

add_executable(runGame JOURNEY_ACROSS_THE_MNT.cpp)
target_link_libraries(runGame applibrary)