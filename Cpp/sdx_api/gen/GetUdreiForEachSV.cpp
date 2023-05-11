
#include "gen/GetUdreiForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetUdreiForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetUdreiForEachSV::CmdName = "GetUdreiForEachSV";
    const char* const GetUdreiForEachSV::Documentation = "Get the UDREI value transmitted by SBAS for all satellites of the specified constellation.";

    REGISTER_COMMAND_FACTORY(GetUdreiForEachSV);


    GetUdreiForEachSV::GetUdreiForEachSV()
      : CommandBase(CmdName)
    {}

    GetUdreiForEachSV::GetUdreiForEachSV(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    GetUdreiForEachSVPtr GetUdreiForEachSV::create(const std::string& system)
    {
      return std::make_shared<GetUdreiForEachSV>(system);
    }

    GetUdreiForEachSVPtr GetUdreiForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetUdreiForEachSV>(ptr);
    }

    bool GetUdreiForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetUdreiForEachSV::documentation() const { return Documentation; }


    int GetUdreiForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetUdreiForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetUdreiForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
