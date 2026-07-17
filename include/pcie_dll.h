#pragma once
typedef unsigned char            uchar;
typedef unsigned int             uint32_t;
typedef unsigned long long       uint64_t;

enum ErrorStatus			// 定义枚举错误类型
{
	NON_ERROR = 0,			// 没有错误
	OPEN_FAIL,				// 设备打开失败
	WRITE_FAIL,				// 写数据失败
	READ_FAIL,				// 读数据失败
	HANDLE_ERROR,			// 句柄错误
	SEEK_ERROR,             // 寻址错误
	MEM_INIT_FAIL,          // 内存初始化失败
	WAIT_DATA,              // 等待数据
	MODE_ERROR,             // 模式错误
	CMD_ERROR,              // 指令错误
	PATH_UNVALID,           // 路径错误
	DDRINIT_FAIL,           // DDR初始化失败
	RD_SLOW_WARNING			// 客户端读数据太慢警告
};

struct CHx_Status
{
	bool HardwareEn;			// 光模块是否存在
	bool Fiberlink;				// 光路是否有光信号
	float linkRate;				// 线速率
	uint32_t dataBitWidth;		// 数据位宽
	bool decodeStatus;           //解码状态
	bool idleCodeValid;			// 空闲码匹配
	bool DataValid;				// 有效数据指示
	float effectiveData_Bandwidth;	// 有效数据带宽
};

struct UserStatus
{
	uint32_t Dev_num;                   // 链接状态
	float Temperature1;                 // 设备温度1
	float Temperature2;                 // 设备温度2
	float Temperature3;                 // 设备温度3
	float Temperature4;                 // 设备温度4
	bool FanStatus;                     // 风扇状态
	uint32_t Heartbeat;                 // 秒脉冲状态
	float PowerConsump;                 // 单板功耗
	bool HardwareEn;			        // 光模块是否存在
	bool Fiberlink;				        // 光路是否有光信号	
	uint32_t dataBitWidth;		        // 数据位宽
	float linkRate;				        // 线速率
	bool decodeStatus;                  // 解码状态
	bool idleCodeValid;		            // 空闲码匹配
	bool DataValid;				        // 有效数据指示
	float ValidBandwidth;               // 有效数据带宽
	uint32_t dataMatchControl;            // 数据对齐控制
	uint32_t idleControlWord;             // 空闲码控制字
	uint32_t idleData;                  // 空闲码数据
	uint32_t FPGAVersion;               // 下位机版本号
	uint32_t PCIeBitWidth;              // PCIe位宽
	uint32_t PCIeRate;                  // PCIe线速率    
	uint32_t DDRStatus;                 // DDR初始化状态
};


__declspec(dllexport) int pcie_H2C_rate_check(uchar* buffer, uint32_t buffer_size, uint32_t count, uint64_t* H2C_elapsed);
__declspec(dllexport) int pcie_C2H_rate_check(uchar* buffer, uint32_t buffer_size, uint32_t count, uint64_t* C2H_elapsed);
__declspec(dllexport) int MultiDev_H2C_rate_check(int Dev_ID, uchar* buffer, uint32_t buffer_size, uint32_t count, uint64_t* H2C_elapsed);
__declspec(dllexport) int MultiDev_C2H_rate_check(int Dev_ID, uchar* buffer, uint32_t buffer_size, uint32_t count, uint64_t* C2H_elapsed);
__declspec(dllexport) int PiYSDev_PCIe_Rate(float* H2C_Rate, float* C2H_Rate);
__declspec(dllexport) void PiYSDev_User_Status(struct UserStatus* User_Status);


