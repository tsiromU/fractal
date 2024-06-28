#include <QRegularExpression>
#include <complex>
#include <QString>
std::complex<double> prosessComplex(QString text){
    if(text == ""){
        return std::complex<double>(0,0);
    }
    if(text[0]!='-' && text[0]!='+'){
        QChar pr = '+';
        text.prepend(pr);
    }
    QRegularExpression reg(R"(^(?<real>[+-]\d+(\.\d+)?)?((?<imaginary>[+-]\d+(\.\d+)?)\*?i)?$)");
    QRegularExpressionMatch match = reg.match(text);
    if(!match.hasMatch()){
        qDebug() << "NO";
    }
    return std::complex<double> (match.captured("real").toDouble(), match.captured("imaginary").toDouble());
}
