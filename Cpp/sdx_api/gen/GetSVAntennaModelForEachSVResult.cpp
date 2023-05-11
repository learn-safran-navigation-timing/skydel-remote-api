
#include "gen/GetSVAntennaModelForEachSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVAntennaModelForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVAntennaModelForEachSVResult::CmdName = "GetSVAntennaModelForEachSVResult";
    const char* const GetSVAntennaModelForEachSVResult::Documentation = "Result of GetSVAntennaModelForEachSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSVAntennaModelForEachSVResult);


    GetSVAntennaModelForEachSVResult::GetSVAntennaModelForEachSVResult()
      : CommandResult(CmdName)
    {}

    GetSVAntennaModelForEachSVResult::GetSVAntennaModelForEachSVResult(const std::string& system, const std::vector<std::string>& antennaModelNames)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setAntennaModelNames(antennaModelNames);
    }

    GetSVAntennaModelForEachSVResult::GetSVAntennaModelForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<std::string>& antennaModelNames)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setAntennaModelNames(antennaModelNames);
    }


    GetSVAntennaModelForEachSVResultPtr GetSVAntennaModelForEachSVResult::create(const std::string& system, const std::vector<std::string>& antennaModelNames)
    {
      return std::make_shared<GetSVAntennaModelForEachSVResult>(system, antennaModelNames);
    }

    GetSVAntennaModelForEachSVResultPtr GetSVAntennaModelForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<std::string>& antennaModelNames)
    {
      return std::make_shared<GetSVAntennaModelForEachSVResult>(relatedCommand, system, antennaModelNames);
    }

    GetSVAntennaModelForEachSVResultPtr GetSVAntennaModelForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVAntennaModelForEachSVResult>(ptr);
    }

    bool GetSVAntennaModelForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<std::string>>::is_valid(m_values["AntennaModelNames"])
        ;

    }

    std::string GetSVAntennaModelForEachSVResult::documentation() const { return Documentation; }


    std::string GetSVAntennaModelForEachSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVAntennaModelForEachSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<std::string> GetSVAntennaModelForEachSVResult::antennaModelNames() const
    {
      return parse_json<std::vector<std::string>>::parse(m_values["AntennaModelNames"]);
    }

    void GetSVAntennaModelForEachSVResult::setAntennaModelNames(const std::vector<std::string>& antennaModelNames)
    {
      m_values.AddMember("AntennaModelNames", parse_json<std::vector<std::string>>::format(antennaModelNames, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
