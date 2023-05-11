
#include "gen/GetGpsTimingReceiverResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsTimingReceiverResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsTimingReceiverResult::CmdName = "GetGpsTimingReceiverResult";
    const char* const GetGpsTimingReceiverResult::Documentation = "Result of GetGpsTimingReceiver.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetGpsTimingReceiverResult);


    GetGpsTimingReceiverResult::GetGpsTimingReceiverResult()
      : CommandResult(CmdName)
    {}

    GetGpsTimingReceiverResult::GetGpsTimingReceiverResult(const std::string& port, const Sdx::optional<int>& baudRate, const Sdx::optional<int>& dataBits, const Sdx::optional<Sdx::SerialPortParity>& parity, const Sdx::optional<int>& stopBits, const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl)
      : CommandResult(CmdName)
    {

      setPort(port);
      setBaudRate(baudRate);
      setDataBits(dataBits);
      setParity(parity);
      setStopBits(stopBits);
      setFlowControl(flowControl);
    }

    GetGpsTimingReceiverResult::GetGpsTimingReceiverResult(CommandBasePtr relatedCommand, const std::string& port, const Sdx::optional<int>& baudRate, const Sdx::optional<int>& dataBits, const Sdx::optional<Sdx::SerialPortParity>& parity, const Sdx::optional<int>& stopBits, const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl)
      : CommandResult(CmdName, relatedCommand)
    {

      setPort(port);
      setBaudRate(baudRate);
      setDataBits(dataBits);
      setParity(parity);
      setStopBits(stopBits);
      setFlowControl(flowControl);
    }


    GetGpsTimingReceiverResultPtr GetGpsTimingReceiverResult::create(const std::string& port, const Sdx::optional<int>& baudRate, const Sdx::optional<int>& dataBits, const Sdx::optional<Sdx::SerialPortParity>& parity, const Sdx::optional<int>& stopBits, const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl)
    {
      return std::make_shared<GetGpsTimingReceiverResult>(port, baudRate, dataBits, parity, stopBits, flowControl);
    }

    GetGpsTimingReceiverResultPtr GetGpsTimingReceiverResult::create(CommandBasePtr relatedCommand, const std::string& port, const Sdx::optional<int>& baudRate, const Sdx::optional<int>& dataBits, const Sdx::optional<Sdx::SerialPortParity>& parity, const Sdx::optional<int>& stopBits, const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl)
    {
      return std::make_shared<GetGpsTimingReceiverResult>(relatedCommand, port, baudRate, dataBits, parity, stopBits, flowControl);
    }

    GetGpsTimingReceiverResultPtr GetGpsTimingReceiverResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsTimingReceiverResult>(ptr);
    }

    bool GetGpsTimingReceiverResult::isValid() const
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

    std::string GetGpsTimingReceiverResult::documentation() const { return Documentation; }


    std::string GetGpsTimingReceiverResult::port() const
    {
      return parse_json<std::string>::parse(m_values["Port"]);
    }

    void GetGpsTimingReceiverResult::setPort(const std::string& port)
    {
      m_values.AddMember("Port", parse_json<std::string>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> GetGpsTimingReceiverResult::baudRate() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["BaudRate"]);
    }

    void GetGpsTimingReceiverResult::setBaudRate(const Sdx::optional<int>& baudRate)
    {
      m_values.AddMember("BaudRate", parse_json<Sdx::optional<int>>::format(baudRate, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> GetGpsTimingReceiverResult::dataBits() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["DataBits"]);
    }

    void GetGpsTimingReceiverResult::setDataBits(const Sdx::optional<int>& dataBits)
    {
      m_values.AddMember("DataBits", parse_json<Sdx::optional<int>>::format(dataBits, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<Sdx::SerialPortParity> GetGpsTimingReceiverResult::parity() const
    {
      return parse_json<Sdx::optional<Sdx::SerialPortParity>>::parse(m_values["Parity"]);
    }

    void GetGpsTimingReceiverResult::setParity(const Sdx::optional<Sdx::SerialPortParity>& parity)
    {
      m_values.AddMember("Parity", parse_json<Sdx::optional<Sdx::SerialPortParity>>::format(parity, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<int> GetGpsTimingReceiverResult::stopBits() const
    {
      return parse_json<Sdx::optional<int>>::parse(m_values["StopBits"]);
    }

    void GetGpsTimingReceiverResult::setStopBits(const Sdx::optional<int>& stopBits)
    {
      m_values.AddMember("StopBits", parse_json<Sdx::optional<int>>::format(stopBits, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<Sdx::SerialPortFlowControl> GetGpsTimingReceiverResult::flowControl() const
    {
      return parse_json<Sdx::optional<Sdx::SerialPortFlowControl>>::parse(m_values["FlowControl"]);
    }

    void GetGpsTimingReceiverResult::setFlowControl(const Sdx::optional<Sdx::SerialPortFlowControl>& flowControl)
    {
      m_values.AddMember("FlowControl", parse_json<Sdx::optional<Sdx::SerialPortFlowControl>>::format(flowControl, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
