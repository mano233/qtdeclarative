%modules = ( # path to module name map
    "QtQml" => "$basedir/src/qml",
    "QtQuick" => "$basedir/src/quick",
    "QtQuickShapes" => "$basedir/src/quickshapes",
    "QtQuickWidgets" => "$basedir/src/quickwidgets",
    "QtQuickParticles" => "$basedir/src/particles",
    "QtQuickTest" => "$basedir/src/qmltest",
    "QtPacketProtocol" => "$basedir/src/plugins/qmltooling/packetprotocol",
    "QtQmlDebug" => "$basedir/src/qmldebug",
    "QtQmlModels" => "$basedir/src/qmlmodels",
    "QtQmlWorkerScript" => "$basedir/src/qmlworkerscript",
    "QtQmlCompiler" => "$basedir/src/qmlcompiler",
    "QtQmlDom" => "$basedir/src/qmldom",
    "QtQuickLayouts" => "$basedir/src/quicklayouts",
    "QtQmlLocalStorage" => "$basedir/src/qmllocalstorage",
    "QtLabsSettings" => "$basedir/src/labs/settings"
);
%inject_headers = (
    "$basedir/src/qml" => [ "^qqmljsgrammar_p.h", "^qqmljsparser_p.h", "^qml_compile_hash_p.h" ],
);
