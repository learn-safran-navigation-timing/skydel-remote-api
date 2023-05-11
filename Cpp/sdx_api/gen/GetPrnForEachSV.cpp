
#include "gen/GetPrnForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPrnForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPrnForEachSV::CmdName = "GetPrnForEachSV";
    const char* const GetPrnForEachSV::Documentation = "Get the PRN for each satellite for specified signals.";

    REGISTER_COMMAND_FACTORY(GetPrnForEachSV);


    GetPrnForEachSV::GetPrnForEachSV()
      : CommandBase(CmdName)
    {}

    GetPrnForEachSV::GetPrnForEachSV(const std::string& signal)
      : CommandBase(CmdName)
    {

      setSignal(signal);
    }

    GetPrnForEachSVPtr GetPrnForEachSV::create(const std::string& signal)
    {
      return std::make_shared<GetPrnForEachSV>(signal);
    }

    GetPrnForEachSVPtr GetPrnForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPrnForEachSV>(ptr);
    }

    bool GetPrnForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string GetPrnForEachSV::documentation() const { return Documentation; }


    int GetPrnForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPrnForEachSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void GetPrnForEachSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
