#pragma once
#include <string>
#include <vector>
#include "Texture.h"

class SkyBox
{
public:
    
    unsigned int textureID;
    unsigned int loadCubemap(std::vector<std::string> faces);
    void Render();
    void Bind();

    int width, height, nrChannels;
    unsigned char* data;
    

private:

    std::vector<std::string> faces
    {
        "right.jpg",
            "left.jpg",
            "top.jpg",
            "bottom.jpg",
            "front.jpg",
            "back.jpg"
    };

    Texture* texture =new Texture(faces);
    
};

