#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"
#include "lve_device.hpp"

namespace lve {
    class FirstApp {
        public:
        FirstApp() {}

        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();
        private:
            LveWindow lveWindow {WIDTH, HEIGHT, "HELLO VULKAN"};
            LveDevice lveDevice{lveWindow};
            LvePipeline lvePipeline{
                lveDevice,
                "/Users/apavl2/projects/cpp/brendan_galea/vulkan_tutorial/shaders/simple_shader.vert.spv",
                "/Users/apavl2/projects/cpp/brendan_galea/vulkan_tutorial/shaders/simple_shader.frag.spv",
                LvePipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)
            };
        };
}