import QtQuick 2.12
import loginui1 1.0

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    Text {
        text: qsTr("Hello loginui1")
        anchors.centerIn: parent
        font.family: Constants.font.family
    }
}
