
#include "gen/HilPortResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of HilPortResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const HilPortResult::CmdName = "HilPortResult";
    const char* const HilPortResult::Documentation = "Result of GetHilPort.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(HilPortResult);


    HilPortResult::HilPortResult()
      : CommandResult(CmdName)
    {}

    HilPortResult::HilPortResult(int port)
      : CommandResult(CmdName)
    {

      setPort(port);
    }

    HilPortResult::HilPortResult(CommandBasePtr relatedCommand, int port)
      : CommandResult(CmdName, relatedCommand)
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
