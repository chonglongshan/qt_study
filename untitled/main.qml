//import QtQuick 2.12
//import QtQuick.Window 2.12

//Window {
//    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Hello World")

////    Rectangle {
////        width: 100; height: 100
////        color: "red"

////        NumberAnimation on x { to: 50; duration: 1000 }
////    }

//}


//Item {
//    id: container
//    width: 520
//    height: 120

//    Rectangle {
//        id: rect
//        color: "red"
//        width: 120
//        height: 120

//        TapHandler {
//            onTapped: container.state === '' ? container.state = 'other' : container.state = ''
//        }
//    }
//    states: [
//        // This adds a second state to the container where the rectangle is farther to the right

//        State { name: "other"

//            PropertyChanges {
//                target: rect
//                x: 400
//            }
//        }
//    ]
//    transitions: [
//        // This adds a transition that defaults to applying to all state changes

//        Transition {

//            // This applies a default NumberAnimation to any changes a state change makes to x or y properties
//            NumberAnimation { properties: "x,y" }
//        }
//    ]
//}

//Item {
//    width: 320
//    height: 120

//    Rectangle {
//        color: "green"
//        width: 120
//        height: 120

//        // This is the behavior, and it applies a NumberAnimation to any attempt to set the x property
//        Behavior on x {

//            NumberAnimation {
//                //This specifies how long the animation takes
//                duration: 600
//                //This selects an easing curve to interpolate with, the default is Easing.Linear
//                easing.type: Easing.OutBounce
//            }
//        }

//        TapHandler {
//            onTapped: parent.x == 0 ? parent.x = 200 : parent.x = 0
//        }
//    }
//}

//Item {
//    width: 320
//    height: 120

//    Rectangle {
//        color: "blue"
//        width: 120
//        height: 120

//        // By setting this SequentialAnimation on x, it and animations within it will automatically animate
//        // the x property of this element
//        SequentialAnimation on x {
//            id: xAnim
//            // Animations on properties start running by default
//            running: false
//            loops: Animation.Infinite // The animation is set to loop indefinitely
//            NumberAnimation { from: 0; to: 200; duration: 500; easing.type: Easing.InOutQuad }
//            NumberAnimation { from: 200; to: 0; duration: 500; easing.type: Easing.InOutQuad }
//            PauseAnimation { duration: 2500 } // This puts a bit of time between the loop
//        }

//        TapHandler {
//            // The animation starts running when you click within the rectangle
//            onTapped: xAnim.running = true
//        }
//    }
//}


//Item {
//    width: 320
//    height: 120

//    Rectangle {
//        id: rectangle
//        color: "yellow"
//        width: 120
//        height: 120

//        TapHandler {
//            // The animation starts running when you click within the rectange
//            onTapped: anim.running = true;
//        }
//    }

//    // This animation specifically targets the Rectangle's properties to animate
//    SequentialAnimation {
//        id: anim
//        // Animations on their own are not running by default
//        // The default number of loops is one, restart the animation to see it again

//        NumberAnimation { target: rectangle; property: "x"; from: 0; to: 200; duration: 500 }

//        NumberAnimation { target: rectangle; property: "x"; from: 200; to: 0; duration: 500 }
//    }
//}


//import QtQuick 2.3

//Item {
//    id: root
//    width: 480
//    height: 320

//    Rectangle {
//        color: "#272822"
//        width: 480
//        height: 320
//    }

//    Column {
//        spacing: 20

//        Text {
//            text: 'I am the very model of a modern major general!'

//            // color can be set on the entire element with this property
//            color: "yellow"

//        }

//        Text {
//            // For text to wrap, a width has to be explicitly provided
//            width: root.width

//            // This setting makes the text wrap at word boundaries when it goes
//            // past the width of the Text object
//            wrapMode: Text.WordWrap

//            // You can use \ to escape quotation marks, or to add new lines (\n).
//            //  Use \\ to get a \ in the string
//            text: 'I am the very model of a modern major general. I\'ve information \
//                  vegetable, animal and mineral. I know the kings of england and I \
//                  quote the fights historical; from Marathon to Waterloo in order categorical.'

//            // color can be set on the entire element with this property
//            color: "white"

//        }

//        Text {
//            text: 'I am the very model of a modern major general!'

//            // color can be set on the entire element with this property
//            color: "yellow"

