import QtQuick 2.10
import QtQuick.Templates 2.1 as T
import loginui1 1.0

T.Button {
    id: control

    font: Constants.font
    implicitWidth: Math.max(
                       buttonBackground ? buttonBackground.implicitWidth : 0,
                       textItem.implicitWidth + leftPadding + rightPadding)
    implicitHeight: Math.max(
                        buttonBackground ? buttonBackground.implicitHeight : 0,
                        textItem.implicitHeight + topPadding + bottomPadding)
    leftPadding: 4
    rightPadding: 4

    text: "My Button"
    property alias textItemFontpointSize: textItem.font.pointSize

    background: buttonBackground
    Rectangle {
        id: buttonBackground
        color: "#41cd52"
        implicitWidth: 100
        implicitHeight: 40
        opacity: enabled ? 1 : 0.3
        border.color: "gray"
        border.width: 1
        radius: 2
    }

    contentItem: textItem
    Text {
        id: textItem
        text: control.text

        opacity: enabled ? 1.0 : 0.3
        color: "#ffffff"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    states: [
        State {
            name: "normal"
            when: !control.down
            PropertyChanges {
                target: buttonBackground
            }
        },
        State {
            name: "down"
            when: control.down
            PropertyChanges {
                target: textItem
                color: "#ffffff"
            }
            PropertyChanges {
                target: buttonBackground
                color: "#21be2b"
                border.color: "black"
            }
        }
    ]
}
