
import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

import icube.igg.schnapps 1.0

ApplicationWindow {

    visible: true

    title: "SCHNApps"
    width: 1110
    height: 750

    menuBar: MenuBar {
        Menu {
            title: "File"
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
        Menu {
            title: "Plugins"
            Menu {
                title: "Surface import"
                MenuItem {
                    text: "Import mesh"
                    onTriggered: {
                        schnapps.plugin("libsurface_import_plugin_d").invoke("import_mesh");
                    }
                }
            }
        }
    }

    RowLayout {
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
                ControlTabPlugin {}
            }
        }

        View {
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

            Tab {
                title: "Plugin 1"
                Rectangle { color: Qt.rgba(0.3, 0, 0.7, 0.7) }
            }
        }
    }

    Component.onCompleted: {
        console.log("SCHNApps loaded");
        schnapps.print_status();
    }

}
