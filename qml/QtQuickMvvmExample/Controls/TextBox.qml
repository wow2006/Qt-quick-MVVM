import QtQuick 2.0

Item {
    id: textBox
    width: 200
    height: 20
    property alias text: textInput.text

    Rectangle {
        id: textLayout
        width: textBox.width
        height: textBox.height
        color: "#ffffff"
        radius: 2
        smooth: true
        border.color: "#000000"

        TextInput {
            id: textInput
            anchors.fill: parent
            font.pointSize: 14
            horizontalAlignment: TextInput.AlignLeft
        }
    }
}
