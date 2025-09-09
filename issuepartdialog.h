#ifndef ISSUEPARTDIALOG_H
#define ISSUEPARTDIALOG_H

#include <QDialog>
#include "part.h"
#include <QList>
#include <optional>

namespace Ui {
class IssuePartDialog;
}

//struktura do zwracania danych z dialogu
struct IssueData{
    int partId;
    int quantity;
};

class IssuePartDialog : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor przyjmujący listę wszystkich części
    explicit IssuePartDialog(const QList<Part> & allParts, QWidget * parent = nullptr);
    ~IssuePartDialog();

    //metoda zwracająca wynik
    std::optional <IssueData> getIssueData() const;

private slots:
    //Aktualizacja UI po wybraniu części z listy
    void onPartSelected(int index);
private:
    Ui::IssuePartDialog *ui;
    QList <Part> m_parts; //Przechowuje listę części
};

#endif // ISSUEPARTDIALOG_H