// --- 驱动层API函数 ---
__declspec(dllexport) int H2C_Transmit(uchar* buffer, uint32_t offsite, uint32_t transfer_size, uint32_t* num_bytes_writen);
__declspec(dllexport) int C2H_Receive(uchar* buffer, uint32_t offsite, uint32_t receive_size, uint32_t* num_bytes_read);
__declspec(dllexport) int pcie_read_bar(uint32_t offsite, uint32_t* reg_value);
__declspec(dllexport) int pcie_write_bar(uint32_t offsite, uint32_t* reg_value);
__declspec(dllexport) void PCIe_Bar_WriteReg(uint32_t offset, uint32_t reg_value);
__declspec(dllexport) int pcie_read_bar_bit(uint32_t offsite, uint32_t bitNum, uint32_t* reg_value);
__declspec(dllexport) int pcie_write_bar_bit(uint32_t offsite, uint32_t bitNum, uint32_t* reg_value);

__declspec(dllexport) int MultiDev_H2C_Transmit(int Dev_ID, uchar* buffer, uint32_t offsite, uint32_t transfer_size, uint32_t* num_bytes_writen);
__declspec(dllexport) int MultiDev_C2H_Receive(int Dev_ID, uchar* buffer, uint32_t offsite, uint32_t receive_size, uint32_t* num_bytes_read);
__declspec(dllexport) int MultiDev_read_bar(int Dev_ID, uint32_t offsite, uint32_t* reg_value);
__declspec(dllexport) int MultiDev_write_bar(int Dev_ID, uint32_t offsite, uint32_t* reg_value);
__declspec(dllexport) void MultiDev_Bar_WriteReg(int Dev_ID, uint32_t offset, uint32_t reg_value);


// --- 用户层API函数 ---
__declspec(dllexport) void PiYSDev_DLL_Version(char* DLLVersion, uint32_t* length);
__declspec(dllexport) int PiYSDev_open(uint32_t* Dev_num);
                                        
__declspec(dllexport) void PiYS_PCIeCardStatus(float* temp, uint32_t* FPGA_version);
__declspec(dllexport) int PiYS_FiberRateConfig(float fiberRate, bool Flag32bit);
__declspec(dllexport) int PiYS_FiberRateConfigUser(float fiberRate, bool Flag32bit, const char* datPath);

__declspec(dllexport) void FiberCH1_Status(struct CHx_Status* CH1_Status);
__declspec(dllexport) void FiberCH2_Status(struct CHx_Status* CH2_Status);
__declspec(dllexport) void FiberCH3_Status(struct CHx_Status* CH3_Status);
__declspec(dllexport) void FiberCH4_Status(struct CHx_Status* CH4_Status);
__declspec(dllexport) void PiYSDev_Fiber_Status(int CH_ID, struct CHx_Status* CH_Status);

__declspec(dllexport) void Fiber_openSignal(int CH_ID, bool enable);
__declspec(dllexport) void PCIe_UserDataRead(int CH_ID, uint32_t* dataMatchControl, uint32_t* idleControlWord, uint32_t* idleData);
__declspec(dllexport) void PCIe_DataMatchControlWrite(int CH_ID, uint32_t dataMatchControl);
__declspec(dllexport) void PCIe_IdleControlWordWrite(int CH_ID, uint32_t idleControlWord);
__declspec(dllexport) void PCIe_IdleDataWrite(int CH_ID, uint32_t idleData);

__declspec(dllexport) void PiYSDev_openSignal(int CH_ID, bool enable);
__declspec(dllexport) void PiYSDev_IdleCodeRead(int CH_ID, uint32_t* dataMatchControl, uint32_t* idleControlWord, uint32_t* idleData);
__declspec(dllexport) void PiYSDev_IdleCodeSet(int CH_ID, uint32_t dataMatchControl, uint32_t idleControlWord, uint32_t idleData);
__declspec(dllexport) void PiYSDev_IdleShieldEn(uint32_t ShieldEn);

__declspec(dllexport) int PiYSDev_startSample(int CH_ID, uint32_t flag);
__declspec(dllexport) int PiYSDev_FetchData(int CH_ID, float MaxWaitTime, uint32_t* AvailableDataLen, uint32_t* ReadDataLen, uint32_t* dataArray);
__declspec(dllexport) int PiYSDev_FetchDataRes(int CH_ID, float MaxWaitTime, uint32_t* AvailableDataLen, uint32_t* ReadDataLen, uint32_t* dataArray);

