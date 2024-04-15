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

      SetGpsTimingReceiver(const std::string& port, const Sdx::optional<int>& baudRate = {}, const Sdx::optional<int>& dataBits = {}, const Sdx::optional<Sdx::SerialPortParity>& parity = {}, const Sdx::optional<int>& stopBits = {}, const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl = {});

      static SetGpsTimingReceiverPtr create(const std::string& port, const Sdx::optional<int>& baudRate = {}, const Sdx::optional<int>& dataBits = {}, const Sdx::optional<Sdx::SerialPortParity>& parity = {}, const Sdx::optional<int>& stopBits = {}, const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl = {});
      static SetGpsTimingReceiverPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

