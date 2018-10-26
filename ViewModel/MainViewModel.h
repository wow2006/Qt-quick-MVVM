#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include "../Model/MainModel.h"

class MainViewModel : public QObject
{
    Q_OBJECT

private:
    // main model
    MainModel _mainModel;

    // declaration of source property
    Q_PROPERTY (QString sourceValue READ GetSourceValue WRITE SetSourceValue NOTIFY SourceChangedEvent);

    // declaration of destination property
    Q_PROPERTY (QString destinationValue READ GetDestinationValue WRITE SetDestinationValue
                NOTIFY DestinationChangedEvent);

public:
    explicit MainViewModel(const MainModel& mainModel)
    {
        _mainModel = mainModel;
    }

    virtual ~MainViewModel()
    { }

    Q_INVOKABLE void clearCommand() // clear command
    {
        QString emptyString = "";        
        SetSourceValue(emptyString);
    }

    QString GetSourceValue() const
    {
        return _mainModel.GetSourceValue();
    }

    QString GetDestinationValue() const
    {
        return _mainModel.GetDestinationValue();
    }

public slots:
    void SetSourceValue(QString& arg)
    {
        if (_mainModel.GetSourceValue() != arg) {
            _mainModel.SetSourceValue(arg);
            SourceChangedEvent(arg);
            SetDestinationValue(arg);
        }
    }

    void SetDestinationValue(QString& arg)
    {
        if (_mainModel.GetDestinationValue() != arg) {
            _mainModel.SetDestinationValue(arg);
            DestinationChangedEvent(arg);
        }
    }

signals:
    void SourceChangedEvent(QString& arg);
    void DestinationChangedEvent(QString& arg);
};

#endif // MAINVIEWMODEL_H
