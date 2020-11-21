#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "./libmodbus/modbus.h"

#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    printf("控制输出");
    qDebug("控制输出");
    printf("[%.2X]", 0xff);
    qDebug("[%.2X]", 0xff);
    //fprintf(stderr, "ERROR %s", modbus_strerror(errno));
    fprintf(stderr, "ERROR %s", modbus_strerror(errno));
    //qDebug(stderr, "ERROR %s", modbus_strerror(errno));
    fflush(stdout);
    fflush(stderr);

    qDebug() << "void MainWindow::on_pushButton_clicked()";
    // 控制输出
    //
    modbus_t *ctx = nullptr;
    ctx = modbus_new_rtu("com3", 9600, 'N', 8, 1);
    if (ctx == nullptr) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return;
    }
    modbus_set_debug(ctx, TRUE);
//    modbus_error_recovery_mode error_recovery = static_cast<modbus_error_recovery_mode>(MODBUS_ERROR_RECOVERY_LINK | MODBUS_ERROR_RECOVERY_PROTOCOL);
//    modbus_set_error_recovery(ctx, error_recovery);
    modbus_set_slave(ctx, 1);
//    uint32_t old_response_to_sec;
//    uint32_t old_response_to_usec;
//    modbus_get_response_timeout(ctx, &old_response_to_sec, &old_response_to_usec);
//    qDebug() << old_response_to_sec << "," << old_response_to_usec;
    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return;
    }
//    uint32_t new_response_to_sec;
//    uint32_t new_response_to_usec;
//    modbus_get_response_timeout(ctx, &new_response_to_sec, &new_response_to_usec);
//    qDebug() << new_response_to_sec << "," << new_response_to_usec;
    int rc;
    rc = modbus_write_bit(ctx, 0x0010, ON);
    qDebug() << "rc:" << rc;
    uint8_t *tab_rp_bits = nullptr;
    size_t nb_points = 0x16;
    tab_rp_bits = static_cast<uint8_t *>(malloc(nb_points * sizeof(uint8_t)));
    memset(tab_rp_bits, 0, nb_points * sizeof(uint8_t));
    rc = modbus_read_bits(ctx, 0x0010, 1, tab_rp_bits);
    for (size_t i = 0; i < nb_points; ++i)
    {
        //
        qDebug() << tab_rp_bits[i];
    }

    modbus_close(ctx);
    modbus_free(ctx);


//    uint8_t *tab_rp_bits = NULL;
//    modbus_t *ctx = NULL;
//    int nb_points;
//    int rc;

//    uint32_t old_response_to_sec;
//    uint32_t old_response_to_usec;
//    uint32_t new_response_to_sec;
//    uint32_t new_response_to_usec;

//        ctx = modbus_new_rtu("com3", 9600, 'N', 8, 1);

//    if (ctx == NULL) {
//        fprintf(stderr, "Unable to allocate libmodbus context\n");

//    }
//    modbus_set_debug(ctx, TRUE);
////    modbus_error_recovery_mode error_recovery = static_cast<modbus_error_recovery_mode>(MODBUS_ERROR_RECOVERY_LINK | MODBUS_ERROR_RECOVERY_PROTOCOL);
////    modbus_set_error_recovery(ctx, error_recovery);


//        modbus_set_slave(ctx, 1);

//    modbus_get_response_timeout(ctx, &old_response_to_sec, &old_response_to_usec);
//    if (modbus_connect(ctx) == -1) {
//        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
//        modbus_free(ctx);
//    }
//    modbus_get_response_timeout(ctx, &new_response_to_sec, &new_response_to_usec);

//    printf("** UNIT TESTING **\n");

//    printf("1/1 No response timeout modification on connect: ");

//    /* Allocate and initialize the memory to store the bits */
//    nb_points = 0x16;
//    tab_rp_bits = (uint8_t *) malloc(nb_points * sizeof(uint8_t));
//    memset(tab_rp_bits, 0, nb_points * sizeof(uint8_t));

//    printf("\nTEST WRITE/READ:\n");

//    /** COIL BITS **/

//    /* Single */
//    rc = modbus_write_bit(ctx, 0x0010, ON);
//    //rc = modbus_write_bit(ctx, UT_BITS_ADDRESS, OFF);
//    //rc = modbus_write_bit(ctx, 0x0011, ON);
//    printf("1/2 modbus_write_bit: ");

