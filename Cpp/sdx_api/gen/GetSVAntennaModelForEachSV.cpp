
#include "gen/GetSVAntennaModelForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVAntennaModelForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVAntennaModelForEachSV::CmdName = "GetSVAntennaModelForEachSV";
    const char* const GetSVAntennaModelForEachSV::Documentation = "Get the antenna model for all satellites.";

    REGISTER_COMMAND_FACTORY(GetSVAntennaModelForEachSV);


    GetSVAntennaModelForEachSV::GetSVAntennaModelForEachSV()
      : CommandBase(CmdName)
    {}

    GetSVAntennaModelForEachSV::GetSVAntennaModelForEachSV(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    GetSVAntennaModelForEachSVPtr GetSVAntennaModelForEachSV::create(const std::string& system)
    {
      return std::make_shared<GetSVAntennaModelForEachSV>(system);
    }

    GetSVAntennaModelForEachSVPtr GetSVAntennaModelForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVAntennaModelForEachSV>(ptr);
    }

    bool GetSVAntennaModelForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetSVAntennaModelForEachSV::documentation() const { return Documentation; }


    int GetSVAntennaModelForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSVAntennaModelForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVAntennaModelForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
