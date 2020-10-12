import QtQuick 2.12
import loginui1 1.0

Rectangle {
    id: root
    width: Constants.width
    height: Constants.height

    Rectangle {
        id: loginPage
        color: "#ffffff"
        anchors.fill: parent

        PushButton {
            id: registerButton
            x: 260
            y: 357
            width: 120
            height: 45
            text: "Create Account"
        }

        PushButton {
            id: loginButton
            x: 259
            y: 288
            width: 120
            height: 45
            text: qsTr("Log In")
        }

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
    }
}
