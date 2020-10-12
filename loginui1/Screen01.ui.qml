import QtQuick 2.12
import loginui1 1.0

Rectangle {
    width: Constants.width
    height: Constants.height

    Text {
        id: pageTitle
        text: qsTr("Qt Account")
        font.pointSize: 24
        anchors.centerIn: parent
        font.family: Constants.font.family
    }

    Image {
        id: logo
        x: 8
        y: 8
        width: 100
        height: 100
        source: "qt_logo_green_64x64px.png"
        fillMode: Image.PreserveAspectFit
    }

    PushButton {
        id: loginButton
        x: 259
        y: 288
        width: 120
        height: 45
        text: qsTr("Log In")
    }

    PushButton {
        id: registerButton
        x: 260
        y: 357
        width: 120
        height: 45
        text: "Create Account"
    }
}
