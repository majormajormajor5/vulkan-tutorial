#pragma once

#include "lve_window.hpp"
#include "lve_pipeline.hpp"

namespace lve {
    class FirstApp {
        public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

        void run();
        private:
            LveWindow lveWindow {WIDTH, HEIGHT, "HELLO VULKAN"};
            LvePipeline lvePipeline{
                "/Users/apavl2/projects/cpp/brendan_galea/vulkan_tutorial/shaders/simple_shader.vert.spv",
                "/Users/apavl2/projects/cpp/brendan_galea/vulkan_tutorial/shaders/simple_shader.frag.spv"
            };
        };
}