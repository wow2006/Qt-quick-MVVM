#include "qmlapplicationviewer.h"

#include <QApplication>
#include <QDir>
#include <QFileInfo>
#include <QQmlEngine>

#include <qplatformdefs.h> // MEEGO_EDITION_HARMATTAN

#ifdef HARMATTAN_BOOSTER
#include <MDeclarativeCache>
#endif

#if defined(QMLJSDEBUGGER) && QT_VERSION < 0x040800

#include <qt_private/qdeclarativedebughelper_p.h>

#if !defined(NO_JSDEBUGGER)
#include <jsdebuggeragent.h>
#endif
#if !defined(NO_QMLOBSERVER)
#include <qdeclarativeviewobserver.h>
#endif

// Enable debugging before any QDeclarativeEngine is created
struct QmlJsDebuggingEnabler {
  QmlJsDebuggingEnabler() { QDeclarativeDebugHelper::enableDebugging(); }
};

// Execute code in constructor before first QDeclarativeEngine is instantiated
static QmlJsDebuggingEnabler enableDebuggingHelper;

#endif // QMLJSDEBUGGER

class QmlApplicationViewerPrivate {
  QString mainQmlFile;
  friend class QmlApplicationViewer;
  static QString adjustPath(const QString &path);
};

QString QmlApplicationViewerPrivate::adjustPath(const QString &path) {
#ifdef Q_OS_UNIX
#ifdef Q_OS_MAC
  if (!QDir::isAbsolutePath(path))
    return QString::fromLatin1("%1/../Resources/%2")
        .arg(QCoreApplication::applicationDirPath(), path);
#else
  const QString pathInInstallDir =
      QString::fromLatin1("%1/../%2")
          .arg(QCoreApplication::applicationDirPath(), path);
  if (QFileInfo(pathInInstallDir).exists())
    return pathInInstallDir;
#endif
#endif
  return path;
}

QmlApplicationViewer::QmlApplicationViewer(QWindow *parent)
    : QQuickView(parent), d(new QmlApplicationViewerPrivate()) {
  connect(engine(), SIGNAL(quit()), SLOT(close()));
  setResizeMode(QQuickView::SizeRootObjectToView);
  // Qt versions prior to 4.8.0 don't have QML/JS debugging services built in
#if defined(QMLJSDEBUGGER) && QT_VERSION < 0x040800
#if !defined(NO_JSDEBUGGER)
  new QmlJSDebugger::JSDebuggerAgent(engine());
#endif
#if !defined(NO_QMLOBSERVER)
  new QmlJSDebugger::QDeclarativeViewObserver(this, this);
#endif
#endif
}

QmlApplicationViewer::~QmlApplicationViewer() { delete d; }

QmlApplicationViewer *QmlApplicationViewer::create() {
  return new QmlApplicationViewer();
}

void QmlApplicationViewer::setMainQmlFile(const QUrl &file) {
  setSource(file);
}

void QmlApplicationViewer::addImportPath(const QString &path) {
  engine()->addImportPath(QmlApplicationViewerPrivate::adjustPath(path));
}

void QmlApplicationViewer::showExpanded() {
#if defined(Q_OS_SYMBIAN) || defined(MEEGO_EDITION_HARMATTAN) ||               \
    defined(Q_WS_SIMULATOR)
  showFullScreen();
#elif defined(Q_WS_MAEMO_5)
  showMaximized();
#else
  show();
#endif
}
