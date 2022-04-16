#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"
#include "lve_swap_chain.hpp"
#include "lve_model.hpp"
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
            void drawFrame();
            void loadModels();


            LveWindow lveWindow {WIDTH, HEIGHT, "HELLO VULKAN"};
            LveDevice lveDevice{lveWindow};
            LveSwapChain lveSwapChain{lveDevice, lveWindow.getExtent()};
//            LvePipeline lvePipeline{
//                lveDevice,
//                "/Users/apavl2/projects/cpp/brendan_galea/vulkan_tutorial/shaders/simple_shader.vert.spv",
//                "/Users/apavl2/projects/cpp/brendan_galea/vulkan_tutorial/shaders/simple_shader.frag.spv",
//                LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
//            };
            std::unique_ptr<LvePipeline> lvePipeline;
            VkPipelineLayout pipelineLayout;
            std::vector<VkCommandBuffer> commandBuffers;
            std::unique_ptr<LveModel> lveModel;
        };
}