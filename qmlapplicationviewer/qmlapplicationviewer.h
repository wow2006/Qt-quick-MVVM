#ifndef QMLAPPLICATIONVIEWER_H
#define QMLAPPLICATIONVIEWER_H

#include <QQuickView>

class QmlApplicationViewer : public QQuickView {
  Q_OBJECT

public:
  enum ScreenOrientation {
    ScreenOrientationLockPortrait,
    ScreenOrientationLockLandscape,
    ScreenOrientationAuto
  };

  explicit QmlApplicationViewer(QWindow *parent = nullptr);

  ~QmlApplicationViewer() override;

  static QmlApplicationViewer *create();

  void setMainQmlFile(const QUrl& path);

  void addImportPath(const QString &path);

  void showExpanded();

private:
  class QmlApplicationViewerPrivate *d;
};

#endif // QMLAPPLICATIONVIEWER_H
