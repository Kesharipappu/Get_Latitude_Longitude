#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , networkManager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    // Set Window Title Name
    setWindowTitle("Latitude & Longitude");

    // Remove icon from window title
    QPixmap transparentPixmap(1, 1);
    transparentPixmap.fill(Qt::transparent);
    setWindowIcon(QIcon(transparentPixmap));
    ui->addressLineEdit->setFocus();
    connect(ui->fetchButton, &QPushButton::clicked, this, &MainWindow::on_fetchButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_fetchButton_clicked() {
    QString address = ui->addressLineEdit->text();
    QString apiKey = "728b948e86d1421196d7db285ca7e186"; // Replace with your OpenCage API key

    QUrl url("https://api.opencagedata.com/geocode/v1/json");
    QUrlQuery query;
    query.addQueryItem("q", address);
    query.addQueryItem("key", apiKey);
    url.setQuery(query);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::UserAgentHeader, "YourAppName/1.0");

    QNetworkReply *reply = networkManager->get(request);
    connect(reply, &QNetworkReply::finished, this, &MainWindow::handleOpenCageResponse);
}

void MainWindow::handleOpenCageResponse() {
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();

        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObject = jsonDoc.object();
        QJsonArray resultsArray = jsonObject["results"].toArray();

        if (!resultsArray.isEmpty()) {
            QJsonObject firstResult = resultsArray.first().toObject();
            QJsonObject geometry = firstResult["geometry"].toObject();

            // Extract lat and lon directly as strings to preserve exact formatting
            QString latStr = geometry["lat"].toVariant().toString();
            QString lonStr = geometry["lng"].toVariant().toString();

            QString result = QString("Latitude: %1\nLongitude: %2").arg(latStr).arg(lonStr);
            ui->resultTextEdit->setText(result);
        } else {
            ui->resultTextEdit->setText("No results found.");
        }
    } else {
        QString errorMessage = QString("Network error: %1\nStatus Code: %2").arg(reply->errorString()).arg(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt());
        ui->resultTextEdit->setText(errorMessage);
    }
    reply->deleteLater();
}

/*
 Steps to Use OpenCage Data API

1. Sign Up for OpenCage Data API Key:
        a. Go to OpenCage Data.
        b. Sign up for a free account.
        c. After signing up, you will receive an   API key.
*/