__declspec(dllexport) int PiYSDev_QueryData(int CH_ID, uint32_t* QueryDataLen, uint32_t AlreadyRecv);
__declspec(dllexport) int PiYSDev_TransData(int CH_ID, uint32_t MaxLen, uint32_t* ReadDataLen, uchar* dataArray);
__declspec(dllexport) int PiYSDev_TransDataRes(int CH_ID, uint32_t MaxLen, uint32_t* ReadDataLen, uchar* dataArray);

__declspec(dllexport) int PiYSDev_StatusCheck();
__declspec(dllexport) void PiYSDev_DataProcessSet(int CH_ID, uint32_t ProcessEn);
__declspec(dllexport) void PiYSDev_DataProcessStatusRead(int CH_ID, uint32_t* ProcessStatus);
__declspec(dllexport) void PiYSDev_PulseDensityRead(int CH_ID, uint32_t* PulseDensity);
__declspec(dllexport) void PiYSDev_MaxFrameLenRead(int CH_ID, uint32_t* MaxFrameLen);
__declspec(dllexport) void PiYSDev_FrameNumberRead(int CH_ID, uint32_t* FrameNumber);



// --- 多设备API函数 ---
__declspec(dllexport) void MultiDev_PCIeCardStatus(int Dev_ID, float* temp, uint32_t* FPGA_version);
__declspec(dllexport) int MultiDev_FiberRateConfig(int Dev_ID, float fiberRate, bool Flag32bit);
__declspec(dllexport) int MultiDev_FiberRateConfigUser(int Dev_ID, float fiberRate, bool Flag32bit, const char* datPath);

__declspec(dllexport) void MultiDev_FiberCH1_Status(int Dev_ID, struct CHx_Status* CH1_Status);
__declspec(dllexport) void MultiDev_FiberCH2_Status(int Dev_ID, struct CHx_Status* CH2_Status);
__declspec(dllexport) void MultiDev_FiberCH3_Status(int Dev_ID, struct CHx_Status* CH3_Status);
__declspec(dllexport) void MultiDev_FiberCH4_Status(int Dev_ID, struct CHx_Status* CH4_Status);
__declspec(dllexport) void MultiDev_Fiber_Status(int Dev_ID, int CH_ID, struct CHx_Status* CH_Status);

__declspec(dllexport) void MultiDev_UserDataRead(int Dev_ID, int CH_ID, uint32_t* dataMatchControl, uint32_t* idleControlWord, uint32_t* idleData);
__declspec(dllexport) void MultiDev_DataMatchControlWrite(int Dev_ID, int CH_ID, uint32_t dataMatchControl);
__declspec(dllexport) void MultiDev_IdleControlWordWrite(int Dev_ID, int CH_ID, uint32_t idleControlWord);
__declspec(dllexport) void MultiDev_IdleDataWrite(int Dev_ID, int CH_ID, uint32_t idleData);

__declspec(dllexport) void MultiDev_openSignal(int Dev_ID, int CH_ID, bool enable);
__declspec(dllexport) void MultiDev_IdleCodeRead(int Dev_ID, int CH_ID, uint32_t* dataMatchControl, uint32_t* idleControlWord, uint32_t* idleData);
__declspec(dllexport) void MultiDev_IdleCodeSet(int Dev_ID, int CH_ID, uint32_t dataMatchControl, uint32_t idleControlWord, uint32_t idleData);

__declspec(dllexport) int MultiDev_startSample(int Dev_ID, int CH_ID, uint32_t flag);
__declspec(dllexport) int MultiDev_FetchData(int Dev_ID, int CH_ID, float MaxWaitTime, uint32_t* AvailableDataLen, uint32_t* ReadDataLen, uint32_t* dataArray);

