#include "window.h"
#include "ui_window.h"
#include <QtGlobal>
#include <QSysInfo>
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QNetworkAddressEntry>
#include <QList>

Window::Window(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Window)
{
    ui->setupUi(this);
    loadSystemDetails();
}

Window::~Window()
{
    delete ui;
}

void Window::loadSystemDetails()
{
    QString string;

    // Environment Variables
    string.append("PATH: ").append((qEnvironmentVariable("PATH")));
    string.append("\nSHELL: ").append((qEnvironmentVariable("SHELL")));
    string.append("\nDESKTOP_SESSION: ").append((qEnvironmentVariable("DESKTOP_SESSION")));
    string.append("\nXCURSOR_SIZE: ").append((qEnvironmentVariable("XCURSOR_SIZE")));
    string.append("\nUSER: ").append((qEnvironmentVariable("USER")));

    // System Information
    string.append("\nQT Build Architecture : ").append(QSysInfo::buildAbi());
    string.append("\nCPU: ").append(QSysInfo::currentCpuArchitecture());
    string.append("\nKernel Version: ").append(QSysInfo::kernelVersion());
    string.append("\nKernel Type: ").append(QSysInfo::kernelType());
    string.append("\nHost Name: ").append(QSysInfo::machineHostName());
    string.append("\nProduct Name: ").append(QSysInfo::prettyProductName());
    string.append("\nProduct Type: ").append(QSysInfo::productType());



   // Network Information
   QList<QNetworkInterface> networkInterfaces = QNetworkInterface::allInterfaces();
    for (int i = 0; i < networkInterfaces.size(); i++) {
        if (networkInterfaces[i].flags() & QNetworkInterface::IsRunning) {
            string.append("\nNetwork: ").append(networkInterfaces[i].name());
        }

        if (networkInterfaces[i].type() & QNetworkInterface::Wifi) {
            string.append("\nType: ").append("WiFI");
        }


        QList<QNetworkAddressEntry> networkAddressEntries = networkInterfaces[i].addressEntries();
        for (int j = 0; j < networkAddressEntries.size(); j++) {
            string.append("\nIp: ").append(networkAddressEntries[j].ip().toString());
            string.append("\tNetMask: ").append(networkAddressEntries[j].netmask().toString());
        }
    }

    ui->textEdit->setText(string);
    ui->textEdit->setReadOnly(true);
}

