
#include "gen/GetVisibleSVResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetVisibleSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetVisibleSVResult::CmdName = "GetVisibleSVResult";
    const char* const GetVisibleSVResult::Documentation = "Result of GetVisibleSV.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetVisibleSVResult);


    GetVisibleSVResult::GetVisibleSVResult()
      : CommandResult(CmdName)
    {}

    GetVisibleSVResult::GetVisibleSVResult(const std::string& system, const std::vector<int>& svId)
      : CommandResult(CmdName)
    {

      setSystem(system);
      setSvId(svId);
    }

    GetVisibleSVResult::GetVisibleSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<int>& svId)
      : CommandResult(CmdName, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
    }


    GetVisibleSVResultPtr GetVisibleSVResult::create(const std::string& system, const std::vector<int>& svId)
    {
      return std::make_shared<GetVisibleSVResult>(system, svId);
    }

    GetVisibleSVResultPtr GetVisibleSVResult::create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<int>& svId)
    {
      return std::make_shared<GetVisibleSVResult>(relatedCommand, system, svId);
    }

    GetVisibleSVResultPtr GetVisibleSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetVisibleSVResult>(ptr);
    }

    bool GetVisibleSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<std::vector<int>>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetVisibleSVResult::documentation() const { return Documentation; }


    std::string GetVisibleSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetVisibleSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<int> GetVisibleSVResult::svId() const
    {
      return parse_json<std::vector<int>>::parse(m_values["SvId"]);
    }

    void GetVisibleSVResult::setSvId(const std::vector<int>& svId)
    {
      m_values.AddMember("SvId", parse_json<std::vector<int>>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
