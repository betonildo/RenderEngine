#ifndef FORMATTYPE_H
#define FORMATTYPE_H

enum class FormatType {
    Uint8,
    Uint16,
    Int16,
    Int32,
    Uint32,
    Float,
    Count
};

const unsigned char GetFormatTypeSizeInBytes(const FormatType& type);

#endif /*FORMATTYPE_H*/