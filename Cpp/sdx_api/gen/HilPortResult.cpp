
#include "HilPortResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of HilPortResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const HilPortResult::CmdName = "HilPortResult";
    const char* const HilPortResult::Documentation = "Result of GetHilPort.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- ---------------\n"
      "Port int  Hil Server Port";
    const char* const HilPortResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(HilPortResult);


    HilPortResult::HilPortResult()
      : CommandResult(CmdName, TargetId)
    {}

    HilPortResult::HilPortResult(int port)
      : CommandResult(CmdName, TargetId)
    {

      setPort(port);
    }

    HilPortResult::HilPortResult(CommandBasePtr relatedCommand, int port)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setPort(port);
    }


    HilPortResultPtr HilPortResult::create(int port)
    {
      return std::make_shared<HilPortResult>(port);
    }

    HilPortResultPtr HilPortResult::create(CommandBasePtr relatedCommand, int port)
    {
      return std::make_shared<HilPortResult>(relatedCommand, port);
    }

    HilPortResultPtr HilPortResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<HilPortResult>(ptr);
    }

    bool HilPortResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Port"])
        ;

    }

    std::string HilPortResult::documentation() const { return Documentation; }

    const std::vector<std::string>& HilPortResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Port"}; 
      return names; 
    }


    int HilPortResult::port() const
    {
      return parse_json<int>::parse(m_values["Port"]);
    }

    void HilPortResult::setPort(int port)
    {
      m_values.AddMember("Port", parse_json<int>::format(port, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