__declspec(dllexport) int MultiDev_QueryData(int Dev_ID, int CH_ID, uint32_t* QueryDataLen, uint32_t AlreadyRecv);
__declspec(dllexport) int MultiDev_TransData(int Dev_ID, int CH_ID, uint32_t MaxLen, uint32_t* ReadDataLen, uchar* dataArray);
__declspec(dllexport) int MultiDev_TransDataRes(int Dev_ID, int CH_ID, uint32_t MaxLen, uint32_t* ReadDataLen, uchar* dataArray);

__declspec(dllexport) int MultiDev_StatusCheck(int Dev_ID);
__declspec(dllexport) void MultiDev_DataProcess(int Dev_ID, int CH_ID, uint32_t ProcessEn);


// --- 信号源控制函数 ---
__declspec(dllexport) void PiYS_SG_ValidDataLenSet(int Dev_ID, int CH_ID, uint32_t ValidDataLen);
__declspec(dllexport) void PiYS_SG_IdleCodeSet(int Dev_ID, int CH_ID, uint32_t IdleDataLen, uint32_t IdleControlWord, uint32_t IdleData);
__declspec(dllexport) void PiYS_SG_BitWidthModeSet(int Dev_ID, int CH_ID, uint32_t BitWidthMode);
__declspec(dllexport) void PiYS_SG_LenRandomSet(int Dev_ID, int CH_ID, uint32_t LenRandom);
__declspec(dllexport) void PiYS_SG_GenerateModeSet(int Dev_ID, int CH_ID, uint32_t GenerateMode);
__declspec(dllexport) void PiYS_SG_StartDataSet(int Dev_ID, int CH_ID, uint32_t StartData);
__declspec(dllexport) void PiYS_SG_StopDataSet(int Dev_ID, int CH_ID, uint32_t StopData);
__declspec(dllexport) void PiYS_SG_TimingLenSet(int Dev_ID, int CH_ID, uint32_t TimingLen);
__declspec(dllexport) void PiYS_SG_EndianModeSet(int Dev_ID, int CH_ID, uint32_t EndianMode);
__declspec(dllexport) void PiYS_SG_OutsideModeSet(int Dev_ID, int CH_ID, uint32_t OutsideMode);
__declspec(dllexport) void PiYS_SG_StartSend(int Dev_ID, int CH_ID);
__declspec(dllexport) void PiYS_SG_StopSend(int Dev_ID, int CH_ID);

__declspec(dllexport) void PiYS_SG_ValidDataLenRead(int Dev_ID, int CH_ID, uint32_t* ValidDataLen);
__declspec(dllexport) void PiYS_SG_IdleCodeRead(int Dev_ID, int CH_ID, uint32_t* IdleDataLen, uint32_t* IdleControlWord, uint32_t* IdleData);
__declspec(dllexport) void PiYS_SG_BitWidthModeRead(int Dev_ID, int CH_ID, uint32_t* BitWidthMode);
__declspec(dllexport) void PiYS_SG_LenRandomRead(int Dev_ID, int CH_ID, uint32_t* LenRandom);
__declspec(dllexport) void PiYS_SG_GenerateModeRead(int Dev_ID, int CH_ID, uint32_t* GenerateMode);
__declspec(dllexport) void PiYS_SG_StartDataRead(int Dev_ID, int CH_ID, uint32_t* StartData);
__declspec(dllexport) void PiYS_SG_StopDataRead(int Dev_ID, int CH_ID, uint32_t* StopData);
__declspec(dllexport) void PiYS_SG_TimingLenRead(int Dev_ID, int CH_ID, uint32_t* TimingLen);
__declspec(dllexport) void PiYS_SG_EndianModeRead(int Dev_ID, int CH_ID, uint32_t* EndianMode);
__declspec(dllexport) void PiYS_SG_OutsideModeRead(int Dev_ID, int CH_ID, uint32_t* OutsideMode);



