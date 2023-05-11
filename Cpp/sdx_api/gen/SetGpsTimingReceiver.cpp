
#include "gen/SetGpsTimingReceiver.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGpsTimingReceiver
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGpsTimingReceiver::CmdName = "SetGpsTimingReceiver";
    const char* const SetGpsTimingReceiver::Documentation = "Set the connection parameters to the GPS Receiver from which the simulator will get the simulation start time.";

    REGISTER_COMMAND_FACTORY(SetGpsTimingReceiver);


    SetGpsTimingReceiver::SetGpsTimingReceiver()
      : CommandBase(CmdName)
    {}

    SetGpsTimingReceiver::SetGpsTimingReceiver(const std::string& port, const Sdx::optional<int>& baudRate, const Sdx::optional<int>& dataBits, const Sdx::optional<Sdx::SerialPortParity>& parity, const Sdx::optional<int>& stopBits, const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl)
      : CommandBase(CmdName)
    {

      setPort(port);
      setBaudRate(baudRate);
      setDataBits(dataBits);
      setParity(parity);
      setStopBits(stopBits);
      setFlowControl(flowControl);
    }

    SetGpsTimingReceiverPtr SetGpsTimingReceiver::create(const std::string& port, const Sdx::optional<int>& baudRate, const Sdx::optional<int>& dataBits, const Sdx::optional<Sdx::SerialPortParity>& parity, const Sdx::optional<int>& stopBits, const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl)
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
          && parse_json<Sdx::optional<int>>::is_valid(m_values["BaudRate"])
          && parse_json<Sdx::optional<int>>::is_valid(m_values["DataBits"])
          && parse_json<Sdx::optional<Sdx::SerialPortParity>>::is_valid(m_values["Parity"])
          && parse_json<Sdx::optional<int>>::is_valid(m_values["StopBits"])
          && parse_json<Sdx::optional<Sdx::SerialPortFlowControl>>::is_valid(m_values["FlowControl"])
        ;

    }

    std::string SetGpsTimingReceiver::documentation() const { return Documentation; }


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



    Sdx::optional<int> SetGpsTimingReceiver::baudRate() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["BaudRate"]);
    }

    void SetGpsTimingReceiver::setBaudRate(const Sdx::optional<int>& baudRate)
    {
      m_values.AddMember("BaudRate", parse_json<Sdx::optional<int>>::format(baudRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> SetGpsTimingReceiver::dataBits() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["DataBits"]);
    }

    void SetGpsTimingReceiver::setDataBits(const Sdx::optional<int>& dataBits)
    {
      m_values.AddMember("DataBits", parse_json<Sdx::optional<int>>::format(dataBits, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<Sdx::SerialPortParity> SetGpsTimingReceiver::parity() const
    {
      return parse_json<Sdx::optional<Sdx::SerialPortParity>>::parse(m_values["Parity"]);
    }

    void SetGpsTimingReceiver::setParity(const Sdx::optional<Sdx::SerialPortParity>& parity)
    {
      m_values.AddMember("Parity", parse_json<Sdx::optional<Sdx::SerialPortParity>>::format(parity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> SetGpsTimingReceiver::stopBits() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["StopBits"]);
    }

    void SetGpsTimingReceiver::setStopBits(const Sdx::optional<int>& stopBits)
    {
      m_values.AddMember("StopBits", parse_json<Sdx::optional<int>>::format(stopBits, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<Sdx::SerialPortFlowControl> SetGpsTimingReceiver::flowControl() const
    {
      return parse_json<Sdx::optional<Sdx::SerialPortFlowControl>>::parse(m_values["FlowControl"]);
    }

    void SetGpsTimingReceiver::setFlowControl(const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl)
    {
      m_values.AddMember("FlowControl", parse_json<Sdx::optional<Sdx::SerialPortFlowControl>>::format(flowControl, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