//            // font properties can be set effciently on the whole string at once
//            font { family: 'Courier'; pixelSize: 20; italic: true; capitalization: Font.SmallCaps }

//        }

//        Text {
//            // HTML like markup can also be used
//            text: '<font color="white">I am the <b>very</b> model of a modern <i>major general</i>!</font>'

//            // This could also be written font { pointSize: 14 }. Both syntaxes are valid.
//            font.pointSize: 14

//            // StyledText format supports fewer tags, but is more efficient than RichText
//            textFormat: Text.StyledText
//        }
//    }
//}


//import QtQuick 2.3

//Item {
//    width: 200; height: 200

//    Rectangle {
//        // Anchored to 20px off the top right corner of the parent
//        anchors.right: parent.right
//        anchors.top: parent.top
//        //anchors.margins: 20 // Sets all margins at once

//        width: 80
//        height: 80
//        color: "orange"
//    }

//    Rectangle {
//        // Anchored to 20px off the top center corner of the parent.
//        // Notice the different group property syntax for 'anchors' compared to
//        // the previous Rectangle. Both are valid.
//        anchors { horizontalCenter: parent.horizontalCenter; top: parent.top; topMargin: 20 }

//        width: 80
//        height: 80
//        color: "green"
//    }
//}

//import QtQuick 2.3

//Item {
//    width: 300; height: 100

//    Row { // The "Row" type lays out its child items in a horizontal line
//        spacing: 20 // Places 20px of space between items

//        Rectangle { width: 80; height: 80; color: "red" }
//        Rectangle { width: 80; height: 80; color: "green" }
//        Rectangle { width: 80; height: 80; color: "blue" }
//    }
//}

//import QtQuick 2.12
//import QtQuick.Controls 1.4
//import QtQuick.Controls.Styles 1.4


//Button {
//    text: qsTr("Hello World")
//    style: ButtonStyle {
//        background: Rectangle {
//            implicitWidth: 100
//            implicitHeight: 25
//            border.width: control.activeFocus ? 2 : 1
//            border.color: "#FFF"
//            radius: 4
//            gradient: Gradient {
//                GradientStop { position: 0 ; color: control.pressed ? "#ccc" : "#fff" }
//                GradientStop { position: 1 ; color: control.pressed ? "#000" : "#fff" }
//            }
//        }
//   }
//}

//import QtQuick 2.12

//Item {
//    id: container
//    width: 320
//    height: 480

//    function randomNumber() {
//        return Math.random() * 360;
//    }

//    function getNumber() {
//        return container.randomNumber();
//    }

//    TapHandler {
//        // This line uses the JS function from the item
//        onTapped: rectangle.rotation = container.getNumber();
//    }

//    Rectangle {
//        color: "#272822"
//        width: 320
//        height: 480
//    }

//    Rectangle {
//        id: rectangle
//        anchors.centerIn: parent
//        width: 160
//        height: 160
//        color: "green"
//        Behavior on rotation { RotationAnimation { direction: RotationAnimation.Clockwise } }

//        //antialiasing: true
//    }

//}


//import QtQuick 2.12
//import "myscript.js" as Logic

//Item {
//    width: 320
//    height: 480

//    Rectangle {
//        color: "#272822"
//        width: 320
//        height: 480
//    }

//    TapHandler {
//        // This line uses the JS function from the separate JS file
//        onTapped: rectangle.rotation = Logic.getRandom(rectangle.rotation);
//    }

//    Rectangle {
//        id: rectangle
//        anchors.centerIn: parent
//        width: 160
//        height: 160
//        color: "green"
//        Behavior on rotation { RotationAnimation { direction: RotationAnimation.Clockwise } }
//    }

//}


import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12


ApplicationWindow {
    id: root
    visible: true
    width: 480
    height: 620

    GridLayout {
        anchors.fill: parent
        anchors.margins: 20
        rowSpacing: 20
        columnSpacing: 20
        flow:  width > height ? GridLayout.LeftToRight : GridLayout.TopToBottom
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#5d5b59"
            Label {
                anchors.centerIn: parent
                text: "Top or left"
                color: "white"
            }
        }
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "#1e1b18"
            Label {
                anchors.centerIn: parent
                text: "Bottom or right"
                color: "white"
            }
        }
    }
}
