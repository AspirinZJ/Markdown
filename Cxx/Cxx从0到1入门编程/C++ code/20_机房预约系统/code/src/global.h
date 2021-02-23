// Created by jackzhang on 2/18/21.
/*
 * 不同的身份有不同的文件操作，此文件定义了所有的文件名
 * */

#ifndef INC_20__GLOBAL_H
#define INC_20__GLOBAL_H

// 管理员文件
#define ADMIN_FILE "../admin.txt"
// 学生文件
#define STUDENT_FILE "../student.txt"
// 教师文件
#define TEACHER_FILE "../teacher.txt"
// 机房信息文件
#define COMPUTER_ROOM_FILE "../computerRoom.txt"
// 预约文件
#define ORDER_FILE "../order.txt"

// 代表预约状态的宏
#define ORDER_PROCESSING	"1" // 审核中
#define ORDER_SUCCESSFULLY "2" // 预约成功
#define ORDER_FAILED "3" // 预约失败
#define ORDER_CANCLED "-1" // 取消的预约

#endif //INC_20__GLOBAL_H
