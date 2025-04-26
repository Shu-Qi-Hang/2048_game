# 🚀 2048 C++ 豪华版 · 重制革新

<div align="center">
  
[![GitHub Release](https://img.shields.io/github/v/release/Shu-Qi-Hang/2048_game?color=2A5CAA&style=for-the-badge&logo=github)](https://github.com/Shu-Qi-Hang/2048_game/releases)
[![License](https://img.shields.io/badge/License-MIT-blueviolet?style=for-the-badge&logo=opensourceinitiative)](https://github.com/Shu-Qi-Hang/2048_game/blob/main/LICENSE)
[![Windows Build](https://img.shields.io/badge/Windows_Executable-Download-0078D6?style=for-the-badge&logo=windows)](https://github.com/Shu-Qi-Hang/2048_game/releases/latest/download/2048.exe)

<img src="https://user-images.githubusercontent.com/xxxxx/xxxxxx.gif" width="650" alt="游戏演示动画">

</div>

---

## ✨ 核心特性

### 🏆 成就系统
- 初出茅庐 → 超越极限的成长之路
- 闪电战模式：50回合内挑战通关
- 隐藏成就「代码改造者」等你解锁

### 🧩 插件架构
- 双模块插件系统（输入/移动）
- 实时热加载技术
- [插件开发文档](docs/plugin_guide.md)

### 🚀 性能优化
- 毫秒级响应控制
- 多线程计算引擎
- 内存占用 < 10MB

---

## 📦 快速开始

### 环境要求
- MinGW-w64 8.1.0+
- Windows 7 或更高版本

### 编译运行
```bash
# 克隆仓库
git clone https://github.com/Shu-Qi-Hang/2048_game.git

# 编译项目
g++ 2048_new.cpp -o 2048.exe -static-libgcc -static-libstdc++ -O3

# 启动游戏
./2048.exe
