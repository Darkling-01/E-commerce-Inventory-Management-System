cmake_minimum_required(VERSION 3.24)
project(E_commerce_Inventory_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(E_commerce_Inventory_Management_System main.cpp src/inventory.cpp src/inventory.h src/accounts.cpp src/accounts.h)
