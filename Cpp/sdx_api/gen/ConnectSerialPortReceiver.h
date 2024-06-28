#pragma once

#include <memory>
#include "command_base.h"

#include "gen/SerialPortFlowControl.h"
#include "gen/SerialPortParity.h"
#include <optional>
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
      static const char* const TargetId;


      ConnectSerialPortReceiver();

      ConnectSerialPortReceiver(const std::string& port, const std::optional<int>& baudRate = {}, const std::optional<int>& dataBits = {}, const std::optional<Sdx::SerialPortParity>& parity = {}, const std::optional<int>& stopBits = {}, const std::optional<Sdx::SerialPortFlowControl>& flowControl = {});

      static ConnectSerialPortReceiverPtr create(const std::string& port, const std::optional<int>& baudRate = {}, const std::optional<int>& dataBits = {}, const std::optional<Sdx::SerialPortParity>& parity = {}, const std::optional<int>& stopBits = {}, const std::optional<Sdx::SerialPortFlowControl>& flowControl = {});
      static ConnectSerialPortReceiverPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** port ****
      std::string port() const;
      void setPort(const std::string& port);


      // **** baudRate ****
      std::optional<int> baudRate() const;
      void setBaudRate(const std::optional<int>& baudRate);


      // **** dataBits ****
      std::optional<int> dataBits() const;
      void setDataBits(const std::optional<int>& dataBits);


      // **** parity ****
      std::optional<Sdx::SerialPortParity> parity() const;
      void setParity(const std::optional<Sdx::SerialPortParity>& parity);


      // **** stopBits ****
      std::optional<int> stopBits() const;
      void setStopBits(const std::optional<int>& stopBits);


      // **** flowControl ****
      std::optional<Sdx::SerialPortFlowControl> flowControl() const;
      void setFlowControl(const std::optional<Sdx::SerialPortFlowControl>& flowControl);
    };
    
  }
}

