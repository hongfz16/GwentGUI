#include "gwentclient.h"

gwentClient::gwentClient(QObject *parent) : QObject(parent)
{
	connected=false;
	connect(&mySocket,SIGNAL(connected()),this,SLOT(successConnection()));
	connect(&mySocket,SIGNAL(readyRead()),this,SLOT(readyRead()));
	connect(&mySocket,SIGNAL(disconnected()),this,SLOT(disconnected()));
}

void gwentClient::requestConnection()
{
	mySocket.connectToHost(QHostAddress("127.0.0.1"),1235);
}

void gwentClient::successConnection()
{

}

void gwentClient::readyRead()
{
	QByteArray data=mySocket.readAll();
	QJsonDocument JDData;
	JDData.fromJson(data);
	QJsonObject JOData=JDData.object();
	dealWithData(JOData);
}

void gwentClient::disconnected()
{

}

void gwentClient::sendData(QByteArray data)
{
	mySocket.write(data);
	mySocket.flush();
	mySocket.waitForBytesWritten(3000);
}

void gwentClient::dealWithData(QJsonObject JOData)
{
	QString type=JOData["type"].toString();
	if(type=="firstDraw")
	{
//return "hand":(QJsonArray) "base":(QJsonArray)
	}
	if(type=="secondDraw")
	{

	}
	if(type=="thirdDraw")
	{

	}
	if(type=="unitChanged")
	{
		int rowNum=JOData["rowNum"].toInt();
		int index=JOData["index"].toInt();
		int fight=JOData["fight"].toInt();
		int protection=JOData["protection"].toInt();
		bool locked=JOData["locked"].toBool();
	}
	if(type=="rowChanged")
	{
		int rowNum=JOData["rowNum"].toInt();
		QJsonArray arr=JOData["sequence"].toArray();
	}
	if(type=="baseChanged")
	{
		bool side=JOData["side"].toBool();
		QJsonArray arr=JOData["sequence"].toArray();
	}
	if(type=="cemeteryChanged")
	{
		bool side=JOData["side"].toBool();
		QJsonArray arr=JOData["sequence"].toArray();
	}
	if(type=="handCardChanged")
	{
		bool side=JOData["side"].toBool();
		QJsonArray arr=JOData["sequence"].toArray();
	}
	if(type=="EffectChooseRow")
	{
		QJsonArray rowRange=JOData["rowRange"].toArray();
		int waitsec=JOData["wait"].toInt();

		//return "rowNum":(rowNum)
	}
	if(type=="EffectChooseTarget")
	{
		QJsonArray rowRange=JOData["rowRange"].toArray();
		int waitsec=JOData["wait"].toInt();

		//return "rowNum":(rowNum) "index":(index)
	}
	if(type=="chooseAndDeploy")
	{
		//return "timeout":0 "handCardIndex" "rowNum" "index"
	}
}
