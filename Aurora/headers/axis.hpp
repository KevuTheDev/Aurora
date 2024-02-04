
#include <glad/glad.h>
#include <glm/glm.hpp>

#include "shader.hpp"


class Axis {

public:
    Axis();

    void render(glm::mat4 projection, glm::mat4 view);


private:
    float *vertices;
    glm::mat4 model;

    unsigned int VAO, VBO;
    
    Shader shader;
};