//
//  SpriteRender.cpp
//  OpenSipmleGame
//
//  Created by yujunzhen on 2018/8/16.
//  Copyright © 2018年 yujunzhen. All rights reserved.
//

#include "SpriteRender.h"
SpriteRender::SpriteRender(Shader shader)
{
    this->shader = shader;
    this->initRenderData();
}

SpriteRender::~SpriteRender()
{
    glDeleteVertexArrays(1, &this->quedVao);
}

void SpriteRender::DrawSprite(Texture2D &texture, glm::vec2 position, glm::vec2 size, GLfloat rotate, glm::vec3 color)
{
    // Prepare transformations
    this->shader.use();
//    glm::mat4 model;
//    model = glm::translate(model, glm::vec3(position, 0.0f));  // First translate (transformations are: scale happens first, then rotation and then finall translation happens; reversed order)
//    
//    model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f)); // Move origin of rotation to center of quad
//    model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f)); // Then rotate
//    model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f)); // Move origin back
//    
//    model = glm::scale(model, glm::vec3(size, 1.0f)); // Last scale
//    
//    this->shader.SetMatrix4("model", model);
//    
//    // Render textured quad
//    this->shader.SetVector3f("spriteColor", color);
//    
//    glActiveTexture(GL_TEXTURE0);
//    texture.Bind();
    GLuint VBO;
    GLfloat vertices[] = {
        // Pos      // Tex
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };
    
    glGenVertexArrays(1, &this->quedVao);
     glBindVertexArray(this->quedVao);
    glGenBuffers(1, &VBO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
   
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
  
  
    glBindVertexArray(this->quedVao);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}

void SpriteRender::initRenderData()
{
    // Configure VAO/VBO
//    GLuint VBO;
//    GLfloat vertices[] = {
//        // Pos      // Tex
//        0.0f, 1.0f, 0.0f, 1.0f,
//        1.0f, 0.0f, 1.0f, 0.0f,
//        0.0f, 0.0f, 0.0f, 0.0f,
//
//        0.0f, 1.0f, 0.0f, 1.0f,
//        1.0f, 1.0f, 1.0f, 1.0f,
//        1.0f, 0.0f, 1.0f, 0.0f
//    };
//
//    glGenVertexArrays(1, &this->quedVao);
//    glGenBuffers(1, &VBO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    glBindVertexArray(this->quedVao);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
}
