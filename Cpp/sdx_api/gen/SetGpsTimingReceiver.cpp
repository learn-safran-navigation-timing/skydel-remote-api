
#include "SetGpsTimingReceiver.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsTimingReceiver
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsTimingReceiver::CmdName = "SetGpsTimingReceiver";
    const char* const SetGpsTimingReceiver::Documentation = "Set the connection parameters to the GPS Receiver from which the simulator will get the simulation start time.\n"
      "\n"
      "Name        Type                           Description\n"
      "----------- ------------------------------ -----------------------------------------------------------------------------------------\n"
      "Port        string                         IP Address (Octoclock-G ex: \"192.168.11.3\") OR Serial Port (ex: \"COM5\")\n"
      "BaudRate    optional int                   Data baud rate of the serial port (optional)\n"
      "DataBits    optional int                   Number of data bits used by the serial port. Possible values are 5, 6, 7 and 8 (optional)\n"
      "Parity      optional SerialPortParity      Parity scheme used by the serial port (optional)\n"
      "StopBits    optional int                   Number of stop bits used by the serial port. Possible values are 1 and 2 (optional)\n"
      "FlowControl optional SerialPortFlowControl Flow control used by the serial port (optional)";
    const char* const SetGpsTimingReceiver::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGpsTimingReceiver);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGpsTimingReceiver);


    SetGpsTimingReceiver::SetGpsTimingReceiver()
      : CommandBase(CmdName, TargetId)
    {}

    SetGpsTimingReceiver::SetGpsTimingReceiver(const std::string& port, const std::optional<int>& baudRate, const std::optional<int>& dataBits, const std::optional<Sdx::SerialPortParity>& parity, const std::optional<int>& stopBits, const std::optional<Sdx::SerialPortFlowControl>& flowControl)
      : CommandBase(CmdName, TargetId)
    {

      setPort(port);
      setBaudRate(baudRate);
      setDataBits(dataBits);
      setParity(parity);
      setStopBits(stopBits);
      setFlowControl(flowControl);
    }

    SetGpsTimingReceiverPtr SetGpsTimingReceiver::create(const std::string& port, const std::optional<int>& baudRate, const std::optional<int>& dataBits, const std::optional<Sdx::SerialPortParity>& parity, const std::optional<int>& stopBits, const std::optional<Sdx::SerialPortFlowControl>& flowControl)
    {
      return std::make_shared<SetGpsTimingReceiver>(port, baudRate, dataBits, parity, stopBits, flowControl);
    }

    SetGpsTimingReceiverPtr SetGpsTimingReceiver::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGpsTimingReceiver>(ptr);
    }

    bool SetGpsTimingReceiver::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Port"])
          && parse_json<std::optional<int>>::is_valid(m_values["BaudRate"])
          && parse_json<std::optional<int>>::is_valid(m_values["DataBits"])
          && parse_json<std::optional<Sdx::SerialPortParity>>::is_valid(m_values["Parity"])
          && parse_json<std::optional<int>>::is_valid(m_values["StopBits"])
          && parse_json<std::optional<Sdx::SerialPortFlowControl>>::is_valid(m_values["FlowControl"])
        ;

    }

    std::string SetGpsTimingReceiver::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGpsTimingReceiver::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Port", "BaudRate", "DataBits", "Parity", "StopBits", "FlowControl"}; 
      return names; 
    }


    int SetGpsTimingReceiver::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGpsTimingReceiver::port() const
    {
      return parse_json<std::string>::parse(m_values["Port"]);
    }

    void SetGpsTimingReceiver::setPort(const std::string& port)
    {
      m_values.AddMember("Port", parse_json<std::string>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> SetGpsTimingReceiver::baudRate() const
    {
      return parse_json<std::optional<int>>::parse(m_values["BaudRate"]);
    }

    void SetGpsTimingReceiver::setBaudRate(const std::optional<int>& baudRate)
    {
      m_values.AddMember("BaudRate", parse_json<std::optional<int>>::format(baudRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> SetGpsTimingReceiver::dataBits() const
    {
      return parse_json<std::optional<int>>::parse(m_values["DataBits"]);
    }

    void SetGpsTimingReceiver::setDataBits(const std::optional<int>& dataBits)
    {
      m_values.AddMember("DataBits", parse_json<std::optional<int>>::format(dataBits, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<Sdx::SerialPortParity> SetGpsTimingReceiver::parity() const
    {
      return parse_json<std::optional<Sdx::SerialPortParity>>::parse(m_values["Parity"]);
    }

    void SetGpsTimingReceiver::setParity(const std::optional<Sdx::SerialPortParity>& parity)
    {
      m_values.AddMember("Parity", parse_json<std::optional<Sdx::SerialPortParity>>::format(parity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> SetGpsTimingReceiver::stopBits() const
    {
      return parse_json<std::optional<int>>::parse(m_values["StopBits"]);
    }

    void SetGpsTimingReceiver::setStopBits(const std::optional<int>& stopBits)
    {
      m_values.AddMember("StopBits", parse_json<std::optional<int>>::format(stopBits, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<Sdx::SerialPortFlowControl> SetGpsTimingReceiver::flowControl() const
    {
      return parse_json<std::optional<Sdx::SerialPortFlowControl>>::parse(m_values["FlowControl"]);
    }

    void SetGpsTimingReceiver::setFlowControl(const std::optional<Sdx::SerialPortFlowControl>& flowControl)
    {
      m_values.AddMember("FlowControl", parse_json<std::optional<Sdx::SerialPortFlowControl>>::format(flowControl, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
