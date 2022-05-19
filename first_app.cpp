#include "first_app.hpp"
#include "simple_render_system.hpp"


#include <stdexcept>
#include <array>
#include <iostream>

#define GLM_FORCE_RADIANS

#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

namespace lve {
//    static float speed = 1.f; //TODO make this not global
//    void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) //TODO make this not global
//    {
//        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
//            glfwSetWindowShouldClose(window, GLFW_TRUE);
//        } else if (key == GLFW_KEY_F && action == GLFW_PRESS) {
//            speed++;
//        };
//    }

    FirstApp::FirstApp() {
        loadGameObjects();
    }

    FirstApp::~FirstApp() {}

    void FirstApp::run()
    {
        SimpleRenderSystem simpleRenderSystem{lveDevice, lveRenderer.getSwapChainRenderPass()};

//        glfwSetKeyCallback(lveWindow.getGlfwWindow(), keyCallback);

        while (!lveWindow.shouldClose()) {
            glfwPollEvents();

            if (auto commandBuffer = lveRenderer.beginFrame()) {
                lveRenderer.beginSwapChainRenderPass(commandBuffer);
                simpleRenderSystem.renderGameObjects(commandBuffer, gameObjects);
                lveRenderer.endSwapChainRenderPass(commandBuffer);
                lveRenderer.endFrame();
            }
        }

        vkDeviceWaitIdle(lveDevice.device());
    }

    void FirstApp::loadGameObjects()
    {
        std::vector<LveModel::Vertex> vertices {
            {{0.0f, -0.5f}, {1.0f, 0.0f, 0.0f}},
            {{0.5f, 0.5f}, {0.0f, 1.0f, 0.0f}},
            {{-0.5f, 0.5f}, {0.0f, 0.0f, 1.0f}}
        };

        auto lveModel = std::make_shared<LveModel>(lveDevice, vertices);

        auto triangle = LveGameObject::createGameObject();
        triangle.model = lveModel;
        triangle.color = {.1f, .8f, .1f};
        triangle.transform2d.translation.x = .2f;
        triangle.transform2d.scale = {2.f, .5f};
        triangle.transform2d.rotation = .25f * glm::two_pi<float>();

        gameObjects.push_back(std::move(triangle));
    }
}