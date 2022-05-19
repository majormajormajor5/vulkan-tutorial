#pragma once

#include "lve_window.hpp"
#include "lve_device.hpp"
#include "lve_renderer.h"
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
            void loadGameObjects();

            LveWindow lveWindow {WIDTH, HEIGHT, "HELLO VULKAN"};
            LveDevice lveDevice{lveWindow};
            LveRenderer lveRenderer{lveWindow, lveDevice};

            std::vector<LveGameObject> gameObjects;
        };
}