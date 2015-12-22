
import QtQuick 2.3
import QtQuick.Layouts 1.1

import schnapps 1.0

Rectangle {
    id: rectangle1

    color: "white"

    ListView {
        id: map_list_view
        height: 275
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        clip: false
        model: schnapps.map_list
        delegate: Text { text: "Name: " + name }
    }

}
