
import QtQuick 2.3
import QtQuick.Layouts 1.1

import schnapps 1.0

Rectangle {

    color: "white"

    ListView {
        id: map_list_view
        height: 500
        model: schnapps.map_list
        delegate: Rectangle {
            Text { text: "Name: " + name }
        }
    }

}
