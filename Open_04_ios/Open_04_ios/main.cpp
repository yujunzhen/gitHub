//
//  main.m
//  Open_04_ios
//
//  Created by yujunzhen on 2018/7/10.
//  Copyright © 2018年 yujunzhen. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "ogldev_math_3d.h"

#include <GLUT/GLUT.h>
GLuint VBO;
/* 渲染回调函数*/

static void RenderScenceCB(){
    glClear(GL_COLOR_BUFFER_BIT);//清空缓存器
    glEnableVertexAttribArray(0);//开启顶点属性
    glBindBuffer(GL_ARRAY_BUFFER,VBO);//绑定GL_ARRAY_BUFFER缓冲器
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);//告诉管线怎样解析buffer中的数据
    glDrawArrays(GL_TRIANGLES, 0, 3);//开始绘制图形
    glDisableVertexAttribArray(0);//禁用顶点数据
    glutSwapBuffers();//交换后缓存
    glFlush();
}
//static void RenderScenceCB(){
//    // 清空颜色缓存
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // 开启顶点属性
//    glEnableVertexAttribArray(0);
//    // 绑定GL_ARRAY_BUFFER缓冲器
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    // 告诉管线怎样解析bufer中的数据
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
//
//    // 开始绘制几何图形(绘制一个三角形，三个顶点)
//    glDrawArrays(GL_TRIANGLES, 0, 3);
//
//    //  禁用顶点数据
//    glDisableVertexAttribArray(0);
//
//    // 交换前后缓存
//    glutSwapBuffers();
//
//    glFlush();
//}
// 创建顶点缓冲器
static void CreateVertexBuffer(){
    //    Vector3f Vertices[1];
    //    Vertices[0] = Vector3f(0.5f, 0.0f, 0.0f);
    // 创建含有3个顶点的顶点数组
    Vector3f Vertices[3];
    // 三角形的三个顶点位置
    Vertices[0] = Vector3f(-0.5f, -0.5f, 0.0f);
    Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
    Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(Vertices),Vertices,GL_STATIC_DRAW);
}
int main(int argc,  char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("第二个窗户");
    glutDisplayFunc(RenderScenceCB);
    glClearColor(0.5f, 0.3f, 0.2f, 0.0f);
    
    GLenum res = glewInit();
    if (res != GLEW_OK) {
        return 1;
    }
    CreateVertexBuffer();
    glutMainLoop();
    
    
    return 0;
}

