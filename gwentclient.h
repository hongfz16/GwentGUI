#ifndef GWENTCLIENT_H
#define GWENTCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QHostAddress>

#include "gameconstant.h"

class gwentClient : public QObject
{
	Q_OBJECT
public:
	explicit gwentClient(QObject *parent = nullptr);

signals:

public slots:
	void requestConnection();
	void successConnection();
	void readyRead();
	void disconnected();
public:
	void sendData(QByteArray data);
	void dealWithData(QJsonObject JOData);

private:
	QTcpSocket mySocket;
	bool connected;
};

#endif // GWENTCLIENT_H
