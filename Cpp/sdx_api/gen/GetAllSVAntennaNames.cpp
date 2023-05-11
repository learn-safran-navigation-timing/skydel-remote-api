
#include "gen/GetAllSVAntennaNames.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAllSVAntennaNames
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAllSVAntennaNames::CmdName = "GetAllSVAntennaNames";
    const char* const GetAllSVAntennaNames::Documentation = "Get a list of all space vehicle antenna names.";

    REGISTER_COMMAND_FACTORY(GetAllSVAntennaNames);


    GetAllSVAntennaNames::GetAllSVAntennaNames()
      : CommandBase(CmdName)
    {}

    GetAllSVAntennaNames::GetAllSVAntennaNames(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    GetAllSVAntennaNamesPtr GetAllSVAntennaNames::create(const std::string& system)
    {
      return std::make_shared<GetAllSVAntennaNames>(system);
    }

    GetAllSVAntennaNamesPtr GetAllSVAntennaNames::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAllSVAntennaNames>(ptr);
    }

    bool GetAllSVAntennaNames::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetAllSVAntennaNames::documentation() const { return Documentation; }


    int GetAllSVAntennaNames::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetAllSVAntennaNames::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetAllSVAntennaNames::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
