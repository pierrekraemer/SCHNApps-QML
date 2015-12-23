
import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

GroupBox {
    anchors.fill: parent
    anchors.margins: 10

    ColumnLayout {
        anchors.fill: parent
        spacing: 5

        Text {
            text: "Map list"
            font.bold: true
            Layout.fillWidth: true
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            border.width: 1
            border.color: "black"

            ScrollView {
                anchors.fill: parent

                ListView {
                    width: parent.width
                    height: parent.height

                    model: schnapps.map_list
                    focus: true

                    highlight: Component {
                        Rectangle {
                            anchors.right: parent.right
                            anchors.left: parent.left
                            color: "lightsteelblue"
                            border.width: 1
                            border.color: "black"
                        }
                    }

                    delegate: Component {
                        Rectangle {
                            id: map_list_view_delegate

                            anchors.right: parent.right
                            anchors.left: parent.left
                            height: 30
                            color: "transparent"

                            MouseArea{
                                anchors.fill: parent
                                onClicked: {
                                    map_list_view_delegate.ListView.view.currentIndex = index;
                                }
                            }

                            Text {
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.left: parent.left
                                anchors.leftMargin: 3
                                text: name + " (" + dimension + "D)"
                            }
                        }
                    }
                }
            }
        }

        Text {
            text: "Map properties"
            font.bold: true
            Layout.fillWidth: true
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            border.width: 1
            border.color: "black"
        }
    }
}
