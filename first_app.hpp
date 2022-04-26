#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_swap_chain.hpp"
#include "lve_model.hpp"
#include "lve_game_object.h"
#include <memory>
#include <vector>

namespace lve {
    class FirstApp {
        public:
        FirstApp();
        ~FirstApp();

        FirstApp(const FirstApp&) = delete;
        FirstApp& operator=(const FirstApp&) = delete;

        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();
        private:
            void createPipelineLayout();
            void createPipeline();
            void createCommandBuffers();
            void freeCommandBuffers();
            void drawFrame();
            void loadGameObjects();
            void recreateSwapChain();
            void recordCommandBuffer(int imageIndex);
            void renderGameObjects(VkCommandBuffer commandBuffer);

            LveWindow lveWindow {WIDTH, HEIGHT, "HELLO VULKAN"};
            LveDevice lveDevice{lveWindow};
            std::unique_ptr<LveSwapChain> lveSwapChain;
            std::unique_ptr<LvePipeline> lvePipeline;
            VkPipelineLayout pipelineLayout;
            std::vector<VkCommandBuffer> commandBuffers;
            std::vector<LveGameObject> gameObjects;
        };
}