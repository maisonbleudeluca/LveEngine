#pragma once

#include "lve_device.hpp"
#include "vulkan/vulkan_core.h"
#include <cstdint>
#include <string>
#include <vector>
namespace lve {
struct PipelineConfigInfo {
  VkViewport viewport;
  VkRect2D scissor;
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
};

class LvePipeline {
public:
  LvePipeline(LveDevice &device, const std::string &vertFilepath,
              const std::string &fragFilepath,
              const PipelineConfigInfo &configInfo);

  ~LvePipeline(){};

  LvePipeline(const LvePipeline &) = delete;
  LvePipeline &operator=(const LvePipeline &) = delete;

  static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width,
                                                      uint32_t heigh);

private:
  static std::vector<char> readFile(const std::string &filepath);

  void createGraphicsPipeline(const std::string &vertFilePath,
                              const std::string &fragFilePath,
                              const PipelineConfigInfo &configInfo);

  void createShareModule(const std::vector<char> &code,
                         VkShaderModule shaderModule);

  LveDevice &lveDevice;
  VkPipeline graphicsPipeline;
  VkShaderModule vertShaderModule;
  VkShaderModule fragShaderModule;
};
} // namespace lve