//    rc = modbus_read_bits(ctx, 0x0010, 1, tab_rp_bits);
//    printf("2/2 modbus_read_bits: ");


//    /* End single */
}

void MainWindow::on_pushButton_2_clicked()
{
    modbus_t *ctx = nullptr;
    ctx = modbus_new_rtu("com3", 9600, 'N', 8, 1);
    if (ctx == nullptr) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return;
    }
    modbus_set_debug(ctx, TRUE);
    modbus_set_slave(ctx, 1);

    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return;
    }
    int rc;
    rc = modbus_write_bit(ctx, 0x0010, OFF);
    qDebug() << "rc:" << rc;
    uint8_t *tab_rp_bits = nullptr;
    size_t nb_points = 0x16;
    tab_rp_bits = static_cast<uint8_t *>(malloc(nb_points * sizeof(uint8_t)));
    memset(tab_rp_bits, 0, nb_points * sizeof(uint8_t));
    rc = modbus_read_bits(ctx, 0x0010, 1, tab_rp_bits);
    for (size_t i = 0; i < nb_points; ++i)
    {
        //
        qDebug() << tab_rp_bits[i];
    }

    modbus_close(ctx);
    modbus_free(ctx);
}

void MainWindow::on_pushButton_3_clicked()
{
    modbus_t *ctx = nullptr;
    ctx = modbus_new_rtu("com3", 9600, 'N', 8, 1);
    if (ctx == nullptr) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return;
    }
    modbus_set_debug(ctx, TRUE);
    modbus_set_slave(ctx, 1);

    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return;
    }
    int rc;
    rc = modbus_write_bit(ctx, 0x0011, ON);
    qDebug() << "rc:" << rc;
    uint8_t *tab_rp_bits = nullptr;
    size_t nb_points = 0x16;
    tab_rp_bits = static_cast<uint8_t *>(malloc(nb_points * sizeof(uint8_t)));
    memset(tab_rp_bits, 0, nb_points * sizeof(uint8_t));
    rc = modbus_read_bits(ctx, 0x0011, 1, tab_rp_bits);
    for (size_t i = 0; i < nb_points; ++i)
    {
        //
        qDebug() << tab_rp_bits[i];
    }

    modbus_close(ctx);
    modbus_free(ctx);
}

void MainWindow::on_pushButton_4_clicked()
{
    modbus_t *ctx = nullptr;
    ctx = modbus_new_rtu("com3", 9600, 'N', 8, 1);
    if (ctx == nullptr) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return;
    }
    modbus_set_debug(ctx, TRUE);
    modbus_set_slave(ctx, 1);

    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return;
    }
    int rc;
    rc = modbus_write_bit(ctx, 0x0012, ON);
    qDebug() << "rc:" << rc;
    uint8_t *tab_rp_bits = nullptr;
    size_t nb_points = 0x16;
    tab_rp_bits = static_cast<uint8_t *>(malloc(nb_points * sizeof(uint8_t)));
    memset(tab_rp_bits, 0, nb_points * sizeof(uint8_t));
    rc = modbus_read_bits(ctx, 0x0012, 1, tab_rp_bits);
    for (size_t i = 0; i < nb_points; ++i)
    {
        //
        qDebug() << tab_rp_bits[i];
    }

    modbus_close(ctx);
    modbus_free(ctx);
}

void MainWindow::on_pushButton_5_clicked()
{
    modbus_t *ctx = nullptr;
    ctx = modbus_new_rtu("com3", 9600, 'N', 8, 1);
    if (ctx == nullptr) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return;
    }
    modbus_set_debug(ctx, TRUE);
    modbus_set_slave(ctx, 1);

    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return;
    }
    int rc;
    rc = modbus_write_bit(ctx, 0x0013, ON);
    qDebug() << "rc:" << rc;
    uint8_t *tab_rp_bits = nullptr;
    size_t nb_points = 0x16;
    tab_rp_bits = static_cast<uint8_t *>(malloc(nb_points * sizeof(uint8_t)));
    memset(tab_rp_bits, 0, nb_points * sizeof(uint8_t));
    rc = modbus_read_bits(ctx, 0x0013, 1, tab_rp_bits);
    for (size_t i = 0; i < nb_points; ++i)
    {
        //
        qDebug() << tab_rp_bits[i];
    }

    modbus_close(ctx);
    modbus_free(ctx);
}

