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

**2020-11-08 P1**
1. 仿写 ui 中的工程管理器 (QTreeView) 初始化。

**2020-11-07 P2**
1. 仿写 QTreeView ，了解 model/view 的操作。
- QTreeView 默认有一个 header 标头。 （其实是其 Model (QStandardItemModel) 有一个默认标头？）
  - 可以使用其 Model 的 setHorizontalHeaderLabels(const QStringList &labels) 来更改标头文本。
  - pTreeViewProjectModel->setHorizontalHeaderLabels(QStringList() << "xyz");
  - setHeaderData 什么作用？用不来？
- QTreeView 添加项，是添加为其标头的子项。
  - 原项目使用隐藏标头，使得子项显示效果为顶层。
- 使用 QStandardItem 来构造项。
  - 项的 appendRow(QStandardItem *aitem) 是将 aitem 作为该项的子项来添加。
  - 项文本默认是可编辑的。

**2020-11-07 P1**
1. 仿写上下文菜单 (QMenu) 的右键显示。
- new 出来的 QMenu ，后续如果没有主动释放，将一直保存在程序中。当其指定的父窗口销毁时，所有 new 出来的 QMenu 会自动随父窗口一起销毁。
- QAction 对应得槽函数暂未实现。

**2020-11-06 P1**
1. 不仿写：
- 原项目封装了 void enableToolBar(QString text);  来使用 void QWidget::setEnabled(bool) 函数控制启用（亮）/禁用（灰）工具栏。
- 原项目使用了 setContextMenuPolicy(Qt::DefaultContextMenu); 来启用 void MainWindow::contextMenuEvent(QContextMenuEvent *event) 事件处理。其实默认（ Qt::DefaultContextMenu ）是启用的。
2. 可以添加多个工具栏 (QToolBar) 。
3. Non-portable path to file ”ui_XXX.h“?
- 将头文件大小写改为与自动生成的 ui 头文件一致。

**2020-11-05 P1**
1. qt designer 的“编辑动作”窗口中 icon theme 可能只是针对类unix系统的。
- setThemeSearchPaths()
- themeSearchPaths()
- setThemeName()
- themeName()
- fromTheme()
- Note: By default, only X11 will support themed icons. In order to use themed icons on Mac and Windows, you will have to bundle a compliant theme in one of your themeSearchPaths() and set the appropriate themeName().

**2020-10-29 P1**
1. 原 HmiFuncDesigner 项目 main 文件中使用的 QtSingleApplication 、 QTextCodec 、 QFont 、 PluginManager 都暂不仿写。
2. 与原项目文件名大小写保持一致。
3. 将 MainWindow.ui 移植过来。
4. 创建 images.qrc 并将 images 文件夹和图片资源移植过来。
5. 测试 QMenu 中 QAction 的 toolTip 显示：
- QMenu 的 toolTipsVisible 是影响菜单上的各个子项，即 QAction 的 toolTip 的显示。
- Qt Creator 设计器中添加 QAction 时，toolTip 会默认填入值，但这时该值并不会生效。需要手动再去点击一下该属性或者修改内容，在保存使其生效。
  - 也即，猜想是各控件的 toolTip 都需要点击或者修改来激活。
- 鼠标位于  QAction 上时，如果勾选了 toolTipsVisible ，则显示 QAction 的 toolTip ；否则显示 QMenu 的 toolTip <即 QWidget 的 toolTip >，如果有的话。
  - 也即，猜想是当勾选了 toolTipsVisible 时， QAction 的 toolTip 优先于  QMenu 的 toolTip 。
- 鼠标位于 QMenu 中非任何  QAction 上时，无论是否勾选了 toolTipsVisible 都显示 QMenu 的 toolTip ，如果有的话。
  - 也即，猜想是鼠标当前实际是定位到 QMenu 上的。
- 不太好的地方：当鼠标已经从 QAction 移动到另一个没有设置 toolTip 的 QAction 上是，前一个 QAction 显示的 toolTip 并不能马上消失。
- 不太好的地方： QAction 的 toolTip 一旦激活就必须输入内容。只能输入空格来模拟无内容。此时不会显示空白提示框，当然也没能让前一个 toolTip 马上消失。

**2020-10-28 P2**
1. 按 HmiFuncDesigner 的工程目录结构，重新创建子目录项目及 Widget 项目 ProjectManager 。

**2020-10-28 P1**
1. 根据 HmiFuncDesigner 进行学习仿写。
- 新建 HmiFuncDesigner 的仿品项目，类型是 子目录项目。

**2020-10-27 P1**
1. Qt-studentmanager 项目的了解学习认为完成。
- 主要是数据库连接调用。部分数据库连接未更改。
- 一些控件的使用。
- 如何仿写一个项目的体会。

**2020-10-16 P1**
1. 根据 Qt-studentmanager 进行学习仿写。
- 新建 Qt-studentmanager 的仿品项目。
- Qt-studentmanager ： https://github.com/chenyongzhe/Qt-studentmanager (chenyongzhe/Qt-studentmanager)

**2020-10-15 P1**
1. 类（无论是否在命名空间中）在用于对象实例定义时（无论是否是 new 形式，即无论栈中分配还是堆中分配），都需要有该类的完整定义。否则编译不过。
- IDE 的编辑状态下的自动智能提示，会提示报错。 QTCreator 中纯 cpp 项目下是这样。
- 但在 QTCreator 中，在新建 Widget 项目但还未编译出 ui_*.h 文件时却不会提示报错。编译后删除  ui_*.h 文件，会报此错误。猜测是 QTCreator 做了一定的辅助优化工作。
- 仅用于对象（变量）声明，可只需要有该类前置声明。
2. 从 Widget 项目拷贝源文件到纯 cpp 项目，进行裁剪后，也同样提示： error: invalid use of incomplete type 'class Ui::MainWindow'

**2020-10-14 P2**
1. 示例 Log In UI 学习猜想。
- 使用时间线，同时需要为时间线设置动画。时间线动画生效必须与某些操作关联（如状态变更），才能触发动画效果。
- 设置时间线 > 设置动画 > 设置动画详情（属性变化） > 将时间线动画绑定到状态 > 将状态绑定到按钮点击动作。
- 程序启动时使用基本状态（ base state ）进行直接显示。此时应该是没有任何动画效果。处于基本状态，效果同登录状态。
- 点击 创建账户 时，触发状态变更，同时触发动画。动画完成后，处于注册状态。
- 点击 返回 时，有触发状态变更，同时触发动画。动画完成后，处于登录状态。
- 后续就维持在这两个状态之间变更。
- 在注册状态下，重复点击 创建账户 时，不会再触发动画效果。 交互上这样应该是正确的。

**2020-10-14 P1**
1. 为验证密码字段的顶部锚点边距设置动画。
2. 向锚点边距动画添加一个缓动曲线（ easing curve ），使过渡看起来更平滑。
3. 添加状态（ states ）并将状态绑定到时间轴中的动画设置。
4. Log In UI - Part 4 学习完成。

**2020-10-13 P1**
1. 删除之前创建的状态( states )，并删除列定位器同时重新锚定文本字段到登录页（新父项）。
- 开始 Log In UI - Part 4 ，说明如何使用时间线和状态( timeline and states )为 UI 组件设置动画。
2. 添加时间线及动画设置。
3. 在时间轴中插入关键帧并记录属性更改。

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
