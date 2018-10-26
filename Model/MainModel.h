#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QCryptographicHash>
#include <QObject>

class MainModel {
private:
  QString _sourceValue;
  QString _destinationValue;

public:
  virtual ~MainModel() {}

  QString GetSourceValue() const { return _sourceValue; }

  void SetSourceValue(const QString &value) { _sourceValue = value; }

  QString GetDestinationValue() const { return _destinationValue; }

  void SetDestinationValue(const QString &value) {
    if (!value.isEmpty()) {
      _destinationValue = HashValue(value);
    } else {
      _destinationValue = value;
    }
  }

private:
  QString HashValue(const QString &value) {
    return QString(
        QCryptographicHash::hash(value.toUtf8(), QCryptographicHash::Md5)
            .toHex());
  }
};

#endif // MAINMODEL_H
