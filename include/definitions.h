#ifndef DEFINITIONS_H
#define DEFINITIONS_H
typedef unsigned char BYTE;
typedef unsigned int uint32_t;
typedef unsigned long long size_t;
typedef BYTE* PBYTE;
typedef unsigned long DWORD;
typedef long long LONGLONG;

#define ALL_CH_START 0x100

#define CH1_START 0x110
#define CH1_INDEX 0x200
#define CH1_resByte 0x240

#define CH2_START 0x120
#define CH2_INDEX 0x210
#define CH2_resByte 0x250

#define CH3_START 0x130
#define CH3_INDEX 0x220
#define CH3_resByte 0x260

#define CH4_START 0x140
#define CH4_INDEX 0x230
#define CH4_resByte 0x270

#define HeartBeat 0x0F0
// #define Temperature 0x050

#define CH1_IdleCodeErr 0x3C0
#define CH2_IdleCodeErr 0x3D0
#define CH3_IdleCodeErr 0x3E0
#define CH4_IdleCodeErr 0x3F0

#define CH1_DataCnt 0x380
#define CH2_DataCnt 0x390
#define CH3_DataCnt 0x3A0
#define CH4_DataCnt 0x3B0

#define CH1_Send 0x400
#define CH2_Send 0x410
#define CH3_Send 0x420
#define CH4_Send 0x430
constexpr uint32_t signalShieldingControl = 0x00100;
constexpr uint32_t interruptInitializationControl = 0x00110;
constexpr uint32_t RT_DELAY = 0x00A60;
const int ROW_size = 7;
const int COLS_size = 64;
#define Index_8MB_2K_num 4096
const int MAX_YAXIS = 30000;
const int MAX_YAXIS_2 = 300;
const int BLOOD_TOLERANCE = 5;
const int BLOOD_MAX = 180;
const int BLOOD_Min = 30;
const int NEED_CHANGE_CH_ID = 5;
const int NEED_CHANGE_CH_ID_LOOP = 5;

enum FileSize
{
    size_4TB = 0,
    size_2TB,
    size_1TB,
    size_512GB,
    size_256GB,
    size_128GB,
    size_64GB
};

struct CHx_check
{
    bool CH1_en;
    bool CH2_en;
    bool CH3_en;
    bool CH4_en;
};

enum FiberRate //光纤速率选择
{
    Rate10g = 0,
    Rate9_6g,
    Rate8g,
    Rate6_4g,
    Rate5g,
    Rate4_8g,
    Rate4g,
    Rate3_2g,
    Rate2g_32bit,
    Rate2g_16bit,
    Rate1_6g_32bit,
    Rate1_6g_16bit,
    Rate1g_16bit
};

#define RateFileSize 66560
#define US_PER_S 1000000
#define MaxIndex_512MB 262144
#define ONE_KB 1024
#define ONE_MB 1048576
#define ONE_GB  1073741824

enum CHStatus
{
    CH_STOP = 0,
    CH_START
};

enum CH_ID
{
    CH1 = 0,
    CH2,
    CH3,
    CH4
};

struct DataFrame
{
    uint32_t value;
    bool flag;
};

//标志计数从0开始
typedef struct
{
    uint32_t header; // 帧头 0xCFCFCFCF
    uint32_t data_type; // 数据报文类型：0-->正常数据；1-->内部固定仿真数据；2-->上位机下载仿真数据；其他未定义；
} FrameHeader; // 帧头结构体 长度为 2 uint_32
// 系统参数结构体
typedef struct
{
    uint32_t frame_index; // 数据报文帧序号 标志计数2
    uint32_t frame_time_MS; //数据报文时间戳，单位ms
    uint32_t frame_time_HMS; // 时戳 时分秒
    uint32_t frame_time_YMD; // 时戳 年月日
    uint32_t device_dna_low; // 设备DNA低32位：
    uint32_t device_dna_high; // 设备DNA高32位：
    uint32_t device_lectotype_CPU; //设备主板CPU选型：量产阶段由UI根据硬件状况配置，写入ROM；
    uint32_t device_lectotype_FPGA; //设备主板FPGA选型：FPGA设计内固定写死；
    uint32_t fpga_dna_low; // FPGA DNA低32位：
    uint32_t fpga_dna_high; // FPGA DNA高32位：
    uint32_t fpga_secretkey_low; //  FPGA密钥低32位：
    uint32_t fpga_secretkey_high; // FPGA密钥高32位： 标志计数 13
    uint32_t SystemParameters_leftover_1[6]; //占位   标志计数 19
    uint32_t fpga_fw_version; // FPGA固件版本号
    uint32_t fpga_heartbeat; // 上位机心跳包
    uint32_t fpga_core_temperature; // FPGA运行核心温度 标志计数  22
    uint32_t SystemParameters_leftover_2[9]; // 根据需要添加更多系统参数字段 标志计数 31
} SystemParameters; //系统基本参数 长度为30 uint_32

typedef struct
{
    uint32_t front_button_0; //  按键0 计数标志 32
    uint32_t front_button_1; //  按键1
    uint32_t front_button_2; //  按键2
    uint32_t front_button_3; //  按键3 计数标志 35
} FrontPannelButton; //前面板设备按键 长度为 4 uint_32;

