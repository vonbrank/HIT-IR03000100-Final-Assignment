# HIT-IR03000100-Final-Assignment

<p align="center">
<img src="https://img.shields.io/badge/HIT-IR03000100-red" alt="HIT-IR03000100">
<img src="https://img.shields.io/badge/OpenGL-3.3-yellow" alt="OpenGL-3.3">
<a href="mailto:vonbrank@outlook.com"><img src="https://img.shields.io/badge/Email-vonbrank@outlook.com-blue?style=flat&logo=mail.cn" alt="Mail"></a>
</p>

哈工大《计算机图形学 · 自然景物模拟与分形艺术》2022春 - 课程大作业：《球体纹理映射与 Phong Shading》



## 使用

### 运行

如果不想或没有条件构建，直接运行 `.\bin\Sphere_Shading.exe` 即可.

### 功能

本次作业基本要求为：用 OpenGL 实现真实感小球的纹理贴图（鼠标可以控制其旋转），具体来说实现了：

+ 鼠标指针左右拖动可以转动球体.
+ 方向键 `↑` `↓` `←` `→` 可以控制摄像机绕球体旋转.
+ 按下 `L` 键可以切换线框与填充模式渲染.
+ 按下 `Esc` 键可以退出.

### 特性

+ 依据光源位置映射昼夜纹理.
+ 大气纹理自动移动.
+ 所有旋转动画均实现平滑过渡.

### 效果

![HIT-IR03000100-01](https://s2.loli.net/2022/04/10/zAxcfsvVumjM5XD.jpg)



## 构建指导

### Windows

#### 依赖项

+ OpenGL
+ GLFW
+ GLAD
+ OpenGL Mathematics (*GLM*)
+ stb_image 

所有依赖项应以下列目录结构布局，并置于项目顶层目录的 `.\lib` 文件夹内：

```bash
HIT-IR03000100-Final-Assignment
├── .git
├── .gitattributes
├── .gitignore
├── .idea
├── CMakeLists.txt
├── Images
├── README.md
├── bin
├── build
└── src
├── lib
    ├── bin
    │   └── libglfw3.a
    ├── cpp
    │   └── glad.c
    └── include
        ├── GLFW
        ├── KHR
        ├── glad
        ├── glm
        └── stb_image.h
```

#### 构建环境

+ x86_64-w64-mingw32
+ GNU Make (Built for i686-pc-mingw32)
+ CMake Windows (version 3.21.0+)

#### 开始构建

准备好上述环境并确认添加必要项至环境变量 `Path` 后：

+ 进入项目顶层目录，创建 `build\` 文件夹（如果未创建的话），并进入：

  ```powershell
  cd <Project-Directory>
  mkdir build
  cd .\build
  ```

+ 使用 CMake 配置项目:

  ```powershell
  cmake -G "MinGW Makefiles" ..
  ```

+ 使用 Make 构建项目：

  ```powershell
  mingw32-make
  ```

+ 运行构建结果：

  ```powershell
  .\Sphere_Shading.exe
  ```

+ 如果物体渲染为黑色，请尝试将 `.\Images` 复制至与 `Sphere_Shading.exe` 同一文件夹内后重试.

### Linux

N/A
