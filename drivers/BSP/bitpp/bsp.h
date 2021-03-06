#pragma once

#include <csp.h>
#include <bsp_template.h>

namespace bsp
{

#if (USE_FREERTOS)
	void initMem();
#endif

//namespace uart
//{
//	using usart1TxPin =
//	    GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_9>, mAfPP, sHi, pUp>;
//	using usart1RxPin =
//	    GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_10>, mInput, sHi, pUp>;
//
//	void usartInitGpio(UartPort port);
//	USART_TypeDef* port2CSP(UartPort port);
//
//}  // namespace uart

//namespace log
//{
//	static const UartPort logPort = uartP1;
//}

using pa0Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_0>, mOutputPP, sHi, pUp>; //PA0
using pa1Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_1>, mOutputPP, sHi, pUp>; //PA1
using pa11Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_11>, mOutputPP, sHi, pUp>; //PA11
using pa12Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_12>, mOutputPP, sHi, pUp>; //PA12
using pa15Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_15>, mOutputPP, sHi, pUp>; //PA15

using pb0Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_0>, mOutputPP, sHi, pUp>; //PB0
using pb1Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_1>, mOutputPP, sHi, pUp>; //PB1
using pb3Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_3>, mOutputPP, sHi, pUp>; //PB3
using pb4Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_4>, mOutputPP, sHi, pUp>; //PB4
using pb5Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_5>, mOutputPP, sHi, pUp>; //PB5
using pb8Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_8>, mOutputPP, sHi, pUp>; //PB8
using pb9Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_9>, mOutputPP, sHi, pUp>; //PB9
using pb10Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_10>, mOutputPP, sHi, pUp>; //PB10
using pb11Pin = GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_11>, mOutputPP, sHi, pUp>; //PB11


namespace usb
{
	void init();
	void deinit();
}

namespace i2c
{
using i2cPins =
    GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_6 | GPIO_PIN_7>, mAfOD, sHi, pUp>;

void init(bsp::I2CPort);
I2C_TypeDef* port2CSP(bsp::I2CPort);
	
}  // namespace i2c

namespace i2conewire
{
	static const I2CPort i2cOnewirePort = i2cP1;

	const uint16_t i2cOnewireAddress = 0x01;
}

namespace lcd
{
	static const bsp::I2CPort lcdI2CPort = bsp::i2cP1;

	static const uint8_t lcdI2CAddress1 = 0x27;
	static const uint8_t lcdI2CAddress2 = 0x27;
}

//spi
namespace spi
{
	enum TypeChipSelect
	{
		AnalogInput = 1,
		Flash = 2,
		Sdio = 3
	};

	using adcFlashSck = GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_5>, mAfPP, sHi>;
	using adcFlashMiso = GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_6>, mInput>;
	using adcFlashMosi = GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_7>, mAfPP, sHi>;

	using sdioSck = GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_13>, mAfPP, sHi>;
	using sdioMiso = GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_14>, mInput>;
	using sdioMosi = GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_15>, mAfPP, sHi>;

	void init(SpiPort port);
	void chipSelect(uint8_t port);
	void chipUnselect(uint8_t port);

	SPI_TypeDef* port2CSP(bsp::SpiPort);
}  // namespace spi

namespace flash
{
	const SpiPort port = spiP1;

	using flashCsPin = GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_4>, mOutputPP>;
	using flashCs = Relay<flashCsPin, PinManageLogic::Inverse>;

	void init();
}

namespace adc
{
	const SpiPort port = spiP1;

	using adcCsPin = GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_3>, mOutputPP>;
	using adcCs = Relay<adcCsPin, PinManageLogic::Inverse>;

	using adcBusy = GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_2>, mInput>;

	void init();
}

namespace sdio
{
	const SpiPort port = spiP2;

	using sdioCd = GPIO<PinDef<CSP_GPIO_PORT_NBR_A, GPIO_PIN_8>, mITFalling, sHi, pUp>;

	using sdioCsPin = GPIO<PinDef<CSP_GPIO_PORT_NBR_B, GPIO_PIN_12>, mOutputPP>;
	using sdioCs = Relay<sdioCsPin, PinManageLogic::Inverse>;

	void init();
}

namespace rtc
{
	void init();
	void deinit();
}
}  // namespace bsp