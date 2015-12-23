
import QtQuick 2.3
import QtQuick.Controls 1.2

Menu {
    title: "Surface Import"
    MenuItem {
        text: "Import mesh"
        onTriggered: schnapps.plugin().import_mesh()
    }
}
