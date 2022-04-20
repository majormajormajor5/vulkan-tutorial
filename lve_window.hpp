#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace lve {
    class LveWindow {
        public:
            LveWindow(int w, int h, std::string name);
            ~LveWindow();

            LveWindow(const LveWindow&) = delete;
            LveWindow &operator=(const LveWindow &) = delete;

            bool shouldClose() { return glfwWindowShouldClose(window); }

            bool wasWindowResized() { return framebufferResized; }

            void resetWindowResizedFlag() { framebufferResized = false; }

            void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);

            VkExtent2D getExtent() { return {static_cast<uint32_t >(width), static_cast<uint32_t >(width)}; }

        private:
            GLFWwindow* window;

            void initWindow();

            static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

            int width;
            int height;
            bool framebufferResized = false;

            std::string windowName;
    };
}