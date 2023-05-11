#pragma once

#include <memory>
#include "command_base.h"

#include "gen/SerialPortFlowControl.h"
#include "gen/SerialPortParity.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Connect a receiver.
    ///
    /// Name        Type                           Description
    /// ----------- ------------------------------ -------------------------------------------------------------------------------------------------------------------------------------
    /// Port        string                         Serial Port (ex: "COM5").
    /// BaudRate    optional int                   Data baud rate of the serial port. Can be 1200 | 2400 | 4800 | 9600 | 19200 | 38400 | 57600 | 115200 | 460800. Default value is 9600.
    /// DataBits    optional int                   Number of data bits used by the serial port. Possible values are 5, 6, 7 and 8. Default value is 8.
    /// Parity      optional SerialPortParity      Parity scheme used by the serial port. Default value is NoParity.
    /// StopBits    optional int                   Number of stop bits used by the serial port. Possible values are 1 and 2. Default value is 1.
    /// FlowControl optional SerialPortFlowControl Flow control used by the serial port. Default value is NoFlowControl.
    ///

    class ConnectSerialPortReceiver;
    typedef std::shared_ptr<ConnectSerialPortReceiver> ConnectSerialPortReceiverPtr;
    
    
    class ConnectSerialPortReceiver : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ConnectSerialPortReceiver();

      ConnectSerialPortReceiver(const std::string& port, const Sdx::optional<int>& baudRate = {}, const Sdx::optional<int>& dataBits = {}, const Sdx::optional<Sdx::SerialPortParity>& parity = {}, const Sdx::optional<int>& stopBits = {}, const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl = {});

      static ConnectSerialPortReceiverPtr create(const std::string& port, const Sdx::optional<int>& baudRate = {}, const Sdx::optional<int>& dataBits = {}, const Sdx::optional<Sdx::SerialPortParity>& parity = {}, const Sdx::optional<int>& stopBits = {}, const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl = {});
      static ConnectSerialPortReceiverPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** port ****
      std::string port() const;
      void setPort(const std::string& port);


      // **** baudRate ****
      Sdx::optional<int> baudRate() const;
      void setBaudRate(const Sdx::optional<int>& baudRate);


      // **** dataBits ****
      Sdx::optional<int> dataBits() const;
      void setDataBits(const Sdx::optional<int>& dataBits);


      // **** parity ****
      Sdx::optional<Sdx::SerialPortParity> parity() const;
      void setParity(const Sdx::optional<Sdx::SerialPortParity>& parity);


      // **** stopBits ****
      Sdx::optional<int> stopBits() const;
      void setStopBits(const Sdx::optional<int>& stopBits);


      // **** flowControl ****
      Sdx::optional<Sdx::SerialPortFlowControl> flowControl() const;
      void setFlowControl(const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl);
    };
    
  }
}