void MainWindow::on_pushButton_8_clicked()
{
    modbus_t *ctx = nullptr;
    ctx = modbus_new_rtu("com3", 9600, 'N', 8, 1);
    if (ctx == nullptr) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return;
    }
    modbus_set_debug(ctx, TRUE);
    modbus_set_slave(ctx, 1);

    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return;
    }
    int rc;
    rc = modbus_write_bit(ctx, 0x0011, OFF);
    qDebug() << "rc:" << rc;
    uint8_t *tab_rp_bits = nullptr;
    size_t nb_points = 0x16;
    tab_rp_bits = static_cast<uint8_t *>(malloc(nb_points * sizeof(uint8_t)));
    memset(tab_rp_bits, 0, nb_points * sizeof(uint8_t));
    rc = modbus_read_bits(ctx, 0x0011, 1, tab_rp_bits);
    for (size_t i = 0; i < nb_points; ++i)
    {
        //
        qDebug() << tab_rp_bits[i];
    }

    modbus_close(ctx);
    modbus_free(ctx);
}

void MainWindow::on_pushButton_7_clicked()
{
    modbus_t *ctx = nullptr;
    ctx = modbus_new_rtu("com3", 9600, 'N', 8, 1);
    if (ctx == nullptr) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return;
    }
    modbus_set_debug(ctx, TRUE);
    modbus_set_slave(ctx, 1);

    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return;
    }
    int rc;
    rc = modbus_write_bit(ctx, 0x0012, OFF);
    qDebug() << "rc:" << rc;
    uint8_t *tab_rp_bits = nullptr;
    size_t nb_points = 0x16;
    tab_rp_bits = static_cast<uint8_t *>(malloc(nb_points * sizeof(uint8_t)));
    memset(tab_rp_bits, 0, nb_points * sizeof(uint8_t));
    rc = modbus_read_bits(ctx, 0x0012, 1, tab_rp_bits);
    for (size_t i = 0; i < nb_points; ++i)
    {
        //
        qDebug() << tab_rp_bits[i];
    }

    modbus_close(ctx);
    modbus_free(ctx);
}

void MainWindow::on_pushButton_6_clicked()
{
    modbus_t *ctx = nullptr;
    ctx = modbus_new_rtu("com3", 9600, 'N', 8, 1);
    if (ctx == nullptr) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return;
    }
    modbus_set_debug(ctx, TRUE);
    modbus_set_slave(ctx, 1);

    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return;
    }
    int rc;
    rc = modbus_write_bit(ctx, 0x0013, OFF);
    qDebug() << "rc:" << rc;
    uint8_t *tab_rp_bits = nullptr;
    size_t nb_points = 0x16;
    tab_rp_bits = static_cast<uint8_t *>(malloc(nb_points * sizeof(uint8_t)));
    memset(tab_rp_bits, 0, nb_points * sizeof(uint8_t));
    rc = modbus_read_bits(ctx, 0x0013, 1, tab_rp_bits);
    for (size_t i = 0; i < nb_points; ++i)
    {
        //
        qDebug() << tab_rp_bits[i];
    }

    modbus_close(ctx);
    modbus_free(ctx);
}

void MainWindow::on_pushButton_9_clicked()
{
    modbus_t *ctx = nullptr;
    ctx = modbus_new_rtu("com3", 9600, 'N', 8, 1);
    if (ctx == nullptr) {
        fprintf(stderr, "Unable to allocate libmodbus context\n");
        return;
    }
    modbus_set_debug(ctx, TRUE);
    modbus_set_slave(ctx, 1);

    if (modbus_connect(ctx) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(ctx);
        return;
    }
    int rc;
    qDebug() << "rc:" << rc;
    uint8_t *tab_rp_bits = nullptr;
    size_t nb_points = 0x16;
    tab_rp_bits = static_cast<uint8_t *>(malloc(nb_points * sizeof(uint8_t)));
    memset(tab_rp_bits, 0, nb_points * sizeof(uint8_t));
    /** DISCRETE INPUTS **/
    rc = modbus_read_input_bits(ctx, 0x0000, 8, tab_rp_bits);
    for (size_t i = 0; i < nb_points; ++i)
    {
        //
        qDebug() << tab_rp_bits[i];
    }

    modbus_close(ctx);
    modbus_free(ctx);
}
