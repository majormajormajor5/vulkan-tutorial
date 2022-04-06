//#define GLFW_INCLUDE_VULKAN
#include <glm/vec4.hpp>
#include <vulkan.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/matrix.hpp>
//#include <glm/mat4x4.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;


    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported\n";

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();

    return 0;
}
