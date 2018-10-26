import QtQuick 2.0
import "Controls"

Rectangle {
    width: 600
    height: 480
    color: "#c4c4c4"

    Text {        
        x: 94
        y: 183
        text: "Source Text"
        anchors.verticalCenterOffset: -50
        anchors.horizontalCenterOffset: -172
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 12
    }

    TextBox {
        id: sourceTbx
        x: 201
        y: 176
        width: 348
        height: 27;
        anchors.verticalCenterOffset: -50
        anchors.horizontalCenterOffset: 75
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: model.sourceValue
        Binding { target: model; property: "sourceValue"; value: sourceTbx.text }
    }

    Text {
        x: 94
        y: 283
        text: "Destination Text"
        anchors.verticalCenterOffset: 50
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenterOffset: -161
        anchors.horizontalCenter: parent.horizontalCenter
        font.pixelSize: 12
    }

    TextBox {
        id: destinationTbx
        x: 200
        y: 277
        width: 348
        height: 27;
        anchors.verticalCenterOffset: 50
        anchors.horizontalCenterOffset: 75
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: model.destinationValue        
    }

    Button {
        x: 244
        y: 361
        width: 113
        height: 37
        anchors.verticalCenterOffset: 140
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        onClick: model.clearCommand()
    }
}
