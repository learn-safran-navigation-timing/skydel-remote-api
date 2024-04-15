
#include "GetSbasMessageUpdateInterval.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasMessageUpdateInterval
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasMessageUpdateInterval::CmdName = "GetSbasMessageUpdateInterval";
    const char* const GetSbasMessageUpdateInterval::Documentation = "Get the SBAS message update interval.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- -----------------\n"
      "Message int  The message type.";
    const char* const GetSbasMessageUpdateInterval::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasMessageUpdateInterval);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasMessageUpdateInterval);


    GetSbasMessageUpdateInterval::GetSbasMessageUpdateInterval()
      : CommandBase(CmdName, TargetId)
    {}

    GetSbasMessageUpdateInterval::GetSbasMessageUpdateInterval(int message)
      : CommandBase(CmdName, TargetId)
    {

      setMessage(message);
    }

    GetSbasMessageUpdateIntervalPtr GetSbasMessageUpdateInterval::create(int message)
    {
      return std::make_shared<GetSbasMessageUpdateInterval>(message);
    }

    GetSbasMessageUpdateIntervalPtr GetSbasMessageUpdateInterval::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasMessageUpdateInterval>(ptr);
    }

    bool GetSbasMessageUpdateInterval::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Message"])
        ;

    }

    std::string GetSbasMessageUpdateInterval::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasMessageUpdateInterval::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Message"}; 
      return names; 
    }


    int GetSbasMessageUpdateInterval::executePermission() const
    {
      return EXECUTE_IF_IDLE | EXECUTE_IF_SIMULATING;
    }


    int GetSbasMessageUpdateInterval::message() const
    {
      return parse_json<int>::parse(m_values["Message"]);
    }

    void GetSbasMessageUpdateInterval::setMessage(int message)
    {
      m_values.AddMember("Message", parse_json<int>::format(message, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
