import QtQuick 2.0

Item {
    id: button
    width: 200
    height: 20
    signal click

    Rectangle {
        id: buttonLayout
        width: button.width
        height: button.height
        radius: 6
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#a8a8a8"
            }

            GradientStop {
                position: 1
                color: "#4f4f4f"
            }
        }
        smooth: true

        Text {
            id: text1
            x: 58
            y: 9
            text: qsTr("Clear text")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 12
        }

        MouseArea {
            anchors.fill: parent
            onClicked: click()
        }
    }
}
