#include "axis.hpp"

Axis::Axis(): shader("axis.vert", "axis.frag"), model(glm::mat4(1.0f)) {
    float vertices[] =  {
        
        //  positions                //  colours
        // x
         1000.0f,      0.0f,     0.0f,  1.0f, 0.0f, 0.0f,
        -1000.0f,      0.0f,     0.0f,  1.0f, 0.0f, 0.0f,
            0.0f,   1000.0f,     0.0f,  0.0f, 1.0f, 0.0f,
            0.0f,  -1000.0f,     0.0f,  0.0f, 1.0f, 0.0f,
            0.0f,      0.0f,  1000.0f,  0.0f, 0.0f, 1.0f,
            0.0f,      0.0f, -1000.0f,  0.0f, 0.0f, 1.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindVertexArray(VAO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void Axis::render(glm::mat4 projection, glm::mat4 view) {
    shader.use();
    shader.setMat4("projection", projection);
    shader.setMat4("view", view);
    shader.setMat4("model", model);

    glBindVertexArray(VAO);
    glDrawArrays(GL_LINES, 0, 6);
}