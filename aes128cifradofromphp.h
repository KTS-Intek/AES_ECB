#ifndef AES128CIFRADOFROMPHP_H
#define AES128CIFRADOFROMPHP_H

#include <QObject>
#include <QtCore>

#include <stdint.h>

// #define the macros below to 1/0 to enable/disable the mode of operation.
//
// CBC enables AES128 encryption in CBC-mode of operation and handles 0-padding.
// ECB enables the basic ECB 16-byte block algorithm. Both can be enabled simultaneously.

// The #ifndef-guard allows it to be configured before #include'ing or at compile time.
//#ifndef CBC
//  #define CBC 1
//#endif

//#ifndef ECB
  #define ECB 1
//#endif

//#if defined(ECB) && ECB


class AES128CifradoFromPhp : public QObject
{
    Q_OBJECT
public:
    explicit AES128CifradoFromPhp(QObject *parent = 0);

signals:

public slots:




public:
//#if defined(ECB) && ECB

void AES128_ECB_encrypt(uint8_t* input, const uint8_t* key, uint8_t *output);
QByteArray aes128_ecb_encrtypt(const QByteArray &arrEncr, const QByteArray &arrKey);
QByteArray aes128_ecb_decrtypt(const QByteArray &arrDecr, const QByteArray &arrKey);

QList<quint8> aes128_ecb_encrtypt(const QList<quint8> &listEncr, const QByteArray &arrKey);
QList<quint8> aes128_ecb_decrtypt(const QList<quint8> &listDecr, const QByteArray &arrKey);

QByteArray keyEncrKey(const QByteArray &arrKey);
QByteArray keyEncrKey(const QByteArray &arrKey, const int &raziv);

bool keyAndKeyGood(const QByteArray &arrKey1Hash, const QByteArray &arrKey2Enrc, const int &raziv);

QByteArray validLogin(const QString &login);
QByteArray validLogin(const QByteArray &login);

 QByteArray validPasswd(const QString &paswrd);
 QByteArray validPasswd(const QByteArray &paswrd);

void AES128_ECB_decrypt(uint8_t* input, const uint8_t* key, uint8_t *output);



private:
//#endif // #if defined(ECB) && ECB


//#if defined(CBC) && CBC

//void AES128_CBC_encrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);
//void AES128_CBC_decrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);

//#endif // #if defined(CBC) && CBC




#if defined(CBC) && CBC
  // Initial Vector used only for CBC mode
  static uint8_t* Iv;
#endif



};

#endif // AES128CIFRADOFROMPHP_H
