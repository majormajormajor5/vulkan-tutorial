cmake_minimum_required(VERSION 3.17)
project(vulkan)

set(CMAKE_CXX_STANDARD 20)

add_executable(vulkan main.cpp lve_window.cpp first_app.cpp lve_pipeline.cpp lve_device.cpp lve_swap_chain.cpp lve_model.hpp lve_model.cpp lve_game_object.h lve_game_object.cpp)

include_directories(/usr/local/include)

find_package(Vulkan REQUIRED)
target_include_directories(vulkan PUBLIC /Users/apavl2/VulkanSDK/1.2.182.0/macOS/include/vulkan)
target_link_libraries(vulkan Vulkan::Vulkan)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(vulkan glfw)