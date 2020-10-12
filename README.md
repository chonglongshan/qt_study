# qt_study
qt学习练手


```
**XXXX-XX-XX P1**
1. AAA
- aaa
- bbb
- ccc
2. BBB
- aaa
- bbb
```

**2020-10-12 P2**
1. 添加按钮 UI 到主 UI 界面。
- 向主界面添加两个自创的按钮实例并修改其id和文本标签。

**2020-10-12 P1**
1. 修改 PushButton 类型的属性。
- 主要是不同状态下按钮的背景和文本颜色。

**2020-10-10 P3**
1. 在 loginui1 项目中 Creating a Push Button 遇到的问题。
- 创建的 PushButton.qml 先是不能自动显示到项目视图中的文件结构内。在使用官方示例文件进行对比定位问题过程中有突然好了。后续再按指导文档操作有可以直接显示出来了。
- 再刚创建好  PushButton.qml 时 ，不能再设计模式中显示出来，报 “ loginui Line: 3: QML module not found (loginui1). ”。第三行是“ import loginui1 1.0 ”。
- 感觉是刚创建 PushButton.qml 时，设计器没有及时将文件加入项目，导致的报错。加入后就可以显示出来了。
- 官方示例，直接打开无法运行，报 “ module "QtQuick.Studio.Components" is not installed ” ，该行内容是” import QtQuick.Studio.Components 1.0 “。但将内容复制到学习项目就可以正常运行。
- 将学习项目下的 import 文件夹复制过去就可以正常运行了，初步感觉是这个文件夹内的内容有差异。

**2020-10-10 P2**
1. 调整 loginui1 的主界面。

**2020-10-10 P1**
1. 创建 loginui1 项目。
