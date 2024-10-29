cmake_minimum_required(VERSION 3.29)
project(CSC_2210_Lab_4)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Direction.h
        Map.h
        Map.cpp
        Game.h
        Game.cpp
        AcidPool.h
        AcidPool.cpp
        Gardener.h
        Gardener.cpp
        GardenShears.h
        GardenShears.cpp
        Hazard.h
        Hazard.cpp
        MutantPlant.h
        MutantPlant.cpp
        Room.h
        Room.cpp
        Spores.h
        Spores.cpp
        Spray.h
        Spray.cpp
        Weapon.h
        Weapon.cpp
)