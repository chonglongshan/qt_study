#ifndef MAINWINDOW_H
#define MAINWINDOW_H


namespace Ui { class YYYWindow; }

class MainWindow
{
public:
    MainWindow();
    ~MainWindow();

    void show();

private:
    Ui::YYYWindow *ui;
};

#endif // MAINWINDOW_H
