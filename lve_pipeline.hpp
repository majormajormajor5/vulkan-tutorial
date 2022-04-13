#pragma once

#include "lve_device.hpp"

#include <string>
#include <vector>

namespace lve {

    struct PipelineConfigInfo {
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkViewport viewport;
        VkRect2D scissor;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        VkPipelineLayout pipelineLayout = nullptr;
        VkRenderPass renderPass = nullptr;
        uint32_t subpass = 0;
    };

    class LvePipeline {
    public:
        LvePipeline(
                LveDevice &device,
                const std::string &vertFilepath,
                const std::string &fragFilepath,
                const PipelineConfigInfo &config
        );

        ~LvePipeline();

        LvePipeline(const LvePipeline &) = delete;

        void operator=(const LvePipeline &) = delete;

        static PipelineConfigInfo defaultPipelineConfigInfo(int32_t width, int32_t height);

    private:
        static std::vector<char> readFile(const std::string &filePath);

        void createGraphicsPipeline(
                const std::string &vertFilepath,
                const std::string &fragFilepath,
                const PipelineConfigInfo &configInfo
        );

        void createShaderModule(const std::vector<char> &code, VkShaderModule *shaderModule);

        LveDevice &lveDevice;
        VkPipeline graphicsPipeline;
        VkShaderModule vertShaderModule;
        VkShaderModule fragShaderModule;
    };
}