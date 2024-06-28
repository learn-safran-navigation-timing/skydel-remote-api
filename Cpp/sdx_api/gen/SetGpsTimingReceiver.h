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
    /// Set the connection parameters to the GPS Receiver from which the simulator will get the simulation start time.
    ///
    /// Name        Type                           Description
    /// ----------- ------------------------------ -----------------------------------------------------------------------------------------
    /// Port        string                         IP Address (Octoclock-G ex: "192.168.11.3") OR Serial Port (ex: "COM5")
    /// BaudRate    optional int                   Data baud rate of the serial port (optional)
    /// DataBits    optional int                   Number of data bits used by the serial port. Possible values are 5, 6, 7 and 8 (optional)
    /// Parity      optional SerialPortParity      Parity scheme used by the serial port (optional)
    /// StopBits    optional int                   Number of stop bits used by the serial port. Possible values are 1 and 2 (optional)
    /// FlowControl optional SerialPortFlowControl Flow control used by the serial port (optional)
    ///

    class SetGpsTimingReceiver;
    typedef std::shared_ptr<SetGpsTimingReceiver> SetGpsTimingReceiverPtr;
    
    
    class SetGpsTimingReceiver : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGpsTimingReceiver();

      SetGpsTimingReceiver(const std::string& port, const std::optional<int>& baudRate = {}, const std::optional<int>& dataBits = {}, const std::optional<Sdx::SerialPortParity>& parity = {}, const std::optional<int>& stopBits = {}, const std::optional<Sdx::SerialPortFlowControl>& flowControl = {});

      static SetGpsTimingReceiverPtr create(const std::string& port, const std::optional<int>& baudRate = {}, const std::optional<int>& dataBits = {}, const std::optional<Sdx::SerialPortParity>& parity = {}, const std::optional<int>& stopBits = {}, const std::optional<Sdx::SerialPortFlowControl>& flowControl = {});
      static SetGpsTimingReceiverPtr dynamicCast(CommandBasePtr ptr);
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

