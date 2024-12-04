#pragma once
#include "../scene/Scene.hpp"
#include "Shader.hpp"
#include <memory>
#include <unordered_map>
#include <string>

class Renderer {
public:
    Renderer();
    ~Renderer();
    
    bool initialize();
    void shutdown();
    void beginFrame();
    void render(const Scene& scene);
    void endFrame();
    
    // Shader management
    std::shared_ptr<Shader> loadShader(const std::string& name, 
                                     const std::string& vertexPath, 
                                     const std::string& fragmentPath);
    std::shared_ptr<Shader> getShader(const std::string& name);

private:
    // Shader cache
    std::unordered_map<std::string, std::shared_ptr<Shader>> shaderCache;
    
    // Default shaders
    std::shared_ptr<Shader> defaultShader;
    
    void setupDefaultShaders();
};