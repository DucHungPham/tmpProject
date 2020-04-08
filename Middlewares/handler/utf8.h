#ifndef __utf8_h
#define __utf8_h
#include "board_init.h"

/**
 * Trả về mã kí tự hiển thị theo bảng mã unicode(endcode by utf8)
 * !Tạo font tiếng việt = ASCII + TV có dấu-> array
 * !mapping sau decode sang array thay vì lưu cả bộ font đầy đủ
 * 
 * ASCII +
 * ă, â, đ, ê, ô, ơ, ư,
 * ả, ã, ạ, à, á, ẳ, ẵ, ặ, ắ, ằ, ẩ, ẫ, ậ, ầ, ấ, 
 * ẻ, ẽ, ẹ, è, é, ể, ễ, ệ, ề, ế,
 * ỉ, ĩ, ị, ì, í, ỏ, õ, ọ, ò, ó
 * ổ, ỗ, ộ, ồ, ố, ở, ỡ, ợ, ờ, ớ,
 * ủ, ũ, ụ, ù, ú, ử, ữ, ự, ừ, ứ
 * ỷ, ỹ, ỵ, ỳ, ý
 */
uint16_t utf8_decode(uint8_t *buf, uint16_t len);
#endif