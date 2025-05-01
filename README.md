# Geometric Modeling Project (CS554)

This project is part of my coursework for CS554: Geometric Modeling. It focuses on 3D mesh analysis using C++ and OpenGL. The goal was to visualize and analyze 3D models stored in `.PLY` format using different geometric and topological methods.

## 📁 Project Structure
- `learnply.cpp`: Core rendering and visualization logic using OpenGL
- `.ply` files: 3D models including Bunny, Dragon, Feline, Icosahedron, and Happy Buddha
- `icMatrix`, `icVector`, `trackball`: Math and interaction support

## 🔍 Implemented Features

### Part 1: Mesh Coloring and Visualization
- ✅ **Display polygon ID coloring**
- ✅ **Vertex RGB coloring** based on `.PLY` input
- ✅ **3D checkerboard coloring** for triangles
- ✅ **Angle deficit computation** and **curvature-based coloring**
- ✅ **Triangle and vertex normal coloring**

### Part 2: Mesh Analysis
- ✅ **Corner list construction**
- ✅ **Euler characteristic calculation** (`χ = V - E + F`)
- ✅ **Gaussian curvature** via total angle deficit
- ✅ **Discrete curvature** using valence deficits
- ✅ **Topological genus (handles)**: `g = (2 - χ) / 2`

## ⚙️ Tools & Technologies
- **C++** for logic and computation
- **OpenGL (GLUT)** for rendering
- **.PLY** format for mesh input

## 📊 Models Used
- **Stanford Bunny**
- **Dragon**
- **Feline**
- **Icosahedron**
- **Happy Buddha**

## 💡 What I Learned
- Parsing and visualizing `.PLY` files
- Using OpenGL for interactive 3D graphics
- Computing topological invariants and curvature
- Debugging geometry-heavy programs and optimizing rendering pipelines

## 📌 My Takeaway
This project deepened my understanding of discrete differential geometry and how visual tools can reveal properties like curvature and genus. It strengthened my C++ and OpenGL skills and improved my intuition about surface properties and topology.

## 🧠 Instructor
Prof. Eugene Zhang | Oregon State University
