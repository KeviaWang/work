#ifndef PROTOCOL_H
#define PROTOCOL_H
#include <QString>

namespace Protocol {

    // 定义消息和文件传输的类型
    const QString MESSAGE_TYPE = "MSG";
    const QString FILE_TYPE = "FILE";

    // 消息格式
    // MESSAGE_TYPE:FILENAME:FILESIZE:DATA
    // 例如: "MSG:Hello World"
    // 文件传输: "FILE:filename.txt:1234:binarydata"

    // 分隔符
    const QChar DELIMITER = ':';

    // 边界标记
    const QString END_OF_MESSAGE = "\n";

}

#endif // PROTOCOL_H
