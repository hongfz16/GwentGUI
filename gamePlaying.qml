import QtQuick 2.0
import QtQuick.Window 2.2
import Gwent.GameController 1.0

Window {
    id: mainWindow
    visible: true
    width: 1920
    height: 1080
    gameController {


    }

    Image {
        id: background
        width: mainWindow.width
        height: mainWindow.height
        fillMode: Image.Stretch
        smooth: true
        source: 'img/background/gamePlayingBackground.jpg'
    }
    ListView {
        width: 1000
        height: 100
        orientation: ListView.Horizontal
        model: myHandCard
        delegate: Rectangle {
            height: 100
            width: 25
            Text {
                text: name
            }
            MouseArea {
                anchors.fill: parent
                onClicked: gc.addMyHandCard
            }
        }
    }
}
