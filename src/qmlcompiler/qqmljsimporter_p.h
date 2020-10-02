/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the tools applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QQMLJSIMPORTER_P_H
#define QQMLJSIMPORTER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.

#include "qqmljsscope_p.h"
#include <QtQml/private/qqmldirparser_p.h>

class QQmlJSImporter
{
public:
    using ImportedTypes = QHash<QString, QQmlJSScope::ConstPtr>;

    QQmlJSImporter(const QStringList &importPaths) : m_importPaths(importPaths) {}

    ImportedTypes importBuiltins();
    ImportedTypes importQmltypes(const QStringList &qmltypesFiles);
    ImportedTypes importFileOrDirectory(
            const QString &fileOrDirectory, const QString &prefix = QString());
    ImportedTypes importModule(
            const QString &module, const QString &prefix = QString(),
            QTypeRevision version = QTypeRevision());

    QStringList takeWarnings()
    {
        QStringList result = std::move(m_warnings);
        m_warnings.clear();
        return result;
    }

private:
    struct AvailableTypes
    {
        // C++ names used in qmltypes files for non-composite types
        QHash<QString, QQmlJSScope::ConstPtr> cppNames;

        // Names the importing component sees, including any prefixes
        QHash<QString, QQmlJSScope::ConstPtr> qmlNames;
    };

    struct Import {
        QHash<QString, QQmlJSScope::Ptr> objects;
        QHash<QString, QQmlJSScope::Ptr> scripts;
        QList<QQmlDirParser::Import> imports;
        QList<QQmlDirParser::Import> dependencies;
    };

    void importHelper(const QString &module, AvailableTypes *types,
                      const QString &prefix = QString(),
                      QTypeRevision version = QTypeRevision());
    void processImport(const Import &import, AvailableTypes *types,
                       const QString &prefix = QString());
    void importDependencies(const QQmlJSImporter::Import &import,
                            AvailableTypes *types,
                            const QString &prefix = QString(),
                            QTypeRevision version = QTypeRevision());
    void readQmltypes(const QString &filename, QHash<QString, QQmlJSScope::Ptr> *objects);
    Import readQmldir(const QString &dirname);
    QQmlJSScope::Ptr localFile2ScopeTree(const QString &filePath);

    QStringList m_importPaths;
    QHash<QPair<QString, QTypeRevision>, Import> m_seenImports;
    QHash<QString, QQmlJSScope::Ptr> m_importedFiles;
    QStringList m_warnings;
};

#endif // QQMLJSIMPORTER_P_H