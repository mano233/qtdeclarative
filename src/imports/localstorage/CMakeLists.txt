# Generated from localstorage.pro.

#####################################################################
## qmllocalstorageplugin Plugin:
#####################################################################

qt_internal_add_qml_module(qmllocalstorageplugin
    URI "QtQuick.LocalStorage"
    VERSION "${CMAKE_PROJECT_VERSION}"
    CLASSNAME QQmlLocalStoragePlugin
    SKIP_TYPE_REGISTRATION
    PLUGIN_OPTIONAL
    SOURCES
        plugin.cpp
    PUBLIC_LIBRARIES
        Qt::Qml
        Qt::QmlLocalStoragePrivate
)

#### Keys ignored in scope 1:.:.:localstorage.pro:<TRUE>:
# CXX_MODULE = "qml"
# OTHER_FILES = "localstorage.json"
# QML_IMPORT_VERSION = "$$QT_VERSION"
# TARGETPATH = "QtQuick/LocalStorage"
