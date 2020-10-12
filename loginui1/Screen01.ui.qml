import QtQuick 2.12
import loginui1 1.0
import QtQuick.Controls 2.15

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

        Column {
            id: fieldColumn
            x: 241
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 200
            spacing: 5

            TextField {
                id: usernameField
                width: 300
                placeholderText: qsTr("Username")
            }

            TextField {
                id: passwordField
                width: 300
                placeholderText: qsTr("Password")
            }

            TextField {
                id: verifyPasswordField
                width: 300
                placeholderText: qsTr("Verify password")
            }
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
        }
    }
}
