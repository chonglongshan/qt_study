import QtQuick 2.12
import loginui1 1.0
import QtQuick.Controls 2.15
import QtQuick.Timeline 1.0

Rectangle {
    id: root
    width: Constants.width
    height: Constants.height

    Rectangle {
        id: loginPage
        color: "#ffffff"
        anchors.fill: parent

        Image {
            id: logo
            width: 100
            height: 100
            anchors.left: parent.left
            anchors.top: parent.top
            source: "qt_logo_green_64x64px.png"
            anchors.leftMargin: 10
            anchors.topMargin: 10
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: pageTitle
            x: 241
            text: qsTr("Qt Account")
            anchors.top: parent.top
            anchors.topMargin: 70
            anchors.horizontalCenter: parent.horizontalCenter
            font.pointSize: 24
            font.family: Constants.font.family
        }

        TextField {
            id: verifyPasswordField
            x: 170
            width: 300
            anchors.top: passwordField.bottom
            anchors.horizontalCenter: passwordField.horizontalCenter
            anchors.topMargin: 5
            placeholderText: qsTr("Verify password")
        }

        TextField {
            id: passwordField
            x: 170
            width: 300
            anchors.top: usernameField.bottom
            anchors.horizontalCenter: usernameField.horizontalCenter
            anchors.topMargin: 5
            placeholderText: qsTr("Password")
        }

        TextField {
            id: usernameField
            x: 170
            width: 300
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 200
            placeholderText: qsTr("Username")
        }

        Column {
            id: buttonColumn
            x: 259
            y: 288
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 50
            spacing: 5

            PushButton {
                id: loginButton
                width: 120
                height: 45
                text: qsTr("Log In")
            }

            PushButton {
                id: registerButton
                width: 120
                height: 45
                text: "Create Account"

                Connections {
                    target: registerButton
                    onClicked: root.state = "registerState"
                }
            }
        }

        PushButton {
            id: backButton
            x: 118
            width: 40
            text: "<"
            anchors.right: parent.right
            anchors.top: parent.top
            textItemFontpointSize: 24
            anchors.rightMargin: 10
            anchors.topMargin: 20

            Connections {
                target: backButton
                onClicked: root.state = "loginState"
            }
        }
    }

    Timeline {
        id: timeline
        animations: [
            TimelineAnimation {
                id: toLoginState
                running: false
                duration: 1000
                loops: 1
                to: 1000
                from: 0
            },
            TimelineAnimation {
                id: toRegisterState
                running: false
                duration: 1000
                loops: 1
                to: 0
                from: 1000
            }
        ]
        endFrame: 1000
        enabled: true
        startFrame: 0

        KeyframeGroup {
            target: backButton
            property: "opacity"
            Keyframe {
                frame: 0
                value: 0
            }

            Keyframe {
                frame: 1000
                value: 1
            }
        }

        KeyframeGroup {
            target: verifyPasswordField
            property: "opacity"
            Keyframe {
                frame: 1000
                value: 1
            }

            Keyframe {
                frame: 0
                value: 0
            }
        }

        KeyframeGroup {
            target: loginButton
            property: "opacity"
            Keyframe {
                frame: 1000
                value: 0
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.100000023841858}D{i:4}D{i:5}D{i:6}D{i:8}D{i:11}D{i:13}
}
##^##*/

