add_rules("mode.debug", "mode.release")

if is_mode("debug") then
    add_defines("DEBUG")
    set_optimize("none")
elseif is_mode("release") then
    add_defines("NDEBUG")
    set_optimize(fastest)
end

add_requires("glfw", "glm")
add_requires( "vulkan-validationlayers","vulkan-headers", "vulkan-loader", "vulkan-tools")
add_requires("glslang")


target("LveEngine")
    set_kind("binary")
    add_files("src/*.cpp")
    add_files("shaders/*.vert", "shaders/*.frag")
    add_packages("glfw", "glm" , "glslang")
    add_packages("vulkan-validationlayers","vulkan-headers", "vulkan-loader", "vulkan-tools")
    add_rules("utils.glsl2spv", {outputdir = "$(buildir)/$(os)/x86_64/release/shaders"})
    add_rules("utils.glsl2spv", {outputdir = "$(buildir)/$(os)/x86_64/debug/shaders"})
target_end()