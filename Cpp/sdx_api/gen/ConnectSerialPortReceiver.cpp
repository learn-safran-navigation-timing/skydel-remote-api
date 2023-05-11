
#include "gen/ConnectSerialPortReceiver.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ConnectSerialPortReceiver
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ConnectSerialPortReceiver::CmdName = "ConnectSerialPortReceiver";
    const char* const ConnectSerialPortReceiver::Documentation = "Connect a receiver.";

    REGISTER_COMMAND_FACTORY(ConnectSerialPortReceiver);


    ConnectSerialPortReceiver::ConnectSerialPortReceiver()
      : CommandBase(CmdName)
    {}

    ConnectSerialPortReceiver::ConnectSerialPortReceiver(const std::string& port, const Sdx::optional<int>& baudRate, const Sdx::optional<int>& dataBits, const Sdx::optional<Sdx::SerialPortParity>& parity, const Sdx::optional<int>& stopBits, const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl)
      : CommandBase(CmdName)
    {

      setPort(port);
      setBaudRate(baudRate);
      setDataBits(dataBits);
      setParity(parity);
      setStopBits(stopBits);
      setFlowControl(flowControl);
    }

    ConnectSerialPortReceiverPtr ConnectSerialPortReceiver::create(const std::string& port, const Sdx::optional<int>& baudRate, const Sdx::optional<int>& dataBits, const Sdx::optional<Sdx::SerialPortParity>& parity, const Sdx::optional<int>& stopBits, const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl)
    {
      return std::make_shared<ConnectSerialPortReceiver>(port, baudRate, dataBits, parity, stopBits, flowControl);
    }

    ConnectSerialPortReceiverPtr ConnectSerialPortReceiver::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ConnectSerialPortReceiver>(ptr);
    }

    bool ConnectSerialPortReceiver::isValid() const
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

    std::string ConnectSerialPortReceiver::documentation() const { return Documentation; }


    int ConnectSerialPortReceiver::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::string ConnectSerialPortReceiver::port() const
    {
      return parse_json<std::string>::parse(m_values["Port"]);
    }

    void ConnectSerialPortReceiver::setPort(const std::string& port)
    {
      m_values.AddMember("Port", parse_json<std::string>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> ConnectSerialPortReceiver::baudRate() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["BaudRate"]);
    }

    void ConnectSerialPortReceiver::setBaudRate(const Sdx::optional<int>& baudRate)
    {
      m_values.AddMember("BaudRate", parse_json<Sdx::optional<int>>::format(baudRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> ConnectSerialPortReceiver::dataBits() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["DataBits"]);
    }

    void ConnectSerialPortReceiver::setDataBits(const Sdx::optional<int>& dataBits)
    {
      m_values.AddMember("DataBits", parse_json<Sdx::optional<int>>::format(dataBits, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<Sdx::SerialPortParity> ConnectSerialPortReceiver::parity() const
    {
      return parse_json<Sdx::optional<Sdx::SerialPortParity>>::parse(m_values["Parity"]);
    }

    void ConnectSerialPortReceiver::setParity(const Sdx::optional<Sdx::SerialPortParity>& parity)
    {
      m_values.AddMember("Parity", parse_json<Sdx::optional<Sdx::SerialPortParity>>::format(parity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> ConnectSerialPortReceiver::stopBits() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["StopBits"]);
    }

    void ConnectSerialPortReceiver::setStopBits(const Sdx::optional<int>& stopBits)
    {
      m_values.AddMember("StopBits", parse_json<Sdx::optional<int>>::format(stopBits, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<Sdx::SerialPortFlowControl> ConnectSerialPortReceiver::flowControl() const
    {
      return parse_json<Sdx::optional<Sdx::SerialPortFlowControl>>::parse(m_values["FlowControl"]);
    }

    void ConnectSerialPortReceiver::setFlowControl(const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl)
    {
      m_values.AddMember("FlowControl", parse_json<Sdx::optional<Sdx::SerialPortFlowControl>>::format(flowControl, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
