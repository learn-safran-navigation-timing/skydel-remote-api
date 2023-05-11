
#include "gen/GetSbasUdreiResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasUdreiResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasUdreiResult::CmdName = "GetSbasUdreiResult";
    const char* const GetSbasUdreiResult::Documentation = "Result of GetSbasUdrei.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSbasUdreiResult);


    GetSbasUdreiResult::GetSbasUdreiResult()
      : CommandResult(CmdName)
    {}

    GetSbasUdreiResult::GetSbasUdreiResult(int udrei)
      : CommandResult(CmdName)
    {

      setUdrei(udrei);
    }

    GetSbasUdreiResult::GetSbasUdreiResult(CommandBasePtr relatedCommand, int udrei)
      : CommandResult(CmdName, relatedCommand)
    {

      setUdrei(udrei);
    }


    GetSbasUdreiResultPtr GetSbasUdreiResult::create(int udrei)
    {
      return std::make_shared<GetSbasUdreiResult>(udrei);
    }

    GetSbasUdreiResultPtr GetSbasUdreiResult::create(CommandBasePtr relatedCommand, int udrei)
    {
      return std::make_shared<GetSbasUdreiResult>(relatedCommand, udrei);
    }

    GetSbasUdreiResultPtr GetSbasUdreiResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasUdreiResult>(ptr);
    }

    bool GetSbasUdreiResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Udrei"])
        ;

    }

    std::string GetSbasUdreiResult::documentation() const { return Documentation; }


    int GetSbasUdreiResult::udrei() const
    {
      return parse_json<int>::parse(m_values["Udrei"]);
    }

    void GetSbasUdreiResult::setUdrei(int udrei)
    {
      m_values.AddMember("Udrei", parse_json<int>::format(udrei, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
