
import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

import schnapps 1.0

ApplicationWindow {

    visible: true

    title: "SCHNApps"
    width: 1110
    height: 750

    SCHNApps {
      id: schnapps
    }

    menuBar: MenuBar {
        Menu {
            title: "File"
            MenuItem {
                text: "Open"
                onTriggered: schnapps.add_map("bla");
            }
            MenuItem {
                text: "Exit"
                onTriggered: Qt.quit();
            }
        }
        Menu {
            title: "View"
            MenuItem {
                text: (control_tab.visible ? "Hide " : "Show ") + "Control Tab"
                onTriggered: control_tab.visible = !control_tab.visible;
            }
            MenuItem {
                text: (plugin_tab.visible ? "Hide " : "Show ") + "Plugin Tab"
                onTriggered: plugin_tab.visible = !plugin_tab.visible;
            }
        }
    }

    RowLayout {
        id: main_layout
        anchors.fill: parent

        TabView {
            id: control_tab

            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth: 100
            Layout.preferredWidth: 250
            Layout.maximumWidth: 250

            Tab {
                title: "Cameras"
                Rectangle { color: Qt.rgba(1, 0, 0, 0.7) }
            }
            Tab {
                title: "Maps"
                ControlTabMap {}
            }
            Tab {
                title: "Plugins"
                Rectangle { color: Qt.rgba(0, 1, 0, 0.7) }
            }
        }

        View {
            id: view

            Layout.fillWidth: true
            Layout.fillHeight: true

            Text {
                anchors.centerIn: parent
                text: parent.width + 'x' + parent.height
                color: "red"
            }
        }

        TabView {
            id: plugin_tab

            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumWidth: 100
            Layout.preferredWidth: 250
            Layout.maximumWidth: 250
        }
    }

    Component.onCompleted: {
        console.log("SCHNApps loaded");
    }

}