typedef struct
{
    uint32_t UnDefineSpace_leftover_0[28]; //标志位置start 36 end 63
} UnDefineSpace; //未定义区 长度为 28 uint_32;

typedef struct
{
    uint32_t raw_I_LA; //原始数据：ECG-I导联(左臂)； 标志位置 64
    uint32_t raw_II_LL; //原始数据：ECG-II导联(左腿)；
    uint32_t raw_III_RA; //原始数据：ECG-III导联(右臂)；
    uint32_t raw_V1;
    uint32_t raw_V2;
    uint32_t raw_Blood_P; //血压
    uint32_t raw_Balloon_P; //球囊压力 标志位置70
    uint32_t SignalProcessing_leftover_1[9]; //标志位置 79
    int fir_I_LA;
    int fir_II_LL;
    int fir_III_RA;
    int fir_V1;
    int fir_V2;
    int fir_Blood_P; //血压
    int fir_Balloon_P; //球囊压力 标志位置86
    uint32_t SignalProcessing_leftover_2[9]; //标志位置 95
    uint32_t sample_Rate; //信号采样率 单位 HZ
    uint32_t heart_Rate; //心率 使用滤波后的数据统计心率
    uint32_t detect_lead_off; //导联是否脱落
    uint32_t type_process; //信号处理类型
    uint32_t type_trig; //当前采用的触发源 0-4：ECG；5：压力
    uint32_t detect_R; //R波检测点
    uint32_t inflate_Pulse; //充气触发脉冲 1：充气；0：保持
    uint32_t deflate_Pulse; //放气触发脉冲 1：充气；0：保持
    uint32_t counterpulsation_pressure; //反博压 标志位置104
    uint32_t counter_pulse_pressure_alarm; //反博压报警 0表示正常，1是有报警
    uint32_t auxiliary_frequency; //辅助频率
    uint32_t detect_T; //T波检测点
    uint32_t maximum_blood_pressure; // 血压最大值 默认值 300 标志位置108
    uint32_t minimum_blood_pressure; // 血压最小值 默认值 10
    uint32_t average_blood_pressure; // 血压平均值 默认值 150 标志位置110
    // uint32_t SignalProcessing_leftover_4[145];
    uint32_t SignalProcessing_leftover_3[17]; //标志位置 127
    uint32_t detect_R_I; //导联I检测R点 //标志位置 128
    uint32_t detect_T_I; //导联I检测T点
    uint32_t detect_R_II; //导联II检测R点
    uint32_t detect_T_II; //导联II检测T点
    uint32_t detect_R_III; //导联III检测R点
    uint32_t detect_T_III; //导联III检测T点
    uint32_t detect_R_V; //导联V检测R点
    uint32_t detect_T_V; //导联V检测T点    mark135
    uint32_t SignalProcessing_leftover_4[72]; //标志位置 207
    uint32_t SYS_MODE; //标志位置 208
    uint32_t SignalProcessing_leftover_5[15]; //标志位置 223
} SignalProcessing; // 信号采集及处理结构体 长度为 160 uint_32;

typedef struct
{
    uint32_t qD_SW; // 气动系统ID  mark224
    uint32_t qD_INF_OPP;
    uint32_t qD_INF_DUR;
    uint32_t qD_DEF_OPP;
    uint32_t qD_DEF_DUR;
    uint32_t qD_RATE;
    uint32_t qD_BALL_VOL; //mark 230
    uint32_t PneumaticSystem_leftover_1[9]; //mark239
} PneumaticSystem; // 气动系统结构体 长度为 16 uint_32;

typedef struct
{
    uint32_t ECG_MODE; //mark 240
    uint32_t ECG_SHOW;
    uint32_t ECG_DIGIT_LP;
    uint32_t ECG_DIGIT_HP;
    uint32_t ECG_DIGIT_DZ;
    uint32_t ECG_DIGIT_MOV; //mark 245
    uint32_t ECGSystem_leftover_1[10]; //mark255
} ECGSystem; // ECG系统结构体 长度为 16 uint_32;

typedef struct
{
    uint32_t IBP_MODE; //mark 256
    uint32_t IBP_Sample_Rate;
    uint32_t IBP_Calibration; //mark 258
    uint32_t IBPSystem_leftover_1[13]; //mark271
} IBPSystem; // 有创血压系统 长度为 16 uint_32;

typedef struct
{
    uint32_t UnDefineSpace_leftover_0[238]; //标志位置start 272 end 509
} UnDefineSpace2; //未定义区 长度为 238 uint_32;

typedef struct
{
    uint32_t crc;
    uint32_t tail;
} FrameTail; //尾部 长度为 2 uint_32

// 完整的帧结构体
typedef struct
{
    FrameHeader header; // 帧头部 2
    SystemParameters sys_params; // 系统参数 30
    FrontPannelButton front_pannel; // 前端面板按钮 4
    UnDefineSpace un_define; //  未定义区 28
    SignalProcessing signal; // 信号采集及处理 160
    PneumaticSystem pneumatics; // 气动系统 16
    ECGSystem ecg_system; // 心电系统  16
    IBPSystem ibp_system; //  血压系统 16
    UnDefineSpace2 un_define2; //  未定义区 238
    FrameTail tail; //帧尾 2
} Frame;

extern "C" {
#include "pcie_dll.h"
}
#endif // DEFINITIONS_H
