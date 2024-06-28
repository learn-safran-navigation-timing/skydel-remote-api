
#include "GetNtpServerResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetNtpServerResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetNtpServerResult::CmdName = "GetNtpServerResult";
    const char* const GetNtpServerResult::Documentation = "Result of GetNtpServer.\n"
      "\n"
      "Name    Type         Description\n"
      "------- ------------ --------------------------------------------------------------------------------------\n"
      "Address string       IP Address of the NTP server.\n"
      "Port    optional int Port at the specified address to reach the NTP server (optional), default port is 123.";
    const char* const GetNtpServerResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetNtpServerResult);


    GetNtpServerResult::GetNtpServerResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetNtpServerResult::GetNtpServerResult(const std::string& address, const std::optional<int>& port)
      : CommandResult(CmdName, TargetId)
    {

      setAddress(address);
      setPort(port);
    }

    GetNtpServerResult::GetNtpServerResult(CommandBasePtr relatedCommand, const std::string& address, const std::optional<int>& port)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setAddress(address);
      setPort(port);
    }


    GetNtpServerResultPtr GetNtpServerResult::create(const std::string& address, const std::optional<int>& port)
    {
      return std::make_shared<GetNtpServerResult>(address, port);
    }

    GetNtpServerResultPtr GetNtpServerResult::create(CommandBasePtr relatedCommand, const std::string& address, const std::optional<int>& port)
    {
      return std::make_shared<GetNtpServerResult>(relatedCommand, address, port);
    }

    GetNtpServerResultPtr GetNtpServerResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetNtpServerResult>(ptr);
    }

    bool GetNtpServerResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Address"])
          && parse_json<std::optional<int>>::is_valid(m_values["Port"])
        ;

    }

    std::string GetNtpServerResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetNtpServerResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Address", "Port"}; 
      return names; 
    }


    std::string GetNtpServerResult::address() const
    {
      return parse_json<std::string>::parse(m_values["Address"]);
    }

    void GetNtpServerResult::setAddress(const std::string& address)
    {
      m_values.AddMember("Address", parse_json<std::string>::format(address, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<int> GetNtpServerResult::port() const
    {
      return parse_json<std::optional<int>>::parse(m_values["Port"]);
    }

    void GetNtpServerResult::setPort(const std::optional<int>& port)
    {
      m_values.AddMember("Port", parse_json<std::optional<int>>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
