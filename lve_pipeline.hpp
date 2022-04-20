#pragma once

#include "lve_device.hpp"
#include "lve_model.hpp"

#include <string>
#include <vector>

namespace lve {
    struct PipelineConfigInfo {
        PipelineConfigInfo() = default;
        PipelineConfigInfo(const PipelineConfigInfo&) = delete;
        PipelineConfigInfo& operator=(const PipelineConfigInfo&) = delete;

        VkPipelineViewportStateCreateInfo viewportInfo;
        VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
        VkPipelineRasterizationStateCreateInfo rasterizationInfo;
        VkPipelineMultisampleStateCreateInfo multisampleInfo;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
        VkPipelineColorBlendStateCreateInfo colorBlendInfo;
        VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
        VkPipelineLayout pipelineLayout = nullptr;
        VkRenderPass renderPass = nullptr;
        uint32_t subpass = 0;
        std::vector<VkDynamicState> dynamicStateEnables;
        VkPipelineDynamicStateCreateInfo dynamicStateInfo;
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
        LvePipeline& operator=(const LvePipeline &) = delete;

        static void defaultPipelineConfigInfo(PipelineConfigInfo &configInfo);

        void bind(VkCommandBuffer commandBuffer);

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