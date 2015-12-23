
import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.1

GroupBox {
    anchors.fill: parent
    anchors.margins: 10

    ColumnLayout {
        anchors.fill: parent
        spacing: 5

        Button {
            text: "Add"
            Layout.fillWidth: true
            onClicked: schnapps.add_plugin();
        }

        Text {
            text: "Plugin list"
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

                    model: schnapps.plugin_list
                    focus: true

                    delegate: Component {
                        Rectangle {
                            anchors.right: parent.right
                            anchors.left: parent.left
                            height: 30
                            color: "transparent"

                            CheckBox {
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.left: parent.left
                                anchors.leftMargin: 3
                                text: name
                                checked: loaded
                                onClicked: {
                                    if (!loaded)
                                        schnapps.plugin(name).load()
                                    else
                                        schnapps.plugin(name).unload()
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
