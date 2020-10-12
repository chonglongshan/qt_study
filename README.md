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

**2020-10-12 P5**
1. 再添加一些用于创建用户界面的 UI 组件。
- 开始 Log In UI - Part 3 ，说明如何使用状态( states )创建第二个 UI 页。
- 问题：在外部使用自定义 PushButton 更改 Font > Size 无效果？
  - 需要将自定义 PushButton 内的 Text 的 Font > Size 以属性别名的方式导出供外部直接设置。设计界面可直接生效。
  - 如果使用属性绑定  Font > Size ，则仅再运行时设置的值才生效。设计界面无法直观感受效果。
2. 根据页面的基本状态，添加其他状态（ state ），以显示和隐藏 UI 组件。
3. 将按钮（事件/信号）连接到状态。
- 有事件响应程序实现变更状态。
4. Log In UI - Part 3 学习完成。
- 下一个示例 Log In UI - Part 4 ，学习了解如何使用时间线为登录页和注册页面之间的过渡设置动画。

**2020-10-12 P4**
1. 主界面对几个 UI 元素使用锚点。
- 开始 Log In UI - Part 2 ，使用锚点和定位器在页面布局 UI 元素。
- 向 Form Editor 添加新矩形，并将所有当前 UI 组件移动到该矩形页面。然后，将静态元素锚定（ anchor ）在该页面上。
2. 使用定位器放置 UI 元素。
- 使用列定位器（ Column ）分组放置布局 UI 元素。
- 在主界面对列定位器进行锚定。
3. Log In UI - Part 2 学习完成。
- 下一个示例 Log In UI - Part 3 ，学习了解如何添加第二页并从主页移动到该页。

**2020-10-12 P3**
1. Log In UI - Part 1 学习完成。
- 下一教程 Log In UI - Part 2 ，学习了解如何添加更多 UI 控件并使用锚点和布局将其定位在页面上，以便 UI 可扩展。

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
